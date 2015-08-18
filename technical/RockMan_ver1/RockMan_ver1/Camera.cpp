#include "Camera.h"

CCamera* CCamera::instance = NULL;

CCamera::CCamera()
{
	D3DXMatrixIdentity(&matrixTransform);
	position.x = 0;
	position.y = SCREEN_HEIGHT;
	position.z = 0;
	this->matrixTransform._22 = -1;
}

D3DXVECTOR3 CCamera::Tranform(float posX, float posY)
{
	this->matrixTransform._41 = -this->position.x;
	this->matrixTransform._42 = this->position.y;

	D3DXVECTOR3 posCurrent(posX, posY, 0);
	D3DXVECTOR4 outTranform;
	D3DXVec3Transform(&outTranform, &posCurrent, &matrixTransform);

	//MessageBox(NULL, "Error initializing Direct3D", "Error", MB_OK);
	return D3DXVECTOR3(outTranform.x, outTranform.y, outTranform.z);
}

void CCamera::Update(float x, float y)
{
	/*position.x = (this->position.x < x || x == 0) ? x : position.x;
	position.y = (y > this->position.y) ? y : this->position.y;*/
	if (this->position.x < x || x == 0)
	{
		this->position.x = x;
	}
	else
		this->position.x = position.x;

	if (y > this->position.y)
	{
		this->position.y= y;
	}
	else
		this->position.y = position.y;
}

D3DXVECTOR2 CCamera::GetPositionCamera()
{
	return D3DXVECTOR2(position.x, position.y);
}

RECT CCamera::GetViewport()
{
	RECT rectViewport;
	rectViewport.top = position.y;
	rectViewport.left = position.x;
	rectViewport.bottom = rectViewport.top + SCREEN_HEIGHT;
	rectViewport.right = rectViewport.left + SCREEN_WIDTH;

	return rectViewport;
}

CCamera* CCamera::GetInstance()
{
	if (instance == NULL)
	{
		instance = new CCamera();
		return instance;
	}
	else
	{
		return instance;
	}
}

CCamera::~CCamera()
{
}
