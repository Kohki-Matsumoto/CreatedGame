#include "Player.h"
#include "sprite.h"
#include "LoadAllTexture.h"
#include "TextureManager.h"
#include "Gravity.h"
#include "SoundManager.h"
#include "sound.h"
#include "score.h"
#include "Game.h"
#include "input.h"
#include "EF_RhythmJudge.h"
#include "Effect.h"

float JUMP_TIME_FRAME = 15.0f;
float ROTATION_TIME = 30.0f;
float ROTATION_JUMP_TIME = 0.5f / ROTATION_TIME;

int JumpShiftX = JUMP_SHIFT_X;
int JumpShiftY = JUMP_SHIFT_Y;



void PLAYER::DrawPlayer(PLAYER_STATUS player_status)
{
	switch (player_status)
	{
	case DEFAULT:
		DrawSprite(
			GetPlayerAniTexture(DEFAULT)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			(m_NowFrame % GetPlayerAniTexture(DEFAULT)->TexNum.x) * (1.0f / GetPlayerAniTexture(DEFAULT)->TexNum.x),
			(m_NowFrame / GetPlayerAniTexture(DEFAULT)->TexNum.x) * (1.0f / GetPlayerAniTexture(DEFAULT)->TexNum.y),
			1.0f / GetPlayerAniTexture(DEFAULT)->TexNum.x,
			1.0f / GetPlayerAniTexture(DEFAULT)->TexNum.y
		);
		break;
	case DASH:
		DrawSprite(
			GetPlayerAniTexture(DASH)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			(m_NowFrame % GetPlayerAniTexture(DASH)->TexNum.x) * (1.0f / GetPlayerAniTexture(DASH)->TexNum.x),
			(m_NowFrame / GetPlayerAniTexture(DASH)->TexNum.x) * (1.0f / GetPlayerAniTexture(DASH)->TexNum.y),
			1.0f / GetPlayerAniTexture(DASH)->TexNum.x,
			1.0f / GetPlayerAniTexture(DASH)->TexNum.y
		);
		break;
	case JUMP:
   		DrawSprite(
			GetPlayerAniTexture(JUMP)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			((m_NowFrame % (GetPlayerAniTexture(JUMP)->TexNum.x - JumpShiftX)) + (JumpShiftX % GetPlayerAniTexture(JUMP)->TexNum.x)) * (1.0f / GetPlayerAniTexture(JUMP)->TexNum.x),
			((m_NowFrame / (GetPlayerAniTexture(JUMP)->TexNum.x - JumpShiftX)) + (JumpShiftY / GetPlayerAniTexture(JUMP)->TexNum.y)) * (1.0f / GetPlayerAniTexture(JUMP)->TexNum.y),
			1.0f / GetPlayerAniTexture(JUMP)->TexNum.x,
			1.0f / GetPlayerAniTexture(JUMP)->TexNum.y
		);
		break;
	case FALL:
		DrawSprite(
			GetPlayerAniTexture(FALL)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			(m_NowFrame % GetPlayerAniTexture(FALL)->TexNum.x) * (1.0f / GetPlayerAniTexture(FALL)->TexNum.x),
			(m_NowFrame / GetPlayerAniTexture(FALL)->TexNum.x) * (1.0f / GetPlayerAniTexture(FALL)->TexNum.y),
			1.0f / GetPlayerAniTexture(FALL)->TexNum.x,
			1.0f / GetPlayerAniTexture(FALL)->TexNum.y
		);
		break;
	case ROTATION:
		DrawSprite(
			GetPlayerAniTexture(ROTATION)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			(m_NowFrame % GetPlayerAniTexture(ROTATION)->TexNum.x) * (1.0f / GetPlayerAniTexture(ROTATION)->TexNum.x),
			(m_NowFrame / GetPlayerAniTexture(ROTATION)->TexNum.x) * (1.0f / GetPlayerAniTexture(ROTATION)->TexNum.y),
			1.0f / GetPlayerAniTexture(ROTATION)->TexNum.x,
			1.0f / GetPlayerAniTexture(ROTATION)->TexNum.y
		);
		break;
	case SLIDING:
		DrawSprite(
			GetPlayerAniTexture(SLIDING)->fileNum,
			m_Pos.x,
			m_Pos.y,
			m_Size.x,
			m_Size.y,
			(m_NowFrame % GetPlayerAniTexture(SLIDING)->TexNum.x) * (1.0f / GetPlayerAniTexture(SLIDING)->TexNum.x),
			(m_NowFrame / GetPlayerAniTexture(SLIDING)->TexNum.x) * (1.0f / GetPlayerAniTexture(SLIDING)->TexNum.y),
			1.0f / GetPlayerAniTexture(SLIDING)->TexNum.x,
			1.0f / GetPlayerAniTexture(SLIDING)->TexNum.y
		);
		break;
	}
}

void PLAYER::AddPlayerFrame(PLAYER_STATUS player_status)
{
	if (!player_status == m_BefPlayerStatus)
		m_NowFrame = 0;

	switch (player_status)
	{
	case DEFAULT:
		if (m_NowFrame < GetPlayerAniTexture(DEFAULT)->TexNum.x * GetPlayerAniTexture(DEFAULT)->TexNum.y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	case DASH:
		if (m_NowFrame < GetPlayerAniTexture(DASH)->TexNum.x * GetPlayerAniTexture(DASH)->TexNum.y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	case JUMP:
		if (m_NowFrame < (GetPlayerAniTexture(JUMP)->TexNum.x - JUMP_SHIFT_X) * (GetPlayerAniTexture(JUMP)->TexNum.y) - JUMP_SHIFT_Y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	case FALL:
		if (m_NowFrame < GetPlayerAniTexture(FALL)->TexNum.x * GetPlayerAniTexture(FALL)->TexNum.y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	case ROTATION:
		if (m_NowFrame < GetPlayerAniTexture(ROTATION)->TexNum.x * GetPlayerAniTexture(ROTATION)->TexNum.y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	case SLIDING:
		if (m_NowFrame < GetPlayerAniTexture(SLIDING)->TexNum.x * GetPlayerAniTexture(SLIDING)->TexNum.y)
			m_NowFrame++;
		else
			m_NowFrame = 0;
		break;
	}

	m_BefPlayerStatus = player_status;
}

void PLAYER::Dojump()
{
	if (m_PlayerStatus == JUMP)
	{
		JumpFinish += 1.0f;

		JumpTime += JUMP_TIME;

		m_Pos = MakeFloat2(m_Pos.x, JumpStartPos - JUMP_HEIGHT * sin(D3DX_PI * JumpTime));

		if (JumpFinish > JUMP_TIME_FRAME)
		{
			UpdateAnim(FALL);
			JumpFinish = 0.0f;
			JumpTime = 0.0f;
			JumpStartPos = 0.0f;
		}
	}
	else
	{
		JumpFinish = 0.0f;
		JumpTime = 0.0f;
		JumpStartPos = 0.0f;
	}
}


void PLAYER::DoRotation()
{
	if (m_PlayerStatus == ROTATION)
	{
		RotateFinish += 1.0f;
		RotationTime += ROTATION_JUMP_TIME;

		m_Pos = MakeFloat2(m_Pos.x, RotationStartPos - ROTATION_JUMP_HEIGHT * sin(D3DX_PI * RotationTime));


		SetGravityStrength__test(0.0f);

		if (RotateFinish > ROTATION_TIME)
		{
			UpdateAnim(FALL);
			RotationTime = 0.0f;
			m_NowRotation = false;
			RotationStartPos = 0.0f;
			RotateFinish = 0.0f;
		}
	}
}

void PLAYER::Dosliding()
{
	if (m_PlayerStatus == SLIDING)
	{
		SetPlayerPos(MakeFloat2(GetPlayerPos().x, GetPlayerPos().y));

		if (SlidingTime < SLIDING_TIME)
		{
			SlidingTime += 1.0f;
		}

		

		if (SlidingTime >= SLIDING_TIME)
		{
			//下の条件文の条件にもし上に障害物があるときという物を作ればいい
			if (KeepSlidingSwitch == true)
			{
				SlidingTime -= 1.0f;
			}

			if (SlidingTime >= SLIDING_TIME)
			{
				SetPlayerPos(MakeFloat2(GetPlayerPos().x, GetPlayerPos().y - 25.001f));
				SlidingTime = 0.0f;
				m_NowSliding = false;
				m_PlayerStatus = DEFAULT;
			}
			
		}
		/*
		else
		{
			SetPlayerPos(MakeFloat2(GetPlayerPos().x, GetPlayerPos().y - 50.001f));
			SlidingTime = 0.0f;
			m_NowSliding = false;
			m_PlayerStatus = DEFAULT;
		}
		*/
	}
	else
	{
		SlidingTime = 0.0f;
	}
}

void PLAYER::UpdateAnim(PLAYER_STATUS player_status)
{
	switch (m_PlayerStatus)
	{
	case DEFAULT:
		m_tyakuti = true;
		switch (player_status)
		{
		case JUMP:
			m_ActionHistory[m_NowTempNum][0] = JUMP;
			RhythmJudgment();
			PlaySound(Get_SE_Inf()[SE_JUMP].fileNum, 0);
			m_OnGravity = false;
			m_PlayerStatus = JUMP;
			//Canjump();
			JumpStartPos = m_Pos.y;
			break;
		case SLIDING:
			m_ActionHistory[m_NowTempNum][0] = SLIDING;
			RhythmJudgment();
			PlaySound(Get_SE_Inf()[SE_SLIDING].fileNum, 0);
			SetPlayerPos(MakeFloat2(GetPlayerPos().x, GetPlayerPos().y + 49.999f));
			SetPlayerSpeed(MakeFloat2(GetPlayerSpeed().x, 0.0f));
			SetPlayerNowSliding(true);
			m_PlayerStatus = SLIDING;
			break;
		case FALL:
			m_OnGravity = true;
			m_PlayerStatus = FALL;
			break;
		}
		break;
	case JUMP:
		switch (player_status)
		{
		case ROTATION:
			if (m_tyakuti)
			{
				PlaySound(Get_SE_Inf()[SE_KAITEN].fileNum, 0);
				m_ActionHistory[m_NowTempNum][0] = ROTATION;
				RhythmJudgment();
				m_PlayerStatus = ROTATION;
				RotationStartPos = m_Pos.y;

				m_tyakuti = false;
				m_OnGravity = false;
			}

			break;
		case FALL:
			m_OnGravity = true;
			m_PlayerStatus = FALL;
			break;
		}
		break;
	case FALL:
		switch (player_status)
		{
		case ROTATION:
			if (m_tyakuti)
			{
				PlaySound(Get_SE_Inf()[SE_KAITEN].fileNum, 0);
				m_ActionHistory[m_NowTempNum][0] = ROTATION;
				RhythmJudgment();
				m_PlayerStatus = ROTATION;
				RotationStartPos = m_Pos.y;

				m_tyakuti = false;
				m_OnGravity = false;
			}
			break;
		case DEFAULT:
			//SetVolume(Get_SE_Inf()[SE_TYAKUTI].fileNum, 80.0f);
			//PlaySound(Get_SE_Inf()[SE_TYAKUTI].fileNum, 0);
			m_PlayerStatus = DEFAULT;
			break;
		}
		break;
	case ROTATION:
		switch (player_status)
		{
		case FALL:
			m_OnGravity = true;
			m_PlayerStatus = FALL;
			break;
		}
		break;
	case SLIDING:
		switch (player_status)
		{
		case DEFAULT:
			m_OnGravity = false;
			m_PlayerStatus = DEFAULT;
			m_Pos.y -= 25.001f;
			break;
		case JUMP:
			m_ActionHistory[m_NowTempNum][0] = JUMP;
			RhythmJudgment();
			PlaySound(Get_SE_Inf()[SE_JUMP].fileNum, 0);
			m_OnGravity = false;
			m_PlayerStatus = JUMP;
			JumpStartPos = m_Pos.y - 25.001f;
			break;
		case FALL:
			m_OnGravity = true;
			m_PlayerStatus = FALL;
			break;
		}
		break;
	default:
		int asdoooaf = 0;	//エラー確認用のブレイクポイント設置のためのもの。
		break;
	}
}

void PLAYER::ChangePlayerSize()
{
	if( m_PlayerStatus == m_BefPlayerStatus){}
	else
	{
		switch (m_PlayerStatus)
		{
		case DEFAULT:
			SetPlayerSize(MakeFloat2(200.0f, 200.0f));
			break;
		case DASH:
			SetPlayerSize(MakeFloat2(200.0f, 200.0f));
			break;
		case JUMP:
			SetPlayerSize(MakeFloat2(200.0f, 200.0f));
			break;
		case FALL:
			SetPlayerSize(MakeFloat2(200.0f, 200.0f));
			break;
		case ROTATION:
			SetPlayerSize(MakeFloat2(200.0f, 200.0f));
			break;
		case SLIDING:
			SetPlayerSize(MakeFloat2(200.0f, 150.0f));
			break;
		}
	}
}


void PLAYER::RhythmJudgment(void)
{
	
	//============================================
	//必要リズムの判定
	//============================================
 	if (*GetStageRhythm(tahuasodhiooiask) == g_Playertmpnum_A && *GetStageRhythmAction(tahuasodhiooiask) == m_ActionHistory[g_Playertmpnum_A][0])
	{
		if (GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) - GetStageBGMSample() * 0.5 < m_NowSampleNum && m_NowSampleNum < GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) + GetStageBGMSample() * 0.5)
		{
			tektkeks = JUDGEMENT_GOOD;
			ActionEF_RhythmJudge(DRAW_EF_TIME, JUDGEMENT_GOOD);

			if (GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) - GetStageBGMSample() * 0.25 < m_NowSampleNum && m_NowSampleNum < GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) + GetStageBGMSample() * 0.25)
			{
				tektkeks = JUDGEMENT_PERFECT;
				ActionEF_RhythmJudge(DRAW_EF_TIME, JUDGEMENT_PERFECT);
			}			
			//AddComboScore(1);
		}
		else
		{
			tektkeks = INIT_JUGEMENT;
			ActionEF_RhythmJudge(DRAW_EF_TIME, INIT_JUGEMENT);
		}
	}
	else if (*GetStageRhythm(tahuasodhiooiask) == m_ActionHistory[g_Playertmpnum_A][0])
	{
		if (m_ActionHistory[m_NowTempNum - 1][0] == JUMP)
		{
			if (GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) - GetStageBGMSample() * 0.5 < m_NowSampleNum && m_NowSampleNum < GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) + GetStageBGMSample() * 0.5)
			{
				tektkeks = JUDGEMENT_GOOD;
				ActionEF_RhythmJudge(DRAW_EF_TIME, JUDGEMENT_GOOD);

				if (GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) - GetStageBGMSample() * 0.25 < m_NowSampleNum && m_NowSampleNum < GetStageBGMSample() * *GetStageRhythm(tahuasodhiooiask) + GetStageBGMSample() * 0.25)
				{
					tektkeks = JUDGEMENT_PERFECT;
					ActionEF_RhythmJudge(DRAW_EF_TIME, JUDGEMENT_PERFECT);
				}
			}
			else
			{
				tektkeks = INIT_JUGEMENT;
				ActionEF_RhythmJudge(DRAW_EF_TIME, INIT_JUGEMENT);
			}
		}
	}
	else
	{
		tektkeks = INIT_JUGEMENT;
	}

	//========================================
	//フリーの判定
	//========================================
	if (m_ActionHistory[g_Playertmpnum_A - 1][0] == JUMP && m_ActionHistory[g_Playertmpnum_A - 1][2] == 0)
	{
		PlaySound(Get_SE_Inf()[SE_combo_2].fileNum, 0);
		switch (m_ActionHistory[g_Playertmpnum_A][0])
		{
		case JUMP:
			//ダブルジャンプ
			ActionVibration(10, 150);
			m_ActionHistory[g_Playertmpnum_A][2] = JUMP_JUMP;
			AddScore(100);
			AddComboScore(1);
			break;
		case ROTATION:
			//ジャンプローテーション
			ActionVibration(10, 150);
			m_ActionHistory[g_Playertmpnum_A][2] = JUMP_ROTATION;
			AddComboScore(1);
			AddScore(150);
			break;
		}
	}

	if (m_ActionHistory[g_Playertmpnum_A - 1][0] == SLIDING && m_ActionHistory[g_Playertmpnum_A - 1][2] == 0)
	{
		PlaySound(Get_SE_Inf()[SE_combo_2].fileNum, 0);
		if (m_ActionHistory[g_Playertmpnum_A][0] == JUMP)
		{
			//スライディングジャンプ
			ActionVibration(10, 150);
			m_ActionHistory[g_Playertmpnum_A][2] = SLIDING_JUMP;
			AddComboScore(1);
			AddScore(80);
		}
	}


	switch ((m_ActionHistory[g_Playertmpnum_A - 1][2]))
	{
	case JUMP_JUMP:
		//三段ジャンプ
		PlaySound(Get_SE_Inf()[SE_combo_3].fileNum, 0);
		if (m_ActionHistory[g_Playertmpnum_A][0] == JUMP)
		{
			ActionVibration(20, 255);
			m_ActionHistory[g_Playertmpnum_A][2] = JUMP_JUMP_JUMP;
			AddScore(300);
			AddComboScore(1);
		} 
		//ジャンプ　ジャンプ　回転
		PlaySound(Get_SE_Inf()[SE_combo_3].fileNum, 0);
		if (m_ActionHistory[g_Playertmpnum_A][0] == ROTATION)
		{
			ActionVibration(15, 200);
			m_ActionHistory[g_Playertmpnum_A][2] = JUMP_JUMP_ROTATION;
			AddScore(400);
			AddComboScore(1);
		}
		break;
	case SLIDING_JUMP:
		//スライディング　ジャンプ　回転
		PlaySound(Get_SE_Inf()[SE_combo_3].fileNum, 0);
		if (m_ActionHistory[g_Playertmpnum_A][0] == ROTATION)
		{
			ActionVibration(15, 200);
			m_ActionHistory[g_Playertmpnum_A][2] = SLIDING_JUMP_ROTATION;
			AddScore(500);
			AddComboScore(1);
		}
		break;
	}




	if (*GetStageRhythm(tahuasodhiooiask) == g_Playertmpnum_A)
	{
		tahuasodhiooiask++;
	}


		
	switch (tektkeks)
	{
	case JUDGEMENT_MISS:
		ActionVibration(0, 0);
		PlaySound(Get_SE_Inf()[SE_miss].fileNum, 0);
		AddScore(0);
		break;
	case JUDGEMENT_GOOD:
		SetEffect(EF_RHYTHM_ANIi);
		ActionVibration(0, 0);
		SetEffect(LIGHT_EF);
		SetEffect(GOOD_FIGURE);
		PlaySound(Get_SE_Inf()[SE_good].fileNum, 0);
		AddScore(100);
		break;
	case JUDGEMENT_PERFECT:
		SetEffect(EF_RHYTHM_ANIi);
		ActionVibration(10, 100);
		SetEffect(LIGHT_EF);
		SetEffect(PERFECT_FIGURE);
		PlaySound(Get_SE_Inf()[SE_perfect].fileNum, 0);
		AddScore(200);
		break;
	}
}


void PLAYER::UpdatePlayer(void)
{
	if (m_NowSampleNum > GetStageBGMSample() * g_Playertmpnum_A + GetStageBGMSample() * 0.5)				//1テンポの判定範囲を超えた時に次の判定に移る処理
	{
		g_Playertmpnum_A++;
	}

	if (*GetStageRhythm(tahuasodhiooiask) < g_Playertmpnum_A)
	{
		tahuasodhiooiask++;
	}
	if (m_Pos.x <= 300.0f)
	{
		tektkeks = JUDGEMENT_MISS;

	}
	else
	{
	}
}



int PLAYER::Getg_Playertmpnum(void)
{
	return m_ActionHistory[g_Playertmpnum_A][2];
}

void SetPlayerStatusForStage(float ChangeMagnification)
{
	JUMP_TIME_FRAME = JUMP_TIME_FRAME * ChangeMagnification;
	ROTATION_TIME = ROTATION_TIME * ChangeMagnification;
	ROTATION_JUMP_TIME = 0.5f / ROTATION_TIME;
}

void ResetPlayerStatusForStage()
{
	JUMP_TIME_FRAME = 15.0f;
	ROTATION_TIME = 30.0f;
	ROTATION_JUMP_TIME = 0.5f / ROTATION_TIME;
}
