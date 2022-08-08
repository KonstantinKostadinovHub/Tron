#pragma once

#include "defines.h"

#include "Animation.h"
#include "Button.h"

class DeathScreen {
public:

	DeathScreen();
	~DeathScreen();

	void init();
	void destroy();

	void start(int winner);

	void update();
	void draw();

private:

	bool* m_active;

	DrawableSrc m_winner;
	Drawable m_finished;	/// played after the m_winner has played

	animationData m_animData;

	Animation m_anim;

	SDL_Texture* m_1wins;
	SDL_Texture* m_1winsAnim;
	SDL_Texture* m_2wins;
	SDL_Texture* m_2winsAnim;
};