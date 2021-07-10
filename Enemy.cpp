#include"Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw(); //we can now use SDLGaame Object
}

void Enemy::update()
{
	preupdate();

	m_velocity.setX(1);
	m_velocity.setY(1);

}

void Enemy::clean()
{

}

