#include "stdafx.h"
#include "Component.h"

Component::Component(int x, int y, int width, int height, int cuframe, int lastframe)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->curframe = cuframe;
	this->lastframe = lastframe;
}

RECT Component::getRect(int columns)
{
	RECT srcRect;
	srcRect.left = (curframe%columns)*width;
	srcRect.top = (curframe / columns)*height;
	srcRect.right = srcRect.left + width;
	srcRect.bottom = srcRect.top + height;
	return srcRect;
}

Component::~Component()
{
}