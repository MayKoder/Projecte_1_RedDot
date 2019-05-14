#include "John.h"

John::John(int player)
{
	this->player = player;
	specialDmg = 15;

	//Rect Colliders
	SDL_Rect rect1 = { -10,-40,25,20 };
	SDL_Rect rect2 = { -20,-20,45,60 };
	SDL_Rect rect3 = { -25,40,50,30 };

	//Jump Colliders
	SDL_Rect head_jump_collider = { -10,-55,25,20 };
	SDL_Rect body_jump_collider = { -20,-40,45,60 };
	SDL_Rect legs_jump_collider = { -25,10,50,30 };

	//Jump Punch Colliders
	SDL_Rect head_jumppunch_collider = { -10,-55,25,20 };
	SDL_Rect body_jumppunch_collider = { -25,-44,35,60 };
	SDL_Rect legs_jumppunch_collider = { -30,5,37,30 };
	

	//Jump Kick Colliders
	SDL_Rect head_jumpkick_collider = { -10,-50,25,20 };
	SDL_Rect body_jumpkick_collider = { -25,-44,35,45 };
	SDL_Rect legs_jumpkick_collider = { -30,-5,47,30 };

	//Crouch Rect Colliders
	SDL_Rect head_crouch_collider = { -10,-8,25,20 };
	SDL_Rect body_crouch_collider = { -20,8,50,58 };

	//Crouch Punch Rect Colliders
	SDL_Rect head_crouchPunch_collider = { 5,-8,25,20 };
	SDL_Rect body_crouchPunch_collider = { -10,8,50,58 };

	//Recover Colliders
	SDL_Rect head_recover_collider = { -10,-19,25,27 };
	SDL_Rect body_recover_collider = { -29,8,55,58 };

	//Kick Colliders
	SDL_Rect head_kick_collider = { -30,-50,25,20 };
	SDL_Rect body_kick_collider = { -30,-30,33,60 };
	SDL_Rect legs_kick_collider = { -27,30,30,40 };

	//Hit Collider
	SDL_Rect hit_punch_colllider = { 20,-25,43,10 };
	SDL_Rect hit_kick_collider = { 5,-45,60,40 };

	//IDLE
	idle.SetReverseOffset({ -27,-43 }, 2);
	idle.PushBack({ 0, 0, 66, 104 }, 0, -39, 2, rect1, rect2, rect3);
	idle.SetReverseOffset({ -30,-43 }, 2);
	idle.PushBack({ 129 , 0, 66, 107 }, 0, -42, 2, rect1, rect2, rect3);
	idle.SetReverseOffset({ -28,-43 }, 2);
	idle.PushBack({ 66, 0, 63, 106 }, 0, -41, 2, rect1, rect2, rect3);

	idle.speed = 0.26f;

	//WALK FORWARD
	forward.PushBack({ 435, 259, 67, 104 }, 0, -39, 5, rect1, rect2, rect3);
	forward.PushBack({ 502, 259, 63, 108 }, 2, -43, 5, rect1, rect2, rect3);
	forward.PushBack({ 565, 259, 61, 110 }, 2, -45, 5, rect1, rect2, rect3);
	forward.PushBack({ 626, 259, 63, 106 }, 0, -41, 5, rect1, rect2, rect3);
	forward.PushBack({ 689, 259, 69, 109 }, -2, -44, 5, rect1, rect2, rect3);
	forward.speed = 0.7f;
	//WALK BACKWARD

	backward.PushBack({ 435, 259, 67, 104 }, 0, -39, 5, rect1, rect2, rect3);
	backward.PushBack({ 502, 259, 63, 108 }, 2, -43, 5, rect1, rect2, rect3);
	backward.PushBack({ 565, 259, 61, 110 }, 2, -45, 5, rect1, rect2, rect3);
	backward.PushBack({ 626, 259, 63, 106 }, 0, -41, 5, rect1, rect2, rect3);
	backward.PushBack({ 689, 259, 69, 109 }, -2, -44, 5, rect1, rect2, rect3);
	backward.speed = 0.7f;

	//JUMP
	jump.loop = false;
	jump.SetReverseOffset({ -23, -18 }, 4);
	jump.PushBack({ 195,3,66,104 }, 0, -39, 3, {}, {}, {}, {});
	jump.SetReverseOffset({ -23, -65 }, 5);
	jump.PushBack({ 261,0,48,118 }, 9, -48, 11, {}, {}, {}, {}, { 0,-7 });
	jump.SetReverseOffset({ -23, -65 }, 5);
	jump.PushBack({ 261,0,48,118 }, 9, -48, 3, {}, {}, {}, {}, { 0,-3 });
	jump.SetReverseOffset({ -23, -58 }, 7);
	jump.PushBack({ 309,30,57,77 }, 0, -35, 8, {}, {}, {}, {});
	jump.SetReverseOffset({ -23, -58 }, 7);
	jump.PushBack({ 309,30,57,77 }, 0, -35, 7, {}, {}, {}, {}, { 0,1 });
	jump.SetReverseOffset({ -20, -58 }, 10);
	jump.PushBack({ 261,0,48,118 }, 9, -48, 14, {}, {}, {}, {}, { 0,6 });
	jump.speed = 0.9f;
	
	//Forward JUMP
	jump_forward.loop = false;
	jump_forward.SetReverseOffset({ -23, -18 }, 4);
	jump_forward.PushBack({ 195,3,66,104 }, 0, -39, 3, {}, {}, {}, {});
	jump_forward.SetReverseOffset({ -23, -65 }, 5);
	jump_forward.PushBack({ 261,0,48,118 }, 9, -48, 11, {}, {}, {}, {}, { 3,-7 });
	jump_forward.SetReverseOffset({ -23, -65 }, 5);
	jump_forward.PushBack({ 261,0,48,118 }, 9, -48, 3, {}, {}, {}, {}, { 3,-3 });
	jump_forward.SetReverseOffset({ -23, -58 }, 7);
	jump_forward.PushBack({ 309,30,57,77 }, 0, -35, 8, {}, {}, {}, {}, { 3,0 });
	jump_forward.SetReverseOffset({ -23, -58 }, 7);
	jump_forward.PushBack({ 309,30,57,77 }, 0, -35, 7, {}, {}, {}, {}, { 3,1 });
	jump_forward.SetReverseOffset({ -20, -58 }, 10);
	jump_forward.PushBack({ 261,0,48,118 }, 9, -48, 14, {}, {}, {}, {}, { 3,6 });
	jump_forward.speed = 0.9f;	

	//Backward JUMP
	jump_backward.loop = false;
	jump_backward.SetReverseOffset({ -23, -18 }, 4);
	jump_backward.PushBack({ 195,3,66,104 }, 0, -39, 3, {}, {}, {}, {});
	jump_backward.SetReverseOffset({ -23, -65 }, 5);
	jump_backward.PushBack({ 261,0,48,118 }, 9, -48, 11, {}, {}, {}, {}, { -3,-7 });
	jump_backward.SetReverseOffset({ -23, -65 }, 5);
	jump_backward.PushBack({ 261,0,48,118 }, 9, -48, 3, {}, {}, {}, {}, { -3,-3 });
	jump_backward.SetReverseOffset({ -23, -58 }, 7);
	jump_backward.PushBack({ 309,30,57,77 }, 0, -35, 8, {}, {}, {}, {}, { -3,0 });
	jump_backward.SetReverseOffset({ -23, -58 }, 7);
	jump_backward.PushBack({ 309,30,57,77 }, 0, -35, 7, {}, {}, {}, {}, { -3,1 });
	jump_backward.SetReverseOffset({ -20, -58 }, 10);
	jump_backward.PushBack({ 261,0,48,118 }, 9, -48, 14, {}, {}, {}, {}, { -3,6 });
	jump_backward.speed = 0.9f;

	//Recover
	recover.loop = false;
	recover.SetReverseOffset({ -20, -58 }, 9);
	recover.PushBack({ 195,3,66,104 }, 0, -39, 3);
	recover.speed = 0.5f;

	//CROUCH
	crouch.PushBack({ 366,3,66,104 });
	crouch.PushBack({ 432,3,66,104 });
	crouch.PushBack({ 498,34,58,73 });

	crouch.speed = 0.25f;

	//CROUCH KICK
	crouch_kick.PushBack({ 556,35,59,72 });
	crouch_kick.PushBack({ 615,39,104,68 });

	crouch_kick.speed = 0.25f;

	//PUNCH
	punch.PushBack({ 719,0,73,111 },-3,-46,1);
	punch.PushBack({ 792,0,107,107 },-2,-42,2);
	punch.PushBack({ 719,0,73,111 },-3,-46,2);
	punch.PushBack({ 0, 0, 66, 104 }, 0, -39, 4, rect1, rect2, rect3);
	punch.loop = false;
	punch.speed = 0.5f;

	//KICK
	kick.PushBack({ 0,128,58,113 }, -1, -48, 2);
	kick.PushBack({ 58,128,52,113 }, 14, -49, 2);
	kick.PushBack({ 110,128,58,111 }, 4, -46, 2);
	kick.PushBack({ 168,129,105,108 }, 1, -43, 5);
	kick.PushBack({ 273,139,83,108 }, 3, -43, 2);
	kick.PushBack({ 110,128,58,111 }, 5, -46, 2);
	kick.PushBack({ 58,128,52,113 }, 14, -49, 2);
	kick.PushBack({ 0,128,58,113 }, -1, -48, 2);
	kick.loop = false;
	kick.speed = 0.7f;

	//KOUKEN
	koouKen.PushBack({ 366,149,69,98 });
	koouKen.PushBack({ 435,155,67,92 });
	koouKen.PushBack({ 502,145,71,101 });
	koouKen.PushBack({ 573,155,108,92 });

	koouKen.speed = 0.25f;

	//FALL

	//Falten frames//

	//JUMP + KICK

	//Falten frames//

	//JUMP + PUNCH
	jumppunch.PushBack({ 109,247,71,123 },0,-48,10);

	jumppunch.speed = 0.25f;
	jumppunch.loop = false;

	//PUNCH + C
	c_punch.PushBack({ 326,374,51,119 });
	c_punch.PushBack({ 380,375,58,117 });
	c_punch.PushBack({ 442,376,55,117 });
	c_punch.PushBack({ 503,377,111,116 });
	c_punch.PushBack({ 615,376,67,120 });


	//KICK + C
	c_kick.PushBack({ 195,3,66,104 });
	c_kick.PushBack({ 137,370,74,123 });
	c_kick.PushBack({ 213,376,111,117 });
	c_kick.PushBack({ 137,370,74,123 });
	c_kick.PushBack({ 195,3,66,104 });

	//falta jump forward i backward, win, defeat
}

bool John::Start()
{
	if (player == 1) {
		if (graphics == nullptr)
			graphics = App->textures->Load("Assets/john_sprite_sheet.png");
	}
	else if (player == 2) {
		if (graphics == nullptr)
			graphics = App->textures->Load("Assets/ryo_sprite_sheet_2.png");
	}
	if (punchfx == nullptr)
		punchfx = App->audio->Load_effects("Assets/Audio/FX/ryo/Ryo_punch.wav");
	if (kickfx == nullptr)
		kickfx = App->audio->Load_effects("Assets/Audio/FX/ryo/Ryo_kick.wav");
	if (kooukenfx == nullptr)
		kooukenfx = App->audio->Load_effects("Assets/Audio/FX/ryo/Ryo_kooken.wav");
	if (jumpfx == nullptr)
		jumpfx = App->audio->Load_effects("Assets/Audio/FX/Jump.wav");
	if (dmg == nullptr)
		dmg = App->audio->Load_effects("Assets/Audio/FX/ryo/Ryo_dmg.wav");
	return true;
}

bool John::CleanUp()
{
	if (graphics != nullptr)
	{
		App->textures->Unload(graphics);
		graphics = nullptr;
	}
	if (punchfx != nullptr)
	{
		App->audio->Unload_effects(punchfx);
		punchfx = nullptr;
	}
	if (kickfx != nullptr)
	{
		App->audio->Unload_effects(kickfx);
		kickfx = nullptr;
	}
	if (kooukenfx != nullptr)
	{
		App->audio->Unload_effects(kooukenfx);
		kooukenfx = nullptr;
	}
	if (jumpfx != nullptr)
	{
		App->audio->Unload_effects(jumpfx);
		jumpfx = nullptr;
	}
	if (dmg != nullptr)
	{
		App->audio->Unload_effects(dmg);
		dmg = nullptr;
	}
	return true;
}
