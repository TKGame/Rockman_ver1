#pragma once
#include"GameObject.h"
#include"Sprite.h"
#include"Camera.h"
#include"Config.h"
#include"Input.h"


class CRockMan : public CMoveableObject
{

public:
	CRockMan();
	int Initlize() override;
	void Update() override;
	void Render( CGraphics* graphics) override;
	void OnCollideWith(CGameObject* obj, CDirection normalX, CDirection normalY, float collideTime) override;
	void UpdateBox() override;
	bool IsDied() override;

	CInput* _input;

	DWORD lastTime;
	~CRockMan();
};

