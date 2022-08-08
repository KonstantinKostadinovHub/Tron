#pragma once

#include "defines.h"

class Player : public Rotatable
{
public:
	Player();
	~Player();
	
	float m_speed;
	float2 m_velocity;

	SDL_Scancode m_up;
	SDL_Scancode m_down;
	SDL_Scancode m_left;
	SDL_Scancode m_right;

	int m_id;

	void init(string file);
	void update();
	
	SDL_Rect getHitbox();
private:

	SDL_Rect m_hitbox;

	int m_hitboxDistance; //< measured from the centre

	void move();
	void trail();

	void chooseAngle();
};