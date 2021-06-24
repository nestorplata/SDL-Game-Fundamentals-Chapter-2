#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string fileName, std::string textureID, SDL_Renderer* pRenderer);

	void draw(SDL_Renderer* pRenderer);

	void update();

	void clean();
};