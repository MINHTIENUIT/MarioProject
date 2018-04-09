#include "stdafx.h"
#include "Component.h"

Component::Component(int x, int y, int width, int height, int cuframe)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->curframe = cuframe;
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

D3DXVECTOR3 Component::getPosition()
{
	return D3DXVECTOR3(x, y, 0);
}

void Component::setPosistion(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Component::getX()
{
	return x;
}

int Component::getY()
{
	return y;
}

int Component::getWidth()
{
	return width;
}

int Component::getHeight()
{
	return height;
}

int Component::setCurframe(int curframe)
{
	return this->curframe = curframe;
}

void Component::animation(long & start, InterfaceAnimation * animation)
{
	animation->start(this,start);
}

Component::~Component()
{
}