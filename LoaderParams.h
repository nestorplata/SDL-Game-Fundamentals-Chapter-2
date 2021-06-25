#pragma once
#include<iostream>
#include <SDL_image.h>
#include "SDL.h"
class LoaderParams
{
public:

	void Loaderparams(int x, int y, int width, int height, std::string fileName,
		std::string textureID, SDL_Renderer* pRenderer) : m_x(x), m_y(y),
		m_width(width), m_height(height), m_fileName(fileName),
		m_textureID(textureID), m_pRenderer(pRenderer)
	{
		

	}
};