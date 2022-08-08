#include "Trail.h"

#include "ConfigManager.h"
#include "Engine.h"

vector<Trail*> Trail::m_all = vector<Trail*>();

Trail::Trail()
{
}

Trail::~Trail()
{
}

void Trail::create(float sx, float sy, float ex, float ey, int creator)
{
    Trail* _trail = new Trail();

    _trail->m_body.s.x = sx;
    _trail->m_body.s.y = sy;
    _trail->m_body.e.x = ex;
    _trail->m_body.e.y = ey;

    _trail->texture = (creator == 1) ? ConfigManager::m_player1Trail : ConfigManager::m_player2Trail;
    
    m_all.push_back(_trail);

    _trail->rotate();
    _trail->rect.x = _trail->m_body.s.x;
    _trail->rect.y = _trail->m_body.s.y;
}

bool Trail::coll(SDL_Rect obj)
{
    SDL_Rect hitbox = { rect.x - rect.w, rect.y - rect.h, rect.w, rect.h };
    return collRectRect(obj, hitbox);
}

void Trail::rotate()
{
    int2 direction;
    direction.x = m_body.e.x - m_body.s.x;
    direction.y = m_body.e.y - m_body.s.y;

    angle = returnAngleByCoordinates(direction);

    rect.h = 20;
    rect.w = 20;
}
