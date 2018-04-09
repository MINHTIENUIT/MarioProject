#pragma once
#include "InterfaceAnimation.h"
class AnimationToRight :
	public InterfaceAnimation
{
public:
	AnimationToRight(int startframe, int lastframe, int mx, int my, int delay, int animcount,int resetframe) :
		InterfaceAnimation(startframe, lastframe, mx, my, delay, animcount,resetframe) {};
	
	void start(Component *sprite,long &start);
	
	~AnimationToRight();
};

