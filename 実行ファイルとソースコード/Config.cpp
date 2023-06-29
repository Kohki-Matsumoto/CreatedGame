#include "Config.h"
#include "declaration.h"
#include "Scene.h"
#include "input.h"
#include "sprite.h"
#include "fade.h"
#include "LoadAllTexture.h"

void InitConfig()
{
}

void UninitConfig()
{
}

void UpdateConfig(void)
{
	
		if (GetKeyboardTrigger(DIK_SPACE) && GetFadeState() == FADE_NONE)
		{
			SceneTransition(SCENE_MENU);
		}

}

void DrawConfig(void)
{
	DrawSprite(
		GetPlayerAniTexture(JUMP)->fileNum,
		SCREEN_HEIGHT/3,
		SCREEN_WIDTH/3,
		SCREEN_HEIGHT,
		SCREEN_WIDTH,
		0.0f,
		0.0f,
		1.0f,
		1.0f
	);

}

