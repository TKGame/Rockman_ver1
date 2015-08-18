#include"Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame gameApp(hInstance);
	gameApp.InitGame();
	gameApp.Run();
}