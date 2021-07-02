#pragma once

#include <vector>

#include "player.h"
#include "Enemy.h"


#ifndef __Game__

#define __Game__

class Game
{
public:

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

	std::vector<GameObject*> m_gameObjects;

private: 
	//make the constructor private
	Game() {};

	//create the s_pInstance member variable
	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int m_currentFrame;

	SDLGameObject* uploader;


};

typedef Game TheGame;

#endif /* defined(__Game__)*/