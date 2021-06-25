#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"

#include "TextureManager.h"

class GameObject
{
public:
	
	virtual void upload(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	virtual void load(int x, int y, int width, int height, std::string textureID);

	virtual void draw(SDL_Renderer* pRenderer);

	virtual void update();

	virtual void clean();

	/*
	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;
	
	
	
	
	*/

protected:

	//GameObject(const LoaderParams* pParams) {}
	//virtual ~GameObject() {}

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

