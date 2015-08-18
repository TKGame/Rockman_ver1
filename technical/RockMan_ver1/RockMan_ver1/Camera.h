#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"Global.h"

class CCamera
{
protected:
	D3DXVECTOR3 position;
	// ma tran 3
	D3DXMATRIX matrixTransform;
	static CCamera* instance;
public:
	CCamera();
	//chuyen toa do sang the gioi ao
	D3DXVECTOR3 Tranform(float posX, float posY);
	// move camera
	void Update(float posX, float posY);
	//lay vi tri camera
	D3DXVECTOR2 GetPositionCamera();
	// lay vung bao cua viewport
	RECT GetViewport();

	static  CCamera* GetInstance();
	~CCamera();
};

