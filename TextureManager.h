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

	//~TextureManager();

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}


	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	//draw

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawframe

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clearFromTextureMap(std::string id);


	std::map<std::string, SDL_Texture*> m_textureMap;

private:
	TextureManager() {}
	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);

	static TextureManager* s_pInstance;
};


typedef TextureManager TheTextureManager;

#endif /* defined(__TextureManager__)*/
