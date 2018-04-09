#include "stdafx.h"
#include "game.h"
#include <process.h>
#include <thread>
#include "Component.h"
#include "AnimationToRight.h"
#include "AnimationToLeft.h"
#include "Component.h"
LPDIRECT3DTEXTURE9 mario_image;
LPDIRECT3DTEXTURE9 bird_image;

Component *mario;
Component *bird;
LPDIRECT3DSURFACE9 back;
LPD3DXSPRITE sprite_handler;

HRESULT result;
//timming variable
long start = GetTickCount();
long start2 = GetTickCount();

InterfaceAnimation *ToRight_Mario;
InterfaceAnimation *ToLeft_Mario;
InterfaceAnimation *Stand_Mario;
InterfaceAnimation *ToLeft_Bird;

int Game_Init(HWND hwnd)
{
	srand((unsigned int)time(NULL));

	//create sprite handler object
	result = D3DXCreateSprite(d3ddev, &sprite_handler);
	if (result != D3D_OK) return 0;

	//load texture with the transparent color
	mario_image = LoadTexture(L"mario_run.bmp", D3DCOLOR_XRGB(255, 255, 255));
	if (mario_image == NULL) return 0;

	bird_image = LoadTexture(L"bird.bmp", D3DCOLOR_XRGB(255, 255, 255));
	if (bird_image == NULL) return 0;

	//load the background image
	back = LoadSurface(L"background.bmp", NULL);

	//initialize the sprite's properties of main
	mario = new Component(100, 168, 75, 91, 1);
	ToRight_Mario = new AnimationToRight(1,6,5,0,3,0,0);
	ToLeft_Mario = new AnimationToLeft(14, 8, 5, 0, 3, 0,13);
	Stand_Mario = new AnimationToRight(15, 14, 0, 0, 0, 0, 14);

	//initialize the sprite's properties of bird
	bird = new Component(SCREEN_WIDTH, 168, 100, 115, 1);
	ToLeft_Bird = new AnimationToLeft(9, 2, 5, 0, 5, 0, 8);
	

	return 1;
}

void Game_Run(HWND hwnd)
{
	//make sure the Direct3D device is valid
	if (d3ddev == NULL) return;

	//after short delay, ready for next frame
	//this keeps the game running at a steady frame rate	
	//Sprite_Mario();	
	if (KEY_DOWN(VK_RIGHT)){
		mario->animation(start,ToRight_Mario);
	}else
	if (KEY_DOWN(VK_LEFT)) {
		mario->animation(start, ToLeft_Mario);
	}
	else {
		mario->animation(start, Stand_Mario);
	}
	
	bird->animation(start2, ToLeft_Bird);
	
	//start rendering
	if (d3ddev->BeginScene())
	{
		//erase the entire background
		d3ddev->StretchRect(back, NULL, backbuffer, NULL, D3DTEXF_NONE);

		//start sprite handler
		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);

		//create vector to update sprite position
		//D3DXVECTOR3 position((float)mario->getX(), (float)mario->getY(), 0);

		//configure the rect for the souuce tile

		RECT rect = mario->getRect(15);
		RECT rect2 = bird->getRect(9);

		//draw the sprite
		sprite_handler->Draw(
			mario_image,
			&rect,
			NULL,
			&mario->getPosition(),
			D3DCOLOR_XRGB(255, 255, 255));

		sprite_handler->Draw(
			bird_image,
			&rect2,
			NULL,
			&bird->getPosition(),
			D3DCOLOR_XRGB(255,255,255));

		//stop drawing
		sprite_handler->End();

		//stop rendering
		d3ddev->EndScene();
	}

	d3ddev->Present(NULL, NULL, NULL, NULL);

	if (KEY_DOWN(VK_ESCAPE))
		PostMessage(hwnd, WM_DESTROY, 0, 0);
}

//frees memory and cleans up befor the game ends
void Game_End(HWND hwnd)
{
	if (mario_image != NULL)
		mario_image->Release();

	if (back != NULL)
		back->Release();

	if (sprite_handler != NULL)
		sprite_handler->Release();
}