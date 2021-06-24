#include"Enemy.h"

void Enemy::load(int x, int y, int width, int height,
	std::string fileName, std::string textureID, SDL_Renderer* pRenderer)
{
	GameObject::load(x, y, width, height, fileName, textureID, pRenderer);
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_y += 1;
	m_x += 1;

}

void Enemy::clean()
{
	GameObject::clean();
}