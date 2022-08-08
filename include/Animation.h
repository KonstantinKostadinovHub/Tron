#pragma once

#include "defines.h"

struct animationData
{
	int frames; /// the number of frames in the animation
	int2 frameSize; /// the width and height of each frame
	int timePerFrame;
};

class Animation
{
public:
	Animation();
	virtual ~Animation();

	animationData* m_aData; /// Pointer to the current animation
	
	DrawableSrc* m_obj;

	void init(DrawableSrc* obj); /// Always give the srcRect and Texure that you want to animate
	void setAnimation(animationData* _aData);
	
	void update(); /// Switches frames
	
	bool hasPlayed(); /// Has the animation played once

	int m_currFrame; /// Current frame of the animation
private:
	Uint32 m_lastFrameUpdate; /// Timestamp when we saved changed the last frame
	bool m_hasPlayed; /// Has the animation played once. Used for VFX
};