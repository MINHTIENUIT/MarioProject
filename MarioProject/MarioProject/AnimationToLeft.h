#pragma once
#include "InterfaceAnimation.h"
class AnimationToLeft :
	public InterfaceAnimation
{
public:
	AnimationToLeft(int startframe, int lastframe, int mx, int my, int delay, int animcount, int resetframe) :
		InterfaceAnimation(startframe, lastframe, mx, my, delay, animcount, resetframe) {};

	void start(Component *sprite, long &start);
	~AnimationToLeft();
};

