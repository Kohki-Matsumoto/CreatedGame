#include "Title.h"
#include "input.h"
#include "scene.h"
#include "declaration.h"
#include "sprite.h"
#include "main.h"
#include "fade.h"
#include "Texture.h"
#include "LoadAllTexture.h"
#include "SoundManager.h"
#include "sound.h"

int FrameCount = 0;
int MoveCount = 0;
bool anybotton = false;
bool Movechar = false;
bool MoreRock = false;
D3DXCOLOR g_fade;
D3DXCOLOR g_color;

void InitTitle()
{
	FrameCount = 0;
	MoveCount = 0;
	MoreRock = false;
	anybotton = false;
	Movechar = false;
	g_fade = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

void UninitTitle()
{
}

void UpdateTitle(void)
{

	if (FrameCount == 0)
	{
		PlaySound(Get_BGM_Inf()[BGM_005].fileNum, -1);
	}

	FrameCount++;
	if (!MoreRock)
	{
		if (FrameCount >= 360)
		{
			if( (IsButtonTriggered(0, XINPUT_GAMEPAD_B)|| IsButtonTriggered(0, XINPUT_GAMEPAD_A) || IsButtonTriggered(0, XINPUT_GAMEPAD_X) || IsButtonTriggered(0, XINPUT_GAMEPAD_Y) || GetKeyboardTrigger(DIK_SPACE)) && GetFadeState() == FADE_NONE)
			{
				SceneTransition(SCENE_MENU);
				PlaySound(Get_SE_Inf()[SE_TITLE_1].fileNum, 0);
				ActionVibration(10, 255);
				MoreRock = true;
				
			}
		}
	}

}

void DrawTitle(void)
{
	if (FrameCount <= 300)//フレームが300カウントより低いとき
	{

		if (FrameCount >= 200)
		{
			g_color.a -= 0.015f;
		}

		/*if (FrameCount <= 100)
		{
			MoveCount ++ ;
		}
		if (FrameCount >= 160)
		{
			MoveCount++;
		}*/


		DrawSprite(
			LoadTexture("data/TEXTURE/BG/Black_001.png"),
			SCREEN_WIDTH / 2,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);

		NewDrawSprite(
			LoadTexture("data/TEXTURE/BG/Title_logo.png"),
			SCREEN_WIDTH / 2 /*- 10.0f * MoveCount*/,
			SCREEN_HEIGHT / 2,
			800.0f,
			800.0f,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			g_color
		);


	}
	else//フレームが300カウント以降の場合
	{


		if (!Movechar)
		{
			MoveCount += 1;
			if (MoveCount == 100)
			{
				Movechar = true;
			}
		}
		else if (Movechar)
		{

			MoveCount -= 1;
			if (MoveCount == 0)
			{
				Movechar = false;
			}
		}

		DrawSprite(
			GetSceneTexture(SCENE_TITLE)->fileNum,
			SCREEN_WIDTH / 2,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);
		DrawSprite(
			LoadTexture("data/TEXTURE/BG/TItle_Char_002.png"),
			SCREEN_WIDTH - 500.0f,
			(SCREEN_HEIGHT / 2) - 70.0f + 1.0f * MoveCount,
			950.0f,
			1050.0f,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);

		if (g_fade.a <= 0.0f)
		{
			anybotton = false;
		}
		else if (g_fade.a >= 1.0f)
		{
			anybotton = true;
		}


		if (anybotton)
		{
			g_fade.a -= 0.025f;
		}
		else
		{
			g_fade.a += 0.025f;
		}
		NewDrawSprite(
			LoadTexture("data/TEXTURE/EF/PRESS.png"),
			SCREEN_WIDTH / 4 + 50.0f,
			(SCREEN_HEIGHT / 4) * 3,
			SCREEN_WIDTH / 2,
			SCREEN_HEIGHT / 10,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			g_fade
		);


	}
}

