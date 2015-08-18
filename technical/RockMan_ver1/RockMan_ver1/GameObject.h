#pragma once
#include"Objects.h"
#include"Texture.h"
#include"Sprite.h"
#include"Collision.h"

class CGameObject 
{
protected:
	CTexture	_border; // text để vẽ vùng va chạm -> test - xác định va chạm
	bool _isInViewPort;
	CBox _boxCollision;	// vùng va chạm, dùng để kiêm tra đối tượng và lấy ra xét va chạm trên màn hình
public:
	CGameObject();
	virtual  ~CGameObject();
	// cài đặt ban đầu các thành phần trong object
	virtual int Initlize() =0;
	// update
	virtual void Update(float deltaTime) =0;
	// draw Object 
	virtual void Render(CGraphics* graphics) =0;
	// update Box
	virtual void UpdateBox() = 0;
	// lấy Cbox của object
	CBox GetBoxCollision();
	//  set box cho object
	void SetBoxCollision(int x, int y, int width, int height);
	// update camera
	void UpdateCamera(CCamera camera);
	// kiểm tra có nằm trong viewport , trả về true nếu có va chạm
	bool IsInViewPort();

	// Mã xác định đối tượng
	int _id;	
	// Mã xác định loại đối tượng
	int _typeID;	
	// vẽ vùng va chạm
	static bool IsDebugMode;
	
	D3DXVECTOR2 _position;	// Vị trí vẽ đối tượng
	D3DXVECTOR2	_origin;	// Vị trí tâm vẽ đối tượng
	D3DXVECTOR2	_size;		// Kích thước đối tượng
};

class CStaticObject : public CGameObject
{
public:
	CStaticObject();
	virtual ~CStaticObject();

	// Đối tượng nắm giữ ảnh của
	CTexture	_texture;
};

//-----------------------------------------------------------------------------
// Định nghĩa các đối tượng có thể di chuyển được trong game, VD: Rockman, emeny, bullet
//
//-----------------------------------------------------------------------------
class CMoveableObject : public CGameObject
{
public:
	CMoveableObject();
	virtual ~CMoveableObject();

	virtual void Render( CGraphics* graphics) override;

	//Kiểm tra xem Enemy có chết hay chưa?
	virtual bool IsDied();

	//Get mức độ sát thương
	virtual int GetDame();

	virtual void OnCollideWith(CGameObject *gameObject, CDirection normalX, CDirection normalY, float deltaTime);

	// Đối tượng nắm giữ ảnh vẽ ảnh động của GameObject
	CSprite* _sprite;

	// Trạng thái của đối tượng, thường được dùng để chuyển sprite, hành vi đối tượng
	int _spriteStatus;

	// Vận tốc di chuyển của đối tượng trên
	D3DXVECTOR2 _v;

	// Gia tốc di chuyển của đối tượng
	D3DXVECTOR2 _a;

	// Số máu còn lại của một mạng sống của đối tượng
	int _blood;

	// Mức độ sát thương của bullet
	int _dame;
};


