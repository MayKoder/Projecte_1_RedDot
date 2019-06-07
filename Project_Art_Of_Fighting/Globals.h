#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum Characters {
	RYO,
	JOHN
};
enum key_state {
	KEY_IDLE = 1,
	KEY_UP,
	KEY_DOWN,
	KEY_REPEAT,
};
enum GamePad {
	PAD_IDLE = 1,
	PAD_UP,
	PAD_DOWN,
	PAD_REPEAT,
};

//States
enum player_state
{
	ST_TEST,
	ST_UNKNOWN,
	ST_IDLE,
	ST_WALK_FORWARD,
	ST_WALK_BACKWARD,
	ST_STANDING_PUNCH,
	ST_STANDING_KICK,
	ST_NEUTRAL_JUMP,
	ST_NEUTRAL_JUMP_PUNCH,
	ST_NEUTRAL_JUMP_KICK,
	ST_FORWARD_JUMP,
	ST_BACKWARD_JUMP,
	ST_FORWARD_JUMP_PUNCH,
	ST_FORWARD_JUMP_KICK,
	ST_BACKWARD_JUMP_PUNCH,
	ST_BACKWARD_JUMP_KICK,
	ST_KOOU_KEN,
	ST_FALL,
	ST_FORWARD_FALL,
	ST_BACKWARD_FALL,
	ST_RECOVER,
	ST_CROUCH,
	ST_CROUCH_PUNCH,
	ST_CROUCH_KICK,
	ST_CROUCH_RECOVER,
	ST_IDLE_TO_DAMAGE,
	ST_CROUCH_DAMAGE,
	ST_STANDING_BLOCK,
	ST_CROUCH_BLOCK,
	ST_STANDING_BLOCKED,
	ST_STRONG_PUNCH,
	ST_STRONG_KICK,
	ST_WIN,
	ST_DEFEAT,
	ST_TAUNT,
	ST_RECHARGE
	
};

//Inputs
enum inputs
{
	IN_TEST,
	IN_UNKNOWN,
	IN_LEFT_UP,
	IN_LEFT_DOWN,
	IN_RIGHT_UP,
	IN_RIGHT_DOWN,
	IN_JUMP_DOWN,
	IN_CROUCH_DOWN,
	IN_CROUCH_UP,
	IN_PUNCH,
	IN_KICK,
	IN_KOOU_KEN,
	IN_JUMP_FINISH,
	IN_ATTACK_FINISH,
	IN_RECOVER_FINISH,
	IN_CROUCH_RECOVER_FINISH,
	IN_CROUCH_RECOVER,
	IN_RECOVER,
	IN_RECEIVE_DAMAGE,
	IN_BLOCKING,
	IN_BLOCKED,
	IN_EMPTY,
	IN_STRONG_PUNCH,
	IN_STRONG_KICK,
	IN_WIN,
	IN_DEFEAT,
	IN_TAUNT,
	IN_RECHARGE,
	IN_RECHARGE_UP,
	
};


struct Timed_Inputs
{


	inputs Input;
	float Time;


};

// Useful typedefs ---------
typedef unsigned int uint;

// Configuration -----------
//To adjust fullscreen set SCREEN_SIZE to 1, else SCREEN_SIZE = 3
#define SCREEN_SIZE 3
#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 224
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
#define REN_VSYNC 1


#endif // __GLOBALS_H__ s
