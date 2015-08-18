// định nghĩa các hằng số trong game

#define TILE_SIZE		32
#define SCREEN_WIDTH	256
#define SCREEN_HEIGHT	224
#define FULL_SCREEEN	0
#define	APP_TITLE		"RockMan v1"
#define PI				acosf(-1.0f)

#define GRAVITY			(9.8f / powf(1000.0f, 2.0f))

#define	ID_KEY_CODE_UP			DIK_I
#define	ID_KEY_CODE_DOWN		DIK_K
#define	ID_KEY_CODE_LEFT		DIK_J
#define	ID_KEY_CODE_RIGHT		DIK_L
#define	ID_KEY_CODE_FIRE		DIK_Z
#define	ID_KEY_CODE_JUMP		DIK_X
#define	ID_KEY_CODE_ENTER		DIK_RETURN
#define	ID_KEY_CODE_PAUSE		DIK_SPACE

#pragma region INPUT_DEVICE

#define KEYBOARD_BUFFER_SIZE 1024

#pragma endregion

#define ROCKMAN_VERLOCITY_X		85.0f/1000.0f
#define ROCKMAN_VERLOCITY_Y		355.0f/1000.0f
#define ROCKMAN_ACCELERATE_X	0.00075f/1000.0f
#define ROCKMAN_ACCELERATE_Y	1.09f/1000.0f

#define BLOOD_DEFAULT				27


#define ID_ROCKMAN			-1
#define ID_CUTMAN			5000
#define ID_GUTSMAN		    5001
#define ID_BOOMMAN			5002
