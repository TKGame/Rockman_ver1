#include "Input.h"

CInput* CInput::_pInstance = NULL;

CInput::CInput()
{
}

CInput::~CInput()
{}

int CInput::InitInput(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT
		hr = DirectInput8Create
		(
		hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8, (VOID**)&_di, NULL
		);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return 0;

	trace(L"DirectInput has been created");

	hr = _di->CreateDevice(GUID_SysKeyboard, &_Keyboard, NULL);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return 0;

	trace(L"DirectInput keyboard has been created");


	hr = _Keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (hr != DI_OK) return 0;

	trace(L"SetDataFormat for keyboard successfully");

	hr = _Keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (hr != DI_OK) return 0;

	trace(L"SetCooperativeLevel for keyboard successfully");

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	trace(L"SetProperty for keyboard successfully");

	hr = _Keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	if (hr != DI_OK) return 0;

	hr = _Keyboard->Acquire();
	if (hr != DI_OK) return 0;

	trace(L"Keyboard has been acquired successfully");

	return 1;
}


CInput* CInput::GetInstance()
{
	if (_pInstance == NULL)
		_pInstance = new CInput();

	return _pInstance;
}

void CInput::ProcessKeyBoard(HWND hwnd)
{
	// Collect all key states first
	_Keyboard->GetDeviceState(sizeof(_KeyStates), _KeyStates);

	if (IsKeyDown(DIK_ESCAPE))
	{
		trace(L"Escape key pressed!");
		PostMessage(hwnd, WM_QUIT, 0, 0);
	}

	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = _Keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0);

	// Scan through all data, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			_keyDown = KeyCode;
		else
		{
			_keyUp = KeyCode;
		}
	}
}

int CInput::IsKeyDown(int KeyCode)
{
	return (_KeyStates[KeyCode] & 0x80) > 0;
}
