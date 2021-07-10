#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()), m_velocity(0,0)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;

}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(),
		(int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}

void SDLGameObject::preupdate()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_position += m_velocity;
}

void SDLGameObject::update()
{
	preupdate();
	m_velocity.setX(1);
}


void SDLGameObject::clean()
{
	std::cout << "clean game object";
}

void SDLGameObject::upload(std::string fileName, std::string id,
	SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->load(fileName, id, pRenderer);
}