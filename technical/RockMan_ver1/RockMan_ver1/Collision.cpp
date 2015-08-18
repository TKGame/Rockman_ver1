#include "Collision.h"

CBox::CBox()
{
	CBox(0, 0, 0, 0, 0, 0);
}

CBox::CBox(float x, float y, float width, float height, float vx, float vy)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_vx = vx;
	_vy = vy;
}

CBox::CBox(RECT rectangle)
{
	_x = rectangle.left;
	_y = rectangle.top;
	_width = abs(rectangle.right - rectangle.left);
	_height = abs(rectangle.top - rectangle.bottom);
	_vx = 0.0f;
	_vy = 0.0f;
}

bool CBox::IntersecWith(CBox box, bool acceptDiffirent)
{
	if (!acceptDiffirent)
		return !(_x > box._x + box._width || _y < box._y - box._height || _x + _width<box._x || _y - _height>box._y);
	else
		return !(floor(_x) > floor(box._x + box._width) || floor(_y) < floor(box._y - box._height) || floor(_x + _width) < floor(box._x) || floor(_y - _height) > floor(box._y));
}


//.....................CColision.......................................//
CBox CCollision::GetSweptBox(CBox box, float frameTime)
{
	CBox re;
	re._x = box._vx > 0 ? box._x : box._x - abs(box._vx)*frameTime;
	re._y = box._vy > 0 ? box._y + abs(box._vy)*frameTime : box._y;
	re._vx = box._vx;
	re._vy = box._vy;
	re._width = box._width + abs(box._vx)*frameTime;
	re._height = box._height + abs(box._vy)*frameTime;

	return re;
}

bool CCollision::AABBCheck(CBox box1, CBox box2)
{
	return box1.IntersecWith(box2, true);
}

CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}
