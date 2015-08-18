#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Graphics.h"

class CTexture
{
protected:
	// chiù cao của ảnh
	float _height;
	// chìu rộng của ảnh 
	float _width;
	//texture 
	LPDIRECT3DTEXTURE9 _texture;
	// đường dẫn đến ảnh
	LPCSTR _namePath;
public:
	CTexture();
	CTexture(LPCSTR pathName, D3DCOLOR color);
	void LoadTextureFromFile(LPCSTR path, D3DXCOLOR color);
	LPDIRECT3DTEXTURE9 GetTexture();
	float GetHeight();
	float GetWidth();

	//static CTexture * GetInstance();
	~CTexture();
};

