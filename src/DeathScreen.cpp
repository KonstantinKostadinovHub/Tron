#include "DeathScreen.h"

#include "GameData.h"
#include "Presenter.h"

DeathScreen::DeathScreen()
{
}

DeathScreen::~DeathScreen()
{
}


void DeathScreen::init()
{
	fstream stream;

	string tmp;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + WIN_SCREEN_FOLDER + "winscreen.txt");


	m_1wins = loadTexture(GAME_FOLDER + WIN_SCREEN_FOLDER + "player1.bmp");
	m_2wins = loadTexture(GAME_FOLDER + WIN_SCREEN_FOLDER + "player2.bmp");
	m_1winsAnim = loadTexture(GAME_FOLDER + WIN_SCREEN_FOLDER + "player1Anim.bmp");
	m_2winsAnim = loadTexture(GAME_FOLDER + WIN_SCREEN_FOLDER + "player2Anim.bmp");

	stream >> tmp >> m_winner.rect.x >> m_winner.rect.y >> m_winner.rect.w >> m_winner.rect.h; 

	stream >> tmp >> m_animData.frames;
	stream >> tmp >> m_animData.frameSize.x >> m_animData.frameSize.y;
	stream >> tmp >> m_animData.timePerFrame;

	stream.close();	

	m_anim.init(&m_winner);
	m_anim.setAnimation(&m_animData);

	m_finished.rect = m_winner.rect;
}

void DeathScreen::destroy()
{
	SDL_DestroyTexture(m_1wins);
	SDL_DestroyTexture(m_2wins);
}

void DeathScreen::start(int winner)
{
	m_winner.texture = winner == 1 ? m_1winsAnim : m_2winsAnim;
	m_finished.texture = winner == 1 ? m_1wins : m_2wins;
}

void DeathScreen::update()
{	
	if (!GameData::active())
	{
		m_anim.update();
	}
}

void DeathScreen::draw()
{
	if (!GameData::active())
	{
		if (m_anim.hasPlayed() == false)
		{
			drawObject(m_winner);
		}
		else
		{
			drawObject(m_finished);
		}
	}
}
