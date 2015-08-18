#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Global.h"
#include"Camera.h"

enum SpriteEffects{
	NONE = 0, // Không chỉ định xoay
	FLIP_HORIZONTALLY = 1, // Xoay 1 góc 180 quanh trục Y
	FLIP_VERTICALLY = 2  // Xoay 1 góc 180 quanh trục X
};

class CGraphics
{
protected:
	LPDIRECT3D9 pd3d;
	LPDIRECT3DDEVICE9 pd3ddv;
	static CGraphics* instance;

	LPD3DXSPRITE spriteHandler;
	LPDIRECT3DSURFACE9 backbuffer;
	LPDIRECT3DSURFACE9 surface;

	CCamera* camera;
public:
	CGraphics();
	static CGraphics* GetInstance();
	//cai dat cua so
	bool InitDirectX(HWND hwnd);

	LPDIRECT3D9 GetDirectX9();
	LPDIRECT3DDEVICE9 GetDevice();
	LPDIRECT3DSURFACE9 GetBackbuffer();
	LPDIRECT3DSURFACE9 GetSurface();

	LPD3DXSPRITE GetSpriteHandle();

	int BeginDraw(CCamera* camera);
	void EndDraw();

	//-----------------------------------------------------------------------------
	// Vẽ một sprite lên màn hình

	// + texture: đối tượng texture cần vẽ
	// + destinationRectangle: khung frame cần vẽ
	// + position: tọa độ cần vẽ(lưu ý transform tọa độ trước)
	// + isDrawAtCenter: có vẽ tại tâm không 
	// + scale: scale đối tượng 
	// + effects: lật đối tượng
	// + colorNotDraw: màu chỉ định không vẽ lên màn hình
	//-----------------------------------------------------------------------------
	void Draw(LPDIRECT3DTEXTURE9 texture, RECT destinationRectangle, D3DXVECTOR2 position, bool isDrawAtCenter, D3DXVECTOR2 scale = D3DXVECTOR2(1, 1), SpriteEffects effects = SpriteEffects::NONE);
	/*void Draw(LPDIRECT3DTEXTURE9 texture, RECT destinationRectangle, D3DXVECTOR2 position, bool isDrawAtCenter, SpriteEffects effect);
	void Draw(LPDIRECT3DTEXTURE9 texture, RECT destinationRectangle, D3DXVECTOR2 position, D3DXVECTOR2 scale);*/

	void Draw(LPDIRECT3DTEXTURE9 texture, RECT desRect, D3DXVECTOR2 pos);

	~CGraphics();
};

