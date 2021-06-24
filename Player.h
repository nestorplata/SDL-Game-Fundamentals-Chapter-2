#pragma once
#include "GameObject.h"
class Player : public GameObject // inherit from GameObject
{
public:

	void load(int x, int y, int width, int height,
		std::string fileName, std::string textureID, SDL_Renderer* pRenderer);

	void draw(SDL_Renderer* pRenderer);

	void update();

	void clean();
};