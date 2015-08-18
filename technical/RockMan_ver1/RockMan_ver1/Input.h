#pragma once
#include <dinput.h>
#include "Config.h"
#include"Trace.h"

class CInput
{
public:
	~CInput();
	//===================================================
	static CInput* GetInstance();
	// Khởi tạo Input
	int InitInput(HINSTANCE hInstance, HWND hwnd);

	// Update KeyState từ KeyEvents
	void ProcessKeyBoard(HWND hwnd);

	int _keyUp;
	int _keyDown;
private:
	CInput();
	static CInput* _pInstance;
	// Đối tượng DirectInput 
	LPDIRECTINPUT8 _di;
	// Bàn phím 
	LPDIRECTINPUTDEVICE8 _Keyboard;
	// Bộ đệm trạng thái của bàn phím DirectInput 
	BYTE  _KeyStates[256];
	// Bộ đệm trạng thái của bàn phím DirectInput 
	BYTE  _preKeyStates[256];

	int IsKeyDown(int KeyCode);

	DIDEVICEOBJECTDATA _KeyEvents[KEYBOARD_BUFFER_SIZE];

};