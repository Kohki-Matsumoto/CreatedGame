#include "Game.h"
#include "Player.h"
#include "Field.h"
#include "input.h"
#include "Gravity.h"
#include "sound.h"
#include "score.h"
#include "fade.h"
#include "EF_RhythmJudge.h"
#include "Effect.h"

//以下一時的なincludeです
#include "Texture.h"
#include "sprite.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Collision.h"



#include <Windows.h>

#ifdef _DEBUG
int hConsole = 0;
FILE* out = 0;
FILE* in = 0;
HANDLE Console;
COORD CursorPos;

#endif

PLAYER* p_Player;
FIELD* p_Field;

KEYNUM g_keynum;

static int g_SE_001 = 0;
static int g_BGM_Num = 0;
int g_CompareWithBlock = 0;
static int g_BlockCount = 0;
int g_treecount = 0;


int temprythmcount = 0;

STAGE1_3_PLACEMENT_FIELD g_testtesttest;
STAGE1_2_PLACEMENT_FIELD g_testtesttest_2;
STAGE1_1_PLACEMENT_FIELD g_testtesttest_1;

STAGE2_3_PLACEMENT_FIELD g_Stage2_3;

STAGE_NAME g_Stage_Name;
int g_Game_maxField = 0;

SOUND_BGM_NUM g_PlayBGMnum = BGM_001;

int EFhanntei = 0;
int efkannkei = 0;

bool efhannteisnokata = false;
bool g_Gamepause = false;
float g_GamePause_SampleNum = 0.0f;

UINT64 framecount = 0;
bool testtest = false;
int framenum = 0;


int ReceptionTime_A = RECEPTION_MAX_TIME + 1;
int ReceptionTime_B = RECEPTION_MAX_TIME + 1;
int ReceptionTime_X = RECEPTION_MAX_TIME + 1;
int ReceptionTime_Y = RECEPTION_MAX_TIME + 1;

int circlenum[5][2];
int PozeCount = 0;

int wazaFrame = 0;
bool wazaRock = false;
D3DXCOLOR g_wazaColor;


//現在のサンプルレートを保存するための変数
long int ositataiminngu = 0;

float FrequencyFrame = 0.0f;
bool PlayerDied = false;
bool GameStartCheck = false;
int GameOverCount = 0;
int GameStartCount = 0;
float g_ReadySpeed = 0.0f;
bool GameStartCountKeep = false;

int GameClearCount = 0;
bool GameClearCheck = false;
int SceneChangeTime = 0;

bool CenterReady = false;
bool ReadyCheck = false;

bool g_stage2_bool = false;

bool PozeCheck = false;
int updatevaibrationframecount = 0;//毎テンポコントローラーを振動させるためのフレームカウント
void InitGame(void)
{
	InitEffect();
	//StopSoundAll();

	g_SE_001 = 0;
	g_BGM_Num = 0;
	g_CompareWithBlock = 0;
	g_BlockCount = 0;
	g_treecount = 0;
	EFhanntei = 0;
	efkannkei = 0;

	efhannteisnokata = false;
	g_Gamepause = false;
	g_GamePause_SampleNum = 0.0f;

	framecount = 0;
	testtest = false;
	framenum = 0;
	ositataiminngu = 0;
	//ゲーム始めゲームオーバー時のグローバル変数
	FrequencyFrame = 0.0f;
	PlayerDied = false;
	GameStartCheck = false;
	GameOverCount = 0;
	GameStartCount = 0;
	g_ReadySpeed = 0.0f;
	GameStartCountKeep = false;
	GameClearCount = 0;
	GameClearCheck = false;
	SceneChangeTime = 0;

	CenterReady = false;
	ReadyCheck = false;
	//

	g_stage2_bool = false;

	updatevaibrationframecount = 0;//毎テンポコントローラーを振動させるためのフレームカウント
	PozeCount = 0;
	PozeCheck = false;

	wazaFrame = 0;
	wazaRock = false;
	g_wazaColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);


	ReceptionTime_A = RECEPTION_MAX_TIME + 1;
	ReceptionTime_B = RECEPTION_MAX_TIME + 1;
	ReceptionTime_X = RECEPTION_MAX_TIME + 1;
	ReceptionTime_Y = RECEPTION_MAX_TIME + 1;
	for (int i = 0; i < 5; i++)
	{
		circlenum[i][0] = 0;
		circlenum[i][1] = 0;
	}

	InitScore();
	InitEF_RhythmJudge();

	switch (g_Stage_Name)
	{
	case STAGE1_1:
		g_PlayBGMnum = BGM_002;
		g_Game_maxField = g_testtesttest_1.m_max_Fieldnum;
		break;
	case STAGE1_2:
		g_PlayBGMnum = BGM_002;
		g_Game_maxField = g_testtesttest_2.m_max_Fieldnum;
		break;
	case STAGE1_3:
		g_PlayBGMnum = BGM_002;
		g_Game_maxField = g_testtesttest.m_max_Fieldnum;
		break;
	case STAGE2_1:
		g_PlayBGMnum = BGM_003;
		break;
	case STAGE2_2:
		g_PlayBGMnum = BGM_003;
		break;
	case STAGE2_3:
		g_PlayBGMnum = BGM_003;
		g_Game_maxField = g_Stage2_3.m_max_Fieldnum;
		break;
	}

	p_Player = new PLAYER;
	p_Field = new FIELD[g_Game_maxField + 3];

	p_Player->InitPlayer();

	if (g_PlayBGMnum == BGM_002)
	{
		p_Player->SetPlayerPos(MakeFloat2(500.0f, 800.0f));
		p_Player->SetPlayerSpeed(MakeFloat2(19.0464f, 0.0f));
		p_Player->SetPlayerSize(MakeFloat2(200.0f, 200.0f));
	}
	else
	{
		p_Player->SetPlayerPos(MakeFloat2(500.0f, 800.0f));
		p_Player->SetPlayerSpeed(MakeFloat2(21.0f, 0.0f));
		p_Player->SetPlayerSize(MakeFloat2(200.0f, 200.0f));
	}



	if (g_PlayBGMnum == BGM_002)
	{

		p_Field[0].SetFieldPos(MakeFloat2((23274.7008f + (float)SCREEN_WIDTH / 2.0f) / 2.0f, (float)SCREEN_HEIGHT));
		p_Field[0].SetFieldSize(MakeFloat2((23274.7008f + (float)SCREEN_WIDTH / 2.0f), 300.0f));
		p_Field[0].SetFieldTexNum(&GetFieldTextureInf(W1_S1_002)->fileNum);

		p_Field[1].SetFieldPos(MakeFloat2((495.2064f * 99.0f - 495.2064f * 49.0f) / 2.0f + 23274.7008f + (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT));
		p_Field[1].SetFieldSize(MakeFloat2(495.2064f * 50, 300.0f));
		p_Field[1].SetFieldTexNum(&GetFieldTextureInf(W1_S1_002)->fileNum);

		p_Field[2].SetFieldPos(MakeFloat2((495.2064f * 99.0f - 495.2064f * 49.0f) / 2.0f + 23274.7008f + (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT));
		p_Field[2].SetFieldSize(MakeFloat2(495.2064f * 50, 300.0f));
		p_Field[2].SetFieldTexNum(&GetFieldTextureInf(W1_S1_002)->fileNum);
	}

	SetSampleNum(g_PlayBGMnum, 0);
	PlayerStatusChangeForStage();
}

//g_testtesttest
void UnInitGame(void)
{
	StopSoundAll();
	delete[] p_Field;
	delete p_Player;
	UninitEF_RhythmJudge();
	UninitScore();
}

void UpdateGame(void)
{


	if (wazaRock)//技が発動したら入る
	{
		wazaFrame++;
		g_wazaColor.a -= 0.06;
		if (wazaFrame == 20)//発動後20フレームで初期化
		{
			g_wazaColor.a = 1.0f;
			wazaFrame = 0;
			wazaRock = false;
		}

	}
	GameStart();


	if (GameStartCheck)
	{
		if (IsButtonTriggered(0, XINPUT_GAMEPAD_START) || GetKeyboardTrigger(DIK_1))
		{
			GamePause(true);
			PozeCheck = true;
			PlaySound(Get_SE_Inf()[SE_TITLE_1].fileNum, 0);
		}
	}

	if (PozeCheck)
	{
		if (PozeCount % 2 == 0)
		{
			if (IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_2))
			{
				GamePause(false);
				PozeCheck = false;
				PlaySound(Get_SE_Inf()[SE_SELECT_OK_1].fileNum, 0);
			}
		}
		else
		{
			if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_2)) && PozeCheck == true)
			{
				SceneTransition(SCENE_MENU);
				GamePause(false);
				PozeCheck = false;
				PlaySound(Get_SE_Inf()[SE_SELECT_OK_1].fileNum, 0);
			}
		}

		if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_DOWN) || GetKeyboardTrigger(DIK_DOWN))
		{
			PozeCount += 1;
			PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);

		}
		if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_UP) || GetKeyboardTrigger(DIK_UP))
		{
			PozeCount += 1;
			PlaySound(Get_SE_Inf()[SE_SELECT_1].fileNum, 0);
		}
	}

	if (p_Player->GetPlayerPos().x <= 250.0f)
	{
		ResetCombo();
	}

	if (!g_Gamepause)
	{
		if (g_PlayBGMnum == BGM_002)
		{

			p_Field[0].SetFieldPos(MakeFloat2((SCREEN_WIDTH / 2.0f), (float)SCREEN_HEIGHT));
			p_Field[0].SetFieldSize(MakeFloat2((SCREEN_WIDTH)+300.0, 300.0f));
		}

		POINT point;
		GetCursorPos(&point);
		ScreenToClient(GetWindowInf(), &point);

		if (IsButtonTriggered(0, XINPUT_GAMEPAD_BACK) || GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
		{
			SceneTransition(SCENE_RESULT);
		}
		if (p_Player->GetPlayerPos().x < p_Player->GetPlayerSize().x / 2.0f || SCREEN_HEIGHT < p_Player->GetPlayerPos().y - p_Player->GetPlayerSize().y )
		{
			SetFrequency(Get_BGM_Inf()[g_PlayBGMnum].fileNum, 1.0f - FrequencyFrame);
			p_Player->SetPlayerOnGravity(false);
			p_Player->SetPlayerPos(MakeFloat2(-1000.0f, -1000.0f));
			p_Player->SetPlayerSize(MakeFloat2(0.0f, 0.0f));
			FrequencyFrame += 0.01f;
			if (!(FrequencyFrame * 100 * p_Player->GetPlayerSpeed().x + SCREEN_WIDTH / 2.0f > SCREEN_WIDTH))
				GameOverCount++;
			if (FrequencyFrame >= 1.0f)
			{
				if (Get_BGM_Inf()[g_PlayBGMnum].fileNum == BGM_002)
				{
					SetSampleNum(g_PlayBGMnum, Get_BGM_Inf()[g_PlayBGMnum].samplenum * 281);
				}
				else if (Get_BGM_Inf()[g_PlayBGMnum].fileNum == BGM_003)
				{
					SetSampleNum(g_PlayBGMnum, Get_BGM_Inf()[g_PlayBGMnum].samplenum * 330);
				}


				SetFrequency(Get_BGM_Inf()[1].fileNum, 1.0f);
				SetFrequency(Get_BGM_Inf()[2].fileNum, 1.0f);
				PlaySound(Get_BGM_Inf()[g_PlayBGMnum].fileNum, 0);
				SceneTransition(SCENE_RESULT);
			}

			PlayerDied = true;
		}

		//===================================================
		//===================================================
		PushButton();


		p_Player->AddPlayerFrame(p_Player->m_PlayerStatus);

		//現在のサンプル数を取得
		ositataiminngu = GetSourceSample(Get_BGM_Inf()[g_PlayBGMnum].fileNum);
		//1テンポの判定範囲を超えた時に次の判定に移る処理
		if (ositataiminngu > Get_BGM_Inf()[g_PlayBGMnum].samplenum * efkannkei + Get_BGM_Inf()[g_PlayBGMnum].samplenum * 0.5f)
		{
			efkannkei++;
		}


		//1テンポごとにコントローラーを揺らす処理
		if (ositataiminngu > (Get_BGM_Inf()[g_PlayBGMnum].samplenum) * updatevaibrationframecount)
		{
			// AddComboScore(1);
			ActionVibration(5, 50 + (int)((float)updatevaibrationframecount * 0.1f));
			updatevaibrationframecount += 1;
			temprythmcount = 10;
		}

		p_Player->SetPlayertempnum(efkannkei);
		p_Player->SetPlayerNowSampleNum(ositataiminngu);
		p_Player->UpdatePlayer();


		if ((int)((float)ositataiminngu / (float)Get_BGM_Inf()[g_PlayBGMnum].samplenum) >= *GetStageRhythm(g_CompareWithBlock) - 4)
		{
			g_CompareWithBlock++;
			for (int i = 0; i < 4; i++)
			{

				circlenum[4 - i][0] = circlenum[3 - i][0];
				circlenum[4 - i][1] = circlenum[3 - i][1];
			}
			circlenum[0][1] = 1;
			circlenum[0][0] = 0;
		}

		if (circlenum[4][1] == 1)
		{
			int a = 0;
		}

		if (g_PlayBGMnum == BGM_002)
		{
			if ((float)GetSourceSample(Get_BGM_Inf()[g_PlayBGMnum].fileNum) / (float)Get_BGM_Inf()[g_PlayBGMnum].samplenum >= *GetStageFieldTemp(g_BlockCount) - 4.0f && g_BlockCount < g_Game_maxField)
			{

				p_Field[g_BlockCount + 2].SetFieldTexNum(&GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fileNum);

				if (*GetStageFieldTexNum(g_BlockCount) == W1_S1_005)
				{
					p_Field[g_BlockCount + 2].SetFieldPos(MakeFloat2((float)SCREEN_WIDTH / 2.0f + 495.2064f * 4 - 50.0f + GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.x / 2.0f, (float)SCREEN_HEIGHT - 150.0f - GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.y / 2.0f - (float)*GetStageFieldHigh(g_BlockCount) * 220.0f + 40.0f));

				}
				else
				{
					p_Field[g_BlockCount + 2].SetFieldPos(MakeFloat2((float)SCREEN_WIDTH / 2.0f + 495.2064f * 4 - 50.0f + GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.x / 2.0f, (float)SCREEN_HEIGHT - 150.0f - GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.y / 2.0f/* - (float)*GetStageFieldHigh(g_BlockCount) * 190.0f*/));

				}
				p_Field[g_BlockCount + 2].SetFieldSize(GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize);
				g_BlockCount++;
			}
		}
		else if (g_PlayBGMnum == BGM_003)
		{
			if (!g_stage2_bool || g_BlockCount > MAX_STAGE_2_3FIELD - 1)
			{
				p_Field[0].SetFieldPos(MakeFloat2((2016.0f + (float)SCREEN_WIDTH / 2.0f) / 2.0f, (float)SCREEN_HEIGHT - 40.0));
			}
			p_Field[0].SetFieldSize(MakeFloat2(2016.0f + (float)SCREEN_WIDTH / 2.0f, 220.0f));
			p_Field[0].SetFieldTexNum(&GetFieldTextureInf(W1_S2_001)->fileNum);
			if ((float)GetSourceSample(Get_BGM_Inf()[g_PlayBGMnum].fileNum) / (float)Get_BGM_Inf()[g_PlayBGMnum].samplenum >= *GetStageFieldTemp(g_BlockCount) - 4.0f && g_BlockCount < g_Game_maxField)
			{
				g_stage2_bool = true;
				p_Field[g_BlockCount + 1].SetFieldTexNum(&GetFieldTextureInf(W1_S2_001)->fileNum);


				if (*GetStageFieldTexNum(g_BlockCount) == W1_S1_005)
				{
					p_Field[g_BlockCount + 1].SetFieldPos(MakeFloat2((float)SCREEN_WIDTH / 2.0f + 504.0f * 4 - 150.0f + GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.x / 2.0f, (float)SCREEN_HEIGHT - 150.0f - GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.y / 2.0f - (float)*GetStageFieldHigh(g_BlockCount) * 220.0f + 40.0f));

				}
				else
				{
					p_Field[g_BlockCount + 1].SetFieldPos(MakeFloat2((float)SCREEN_WIDTH / 2.0f + 504.0f * 4 - 150.0f + GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.x / 2.0f, (float)SCREEN_HEIGHT - 150.0f - GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize.y / 2.0f - (float)*GetStageFieldHigh(g_BlockCount) * 220.0f));

				}
				p_Field[g_BlockCount + 1].SetFieldSize(GetFieldTextureInf(*GetStageFieldTexNum(g_BlockCount))->fieldsize);
				g_BlockCount++;
			}
		}


		//先行入力の受付
		Playertransition();



		if (GetGravityStrength__test() > 0.1f && (p_Player->GetPlayerStatus() == SLIDING || p_Player->GetPlayerStatus() == DEFAULT))
		{
			p_Player->SetPlayerOnGravity(true);
			p_Player->UpdateAnim(FALL);
		}



		p_Player->Dojump();
		p_Player->DoRotation();
		p_Player->Dosliding();

		Gravity(p_Player);

		for (int i = 0; i < g_Game_maxField; i++)
			ResetGravity(p_Player, &p_Field[i]);
		NowPlayerSky(p_Player);

		p_Player->AddPlayerSpeed();

		//初期値からずれたプレイヤーをゆっくり元の位置に戻す処理
		if (p_Player->GetPlayerPos().x < 500.0f)
		{
			p_Player->SetPlayerPos(MakeFloat2(p_Player->GetPlayerPos().x + 4.0f, p_Player->GetPlayerPos().y));
		}

		for (int i = 0; i < g_Game_maxField; i++)
		{
			//if (i != 0)
			p_Field[i].SetFieldPos(MakeFloat2(p_Field[i].GetFieldPos().x + (p_Player->GetPlayerSpeed().x * -1.0f), p_Field[i].GetFieldPos().y));
		}

		p_Player->ChangePlayerSize();

		//p_Player->SetPlayerStatus(p_Player->m_PlayerStatus);


		p_Player->KeepSlidingSwitch = false;



		GameResultProcess();

		for (int i = 0; i < g_Game_maxField; i++)
		{
			PushOutPlayer(p_Player, &p_Field[i]);
			KeepSliding(p_Player, &p_Field[i]);
		}

		PushOutPlayer(p_Player, &p_Field[0]);


		p_Player->SetPlayerBefPos(p_Player->GetPlayerPos());

		g_treecount++;
		if (g_treecount > 200)
		{
			g_treecount = 0;
		}
		framecount++;

		//UpdateEF_RhythmJudge();
		UpdateEffect();
		UpdateScore();
	}
	else              //ポーズ中の更新処理を書く場所
	{
		if (GetKeyboardTrigger(DIK_SPACE))
		{
			SceneTransition(SCENE_MENU);
		}
	}
}


int sdiiisaoasfk = 0;
int a = 0, b = 0;


void DrawGame(void)
{
	if (g_PlayBGMnum == BGM_002)
	{
		DrawSprite(*GetBGTextureInf(BG_001), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(*GetBGTextureInf(BG_004), (float)5760 / 2.0f - 0.52559540104024089789214344374487f * (float)framecount, (float)SCREEN_HEIGHT / 2.0f - 50.0f, 5760, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(*GetBGTextureInf(BG_003), (float)5760 / 2.0f - 0.52559540104024089789214344374487f * (float)framecount * 3.0f, (float)SCREEN_HEIGHT / 2.0f - 50.0f, 5760, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(*GetBGTextureInf(BG_002), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f + 0.005f * (float)framecount, 0.0f, 0.29574861367837338262476894639556f, 1.0f);
		//DrawSprite(*GetBGTextureInf(BG_001), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, p_Player->GetPlayerSize().x, p_Player->GetPlayerSize().y, 0.0f, 0.0f, 1.0f, 1.0f);

		DrawSprite(*GetBGTextureInf(BG_005), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT - 225.0f, SCREEN_WIDTH, 150.0f, 0.0f + 0.00992f * (float)framecount, 0.0f, 1.0f, 1.0f);
	}
	else if (g_PlayBGMnum == BGM_003)
	{
		DrawSprite(LoadTexture("data/TEXTURE/BG/Future_3.png"), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(LoadTexture("data/TEXTURE/BG/Future_2.png"), (float)5760 / 2.0f - 0.52559540104024089789214344374487f * (float)framecount, (float)SCREEN_HEIGHT / 2.0f - 50.0f, 5760, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(LoadTexture("data/TEXTURE/BG/Future_1.png"), (float)5760 / 2.0f - 0.52559540104024089789214344374487f * (float)framecount * 3.0f, (float)SCREEN_HEIGHT / 2.0f - 50.0f, 5760, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(LoadTexture("data/TEXTURE/BG/Future_4.png"), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f + 0.005f * (float)framecount, 0.0f, 0.29574861367837338262476894639556f, 1.0f);
		//DrawSprite(*GetBGTextureInf(BG_001), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, p_Player->GetPlayerSize().x, p_Player->GetPlayerSize().y, 0.0f, 0.0f, 1.0f, 1.0f);

		//DrawSprite(*GetBGTextureInf(BG_005), (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT - 225.0f, SCREEN_WIDTH, 150.0f, 0.0f + 0.00992f * (float)framecount, 0.0f, 1.0f, 1.0f);
	}
	else
	{

	}


	if (GameStartCheck == true)
	{
		DrawSpriteColorRotate(
			LoadTexture("data/TEXTURE/EF/GO_1.png"),
			SCREEN_WIDTH - g_ReadySpeed + SCREEN_WIDTH / 2.0f + SCREEN_WIDTH / 2.0f + SCREEN_WIDTH / 2.0f,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH / 3 * 2,
			SCREEN_HEIGHT / 2,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			0.0f
		);
	}

	p_Player->DrawPlayer(p_Player->m_PlayerStatus);


	for (int i = 0; i < g_Game_maxField; i++)
	{
		if (!OffField(&p_Field[i]))
			p_Field[i].DrawField();
	}

	if (g_PlayBGMnum == BGM_002)
		DrawSprite(*GetBGTextureInf(BG_006), (float)SCREEN_WIDTH * 2.0f - 19.0464f * (float)g_treecount * 1.1f, (float)SCREEN_HEIGHT - 400.0f, 842.0f, 859.0f, 0.0f, 0.0f, 1.0f, 1.0f);


	//	if (efhannteisnokata)
	{
		if (sdiiisaoasfk > 10)
		{
			sdiiisaoasfk = 0;
			efhannteisnokata = false;
		}
	}


	switch (p_Player->Getg_Playertmpnum())
	{
	case JUMP_JUMP:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/JUMP_JUMP.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	//	break;
	//case JUMP_JUMP_JUMP:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/JUMPJUMP_JUMP.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	//	break;
	//case JUMP_ROTATION:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/JUMP_ROTATE.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	//	break;
	//case SLIDING_JUMP:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/SLIDING_JUMP.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	//	break;
	//case SLIDING_JUMP_ROTATION:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/SLIDING_JUMP_ROTATE.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	//	break;
	//case JUMP_JUMP_ROTATION:
	//	DrawSprite(LoadTexture("data/TEXTURE/EF/JUMPJUMP_ROTATE.png"), 250.0f, 450.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/JUMP_JUMP.png"), 300.0f , 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);
		break;
	case JUMP_JUMP_JUMP:
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/JUMPJUMP_JUMP.png"), 300.0f, 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);

		break;
	case JUMP_ROTATION:
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/JUMP_ROTATE.png"), 300.0f, 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);

		break;
	case SLIDING_JUMP:
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/SLIDING_JUMP.png"), 300.0f, 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);

		break;
	case SLIDING_JUMP_ROTATION:
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/SLIDING_JUMP_ROTATE.png"), 300.0f, 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);

		break;
	case JUMP_JUMP_ROTATION:
		wazaRock = true;
		NewDrawSprite(LoadTexture("data/TEXTURE/EF/JUMPJUMP_ROTATE.png"), 300.0f, 300.0f, 500.0f + 20.0f * wazaFrame, 300.0f + 20.0f * wazaFrame, 0.0f, 0.0f, 1.0f, 1.0f, g_wazaColor);
		break;
	}


	DrawSprite(LoadTexture("data/TEXTURE/EF/ringA.png"), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, 300.0f + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 300.0f + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 0.0f, 0.0f, 1.0f, 1.0f);


	for (int i = 0; i < 4; i++)
	{
		if (circlenum[i][1] == 1)
		{
			if (g_PlayBGMnum == BGM_002)
				DrawSprite(LoadTexture("data/TEXTURE/EF/ringB.png"), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, 900.0f - (5.7692307692307692307692307692308 * (float)circlenum[i][0]) + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 900.0f - (5.7692307692307692307692307692308 * (float)circlenum[i][0]) + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 0.0f, 0.0f, 1.0f, 1.0f);
			else
				DrawSprite(LoadTexture("data/TEXTURE/EF/ringB.png"), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, 900.0f - (6.25f * (float)circlenum[i][0]) + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 900.0f - (6.25f * (float)circlenum[i][0]) + (1.0f * updatevaibrationframecount / (float)281) * (float)temprythmcount, 0.0f, 0.0f, 1.0f, 1.0f);


			if (!g_Gamepause)
				circlenum[i][0]++;
			if (circlenum[i][0] == 104)
			{
				circlenum[i][0] = 0;
				circlenum[i][1] = 0;
			}
		}
	}
	if (temprythmcount > 0)
	{
		temprythmcount--;
	}


	if (p_Player->GetPlayerStatus() == ROTATION)
	{
		DrawSprite(LoadTexture("data/TEXTURE/EF/rotation_effect002.png"), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y, p_Player->GetPlayerSize().x, p_Player->GetPlayerSize().y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (p_Player->GetPlayerStatus() == DEFAULT)
	{

		if (b % 30 == 0 || b % 30 == 1 || b % 30 == 2 || b % 30 == 3)
		{
			DrawSprite(LoadTexture("data/TEXTURE/EF/running_effect001.png"), p_Player->GetPlayerPos().x - 100.0f, p_Player->GetPlayerPos().y + 60.0f, p_Player->GetPlayerSize().x - 125.0f, p_Player->GetPlayerSize().y - 125.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		}
		if (!g_Gamepause)
			b++;
	}



	if (p_Player->GetPlayerStatus() == JUMP)
	{
		if (a < 3)
		{
			DrawSprite(LoadTexture("data/TEXTURE/EF/jump_effect001.png"), p_Player->GetPlayerPos().x, p_Player->GetPlayerPos().y + 50.0f, p_Player->GetPlayerSize().x, p_Player->GetPlayerSize().y, 0.0f, 0.0f, 1.0f, 1.0f);

		}
		if (!g_Gamepause)
			a++;
	}
	else if (p_Player->GetPlayerStatus() != JUMP)
	{
		a = 0;
	}

	//DrawEF_RhythmJudge();
	DrawEffect();
	DrawScore();

	if (GameStartCheck == false)
	{
		DrawSpriteColorRotate(
			LoadTexture("data/TEXTURE/EF/READY_003.png"),
			SCREEN_WIDTH - g_ReadySpeed + SCREEN_WIDTH / 2.0f,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH / 3 * 2,
			SCREEN_HEIGHT / 4,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			0.0f
		);
	}

	if (GameStartCheck == true)
	{
		DrawSpriteColorRotate(
			LoadTexture("data/TEXTURE/EF/READY_003.png"),
			SCREEN_WIDTH - g_ReadySpeed + SCREEN_WIDTH / 2.0f,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH / 3 * 2,
			SCREEN_HEIGHT / 4,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			0.0f
		);


	}

	if (PlayerDied == true)
	{
		DrawSpriteColorRotate(
			LoadTexture("data/TEXTURE/EF/GAMEOVER_1.png"),
			SCREEN_WIDTH - GameOverCount * p_Player->GetPlayerSpeed().x,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH / 3 * 2,
			SCREEN_HEIGHT / 4,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			0.0f
		);
	}

	if (GameClearCheck == true)
	{
		DrawSpriteColorRotate(
			LoadTexture("data/TEXTURE/EF/GAME_CLEAR_1.png"),
			SCREEN_WIDTH - GameClearCount * p_Player->GetPlayerSpeed().x,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH / 3 * 2,
			SCREEN_HEIGHT / 2,
			0.0f,
			0.0f,
			1.0f,
			1.0f,
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			0.0f
		);
	}

	if (g_Gamepause)//ポーズ中の描画処理をここに書く
	{
		DrawSprite(
			LoadTexture("data/TEXTURE/BG/Poze_BG_001.png"),
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
			LoadTexture("data/TEXTURE/BG/Poze.png"),
			SCREEN_WIDTH / 2,
			SCREEN_HEIGHT / 5,
			SCREEN_WIDTH / 4,
			SCREEN_HEIGHT / 4,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);
		if (PozeCount % 2 == 0)
		{
			DrawSprite(
				LoadTexture("data/TEXTURE/BG/Poze_Restart_1.png"),
				SCREEN_WIDTH / 2,
				SCREEN_HEIGHT / 2,
				SCREEN_WIDTH / 4,
				SCREEN_HEIGHT / 4,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);

			DrawSprite(
				LoadTexture("data/TEXTURE/BG/Poze_Menu.png"),
				SCREEN_WIDTH / 2,
				(SCREEN_HEIGHT / 2) + 300.0f,
				SCREEN_WIDTH / 4,
				SCREEN_HEIGHT / 4,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);
		}
		else
		{
			DrawSprite(
				LoadTexture("data/TEXTURE/BG/Poze_Restart.png"),
				SCREEN_WIDTH / 2,
				SCREEN_HEIGHT / 2,
				SCREEN_WIDTH / 4,
				SCREEN_HEIGHT / 4,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);

			DrawSprite(
				LoadTexture("data/TEXTURE/BG/Poze_Menu_1.png"),
				SCREEN_WIDTH / 2,
				(SCREEN_HEIGHT / 2) + 300.0f,
				SCREEN_WIDTH / 4,
				SCREEN_HEIGHT / 4,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);
		}



		/*	DrawSprite(
				GetSceneTexture(SCENE_SUBCONFIG)->fileNum,
				SCREEN_WIDTH / 2,
				SCREEN_HEIGHT / 2,
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				0.0f,
				0.0f,
				1.0f,
				1.0f
			);*/


		DrawSprite(
			LoadTexture("data/TEXTURE/BG/Title_logo.png"),
			SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 + 150.0f,
			(SCREEN_HEIGHT / 2) + ((PozeCount % 2) * 300.0f),
			150.0f,
			150.0f,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);

		DrawSprite(
			LoadTexture("data/TEXTURE/BG/Title_logo.png"),
			SCREEN_WIDTH / 2 + SCREEN_WIDTH / 4 - 150.0f,
			(SCREEN_HEIGHT / 2) + ((PozeCount % 2) * 300.0f),
			150.0f,
			150.0f,
			0.0f,
			0.0f,
			1.0f,
			1.0f
		);


	}

}

void PushButton(void)
{
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_X) || GetKeyboardTrigger(DIK_SPACE))
		g_keynum.KEY_X = true;
	else
		g_keynum.KEY_X = false;

	if (GetKeyboardTrigger(DIK_LSHIFT) || IsButtonTriggered(0, XINPUT_GAMEPAD_Y))
		g_keynum.KEY_Y = true;
	else
		g_keynum.KEY_Y = false;

	if (IsButtonTriggered(0, XINPUT_GAMEPAD_A) || GetKeyboardTrigger(DIK_LCONTROL))
		g_keynum.KEY_A = true;
	else
		g_keynum.KEY_A = false;

	//g_keynum
}


void Playertransition(void)
{

	//jumpの判定
	if (g_keynum.KEY_X)
	{
		ReceptionTime_X = 0;
	}
	if (g_keynum.KEY_Y)
	{
		ReceptionTime_Y = 0;
	}
	if (g_keynum.KEY_A)
	{
		ReceptionTime_A = 0;
	}
	if (g_keynum.KEY_B)
	{

	}

	if (GameStartCheck)
	{
		if (ReceptionTime_X < RECEPTION_MAX_TIME)
		{
			if (!p_Player->KeepSlidingSwitch)
				p_Player->UpdateAnim(JUMP);
		}
		if (ReceptionTime_Y < RECEPTION_MAX_TIME)
		{
			p_Player->UpdateAnim(ROTATION);
		}
		if (ReceptionTime_A < RECEPTION_MAX_TIME)
		{
			p_Player->UpdateAnim(SLIDING);
		}
		if (ReceptionTime_B < RECEPTION_MAX_TIME)
		{

		}
	}



	ReceptionTime_X++;
	ReceptionTime_Y++;
	ReceptionTime_A++;
	ReceptionTime_B++;
}

void KeepSliding(PLAYER* p, FIELD* q)
{
	if (p->GetPlayerStatus() == SLIDING)
	{
		if (p->GetPlayerPos().y - p->GetPlayerSize().y / 2.0f > q->GetFieldPos().y)
		{
			if (q->GetFieldPos().x - q->GetFieldSize().x / 2.0f < p->GetPlayerPos().x + p->GetPlayerSize().x / 2.0f &&
				q->GetFieldPos().x + q->GetFieldSize().x / 2.0f > p->GetPlayerPos().x - p->GetPlayerSize().x / 2.0f
				)
			{
				p->KeepSlidingSwitch = true;
			}
		}
	}
}

PLAYER* GetPlayerpoint(void)
{
	return p_Player;
}


void GamePause(bool pause)
{
	g_Gamepause = pause;
	if (pause)
	{
		g_GamePause_SampleNum = GetSourceSample(Get_BGM_Inf()[g_PlayBGMnum].fileNum);
		StopSoundAll();

	}
	else
	{
		SetSampleNum(g_PlayBGMnum, g_GamePause_SampleNum);
		PlaySound(Get_BGM_Inf()[g_PlayBGMnum].fileNum, 0);
	}
}



//
//ステージ情報
//
int* GetStageRhythm(int num)
{
	switch (g_Stage_Name) {
	case STAGE1_1:
		return &g_testtesttest_1.m_RhythmJudgement[num][0];

		break;
	case STAGE1_2:
		return &g_testtesttest_2.m_RhythmJudgement[num][0];
		break;
	case STAGE1_3:
		return &g_testtesttest.m_RhythmJudgement[num][0];
		break;
	case STAGE2_1:

		break;
	case STAGE2_2:

		break;
	case STAGE2_3:
		return &g_Stage2_3.m_RhythmJudgement[num][0];
		break;
	}

	return &g_testtesttest.m_RhythmJudgement[num][0];
}
int* GetStageRhythmAction(int num)
{
	switch (g_Stage_Name) {
	case STAGE1_1:
		return &g_testtesttest_1.m_RhythmJudgement[num][1];
		break;
	case STAGE1_2:
		return &g_testtesttest_2.m_RhythmJudgement[num][1];
		break;
	case STAGE1_3:
		return &g_testtesttest.m_RhythmJudgement[num][1];
		break;
	case STAGE2_1:

		break;
	case STAGE2_2:

		break;
	case STAGE2_3:
		return &g_Stage2_3.m_RhythmJudgement[num][1];
		break;
	}

	return &g_testtesttest.m_RhythmJudgement[num][1];
}
FIELD_TEXTURE_NUM* GetStageFieldTexNum(int num)
{
	switch (g_Stage_Name) {
	case STAGE1_1:
		return &g_testtesttest_1.m_FieldTexNum[num];
		break;
	case STAGE1_2:
		return &g_testtesttest_2.m_FieldTexNum[num];
		break;
	case STAGE1_3:
		return &g_testtesttest.m_FieldTexNum[num];
		break;
	case STAGE2_1:

		break;
	case STAGE2_2:

		break;
	case STAGE2_3:
		return &g_Stage2_3.m_FieldTexNum[num];
		break;
	}

	return &g_testtesttest.m_FieldTexNum[num];
}
int* GetStageFieldHigh(int num)
{
	switch (g_Stage_Name) {
	case STAGE1_1:
		return &g_testtesttest_1.m_PlacementFigh[num];
		break;
	case STAGE1_2:
		return &g_testtesttest_2.m_PlacementFigh[num];
		break;
	case STAGE1_3:
		return &g_testtesttest.m_PlacementFigh[num];
		break;
	case STAGE2_1:

		break;
	case STAGE2_2:

		break;
	case STAGE2_3:
		return &g_Stage2_3.m_PlacementFigh[num];
		break;
	}

	return &g_testtesttest.m_PlacementFigh[num];
}
float* GetStageFieldTemp(int num)
{
	switch (g_Stage_Name) {
	case STAGE1_1:
		return &g_testtesttest_1.m_PlacementField[num];
		break;
	case STAGE1_2:
		return &g_testtesttest_2.m_PlacementField[num];
		break;
	case STAGE1_3:
		return &g_testtesttest.m_PlacementField[num];
		break;
	case STAGE2_1:

		break;
	case STAGE2_2:

		break;
	case STAGE2_3:
		return &g_Stage2_3.m_PlacementField[num];
		break;
	}
	return &g_testtesttest.m_PlacementField[num];
}
int GetStageBGMSample(void)
{
	return Get_BGM_Inf()[g_PlayBGMnum].samplenum;
}


void ResetGame(void)
{

}

void GameStart(void)
{
	if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_K)) && GameStartCheck == false &&CenterReady == true )
	{
		SetVolume(Get_BGM_Inf()[g_PlayBGMnum].fileNum, 1.0f);
		PlaySound(Get_BGM_Inf()[g_PlayBGMnum].fileNum, 0);
		GameStartCheck = true;
		CenterReady = false;
		ActionVibration(30, 200);
		PlaySound(Get_SE_Inf()[SE_GO_1].fileNum, 0);
	}
	else
	{
		if (!(GameStartCount * p_Player->GetPlayerSpeed().x > SCREEN_WIDTH))
		{
			g_ReadySpeed = GameStartCount * p_Player->GetPlayerSpeed().x;
		}
		else
		{
			GameStartCountKeep = true;
			CenterReady = true;
		}

		if (GameStartCountKeep == false)
		{
			GameStartCount++;

			InitScore();
		}

		if (CenterReady == true&& ReadyCheck == false)
		{
			ReadyCheck = true;
			PlaySound(Get_SE_Inf()[SE_READY_1].fileNum, 0);
		}


	}

	if (GameStartCheck == true)
	{
		if (!PozeCheck)
		{
			if (GameStartCount * p_Player->GetPlayerSpeed().x > SCREEN_WIDTH)
				g_ReadySpeed = GameStartCount * p_Player->GetPlayerSpeed().x;
			GameStartCount++;
		}
	}
}

void SetStageNum(STAGE_NAME num)
{
	g_Stage_Name = num;
}


void GameResultProcess()
{

	if (g_PlayBGMnum == BGM_002)
	{
		if (updatevaibrationframecount > BGM_MAX_TEMP_NUM_002 - 1)
		{
			GameClearCheck = true;

			if (!(GameClearCount * p_Player->GetPlayerSpeed().x + SCREEN_WIDTH / 2.0f > SCREEN_WIDTH))
				GameClearCount++;
			else
			{
				SceneChangeTime++;
				if (SceneChangeTime > 120)
					SceneTransition(SCENE_RESULT);
			}
		}
	}
	else if (g_PlayBGMnum == BGM_003)
	{
		if (updatevaibrationframecount > BGM_MAX_TEMP_NUM_003 - 1)
		{

			GameClearCheck = true;

			if (!(GameClearCount * p_Player->GetPlayerSpeed().x + SCREEN_WIDTH / 2.0f > SCREEN_WIDTH))
				GameClearCount++;
			else
			{
				SceneChangeTime++;
				if (SceneChangeTime > 120)
					SceneTransition(SCENE_RESULT);
			}

		}
	}
	else
	{

	}
}

void PlayerStatusChangeForStage()
{
	ResetPlayerStatusForStage();
	ResetGravityStrengthForStage();

	if (g_PlayBGMnum == BGM_002)
	{
		SetPlayerStatusForStage(1.0f);
		SetGravityStrengthForStage(1.0f);
	}
	if (g_PlayBGMnum == BGM_003)
	{
		SetPlayerStatusForStage(0.9f);
		SetGravityStrengthForStage(1.1f);
	}
}
