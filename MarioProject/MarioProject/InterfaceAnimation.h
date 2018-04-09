#pragma once
#include "Component.h"
class Component;
class InterfaceAnimation
{
protected:
	int startframe;
	int lastframe;
	int mx, my;
	int delay;
	int animcount;	
	int resetframe;
public:
	InterfaceAnimation(int startframe, int lastframe, int mx, int my, int delay, int animcount,int resetframe);
	virtual void start(Component *sprite, long &start) = 0;
	~InterfaceAnimation();
};