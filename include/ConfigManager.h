#pragma once

#include "defines.h"

#include <fstream>

#include "Trail.h"

class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();

	static SDL_Texture* m_player1Trail;
	static SDL_Texture* m_player2Trail;

	void load();
};
