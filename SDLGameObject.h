#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"

#include "GameObject.h"
#include "TextureManager.h"


#ifndef __SDLGameObject__

#define __SDLGameObject__



class SDLGameObject : public GameObject
{
public:
	 
	SDLGameObject(const LoaderParams* pParams);

	void upload(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	int m_x;
	int m_y;

	int m_width;
	int m_height;
	
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;

};

#endif /* defined(__SDLGameObject__)*/