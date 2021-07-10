#pragma once

#include<iostream>
#include <SDL_image.h>
#include "SDL.h"

#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"


#ifndef __SDLGameObject__

#define __SDLGameObject__



class SDLGameObject : public GameObject
{
public:
	 
	SDLGameObject(const LoaderParams* pParams);

	void upload(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	virtual void draw();
	virtual void preupdate();
	virtual void update();
	virtual void clean();

protected:


	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;

};

#endif /* defined(__SDLGameObject__)*/