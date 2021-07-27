#include "player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	SDLGameObject::SDLGameObject(pParams);
}

void Player::draw()
{
	SDLGameObject::draw(); //we can now use SDLGaame Object
}


void Player::update()
{
	preupdate();

	Vector2D* nell = TheInputHandler::Instance()->getMousePosition();
	if (nell)
	{
		Vector2D* vec = nell;
		m_velocity = (*vec - m_position)/100;

	}

	handleInput(); // add our function
}

void Player::clean()
{
	SDLGameObject::clean();
}

void Player::handleInput()
{

	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
		}

		if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
		}

		if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
		}

		if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
		}
	}

	//when controller is connected
	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		if (TheInputHandler::Instance()->getButtonState(0, 3))
		{
			m_velocity.setX(3);
		}
		if (TheInputHandler::Instance()->getMouseButtonStates(LEFT))
		{
			m_velocity.setX(-3);
		}
	}

	//x value based on key input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) &&
		TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(0);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	else if(TheInputHandler::Instance()->joysticksInitialised() ==false && TheInputHandler::Instance()->getMousePosition() == NULL)
	{
		m_velocity.setX(0);
	}

	//y value based on key input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) &&
		TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(0);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	else if (TheInputHandler::Instance()->joysticksInitialised() == false && TheInputHandler::Instance()->getMousePosition() == NULL)
	{
		m_velocity.setY(0);
	}


}

