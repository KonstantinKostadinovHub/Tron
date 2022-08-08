#include "Player.h"

#include "InputManager.h"
#include "Presenter.h"
#include "Trail.h" 

#include <fstream>

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(string file)
{
	fstream stream;
	
	string tmp;
	int ctrls;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + PLAYER_FOLDER + file);

	stream >> tmp >> rect.x >> rect.y >> rect.w >> rect.h;

	stream >> tmp >> tmp;

	texture = loadTexture(GAME_FOLDER + PLAYER_FOLDER + tmp);

	stream >> tmp >> m_speed;

	stream >> tmp >> m_velocity.x;

	stream >> tmp >> ctrls;
	m_up = SDL_Scancode(ctrls);
	stream >> tmp >> ctrls;
	m_left = SDL_Scancode(ctrls);
	stream >> tmp >> ctrls;
	m_down = SDL_Scancode(ctrls);
	stream >> tmp >> ctrls;
	m_right = SDL_Scancode(ctrls);

	stream >> tmp >> m_hitbox.w;
	m_hitbox.h = m_hitbox.w;

	stream >> tmp >> m_hitboxDistance;

	if (m_velocity.x == 1)
	{
		m_id = 1;
	}
	else
	{
		m_id = 2;
	}

	m_velocity.y = 0;

	stream.close();
}

void Player::update()
{
	move();
}

SDL_Rect Player::getHitbox()
{
	m_hitbox.x = rect.x + m_hitboxDistance * m_velocity.x - m_hitbox.w / 2;
	m_hitbox.y = rect.y + m_hitboxDistance * m_velocity.y - m_hitbox.h / 2;
	return m_hitbox;
}

void Player::move()
{
	float2 startVel = m_velocity;

	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;


	if (InputManager::m_keyboardState[m_up] && (startVel.y != 1.0f))
	{
		m_velocity.y = -1.0f;
	}
	else if (InputManager::m_keyboardState[m_down] && (startVel.y != -1.0f))
	{
		m_velocity.y = 1.0f;
	}
	else
	{
		m_velocity.y = 0.0f;
	}
	if (InputManager::m_keyboardState[m_left] && (startVel.x != 1.0f))
	{
		m_velocity.x = -1.0f;
	}
	else if (InputManager::m_keyboardState[m_right] && (startVel.x != -1.0f))
	{
		m_velocity.x = 1.0f;
	}
	else
	{
		m_velocity.x = 0.0f;
	}

	// if nothing is pressed go with the prev pos
	if (m_velocity == 0)
	{
		m_velocity = startVel;
	}

	Trail::create(rect.x - m_velocity.x, rect.y - m_velocity.y, rect.x, rect.y , m_id);
	rect.x += m_velocity.x * m_speed;
	rect.y += m_velocity.y * m_speed;

	// change for the draw
	chooseAngle();
}

void Player::trail()
{
	
}

void Player::chooseAngle()
{
	if (m_velocity.x == 1.0f)
	{
		if (m_velocity.y == 1.0f)
		{
			angle = 135;
		}
		else if (m_velocity.y == -1.0f)
		{
			angle = 45;
		}
		else
		{
			angle = 90;
		}
	}
	else if (m_velocity.x == -1.0f)
	{
		if (m_velocity.y == 1.0f)
		{
			angle = -135;
		}
		else if (m_velocity.y == -1.0f)
		{
			angle = -45;
		}
		else
		{
			angle = -90;
		}
	}
	else
	{
		if (m_velocity.y == 1.0f)
		{
			angle = 180;
		}
		else if (m_velocity.y == -1.0f)
		{
			angle = 0;
		}
		else
		{
			D("ERROR: NO DIRECTION");
		}
	}
}
