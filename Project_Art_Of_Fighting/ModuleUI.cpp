#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleUI.h"
#include "SDL/include/SDL.h"
#include "ModuleCollision.h"


ModuleUI::ModuleUI()
{


}

ModuleUI::~ModuleUI()
{}


bool ModuleUI::Start()
{
	LOG("Loading UI");

	//Load All UI
	TimerTexture = App->textures->Load("Assets/UI_Sprites/Timer.png");
	App->player1->Player_Health_BG = App->player2->Player_Health_BG = App->textures->Load("Assets/UI_Sprites/Health.png");
	App->player1->Player_Health = App->player2->Player_Health = App->textures->Load("Assets/UI_Sprites/Health_Value.png");
	App->player1->Player_Health_BG_Empty = App->player2->Player_Health_BG_Empty = App->textures->Load("Assets/UI_Sprites/HealthBar_Empty.png");

	//126 = player health texture lenght
	//Do same with App.player2
	App->player1->Player_Health_Value = 126;
	App->player2->Player_Health_Value = 126;

	return true;
}

update_status ModuleUI::Update()
{


	//Draw UI
	//if ((App->render->Blit(graphics, 0, 0, &rect_background)) == false)
	//{
	//	SDL_Log("Unable to [BLIT] texture: texture_background");
	//	return update_status::UPDATE_STOP;
	//}

	//Needs To sTop on fail bliT
	//Timer renderer
	RendPosition = { { 0, 0, 32, 24 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(TimerTexture, SCREEN_WIDTH / 2 - RendPosition.rect.w / 2, 8, &RendPosition, 0);

	//Player 1 Health
	//Render order is really important
	RendPosition = { { 0, 0, 126, 6 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player1->Player_Health_BG_Empty, (SCREEN_WIDTH / 2 - RendPosition.rect.w) - 17, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);
	RendPosition = { { 0, 0, App->player1->Player_Health_Value, 6 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player1->Player_Health, (SCREEN_WIDTH / 2 - RendPosition.rect.w) - 17, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);
	RendPosition = { { 0, 0, 128, 8 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player1->Player_Health_BG, (SCREEN_WIDTH / 2 - RendPosition.rect.w) - 16, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);



	//Player 2 Health BackGround
	RendPosition = { { 0, 0, 126, 6 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player2->Player_Health_BG_Empty, (SCREEN_WIDTH / 2) + 17, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);
	RendPosition = { { 0, 0, App->player2->Player_Health_Value, 6 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player2->Player_Health, (SCREEN_WIDTH / 2 ) + 17, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);
	RendPosition = { { 0, 0, 128, 8 },{ 0, 0 } ,{ 0, 0 } };
	App->render->Blit(App->player2->Player_Health_BG, (SCREEN_WIDTH / 2) + 16, 20 - (RendPosition.rect.h / 2), &RendPosition, 0);




	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp()
{


	//Unload everything

		App->textures->Unload(TimerTexture);
		App->textures->Unload(App->player1->Player_Health_BG);
		App->textures->Unload(App->player1->Player_Health);
		App->textures->Unload(App->player1->Player_Health_BG_Empty);



		App->textures->Unload(App->player2->Player_Health_BG);
		App->textures->Unload(App->player2->Player_Health);
		App->textures->Unload(App->player2->Player_Health_BG_Empty);

	

	LOG("Unloading todo scene");
	return true;
}