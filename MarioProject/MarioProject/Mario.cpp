#include "stdafx.h"
#include "Mario.h"
#include "game.h"


void Mario::animation(long &start)
{
	if (KEY_DOWN(VK_RIGHT)) {
		if (GetTickCount() - start > 30)
		{
			//reset timing
			start = GetTickCount();			
			//move the sprite;
			x += movex;
			y += movey;

			//wrap the spriate at screen edges
			if (x > SCREEN_WIDTH - width)
				x = 0;
			if (x < 0) {
				x = SCREEN_WIDTH - width;
			}

			//has animation delay reached threshold
			if (++animcount > animdelay) {
				//reset counter
				animcount = 0;

				if (++curframe > 6)
					curframe = 1;
			}
		}
	}else if (KEY_DOWN(VK_LEFT)) {
		if (GetTickCount() - start > 30)
		{
			if (curframe < 7) curframe = 13;
			//reset timing
			start = GetTickCount();

			//move the sprite;
			x -= movex;
			y -= movey;

			//wrap the spriate at screen edges
			if (x > SCREEN_WIDTH - width)
				x = 0;
			if (x < 0) {
				x = SCREEN_WIDTH - width;
			}

			//has animation delay reached threshold
			if (++animcount > animdelay) {
				//reset counter
				animcount = 0;

				if (--curframe < 7)
					curframe = 13;
			}
		}
	}
	else {
		curframe = 14;
	}
}

int Mario::getX()
{
	return x;
}

int Mario::getY()
{
	return y;
}

int Mario::getWidth()
{
	return width;
}

int Mario::getheight()
{
	return height;
}

Mario::~Mario()
{
}
