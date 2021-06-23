#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "player.h"


#ifndef __Game__

#define __Game__

class Game
{
public:
	Game() {}


	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private: 

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int m_currentFrame;


	GameObject m_go;
	Player m_player;
	
};

#endif /* defined(__Game__)*/