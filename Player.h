#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
class Player : public SDLGameObject // inherit from GameObject
{
 public:

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

	void handleInput();

};