#include "stdafx.h"
#include "AnimationToRight.h"
#include "game.h"

void AnimationToRight::start(Component * sprite, long & start)
{
	if (GetTickCount() - start > 30)
	{
		start = GetTickCount();
		//move the sprite;

		sprite->setPosistion(sprite->getX() + mx,sprite->getY() + my);

		if (sprite->getX() > SCREEN_WIDTH) sprite->setPosistion(0,sprite->getY() + my);
		if (sprite->getX() < 0) sprite->setPosistion(SCREEN_WIDTH-sprite->getWidth(), sprite->getY() + my);

		//has animation delay reached threshold
		if (++animcount > delay) {
			//reset counter
			animcount = 0;

			if (++startframe > lastframe)
				startframe = resetframe;
		}
		sprite->setCurframe(startframe);
	}
}

AnimationToRight::~AnimationToRight()
{
}