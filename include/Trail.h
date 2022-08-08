#pragma once

#include "defines.h"

class Trail : public Rotatable
{
public:
	Trail();
	~Trail();

	line m_body;
	static vector<Trail*> m_all;

	static void create(float sx, float sy, float ex, float ey, int creator);

	bool coll(SDL_Rect obj);
private:

	void rotate();
};