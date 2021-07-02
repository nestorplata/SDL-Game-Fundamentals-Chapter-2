#pragma once

#include"SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	//void load(int x, int y, int width, int height, std::string textureID);

	//void draw(SDL_Renderer* pRenderer);

	//void update();

	//void clean();
};