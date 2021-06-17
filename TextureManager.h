#pragma once

#include <map>
#include<iostream>
#include<string>
#include <SDL_image.h>
#include "SDL.h"

#ifndef __TextureManager__

#define __TextrueManager__

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	//draw

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawframe

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	
private:

	std::map<std::string, SDL_Texture*> m_textureMap;

};





#endif /* defined(__TextureManager__)*/
