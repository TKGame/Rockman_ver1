#include "Game.h"
#include"Windows.h"

CGame::CGame()
{
}

CGame::CGame(HINSTANCE hInst)
{
	this->hInstance = hInst;
	camera = new CCamera();

}

void CGame::InitGame()
{
	// khởi tạo cửa sổ
	if (CWindows::GetInstance()->InitWindow() == false)
	{
		MessageBox(NULL, "Khong Khoi Tao Windows", "Loi CreateWindows", MB_OK);
		return;
	}
	this->hwnd = CWindows::GetInstance()->GetHWND();
	// khởi tạo directX
	if (CGraphics::GetInstance()->InitDirectX(hwnd) == false)
	{
		MessageBox(NULL, "Khong Khoi Tao DirectX", "error", MB_OK);
		return;
	}
	if (CInput::GetInstance()->InitInput(hInstance, hwnd) == 0)
	{
		MessageBox(NULL, "Khong Khoi Tao duoc input!", "error", MB_OK);
		return;
	}
	LoadResource();
}

DWORD lastTime;
// vòng lặp chính của game
void CGame::Run()
{
	MSG msg;
	int done = 0;

	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeStart);

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	
		QueryPerformanceCounter(&timeEnd);
		deltaTime = ((float)timeEnd.QuadPart - (float)timeStart.QuadPart) / timerFreq.QuadPart;
		if (deltaTime >= fps)
		{
			// to do

			Render();// test

			/*DWORD now = GetTickCount();
			if (now - lastTime > 1000 / 10)
			{
				demoSprite->NextSprite();

				lastTime = now;
			}*/
			rockman->Update();

			timeStart = timeEnd;
		}

		CInput::GetInstance()->ProcessKeyBoard(this->hwnd);
	}
}

CGame::~CGame()
{
	if (CGraphics::GetInstance() != nullptr)
		CGraphics::GetInstance()->~CGraphics();
}


//...........................DEMO.......................................//
#define FILENAME "roackman_run.png"
#define BackGround "../Resources/boom_man_stage.bmp"

void CGame::Render()
{
	//CCamera::GetInstance()->Update(posXCamera += (int)(deltaTime * 100), SCREEN_HEIGHT );

	if (CGraphics::GetInstance()->BeginDraw(CCamera::GetInstance()) == 1)
	{
		//CGraphics::GetInstance()->Draw(demoSprite->GetTexture(), demoSprite->GetDestinationRectangle(), D3DXVECTOR2(100, 100));
		//bg->RenderBackGround(*CTexture::GetInstance(), CCamera::GetInstance()->GetViewport());

		//MessageBox(NULL, "Khong D3DXGetImageInfoFromFile ", "error", MB_OK);
		//CGraphics::GetInstance()->GetDevice()->ColorFill(CGraphics::GetInstance()->GetBackbuffer(), NULL, D3DCOLOR_XRGB(0, 0, 33));
		
		//CGraphics::GetInstance()->Draw(CTexture::GetInstance()->GetTexture(), rect,pos, false, D3DXVECTOR2(1, 1), SpriteEffects::NONE);
		rockman->Render(CGraphics::GetInstance());
		//CGraphics::GetInstance()->GetSpriteHandle()->Draw(_texture, &rect, NULL,&posDemo, D3DCOLOR_XRGB(255, 255, 255));
	}

	CGraphics::GetInstance()->EndDraw();
}

void CGame::LoadResource()
{
	/*D3DXIMAGE_INFO imageInfo;
	HRESULT hr = D3DXGetImageInfoFromFile(FILENAME, &imageInfo);
	if (hr != D3D_OK)
	{
		MessageBox(NULL, "Khong D3DXGetImageInfoFromFile ", "error", MB_OK);
		return;
	}
	LPDIRECT3DDEVICE9 d3ddv = CGraphics::GetInstance()->GetDevice();
	if (d3ddv)
	{
		hr = D3DXCreateTextureFromFileEx(
			d3ddv,
			FILENAME,
			imageInfo.Width,
			imageInfo.Height,
			1,
			D3DPOOL_DEFAULT,
			D3DFMT_A8R8G8B8,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 255, 255),
			&imageInfo,
			NULL,
			&_texture
			);
	}
	else
		MessageBox(NULL, "Khong Khoi Tao D3DXCreateTextureFromFileEx ", "error", MB_OK);

	if (hr != D3D_OK)
	{
		MessageBox(NULL, "Khong Khoi Tao D3DXCreateTextureFromFileEx ", "error", MB_OK);
		return;
	}*/

	//demoSprite = new CSprite(FILENAME, 3, 3, 6, this->anim_rate, D3DCOLOR_XRGB(255, 255, 255));
	//demoSprite->LoadImageFromFile(FILENAME);

	// load texture map

	//CTexture::GetInstance()->LoadTextureFromFile(BackGround);

	/*bg = new CLoadBackground();
	bg->LoadMatrix("../Resources/boom_man_stage.txt");

	rockman = new CRockMan();
	rockman->Initlize();*/
	//demoSprite = new CSprite(FILENAME,1, 3, 3, 0.1, D3DCOLOR_XRGB(0, 102, 102));

	rockman = new CRockMan();

	rockman->Initlize();
}
