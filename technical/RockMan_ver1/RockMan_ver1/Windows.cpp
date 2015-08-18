#include "Windows.h"


CWindows* CWindows::instance = NULL;

CWindows::CWindows()
{
	hInstance = nullptr;
	hwnd = nullptr;
}

CWindows::CWindows(HINSTANCE hInst)
{
	this->hInstance = hInst;
	hwnd = nullptr;
}


LRESULT CALLBACK CWindows::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool CWindows::InitWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	//fill the struct with info
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)CWindows::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APP_TITLE;
	wc.hIconSm = NULL;

	//set up the window with the class info
	RegisterClassEx(&wc);

	DWORD style;
	style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	this->hwnd = CreateWindow(
		APP_TITLE,
		APP_TITLE,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH*2,
		SCREEN_HEIGHT*2,
		NULL,
		NULL,
		this->hInstance,
		NULL);

	if (!(this->hwnd))
	{
		MessageBox(NULL, "Error Create Window", "Error", MB_OK);
		return false;
	}

	ShowWindow(this->hwnd, SW_NORMAL); //?????? _isFullScreen
	UpdateWindow(this->hwnd);
	return true;
}

CWindows* CWindows::GetInstance()
{
	if (instance == NULL)
	{
		instance = new CWindows();
	}
	return instance;
}

HWND CWindows::GetHWND()
{
	return hwnd;
}

CWindows::~CWindows()
{
	if (this->hInstance != nullptr)
		delete this->hInstance;
	this->hInstance = nullptr;

	if (this->hwnd != nullptr)
		delete this->hwnd;
	this->hwnd = nullptr;

	if (this->hInstance != nullptr)
		delete this->hInstance;
	this->hInstance = nullptr;
}
