#include "Texture.h"

CTexture::CTexture()
{
	
}

CTexture::CTexture(LPCSTR pathName, D3DCOLOR color)
{
	this->_texture = NULL;
	this->_namePath = pathName;
	LoadTextureFromFile(this->_namePath,color);
}

//CTexture* CTexture::GetInstance()
//{
//	if (instance == NULL)
//	{
//		instance = new CTexture();
//		return instance;
//	}
//	else
//		return instance;
//}

void CTexture::LoadTextureFromFile(LPCSTR path, D3DXCOLOR color)
{
	D3DXIMAGE_INFO _imageInfo;
	HRESULT hr;
	hr = D3DXGetImageInfoFromFile(path, &_imageInfo);
	if (hr != D3D_OK)
	{
		MessageBox(NULL, "can't get image !", "error", MB_OK);
		return;
	}
	this->_width = _imageInfo.Width;
	this->_height = _imageInfo.Height;

	LPDIRECT3DDEVICE9 d3ddv = CGraphics ::GetInstance()->GetDevice();
	hr = D3DXCreateTextureFromFileEx(
		d3ddv,
		path,
		this->_width,
		this->_height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		color,
		&_imageInfo,
		NULL,
		&_texture
		);
	if (hr != D3D_OK)
	{
		MessageBox(NULL, "can't create texture from file (CTexture)!", "error", MB_OK);
		return;
	}
}

LPDIRECT3DTEXTURE9 CTexture::GetTexture()
{
	if (this->_texture != NULL)
	{
		return this->_texture;
	}
	else
		return NULL;
}

float CTexture::GetWidth()
{
	return this->_width;
}

float CTexture::GetHeight()
{
	return this->_height;
}

CTexture::~CTexture()
{
}
