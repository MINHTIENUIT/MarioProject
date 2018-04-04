#pragma once
#include "Component.h"
class SpriteAnimation : public Component
{
protected:		
	int movex, movey;	
	int animdelay, animcount;
public:
	SpriteAnimation(int x, int y,
		int width, int height,
		int curframe, int lastframe,
		int movex, int movey,
		int animedelay, int animcount) :Component(x, y, width, height, curframe, lastframe) {
		this->movex = movex;
		this->movey = movey;
		this->animdelay = animedelay;
		this->animcount = animcount;
	};

	virtual void animation(long &startTime) = 0;

	~SpriteAnimation();
};

