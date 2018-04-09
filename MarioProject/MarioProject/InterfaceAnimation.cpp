#include "stdafx.h"
#include "InterfaceAnimation.h"

InterfaceAnimation::InterfaceAnimation(int startframe, int lastframe, int mx, int my, int delay, int animcount,int resetframe)
{
	this->startframe = startframe;
	this->lastframe = lastframe;
	this->mx = mx;
	this->my = my;
	this->delay = delay;
	this->animcount = animcount;
	this->resetframe = resetframe;
}

InterfaceAnimation::~InterfaceAnimation()
{
}