#include "SDLGameObject.h"
#include "Game.h"
SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;

}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height,
		m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_x += 1;
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