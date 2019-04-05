#ifndef __ModuleDebug_H__
#define __ModuleDebug_H__
#include "Module.h"
#include "Globals.h"
#include "RectSprites.h"
#include "SDL_image/include/SDL_image.h"
#include "Animation.h"

class ModuleDebug : public Module {
public:
	RectSprites point;
	
	Animation idle;

	SDL_Texture * graphic;
	SDL_Texture * graphic_player;
	iPoint square_pos;


public:

	bool Init() override;
	update_status Update() override;
	bool CleanUp() override;

	void ShowDebug(iPoint *);

};

#endif // !__ModuleDebug_H__