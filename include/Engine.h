#pragma once

#include <cmath>
#include <string>
#include <float.h>
#include <utility>

#include <SDL.h>
#include <SDL_TTF.h>

#include "defines.h"

SDL_Texture* LoadTexture(string configFile, SDL_Renderer* renderer);
bool MouseIsInRect(int2 coor, SDL_Rect rect);
float returnAngleByCoordinates(int2 direction);
float distance(float2 a, float2 b);
bool collRectRect(SDL_Rect a, SDL_Rect b);
bool isOffOfRect(SDL_Rect obj, SDL_Rect frame);
