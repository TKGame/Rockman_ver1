#include "LoadBackground.h"


CLoadBackground::CLoadBackground()
{
}

void CLoadBackground::LoadMatrix(const std::string filePath)
{
	std::wstring widestr = std::wstring(filePath.begin(), filePath.end());
	// duong dan file txt
	const wchar_t* mapData = widestr.c_str();
	//wchar_t* mapImage;

	ifstream fs;		// Luồng đọc file map
	string line;		// Chuỗi đọc file map

	// Mở file và đọc, nếu không được thì out
	fs.open(mapData, ios::in);
	if (!fs.is_open())
	{
		OutputDebugString("Can not open map file");
		return;
	}

	// luong chuoi string
	istringstream iss;

	getline(fs, line);
	if (line.compare("#Tile_Matrix") == 0)
	{
		getline(fs, line);								// Bỏ qua dòng "Total_Row	Total_Column	Total_Tile"
		getline(fs, line);
		iss.clear();
		iss.str(line);
		iss >> _countRow >> _countColumn >> _totalTile;	// Đẩy giá trị tổng số dòng, cột, tổng số tile vào biến
		getline(fs, line);								// Bỏ qua dòng "#Tile_Matrix_Value"

		// Tạo mảng hai chiều lưu ma trận tile
		for (int i = 0; i < _countRow; i++)
		{
			vector<int> row;
			row.resize(_countColumn);
			_tileMatrix.push_back(row);
		}

		// Tiến hành đọc dữ liệu
		for (int i = 0; i < _countRow; i++)
		{
			getline(fs, line);
			iss.clear();
			iss.str(line);
			for (int j = 0; j < _countColumn; j++)
				iss >> _tileMatrix[i][j];
		}
		getline(fs, line);					// Bỏ qua dòng "#Tile_Matrix_End"
	}
}

void CLoadBackground::RenderBackGround(CTexture test, RECT viewport)
{
	this->_textureBackground = test;

	/*int startRow = floor(viewport.bottom / 32);
	int endRow = floor(viewport.top / 32) + 1;
	int startColumn = floor(viewport.left / 32);
	int endColumn = floor(viewport.right / 32) + 1;

	if (startColumn < 0)
		startColumn = 0;
	if (startRow < 0)
		startRow = 0;
	if (endColumn > _countColumn)
		endColumn = _countColumn;
	if (endRow > _countRow)
		endRow = _countRow;
	
	D3DXVECTOR2 startDrawPos = D3DXVECTOR2(startColumn * 32, endRow * 32);*/

	// sô cột của texture
	int _numColums = sqrt(this->_totalTile)+1;
	// size của 1 title
	D3DXVECTOR2 size;
	size.x = 32;
	size.y = 32;
	// rect resources
	RECT rect;
	D3DXVECTOR2 position;

	//for (int i = endRow; i < startRow; i++)
	//{
	//	for (int j = startColumn;j < endColumn; j++)
	//	{
	//		RECT desRect;
	//		desRect.top = (_tileMatrix[_countRow - i][j] / _numColums)* 32;
	//		desRect.left = (_tileMatrix[_countRow - i][j] % _numColums)*32;
	//		desRect.right = desRect.left + 32;
	//		desRect.bottom = desRect.top + 32;

	//		CGraphics::GetInstance()->Draw(_textureBackground.GetTexture(), desRect, startDrawPos);

	//		//startDrawPos.x += 32;
	//	}

	//	/*startDrawPos.y -= 32;
	//	startDrawPos.x -= 32*abs(startColumn - endColumn);*/
	//}

	for (int i = 0; i < this->_countRow; i++)
	{
		for (int j = 0; j < this->_countColumn; j++)
		{
			if (this->_tileMatrix[i][j] != -1)
			{
				rect.left = this->_tileMatrix[i][j] % _numColums * size.x;
				rect.top = this->_tileMatrix[i][j] / _numColums * size.y;
				rect.right = rect.left + size.x;
				rect.bottom = rect.top + size.y;

				position.x = j *size.x;
				position.y = ((_countRow - 1) - i) * size.y;

				CGraphics::GetInstance()->Draw(_textureBackground.GetTexture(), rect, position);
				//CGraphics::GetInstance()->Draw(_textureBackground.GetTexture(),rect, position, false, D3DXVECTOR2(1, 1), SpriteEffects::NONE);
			}
		}
	}
}


CLoadBackground::~CLoadBackground()
{
}
