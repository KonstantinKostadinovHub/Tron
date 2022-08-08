#pragma once

#include "defines.h"

class GameData
{
public:
	GameData();
	~GameData();

	static bool active();
	static int2 score();
	static string p1Username();
	static string p2Username();

protected:
	friend class Board;
	void startMatch();

	static bool m_active;
	static int2 m_score;
	static string m_pl1Username;
	static string m_pl2Username;
};