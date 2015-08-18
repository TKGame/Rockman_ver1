#pragma once
#include<Windows.h>
#include"Config.h"
class CWindows
{
protected:
	HINSTANCE hInstance;
	HWND hwnd;
	static CWindows* instance;
public:
	CWindows();
	CWindows(HINSTANCE hInst);
	static CWindows* GetInstance();
	bool InitWindow();
	static LRESULT CALLBACK CWindows::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	HWND GetHWND();
	~CWindows();
};

