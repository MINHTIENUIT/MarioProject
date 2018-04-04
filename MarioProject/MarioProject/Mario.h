#pragma once
#include "SpriteAnimation.h"
class Mario: public SpriteAnimation
{
public:
	Mario(int x, int y,
		int width, int height,
		int curframe, int lastframe,
		int movex, int movey,
		int animedelay, int animcount) :SpriteAnimation(x, y, width, height, curframe, lastframe,movex, movey,animedelay,animcount){};
	void animation(long &start);


	int getX();
	int getY();
	int getWidth();
	int getheight();
	~Mario();
};

