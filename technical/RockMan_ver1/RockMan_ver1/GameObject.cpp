#include "GameObject.h"

bool CGameObject::IsDebugMode = true;

#define FILE_PATH_BORDER "../Resources/block.png"

CGameObject::CGameObject() 
{
	_id = -1;
	_typeID = -1;
	//_border = ResourceManager::GetSprite(ID_DEBUG_BOX);
	_border = CTexture(FILE_PATH_BORDER, D3DCOLOR_XRGB(0, 0, 0));
	_boxCollision._vx = _boxCollision._vy = _boxCollision._x = _boxCollision._y = _boxCollision._width = _boxCollision._height = 0;
	_isInViewPort = false;
}

CGameObject::~CGameObject()
{

}

int CGameObject::Initlize()
{
	return 1;
}

void CGameObject::Update()
{

}

bool CGameObject::IsInViewPort()
{
	return _isInViewPort;
}

void CGameObject::Render( CGraphics* graphics)
{

	RECT rectBorder;
	rectBorder.left = _boxCollision._x;
	rectBorder.top = _boxCollision._y;
	rectBorder.right = _boxCollision._x + _border.GetWidth();
	rectBorder.bottom = _boxCollision._y + _border.GetHeight();
	// vẽ vùng va chạm lên màn hình 
	if (CGameObject::IsDebugMode)
		graphics->Draw(_border.GetTexture(), rectBorder, D3DXVECTOR2(_boxCollision._width / _border.GetWidth(), _boxCollision._height / _border.GetHeight()));
}

void CGameObject::UpdateCamera(CCamera camera)
{
	if (_boxCollision.IntersecWith(CBox(camera.GetViewport())) && !_isInViewPort)
		_isInViewPort = true;
}

void CGameObject::UpdateBox()
{
	_boxCollision._x = _position.x;
	_boxCollision._y = _position.y;
	_boxCollision._width = _size.x;
	_boxCollision._height = _size.y;
	_boxCollision._vx = 0.0f;
	_boxCollision._vy = 0.0f;
}

CBox CGameObject::GetBoxCollision()
{
	return _boxCollision;
}

void CGameObject::SetBoxCollision(int x, int y, int width, int height)
{
	if (x == 0 && y == 0 && width == 0 && height == 0)
	{
		_boxCollision = GetBoxCollision();
	}
	else
	{
		_boxCollision._vx = 0.0f;
		_boxCollision._vy = 0.0f;
		_boxCollision._x = x;
		_boxCollision._y = y;
		_boxCollision._width = width;
		_boxCollision._height = height;
	}
}

// Định nghĩa lớp đối tượng CStaticObject
CStaticObject::CStaticObject() :  CGameObject()
{


}

CStaticObject::~CStaticObject()
{

}


// Định nghĩa lớp đối tượng CMoveableObject
CMoveableObject::CMoveableObject() :CGameObject()
{
	_v = D3DXVECTOR2(0.0f, 0.0f);
	_a = D3DXVECTOR2(0.0f, 0.0f);
	_blood = 0;
	_dame = 0;
}

CMoveableObject::~CMoveableObject()
{

}

void CMoveableObject::Render(CGraphics* graphics)
{
	if (IsDebugMode)
		CGameObject::Render(graphics);
}

bool CMoveableObject::IsDied()
{
	if (_blood <= 0)
		return true;
	else
		return false;
}

int CMoveableObject::GetDame()
{
	return _dame;
}

void CMoveableObject::OnCollideWith(CGameObject *gameObject, CDirection normalX, CDirection normalY, float deltaTime)
{

}