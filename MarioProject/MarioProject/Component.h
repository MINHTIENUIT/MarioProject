#pragma once
#include "dxgraphics.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "InterfaceAnimation.h"
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")
class InterfaceAnimation;
class Component
{
protected:
	int x, y;
	int width, height;
	int curframe;
public:
	Component(int x, int y, int width, int height, int cuframe);
	RECT getRect(int columns);

	D3DXVECTOR3 getPosition();
	void setPosistion(int x, int y);

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int setCurframe(int curframe);

	void animation(long &start,InterfaceAnimation *animation);
	~Component();
};

