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
	m_velocity.setY(1);
	m_velocity.setX(1);
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	////m_position.NULLifier(*vec);
	//m_velocity = (*vec - m_position) / 100;

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

	if (TheInputHandler::Instance()->getButtonState(0, 3))
	{
	m_velocity.setX(3);

	}

	if (TheInputHandler::Instance()->getMouseButtonStates(LEFT))
	{
		m_velocity.setX(-3);
	}


}

