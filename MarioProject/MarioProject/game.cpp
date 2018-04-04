#include "stdafx.h"
#include "game.h"
#include <process.h>
#include <thread>
#include "Component.h"
LPDIRECT3DTEXTURE9 caveman_image;
LPDIRECT3DTEXTURE9 bird_image;
SPRITE caveman;
SPRITE bird;

Mario *mario;
LPDIRECT3DSURFACE9 back;
LPD3DXSPRITE sprite_handler;

static std::thread *threadAnimation = nullptr;

HRESULT result;
//timming variable
long start = GetTickCount();
long start2 = GetTickCount();

int Game_Init(HWND hwnd)
{
	srand((unsigned int)time(NULL));

	//create sprite handler object
	result = D3DXCreateSprite(d3ddev, &sprite_handler);
	if (result != D3D_OK) return 0;

	//load texture with the transparent color
	caveman_image = LoadTexture(L"mario_run.bmp", D3DCOLOR_XRGB(255, 255, 255));
	if (caveman_image == NULL) return 0;

	bird_image = LoadTexture(L"bird.bmp", D3DCOLOR_XRGB(255, 255, 255));
	if (bird_image == NULL) return 0;

	//load the background image
	back = LoadSurface(L"background.bmp", NULL);

	//initialize the sprite's properties of main
	mario = new Mario(100, 168, 75, 91, 1, 15, 5, 0, 4, 0);

	//initialize the sprite's properties of bird
	bird.x = 340;
	bird.y = 168;
	bird.width = 100;
	bird.height = 115;
	bird.curframe = 1;
	bird.lastframe = 9;
	bird.animdelay = 4;
	bird.animcount = 0;
	bird.movex = 1;
	bird.movey = 0;

	//thread for animation
	threadAnimation = new std::thread(bird_animation);
	return 1;
}

void Game_Run(HWND hwnd)
{
	//make sure the Direct3D device is valid
	if (d3ddev == NULL) return;

	//after short delay, ready for next frame
	//this keeps the game running at a steady frame rate	
	//Sprite_Mario();	
	mario->animation(start);
	bird_animation();
	
	//start rendering
	if (d3ddev->BeginScene())
	{
		//erase the entire background
		d3ddev->StretchRect(back, NULL, backbuffer, NULL, D3DTEXF_NONE);

		//start sprite handler
		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);

		//create vector to update sprite position
		D3DXVECTOR3 position((float)mario->getX(), (float)mario->getY(), 0);

		//configure the rect for the souuce tile

		D3DXVECTOR3 position2((float)bird.x, (float)bird.y, 0);

		RECT srcRect2;
		int columns2 = 9;
		srcRect2.left = (bird.curframe%columns2)*bird.width;
		srcRect2.top = (bird.curframe / columns2)*bird.height;
		srcRect2.right = srcRect2.left + bird.width;
		srcRect2.bottom = srcRect2.top + bird.height;

		RECT rect = mario->getRect(15);

		//draw the sprite
		sprite_handler->Draw(
			caveman_image,
			&rect,
			NULL,
			&position,
			D3DCOLOR_XRGB(255, 255, 255));

		sprite_handler->Draw(
			bird_image,
			&srcRect2,
			NULL,
			&position2,
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
	if (caveman_image != NULL)
		caveman_image->Release();

	if (back != NULL)
		back->Release();

	if (sprite_handler != NULL)
		sprite_handler->Release();
}

void Sprite_Mario() {
	if (KEY_DOWN(VK_RIGHT)) {
		if (GetTickCount() - start > 30)
		{
			//reset timing
			start = GetTickCount();

			//move the sprite;
			caveman.x += caveman.movex;
			caveman.y += caveman.movey;

			//wrap the spriate at screen edges
			if (caveman.x > SCREEN_WIDTH - caveman.width)
				caveman.x = 0;
			if (caveman.x < 0) {
				caveman.x = SCREEN_WIDTH - caveman.width;
			}

			//has animation delay reached threshold
			if (++caveman.animcount > caveman.animdelay) {
				//reset counter
				caveman.animcount = 0;

				if (++caveman.curframe > 6)
					caveman.curframe = 1;
			}
		}
	}
	else if (KEY_DOWN(VK_LEFT)) {
		if (GetTickCount() - start > 30)
		{
			if (caveman.curframe < 7) caveman.curframe = 14;
			//reset timing
			start = GetTickCount();

			//move the sprite;
			caveman.x -= caveman.movex;
			caveman.y -= caveman.movey;

			//wrap the spriate at screen edges
			if (caveman.x > SCREEN_WIDTH - caveman.width)
				caveman.x = 0;
			if (caveman.x < 0) {
				caveman.x = SCREEN_WIDTH - caveman.width;
			}

			//has animation delay reached threshold
			if (++caveman.animcount > caveman.animdelay) {
				//reset counter
				caveman.animcount = 0;

				if (--caveman.curframe < 7)
					caveman.curframe = 13;
			}
		}
	}
	else {
		caveman.curframe = 14;
	}
}

void bird_animation() {
	if (GetTickCount() - start2 > 30)
	{
		//reset timing
		start2 = GetTickCount();

		//move the sprite;
		bird.x -= bird.movex;
		bird.y -= bird.movey;

		//wrap the spriate at screen edges
		if (bird.x > SCREEN_WIDTH - bird.width)
			bird.x = 0;
		if (bird.x+bird.width < 0) {
			bird.x = SCREEN_WIDTH - bird.width;
		}

		//has animation delay reached threshold
		if (++bird.animcount > bird.animdelay) {
			//reset counter
			bird.animcount = 0;

			if (--bird.curframe < 0)
				bird.curframe = 8;
		}
	}
}