#include "ConfigManager.h"

#include "Presenter.h"

SDL_Texture* ConfigManager::m_player1Trail = nullptr;
SDL_Texture* ConfigManager::m_player2Trail = nullptr;

ConfigManager::ConfigManager()
{

}

ConfigManager::~ConfigManager()
{

}

void ConfigManager::load()
{
	m_player1Trail = loadTexture(GAME_FOLDER + "trail1.bmp");
	m_player2Trail = loadTexture(GAME_FOLDER + "trail2.bmp");
}