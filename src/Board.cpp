#include "Board.h"
#include "World.h"
#include "InputManager.h"
#include "World.h"

extern World world;

Board::Board()
{
}

Board::~Board()
{
}


void Board::load()
{
	m_p1.init("player1.txt");
	m_p2.init("player2.txt");

	m_background = loadTexture(GAME_FOLDER + "background.bmp");
	m_board.rect = { 316, 209, 1288, 856 };

	m_boardDefault = loadTexture(GAME_FOLDER + "board.bmp");
	m_boardBroken = loadTexture(GAME_FOLDER + "boardBroken.bmp");
	m_board.texture = m_boardDefault;
	
	m_deathScreen.init();

	m_brokenAnim.frames = 23;
	m_brokenAnim.frameSize.x = 640;
	m_brokenAnim.frameSize.y = 428;
	m_brokenAnim.timePerFrame = 40;

	m_defaultAnim.frames = 5;
	m_defaultAnim.frameSize.x = 1308;
	m_defaultAnim.frameSize.y = 871;
	m_defaultAnim.timePerFrame = 70;

	m_boardAnim.init(&m_board);

	m_boardAnim.setAnimation(&m_defaultAnim);

	m_gameData.m_active = true;
}

void Board::update()
{
	if (m_gameData.active())
	{
		m_p1.update();
		m_p2.update();

		checkForWinner();
	}
	else
	{
		if (InputManager::m_keyboardState[SDL_SCANCODE_SPACE])
		{
			reload();
		}
	}

	m_boardAnim.update();

	m_deathScreen.update();
}

void Board::draw()
{
	drawObject(m_background);

	drawObject(m_board);

	for (auto& trail : Trail::m_all)
	{
		drawObject(*trail);
	}

	drawObject(m_p1);
	drawObject(m_p2);

	m_deathScreen.draw();
}

void Board::destroy()
{
	
}

void Board::win(int player)
{
	m_gameData.m_active = false;
	m_board.texture = m_boardBroken;
	m_boardAnim.setAnimation(&m_brokenAnim);
}

void Board::checkForWinner()
{
	for (auto& trail : Trail::m_all)
	{
		if (trail->coll(m_p1.getHitbox()))
		{
			win(2);
		}
		if (trail->coll(m_p2.getHitbox()))
		{
			win(1);
		}
	}

	if (isOffOfRect(m_p1.getHitbox(), m_board.rect))
	{
		win(2);
	}
	if (isOffOfRect(m_p2.getHitbox(), m_board.rect))
	{
		win(1);
	}
}

void Board::reload()
{
	Trail::m_all.clear();
	load();
	m_gameData.startMatch();
}
