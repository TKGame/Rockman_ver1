#pragma once
#include<Windows.h>

#include"Game.h"
#include"Graphics.h"
#include"Sprite.h"
#include"Texture.h"

#include"LoadBackground.h"
#include"RockMan.h"
#include"GameTime.h"
#include"Input.h"
#define FRAME_RATE 30

class CGame
{
private:
	HINSTANCE hInstance;
	HWND hwnd;

	LARGE_INTEGER timeStart;
	LARGE_INTEGER timeEnd;
	LARGE_INTEGER timerFreq;
	float         deltaTime;
	float fps = 1 / FRAME_RATE;

public:
	CGame();
	// khởi tao tất cả các thành phần của game
	CGame(HINSTANCE hInst);
	// vòng lặp chính của game
	void Run();
	// khởi tạo các đối tượng của game
	void InitGame();

	float GetDeltaTime(float &delta);



	// ........................demo................
	void Render();
	void LoadResource();
	CSprite *demoSprite;


	LPDIRECT3DTEXTURE9 _texture;
	CLoadBackground * bg;
	
	float posXCamera = 0;

	CRockMan* rockman;

	//CGameTime*_gameTime;

	CCamera* camera;
	~CGame();

};

