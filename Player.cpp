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

	m_velocity.setX(-1);

}

void Player::clean()
{
	SDLGameObject::clean();
}

