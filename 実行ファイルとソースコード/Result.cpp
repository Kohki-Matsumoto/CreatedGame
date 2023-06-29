#include "Result.h"
#include "input.h"
#include "Scene.h"
#include "sprite.h"
#include "fade.h"
#include "LoadAllTexture.h"
#include "score.h"
#include "sound.h"
#include "SoundManager.h"
#include "Texture.h"


#define TEXTURE_WIDTH				(32)	// キャラサイズ
#define TEXTURE_HEIGHT				(64)	// 


static bool						g_Use;						// true:使っている  false:未使用
static float					g_w, g_h;					// 幅と高さ
static D3DXVECTOR3				g_Pos;						// ポリゴンの座標
static int						g_TexNo;					// テクスチャ番号
bool MoveTx = false;
bool MoveEx = false;
bool rockcheck = false;
int MoveTxCount = 0;

static int						g_Score;					// スコア

int g_resultScoreFrame;

void InitResult()
{
	//テクスチャ生成
	g_TexNo = LoadTexture("data/TEXTURE/DebugMode/COMBO_SCORE_03.png");

	//初期化
	g_Use = true;
	g_w = TEXTURE_WIDTH;
	g_h = TEXTURE_HEIGHT;
	g_Pos = D3DXVECTOR3(800.0f, 200.0f, 0.0f);

	g_Score = 0;	// スコアの初期化

	MoveTx = false;
	MoveEx = false;
	rockcheck = false;
	MoveTxCount = 0;

	SetFrequency(BGM_005, 1.5f);
	PlaySound(2, -1);

	PlaySound(Get_BGM_Inf()[BGM_005].fileNum, -1);
}

void UninitResult()
{
	SetFrequency(BGM_005, 1.0f);
	StopSoundAll();
}

void  UpdateResult(void)
{
	

	if (!MoveEx)
	{
		if (IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_SPACE) && GetFadeState() == FADE_NONE)
		{
			MoveEx = true;
			MoveTx = true;
			PlaySound(Get_SE_Inf()[SE_combo_1].fileNum, 0);
			ActionVibration(80, 255);
		}
	}
	else if (MoveEx)
	{
		if (MoveTx)
		{
			MoveTxCount++;
		}

		if (MoveTxCount == 60)
		{
			MoveTx = false;
		}
		if (!rockcheck)
		{
			if (IsButtonTriggered(0, XINPUT_GAMEPAD_B) || GetKeyboardTrigger(DIK_SPACE) && GetFadeState() == FADE_NONE)
			{
				SceneTransition(SCENE_MENU);
				PlaySound(Get_SE_Inf()[SE_SELECT_OK_1].fileNum, 0);
				rockcheck = true;
				ActionVibration(10, 150);
			}
		}
	}
	
}
void DrawResult(void)
{
	
	DrawSprite(
		GetSceneTexture(SCENE_RESULT)->fileNum,
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0.0f,
		0.0f,
		1.0f,
		1.0f
	);


		// テクスチャ設定
		GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));

		g_Pos = D3DXVECTOR3(-50.0f , 50.0f, 0.0f);//ここで表示位置を変える
		g_w = TEXTURE_WIDTH;
		g_h = TEXTURE_HEIGHT;
		// 桁数分処理する
		int number = GetScore();
		int combonumber = GetComboScore();
		for (int i = 0; i < 6; i++)
		{
			// 今回表示する桁の数字
			float x = (float)(number % 10);

			// スコアの位置やテクスチャー座標を反映
			float px = g_Pos.x - 110.0f * i;	// プレイヤーの表示位置X
			float py = g_Pos.y;			// プレイヤーの表示位置Y
			float pw = g_w;				// プレイヤーの表示幅
			float ph = g_h;				// プレイヤーの表示高さ

			float tw = 1.0f / 10;		// テクスチャの幅
			float th = 1.0f / 1;		// テクスチャの高さ
			float tx = x * tw;			// テクスチャの左上X座標
			float ty = 0.0f;			// テクスチャの左上Y座標

			// １枚のポリゴンの頂点とテクスチャ座標を設定			ここは得点の表示
			DrawSprite(LoadTexture("data/TEXTURE/DebugMode/ComboScoreNum.png"), px + 18.5f * MoveTxCount, SCREEN_HEIGHT / 2 +450.0f , 100.0f, 100.0f, tx, ty, tw, th);

			// 次の桁へ
			number /= 10;
		}


		g_Pos = D3DXVECTOR3(-50.0f, 100.0f, 0.0f);
		for (int i = 0; i < 3; i++)
		{
			// 今回表示する桁の数字
			float x = (float)(combonumber % 10);

			// スコアの位置やテクスチャー座標を反映
			float px = g_Pos.x - 110.0f * i;	// プレイヤーの表示位置X
			float py = g_Pos.y;			// プレイヤーの表示位置Y
			float pw = g_w;				// プレイヤーの表示幅
			float ph = g_h;				// プレイヤーの表示高さ

			float tw = 1.0f / 10;		// テクスチャの幅
			float th = 1.0f / 1;		// テクスチャの高さ
			float tx = x * tw;			// テクスチャの左上X座標
			float ty = 0.0f;			// テクスチャの左上Y座標

			// １枚のポリゴンの頂点とテクスチャ座標を設定
			DrawSprite(g_TexNo, px + 18.5f * MoveTxCount, SCREEN_HEIGHT / 3 + 450.0f, 100.0f, 100.0f, tx, ty, tw, th);//コンボ数の表示
			// 次の桁へ
			combonumber /= 10;
		}
		
		DrawSprite(LoadTexture("data/TEXTURE/BG/RESULT_MAXCOMBO_001.png"), 500.0f, SCREEN_HEIGHT / 3 + 350.0f, 500.0f,150.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(LoadTexture("data/TEXTURE/BG/RESULT_SCORE_001.png"), 300.0f, SCREEN_HEIGHT / 3 + 530.0f, 400.0f, 120.0f, 0.0f, 0.0f, 1.0f, 1.0f);

}


