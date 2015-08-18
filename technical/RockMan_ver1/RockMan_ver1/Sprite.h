#pragma once
#include"GameTime.h"
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"Graphics.h"
#include"Texture.h"

class CSprite : public CTexture
{
	// frame hiện tại
	int _index;
	// tổng số frame
	int _countFrame;
	// tổng frame trên một dòng
	int _countRow;
	// tổng frame trên một cột 
	int _countColumn;
	// chiều cao của mỗi frame
	int _frameHeight;
	// chiều dài của mỗi frame
	int _frameWidth;
	// khoảng thởi gian giữa 2 lần next frame
	int _timeFrame;
	// cộng dôn thời gian để chyển frame
	float _tick;	
	// chìu rộng bức ảnh 
	float _imageWidth;
	// chiù dài bức ảnh
	float _imageHeight;

	LPDIRECT3DTEXTURE9 _texture;
	bool _isNextFrame;
	int _frameStart;
	int _frameEnd;
public:
	CSprite();
	~CSprite();
	CSprite(LPCSTR pNamePath, int countRow, int countColumn, int countFrame, int timeframe, D3DCOLOR color);
	int _timeFrameDefault;

	void SetIndex(int index);
	// get index cua frame hien tai
	int GetIndex();
	// chuyển frame
	void NextSprite();
	
	//void Update(int deltaTime);
	// get rect
	RECT GetDestinationRectangle();

	int GetColum();
	int GetRow();

	int GetFrameHeight();
	int GetFrameWidth();

	int GetCountFrame();

	bool IsNextFrame();

	void Reset();

	void SetAllowAnimate(int timeFrame);

	int SetFrame(int frameStart, int frameEnd);
};

