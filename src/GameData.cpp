#include "GameData.h"

bool GameData::m_active = false;
int2 GameData::m_score = int2();
string GameData::m_pl1Username = "";
string GameData::m_pl2Username = "";

GameData::GameData()
{
}

GameData::~GameData()
{
}

bool GameData::active()
{
	return m_active;
}

int2 GameData::score()
{
	return m_score;
}

string GameData::p1Username()
{
	return m_pl1Username;
}

string GameData::p2Username()
{
	return m_pl2Username;
}

void GameData::startMatch()
{
	m_score = { 0, 0 };
	m_active = true;
}