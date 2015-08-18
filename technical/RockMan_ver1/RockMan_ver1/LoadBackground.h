#pragma once
#include"Windows.h"
#include"Graphics.h"
#include"Sprite.h"
#include"Texture.h"

#include"FileUtil.h"

#include<vector>
#include<string>
#include<cstring>
#include<math.h>

class CLoadBackground
{
protected:
	CLoadBackground* instance;
	// ma trận lưu các id của map
	std::vector<std::vector<int>> _tileMatrix;
	int						_countRow;		// Số lượng dòng của ma trận
	int						_countColumn;	// Số lượng cột của ma trận
	int						_totalTile;		// Tổng số tile được cắt
	CTexture				_textureBackground;	// Đối tượng nắm giữ ảnh nền
public:
	CLoadBackground();
	void LoadMatrix(std::string filePath);

	void RenderBackGround(CTexture test , RECT viewport);

	~CLoadBackground();
};

