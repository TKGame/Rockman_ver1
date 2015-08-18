#pragma once
#include"GameObject.h"
#include"Sprite.h"
#include"Camera.h"
#include"Config.h"
#include"Input.h"

enum Behave
{
	START,
	STAND_FIRE,
	STAND,
	STAIR,
	STAIR_BEGIN_END,
	STAIR_FIRE,
	RUN,
	PREPARE_RUN,
	RUN_FIRE,
	JUMP,
	JUMP_FIRE,
	FALL,
	FALL_FIRE,
	REAL_DIE,
	DYING,
	HURT_ON_GROUND,
	HURT_IN_AIR
};

class CRockMan : public CMoveableObject
{

public:
	CRockMan();
	int Initlize() override;
	void Update(float deltaTime) override;
	void Render( CGraphics* graphics) override;
	void OnCollideWith(CGameObject* obj, CDirection normalX, CDirection normalY, float collideTime) override;
	void UpdateBox() override;
	bool IsDied() override;

	CInput* _input;

	DWORD lastTime;
	~CRockMan();
};

