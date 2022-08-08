#pragma once

#include <fstream>

#include "State.h"
#include "ConfigManager.h"

#include "Board.h"

class Game : public State
{
public:

	Game();
	~Game();
		
	Board m_board;

	void init();
	void destroy();
	void run();
};