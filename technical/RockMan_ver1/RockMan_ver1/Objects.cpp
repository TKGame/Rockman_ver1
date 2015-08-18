#include "Objects.h"


//CObjects::CObjects()
//{
//	_position = D3DXVECTOR2(0, 0);
//	_origin = D3DXVECTOR2(0, 0);
//	_size = D3DXVECTOR2(0, 0);
//}
//
//// update lai vi tri cua box khi đối tượng di chuyển
//void CObjects::UpdateBox()
//{
//	_box._x = _position.x;
//	_box._y = _position.y;
//	_box._width = _size.x;
//	_box._height = _size.y;
//	_box._vx = 0.0f;
//	_box._vy = 0.0f;
//}
//
//CBox CObjects::GetBox()
//{
//	return _box;
//}
//
//// lấy khung chữ nhật bao của đối tượng dựa vào size của texture
//RECT CObjects::GetBoundingRectangle(){
//	RECT boundingRect;
//	boundingRect.left = _position.x;
//	boundingRect.top = _position.y;
//	boundingRect.right = boundingRect.left + _size.x;
//	boundingRect.bottom = boundingRect.top + _size.y;
//
//	return boundingRect;
//}
//
//D3DXVECTOR2 CObjects::GetPositionCenter()
//{
//	return D3DXVECTOR2(_position.x/* + _origin.x*/, _position.y/* + _origin.y*/);
//}
//
//CObjects::~CObjects()
//{
//}
