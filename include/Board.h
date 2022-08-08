#pragma once

#include <map>
#include <fstream>

#include "Presenter.h"
#include "defines.h"

#include "Player.h"
#include "Animation.h"
#include "InGameUI.h"
#include "GameData.h"

class Board
{
public:
	Board();
	~Board();

	void load();

	void update();

	void draw();

	void destroy();

private:
	SDL_Texture* m_background;
	
	Player m_p1;
	Player m_p2;

	DrawableSrc m_board;

	SDL_Texture* m_boardDefault;
	SDL_Texture* m_boardBroken;

	animationData m_defaultAnim;
	animationData m_brokenAnim;

	Animation m_boardAnim;

	GameData m_gameData;
	
	void win(int player);
	void checkForWinner();
	void reload();
};