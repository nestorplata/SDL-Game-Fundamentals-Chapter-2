#pragma once

#include "SDLGameObject.h"
class Player : public SDLGameObject // inherit from GameObject
{
 public:

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	//void load(int x, int y, int width, int height, std::string textureID);

	//void draw(SDL_Renderer* pRenderer);

	//void update();

	//void clean();
};