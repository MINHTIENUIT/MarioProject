#pragma once
#ifndef _DXGRAPHICS_H
#define _DXGRAPHICS_H
#include <d3dx9.h>
#include <d3d9.h>

#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")
//function prototypes
int Init_Direct3D(HWND, int, int, int);
LPDIRECT3DSURFACE9 LoadSurface(LPCWCHAR, D3DCOLOR);
LPDIRECT3DTEXTURE9 LoadTexture(LPCWCHAR, D3DCOLOR);

//variable declarations
extern LPDIRECT3D9 d3d;
extern LPDIRECT3DDEVICE9 d3ddev;
extern LPDIRECT3DSURFACE9 backbuffer;

#endif