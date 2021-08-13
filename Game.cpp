#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	//attempt to initialize initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		std:: cout << "SDL init success\n";

		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer int fail\n";
				return false; //renderer init fail
			}
		}
		else 
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; //SDL init fail
	}
	std:: cout<< "init success \n";

	TheInputHandler::Instance()->initialiseJoysticks();

	m_bRunning = true; //everything inited successfully, start the main loop

	//setting up menu
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	uploader->upload("Assets/animate-alpha.png", "animate", m_pRenderer);
	uploader->upload("Assets/button.png", "playbutton", m_pRenderer);
	uploader->upload("Assets/exit.png", "exitbutton", m_pRenderer); 
	uploader->upload("Assets/helicopter.png", "helicopter", m_pRenderer);


	//m_gameObjects.push_back(new Player(new LoaderParams(320, 240, 128, 82, "animate")));
	//m_gameObjects.push_back(new SDLGameObject(new LoaderParams(0, 0, 128, 82, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 128, 82, "animate")));

	return true;
}

void  Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear the renderer to draw the color
	
	//loop through our objects and draw them
	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); //draw to the screen

}
	
void Game::update()
{
	m_pGameStateMachine->update();
}

void  Game::clean()
{
	std::cout << "cleaning game \n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	SDL_Quit();
}

void Game::handleEvents()
{

	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}
