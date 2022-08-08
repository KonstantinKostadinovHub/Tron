#pragma once

#include "defines.h"

#include "DeathScreen.h"

class InGameUI
{
public:
	InGameUI();
	~InGameUI();

	void init();
	void destroy();

	void update();
	void draw();
	

 private:
	 DeathScreen m_deathScreen;
};