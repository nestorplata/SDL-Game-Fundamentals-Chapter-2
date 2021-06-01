#include "Game.h"

Game::Game()
{
	std::cout << "game created\n";
}

Game::~Game()
{
	std::cout << "game destroyed\n";
}

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
				SDL_SetRenderDrawColor(m_pRenderer, 43, 120, 63, 255);
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

	//create the texture
	SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	//get the dimensions of the texture

	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	//Setting the width ahd height of the rectangle

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	m_bRunning = true; //everything inited successfully, start the main loop
	return true;

}

void  Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear the rendere to draw the color
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle); //render texture
	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::update()
{
}

void  Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}