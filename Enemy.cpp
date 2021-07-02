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
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{

}

//void Enemy::load(int x, int y, int width, int height, std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//}
//
//void Enemy::draw(SDL_Renderer* pRenderer)
//{
//	GameObject::draw(pRenderer);
//}
//
//void Enemy::update()
//{
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
//	m_y += 1;
//	m_x += 1;
//
//}
//
//void Enemy::clean()
//{
//	GameObject::clean();
//}