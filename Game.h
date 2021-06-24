#pragma once

#include<iostream>
#include <SDL_image.h>
#include <vector>
#include "SDL.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "player.h"
#include "Enemy.h"


#ifndef __Game__

#define __Game__

class Game
{
public:
	Game() {}


	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void draw();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

	std::vector<GameObject*> m_gameObjects;

private: 

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int m_currentFrame;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

};

#endif /* defined(__Game__)*/