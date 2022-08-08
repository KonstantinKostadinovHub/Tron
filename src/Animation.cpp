#include "Animation.h"

Animation::Animation()
{
	m_hasPlayed = false;
	m_obj = nullptr;
}

Animation::~Animation()
{
	m_obj = nullptr;
}

void Animation::init(DrawableSrc* obj)
{
	m_obj = obj;
	
	m_hasPlayed = false;
	m_lastFrameUpdate = SDL_GetTicks();
	m_currFrame = 0;
}

/*
* @param _aData - pass the animation data for the animation that you want to play
*/
void Animation::setAnimation(animationData* _aData)
{
	m_aData = _aData;
	
	m_obj->srcRect = 
		{ 0, 0, m_aData->frameSize.x, m_aData->frameSize.y };

	m_lastFrameUpdate = 0;
	m_currFrame = 0;
	m_hasPlayed = false;
}

void Animation::update()
{
	// Check if the frame is ready to be switched
	if (SDL_GetTicks() - m_lastFrameUpdate > m_aData->timePerFrame)
	{
		m_currFrame++;

		// Check if we have reached the end of the animation
		if (m_currFrame >= m_aData->frames)
		{
			m_currFrame = 0;

			m_hasPlayed = true;
		}
		
		m_obj->srcRect.x = m_aData->frameSize.x * m_currFrame;
		
		m_lastFrameUpdate = SDL_GetTicks();
	}
}

bool Animation::hasPlayed()
{
	return m_hasPlayed;
}


