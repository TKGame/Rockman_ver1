#pragma once
#include"Graphics.h"
#include"GameTime.h"
#include"Collision.h"

//class CObjects
//{
//protected:
//	CBox _box;
//
//public:
//	CObjects();
//	// 	Khởi tạo tất cả các thành phần của 1 đối tượng với các giá trí đã có
//	//	Trả về 0 nếu lối hoặc 1 nếu thành công
//	virtual int Initlize() = 0;
//	// 	Vẽ tất cả các thành phần của 1 đối tượng
//	//	+ gameTime	: Thời gian cập nhật hệ thống
//	//	+ graphics	: cọ vẽ đối tượng
//	virtual void Render( CGraphics* graphics) = 0;
//	// 	Cập nhật tất cả các logic của 1 đối tượng
//	//	+ gameTime	: Thời gian cập nhật hệ thống
//	//-----------------------------------------------------------------------------
//	virtual void Update() = 0;
//	// Lấy box, nhằm xét va chạm đối tượng
//	//-----------------------------------------------------------------------------
//	virtual void UpdateBox();
//	// Lấy khung hình chữ nhật bao đối tượng để xet va cham
//	//-----------------------------------------------------------------------------
//	RECT GetBoundingRectangle();	
//	//Lấy vị trí của đối tượng tính tại tâm
//	D3DXVECTOR2 GetPositionCenter();
//	CBox GetBox();
//	D3DXVECTOR2 _position;	// Vị trí vẽ đối tượng
//	D3DXVECTOR2	_origin;	// Vị trí tâm vẽ đối tượng
//	D3DXVECTOR2	_size;		// Kích thước đối tượng
//
//	virtual ~CObjects();
//};
//
