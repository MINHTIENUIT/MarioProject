#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "dxgraphics.h"
#include <thread>
#include <iostream>
#include <Windowsx.h>

//application title
#define APPTITLE L"Trans_Sprite"

//screen setup
#define FULLSCREEN 0       //0 = windowed, 1 = fullscreen
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//macros to read the keyboard asynchronously
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//function prototypes
int Game_Init(HWND);
void Game_Run(HWND);
void Game_End(HWND);

void Sprite_Mario();
void bird_animation();

//sprite structure
struct SPRITE{
	int x, y;
	int width, height;
	int movex, movey;
	int curframe, lastframe;
	int animdelay, animcount;
	int scalex, scaley;
	int rotation, rotaterate;
}typedef SPRITE;