#include "RockMan.h"

#define FILENAMEROCKMAN "roackman_run.png"

CRockMan::CRockMan() : CMoveableObject()
{
	this->_typeID = -1;
}

int CRockMan::Initlize()
{
	this->_v.x = 0.0f;
	this->_v.y = ROCKMAN_VERLOCITY_Y;
	this->_a.x = 0.0f;
	this->_a.y = ROCKMAN_ACCELERATE_Y;
	this->_blood = BLOOD_DEFAULT;

	this->_sprite = new CSprite(FILENAMEROCKMAN,1,3,3,1,D3DCOLOR_XRGB(0,102,102));
	
	_input = CInput::GetInstance();

	return 1;
}

void CRockMan::Render(CGraphics* graphics)
{
	CGraphics::GetInstance()->Draw(_sprite->GetTexture(), _sprite->GetDestinationRectangle(), D3DXVECTOR2(10, 100));
	CMoveableObject::Render(graphics);
}

void CRockMan::Update(float deltaTime)
{	
	// update vị trí của object
	this->_position.x += _v.x*deltaTime;
	this->_position.y += _v.y*deltaTime;

	DWORD now = GetTickCount();
	if (now - lastTime > 1000 / 10)
	{
		_sprite->NextSprite();
		lastTime = now;
	}
	UpdateBox();
}

void CRockMan::UpdateBox()
{
	_boxCollision._width = 16.0f;
	_boxCollision._height = 24.0f;
	_boxCollision._x = _position.x - _boxCollision._width / 2.0f;
	_boxCollision._y = _position.y + _boxCollision._height / 2.0f;
	_boxCollision._vx = _v.x;
	_boxCollision._vy = _v.y;
}

bool CRockMan::IsDied()
{
	return false;
}

void CRockMan::OnCollideWith(CGameObject* obj, CDirection normalX, CDirection normalY, float collideTime)
{

}

CRockMan::~CRockMan()
{
}
