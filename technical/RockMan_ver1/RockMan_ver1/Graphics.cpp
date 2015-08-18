#include "Graphics.h"

CGraphics* CGraphics::instance = NULL;

CGraphics::CGraphics()
{
	this->pd3d = NULL;
	this->pd3ddv = NULL;
	this->spriteHandler = NULL;
	this->surface = NULL;
	this->backbuffer = NULL;
}

CGraphics* CGraphics::GetInstance()
{
	if (instance == NULL)
	{
		instance = new CGraphics();
		return instance;
	}
	return instance;
}

bool CGraphics::InitDirectX(HWND hwnd)
{
	// Khoi tao device
	this->pd3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (this->pd3d == NULL)
	{
		MessageBox(NULL, "Error initializing Direct3D", "Error", MB_OK);
		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = (!FULL_SCREEN);
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	//create Direct3D device
	this->pd3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&this->pd3ddv);

	if (this->pd3ddv == NULL)
	{
		MessageBox(hwnd, "Error creating Direct3D device", "Error", MB_OK);
		return false;
	}

	HRESULT result;
	// Khởi tạo SpriteHandler
	result = D3DXCreateSprite(pd3ddv, &spriteHandler);
	if (result != D3D_OK){
		MessageBox(hwnd, "Failed to create Sprite Handler", "Error", MB_OK);
		return false;
	}

	// Khởi tạo font handler
	/*result = D3DXCreateFont(this->pd3ddv, FONT_SIZE, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Megaman 2", &spriteFontHandler);
	if (result != D3D_OK){
		return false;
	}*/

	// tao backbuffer
	this->pd3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &this->backbuffer);
	// tao offscreen
	result = this->pd3ddv->CreateOffscreenPlainSurface(
		515,					//width of the surface
		450,					//height of the surface
		D3DFMT_X8R8G8B8,    //surface format
		D3DPOOL_DEFAULT,    //memory pool to use
		&this->surface,           //pointer to the surface
		NULL);
	if (result != D3D_OK){
		MessageBox(hwnd, "Failed to create offscreen", "Error", MB_OK);
		return false;
	}

	return true;
}

int CGraphics::BeginDraw(CCamera* camera)
{
	if (camera == NULL)
	{
		MessageBox(NULL, "Create Camera front begin Draw!", "Error", MB_OK);
		return 0;
	}
	if (this->pd3ddv->BeginScene())
	{
		return 0;
	}
	this->pd3ddv->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	this->spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	this->camera = camera;

	return 1;
}

void CGraphics::EndDraw()
{
	this->spriteHandler->End();
	this->pd3ddv->EndScene();
	this - pd3ddv->Present(NULL, NULL, NULL, NULL);
	this->camera = NULL;
}

LPDIRECT3D9 CGraphics::GetDirectX9()
{
	return this->pd3d;
}
LPDIRECT3DDEVICE9 CGraphics::GetDevice()
{
	return this->pd3ddv;
}

LPDIRECT3DSURFACE9 CGraphics::GetBackbuffer()
{
	if (backbuffer != NULL)
	{
		return this->backbuffer;
	}
	else
		return NULL;
}

LPDIRECT3DSURFACE9 CGraphics::GetSurface()
{
	if (surface != NULL)
	{
		return surface;
	}
	else
		return NULL;
}

LPD3DXSPRITE CGraphics::GetSpriteHandle()
{
	if (spriteHandler)
	{
		return this->spriteHandler;
	}
}

void CGraphics::Draw(LPDIRECT3DTEXTURE9 texture, RECT destinationRectangle,
	D3DXVECTOR2 position, bool isDrawAtCenter, D3DXVECTOR2 scale , 
	SpriteEffects effects)
{
	D3DXVECTOR3 center;
	if (isDrawAtCenter)
	{
		// tâm la tâm hcn
		center.x = (destinationRectangle.left + destinationRectangle.right) / 2;
		center.y = (destinationRectangle.top + destinationRectangle.bottom) / 2;
		center.z = 0;
	}
	else
	{
		//tâm taị top - left
		center.x = destinationRectangle.left;
		center.y = destinationRectangle.top;
		center.z = 0;
	}

	D3DXVECTOR3 newPosition;
	// tranform toa do sang toa do viewport

	if (camera != NULL)
	{
		//MessageBox(NULL, "Create Camera front begin Draw!", "Error", MB_OK);
		newPosition = camera->Tranform(position.x, position.y);
	}
	
	newPosition = D3DXVECTOR3(position.x, position.y, 0);
	// scale doi tuong
	D3DXVECTOR3 positionDraw;
	positionDraw.x = newPosition.x / scale.x;
	positionDraw.y = newPosition.y / scale.y;
	positionDraw.z = 0;

	//hai ma trận lưu trữ hệ thống tọa độ cũ, mới 
	D3DXMATRIX oldMatrix;
	D3DXMATRIX newMatrix;

	this->spriteHandler->GetTransform(&oldMatrix);

	//đặt ma trận scale 
	D3DXMatrixIdentity(&newMatrix);
	newMatrix._11 = scale.x;
	newMatrix._22 = scale.y;

	switch (effects)
	{
	case SpriteEffects::FLIP_HORIZONTALLY:
		newMatrix._11 *= -1;
		positionDraw.x *= -1;
		break;
	case SpriteEffects::FLIP_VERTICALLY:
		newMatrix._22 *= -1;
		positionDraw.y *= -1;
		break;
	default:
		break;
	}

	spriteHandler->SetTransform(&newMatrix);

	spriteHandler->Draw(texture, &destinationRectangle, &center, &positionDraw, D3DCOLOR_XRGB(255, 255, 255));

	spriteHandler->SetTransform(&oldMatrix);
}

void CGraphics::Draw(LPDIRECT3DTEXTURE9 texture, RECT desRect, D3DXVECTOR2 pos)
{
	D3DXVECTOR3 posTranform;
	if (camera != NULL)
	{
		posTranform = camera->Tranform(pos.x, pos.y);
	}
	/*D3DXVECTOR3 newPos;
	newPos.x = pos.x;
	newPos.y = pos.y;
	newPos.z = 0;*/
	spriteHandler->Draw(texture, &desRect, NULL, &posTranform, D3DCOLOR_XRGB(255, 255, 255));
}

CGraphics::~CGraphics()
{
	/*if (pd3d != NULL)
	{
		delete pd3d;
	}
	if (pd3ddv != NULL)
	{
		delete pd3ddv;
	}*/
	/*if (backbuffer != NULL)
	{
		delete backbuffer;
	}
	if (surface != NULL)
	{
		delete surface;
	}*/
}
