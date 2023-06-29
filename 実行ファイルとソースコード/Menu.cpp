#include"Menu.h"
#include"input.h"
#include "declaration.h"
#include"Scene.h"
#include "sprite.h"
#include "fade.h"
#include "LoadAllTexture.h"
#include "Game.h"
#include"Texture.h"
#include "sound.h"
#include "SoundManager.h"

int StageCount = 0;
int GradeCount = 0;
int resetCount = 0;
bool resetRock = false;
bool GradeSerect = false;
bool ROCK = false;
void InitMenu()
{
	StageCount = 0;
	GradeCount = 0;
	resetCount = 0;
	resetRock = false;
	GradeSerect = false;
	ROCK = false;

	SetSampleNum(BGM_003, 17640 * 332);
	SetVolume(BGM_003, 0.0f);
	PlaySound(BGM_003, 0);

	SetSampleNum(BGM_002, 17640 * 281);
	SetVolume(BGM_002, 0.0f);
	PlaySound(BGM_002, 0);
	PlaySound(Get_BGM_Inf()[BGM_005].fileNum, -1);
}
bool asjhdj = true;
void UninitMenu()
{
}

void UpdateMenu()
{

	/*if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_CONFIG);
	}*/

	/* if(GetKeyboardTrigger(DIK_SPACE) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_GAME);
	}*/

	//	if (!GradeSerect)//�O���[�h�̑I��false

	if (!resetRock)
	{
		if (IsButtonTriggered(0, XINPUT_GAMEPAD_START) || GetKeyboardTrigger(DIK_1))
		{
			resetRock = true;

		}
		if (!GradeSerect)//�O���[�h�̑I��false
		{

			//�X�e�[�W�̑I�������E�ɓ�����
			if ((IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_DOWN) || GetKeyboardTrigger(DIK_DOWN)) && resetRock == false)
			{
				if (StageCount != 1)
				{
					StageCount += 1;
					PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
					ActionVibration(5, 3);

				}

			}
			else if ((IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_UP) || GetKeyboardTrigger(DIK_UP)) && resetRock == false)
			{
				if (StageCount != 0)
				{
					StageCount -= 1;
					PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
					ActionVibration(5, 3);
				}
			}


			if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_RETURN)) && resetRock == false)
			{
				//��Փx�I���̉�ʂ̕\��
				GradeSerect = true;
				if (ROCK == false)
				{
					ActionVibration(10, 100);
					PlaySound(Get_SE_Inf()[SE_SELECT_OK_1].fileNum, 0);
				}

			}



		}
		else if (GradeSerect)		//�O���[�h�̑I��true
		{
			if (StageCount == 0)
			{
				if ((IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_UP) || GetKeyboardTrigger(DIK_UP)) && resetRock == false)
				{
					if (GradeCount != 0)
					{
						GradeCount -= 1;
						PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
						ActionVibration(5, 3);
					}

				}
				else if ((IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_DOWN) || GetKeyboardTrigger(DIK_DOWN)) && resetRock == false)
				{
					if (GradeCount != 2)
					{
						GradeCount += 1;
						PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
						ActionVibration(5, 3);
					}
				}

			}

			//�Ȃ̑I���ɖ߂�
			if ((IsButtonTriggered(0, XINPUT_GAMEPAD_A) || GetKeyboardTrigger(DIK_SPACE)) && resetRock == false)
			{
				GradeSerect = false;
				GradeCount = 0;
				PlaySound(Get_SE_Inf()[SE_SELECT_BACK_1].fileNum, 0);
			}


			if (ROCK == false)
			{
				if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_RETURN)) && resetRock == false)
				{
					ROCK = true;

					PlaySound(Get_SE_Inf()[SE_SELECT_OK_1].fileNum, 0);
					ActionVibration(10, 255);
					StopSoundAll();
					if (StageCount % 2 == 0 && GradeCount == 0)			//1-1�̏ꍇ
					{
						StageCount = 3;
						//��Փx�̃Z�b�g?�ł���?
						SetStageNum(STAGE1_1);
						SceneTransition(SCENE_GAME);
						GradeCount = 0;
						GradeSerect = false;
					}
					else if (StageCount % 2 == 0 && GradeCount == 1)	//1-2�̏ꍇ
					{
						//��Փx�̃Z�b�g?�ł���?
						StageCount = 3;
						SetStageNum(STAGE1_2);
						SceneTransition(SCENE_GAME);

						GradeCount = 0;
						GradeSerect = false;
					}
					else if (StageCount % 2 == 0 && GradeCount == 2)	//1-3�̏ꍇ
					{
						StageCount = 3;
						//��Փx�̃Z�b�g?�ł���?
						SetStageNum(STAGE1_3);
						SceneTransition(SCENE_GAME);
						GradeCount = 0;
						GradeSerect = false;
					}

					//===============================�X�e�[�W�̑I��2-1��2-2====================================//
					//else if (StageCount % 2 == 1 && GradeCount == 0)	//2-1�̏ꍇ
					//{
					//		StageCount = 3;
					//		//��Փx�̃Z�b�g?�ł���?
					//		SetStageNum(STAGE2_1);
					//		SceneTransition(SCENE_GAME);
					//		GradeCount = 0;
					//		GradeSerect = false;
					//}
					//else if (StageCount % 2 == 1 && GradeCount == 2)	//2-2�̏ꍇ
					//{
					// StageCount = 3;
					//	//��Փx�̃Z�b�g?�ł���?
					//	SetStageNum(STAGE2_2);
					//	SceneTransition(SCENE_GAME);
					//	GradeCount = 0;
					//	GradeSerect = false;
					//}
					else if (StageCount % 2 == 1 /*&& GradeCount == 2*/)	//2-3�̏ꍇ
					{
						StageCount = 3;
						//��Փx�̃Z�b�g?�ł���?
						SetStageNum(STAGE2_3);
						SceneTransition(SCENE_GAME);
						GradeCount = 0;
						GradeSerect = false;
					}

				}
			}

		}

	}
	else
	{
		if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_DOWN) || GetKeyboardTrigger(DIK_DOWN))
		{
			if (resetCount != 1)
			{
				resetCount += 1;
				PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
				ActionVibration(5, 3);

			}

		}
		else if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_UP) || GetKeyboardTrigger(DIK_UP))
		{
			if (resetCount != 0)
			{
				resetCount -= 1;
				PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
				ActionVibration(5, 3);
			}
		}


		if (IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_RETURN))
		{
			if (resetCount == 0)
			{
				PostQuitMessage(0);
			}
			else
			{
				resetCount = 0;
				resetRock = false;
			}

		}

	}



}

void DrawMenu()
{
	DrawSprite(
		GetSceneTexture(SCENE_MENU)->fileNum,
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0.0f,
		0.0f,
		1.0f,
		1.0f
	);

	if (!resetRock)
	{
		if (StageCount == 0 || StageCount == 1)
		{
			DrawSprite(
				LoadTexture("data/TEXTURE/BG/StageSelect.png"),
				(SCREEN_WIDTH / 4) * 3,
				(SCREEN_HEIGHT / 5),
				SCREEN_WIDTH / 3,
				SCREEN_HEIGHT / 3,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);


			if (!GradeSerect)//�X�e�[�W�I���̎�
			{
				if (StageCount == 0 || StageCount == 1)
				{

					if (StageCount % 2 == 0)//�X�e�[�W�I��1�̎�
					{
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/Menu_S1_S.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 5) * 2,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/Menu_S2.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 5) * 4,
							SCREEN_WIDTH / 5,
							SCREEN_HEIGHT / 5,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
					}
					else//�X�e�[�W�I����2�̎�
					{
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/Menu_S1.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 5) * 2,
							SCREEN_WIDTH / 5,
							SCREEN_HEIGHT / 5,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/Menu_S2_S.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 5) * 4,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
					}
				}
			}
			//<<<<<<< HEAD
			//	}
			//	else if (GradeSerect)//��Փx�I���̏ꍇ
			//	{
			//		DrawSprite(
			//			LoadTexture("data/TEXTURE/BG/StageSelect2.png"),
			//			(SCREEN_WIDTH / 4) * 3,
			//			SCREEN_HEIGHT / 3 / 2,
			//			SCREEN_WIDTH / 3,
			//			SCREEN_HEIGHT / 3,
			//			0.0f,
			//			0.0f,
			//			1.0f,
			//			1.0f
			//		);
			//
			//		if (GradeCount == 0)//��ՓxEASY�̎�
			//		{
			//			DrawSprite(
			//				LoadTexture("data/TEXTURE/BG/EASY_1_S.png"),
			//				(SCREEN_WIDTH / 4) * 3,
			//				SCREEN_HEIGHT / 4 + 150.0f,
			//				SCREEN_WIDTH / 3,
			//				SCREEN_HEIGHT / 3,
			//				0.0f,
			//				0.0f,
			//				1.0f,
			//				1.0f
			//			);
			//			DrawSprite(
			//				LoadTexture("data/TEXTURE/BG/NORMAL_1.png"),
			//				(SCREEN_WIDTH / 4) * 3,
			//				(SCREEN_HEIGHT / 4) * 2 + 150.0f,
			//				SCREEN_WIDTH / 4,
			//				SCREEN_HEIGHT / 4,
			//				0.0f,
			//				0.0f,
			//				1.0f,
			//				1.0f
			//			);
			//=======
			else if (GradeSerect)//��Փx�I���̏ꍇ
			{
				if (StageCount == 0)
				{
					if (GradeCount == 0)//��ՓxEASY�̎�
					{
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/EASY_1_S.png"),
							(SCREEN_WIDTH / 4) * 3,
							SCREEN_HEIGHT / 4,
							SCREEN_WIDTH / 3,
							SCREEN_HEIGHT / 3,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/NORMAL_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 2,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);

						DrawSprite(
							LoadTexture("data/TEXTURE/BG/HARD_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 3,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
					}
					if (GradeCount == 1)//��ՓxNORMAL�̎�
					{
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/EASY_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							SCREEN_HEIGHT / 4,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);


						DrawSprite(
							LoadTexture("data/TEXTURE/BG/NORMAL_1_S.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 2,
							SCREEN_WIDTH / 3,
							SCREEN_HEIGHT / 3,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/HARD_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 3,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
					}
					else if (GradeCount == 2)//HARD�̏ꍇ
					{
						DrawSprite(
							LoadTexture("data/TEXTURE/BG/EASY_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							SCREEN_HEIGHT / 4,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);

						DrawSprite(
							LoadTexture("data/TEXTURE/BG/NORMAL_1.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 2,
							SCREEN_WIDTH / 4,
							SCREEN_HEIGHT / 4,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);

						DrawSprite(
							LoadTexture("data/TEXTURE/BG/HARD_1_S.png"),
							(SCREEN_WIDTH / 4) * 3,
							(SCREEN_HEIGHT / 4) * 3,
							SCREEN_WIDTH / 3,
							SCREEN_HEIGHT / 3,
							0.0f,
							0.0f,
							1.0f,
							1.0f
						);
					}
				}
				else if (StageCount == 1)
				{

					DrawSprite(
						LoadTexture("data/TEXTURE/BG/HARD_1_S.png"),
						(SCREEN_WIDTH / 4) * 3,
						SCREEN_HEIGHT / 2,
						SCREEN_WIDTH / 2,
						SCREEN_HEIGHT / 2,
						0.0f,
						0.0f,
						1.0f,
						1.0f
					);

				}




			}
		}
		else//resetRock��true�̎�
		{
			DrawSprite(
				LoadTexture("data/TEXTURE/BG/reset_game.png"),
				SCREEN_WIDTH / 2,
				200.0f,
				800.0f,
				160.0f,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);

			if (resetCount == 0)//�n�C���I��
			{
				DrawSprite(
					LoadTexture("data/TEXTURE/BG/reset_yes_s.png"),
					SCREEN_WIDTH / 2,
					SCREEN_HEIGHT / 3 + 200.0f,
					SCREEN_WIDTH / 3,
					SCREEN_HEIGHT / 3,
					0.0f,
					0.0f,
					1.0f,
					1.0f
				);

				DrawSprite(
					LoadTexture("data/TEXTURE/BG/reset_no.png"),
					SCREEN_WIDTH / 2,
					(SCREEN_HEIGHT / 3) * 2 + 200.0f,
					SCREEN_WIDTH / 3,
					SCREEN_HEIGHT / 3,
					0.0f,
					0.0f,
					1.0f,
					1.0f
				);
				DrawSprite(
					LoadTexture("data/TEXTURE/BG/HARD_1.png"),
					(SCREEN_WIDTH / 4) * 3,
					(SCREEN_HEIGHT / 4) * 3 + 150.0f,
					SCREEN_WIDTH / 4,
					SCREEN_HEIGHT / 4,
					0.0f,
					0.0f,
					1.0f,
					1.0f
				);
			}
			else//���������I��
			{
				DrawSprite(
					LoadTexture("data/TEXTURE/BG/reset_yes.png"),
					SCREEN_WIDTH / 2,
					SCREEN_HEIGHT / 3 + 200.0f,
					SCREEN_WIDTH / 3,
					SCREEN_HEIGHT / 3,
					0.0f,
					0.0f,
					1.0f,
					1.0f
				);

				DrawSprite(
					LoadTexture("data/TEXTURE/BG/reset_no_s.png"),
					SCREEN_WIDTH / 2,
					(SCREEN_HEIGHT / 3) * 2 + 200.0f,
					SCREEN_WIDTH / 3,
					SCREEN_HEIGHT / 3,
					0.0f,
					0.0f,
					1.0f,
					1.0f
				);

			}

		}

	}
}