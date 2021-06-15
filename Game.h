#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"




#ifndef __Game__

#define __Game__

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private: 

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture; /// the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; //another rectangle

	bool m_bRunning;

};

#endif /* defined(__Game__)*/