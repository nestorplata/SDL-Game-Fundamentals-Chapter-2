#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"

class GameObject
{
public:

	virtual void load(int x, int y, int width, int height,
		std::string fileName, std::string textureID, SDL_Renderer* pRenderer);

	virtual void draw(SDL_Renderer* pRenderer);

	virtual void update();

	virtual void clean();

protected:

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

