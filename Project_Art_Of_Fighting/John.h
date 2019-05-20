#ifndef __JOHN_H__
#define __JOHN_H__

#include "Character.h"
#include "Application.h"
#include "ModuleTextures.h"

struct SDL_Texture;

class John : public Character
{
public:
	John(int player);
	~John() {};
	bool Start() override;
	bool CleanUp() override;

	//Special Move Settings
	int SpecialLenght = 0;
	Special_Move *PlayerSpecialMoves[20];
	inputs Input_Queue[30];
	inputs *FirstInQueue = nullptr;
	inputs *LastInQueue = nullptr;
	int TopPosition = 0;
	int BottomPosition = 0;
	virtual void AddInput(inputs) override;
	virtual inputs CheckCombos() override;
	virtual void AddCombo(int NumberOfInputs, inputs EndState, inputs Inp...)override;
};

#endif // !__RYO_H__
