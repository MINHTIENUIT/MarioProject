#pragma once
#include "dxgraphics.h"
class Component
{
protected:
	int x, y;
	int width, height;
	int curframe, lastframe;
public:
	Component(int x, int y, int width, int height, int cuframe, int lastframe);
	RECT getRect(int columns);
	~Component();
};

