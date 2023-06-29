
#include "score.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_WIDTH				(64)	// キャラサイズ
#define TEXTURE_HEIGHT				(128)	// 


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static bool						g_Use;						// true:使っている  false:未使用
static float					g_w, g_h;					// 幅と高さ
static D3DXVECTOR3				g_Pos;						// ポリゴンの座標
static int						g_TexNo;					// テクスチャ番号

static int						g_Score;					// スコア
static int						g_ComboScoe = 0;			//コンボ
static int						g_ComboScoreMax;			//コンボの最大値	

bool kakudaisyori = false;
int g_ComboFrame = 0;

bool g_scoreBool = false;
int g_ScoreFrame = 0;

int sjdhajhjkjjkf = 0;

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitScore(void)
{
	//テクスチャ生成
	g_TexNo = LoadTexture("data/TEXTURE/DebugMode/COMBO_SCORE_03.png");

	//初期化
	g_Use = true;
	g_w = TEXTURE_WIDTH;
	g_h = TEXTURE_HEIGHT;
	g_Pos = D3DXVECTOR3(800.0f, 200.0f, 0.0f);

	g_Score = 0;	// スコアの初期化
	g_ComboScoe = 0;//コンボの初期化
	g_ComboScoreMax = 0;//コンボの最大値の初期化

	kakudaisyori = false;
	g_ComboFrame = 0;

	g_scoreBool = false;
	g_ScoreFrame = 0;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitScore(void)
{
	
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateScore(void)
{

	if (kakudaisyori && g_ComboFrame < 3)
	{
		g_ComboFrame++;
	}
	else
	{
		kakudaisyori = false;
	}

	if (!kakudaisyori && g_ComboFrame >= 0)
	{
		g_ComboFrame--;
		if (g_ComboFrame <= 0)
		{
			kakudaisyori = false;
			g_ComboFrame = 0;
		}
	}

	if (g_scoreBool && g_ScoreFrame < 3)
	{
		g_ScoreFrame++;
	}
	else
	{
		g_scoreBool = false;
	}

	if (!g_scoreBool && g_ScoreFrame >= 0)
	{
		g_ScoreFrame--;
		if (g_scoreBool <= 0)
		{
			g_scoreBool = false;
			g_ScoreFrame = 0;
		}
	}
}


//=============================================================================
// 描画処理
//=============================================================================
void DrawScore(void)
{
	//有効化フラグがONなら描画する
	if (g_Use)
	{
		// テクスチャ設定
		GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));

		g_Pos = D3DXVECTOR3(SCREEN_WIDTH - 50.0f, 50.0f, 0.0f);
		g_w = TEXTURE_WIDTH;
		g_h = TEXTURE_HEIGHT;
		// 桁数分処理する
		int number = g_Score;
		int combonumber = g_ComboScoe;
		for (int i = 0; i < 6; i++)
		{
			// 今回表示する桁の数字
			float x = (float)(number % 10);

			// スコアの位置やテクスチャー座標を反映
			float px = g_Pos.x - g_w * i;	// プレイヤーの表示位置X
			float py = g_Pos.y;			// プレイヤーの表示位置Y
			float pw = g_w;				// プレイヤーの表示幅
			float ph = g_h;				// プレイヤーの表示高さ

			float tw = 1.0f / 10;		// テクスチャの幅
			float th = 1.0f / 1;		// テクスチャの高さ
			float tx = x * tw;			// テクスチャの左上X座標
			float ty = 0.0f;			// テクスチャの左上Y座標

			// １枚のポリゴンの頂点とテクスチャ座標を設定
			DrawSprite(LoadTexture("data/TEXTURE/DebugMode/ComboScoreNum.png"), px, py, pw + 10.0f * g_ScoreFrame, ph + 10.0f * g_ScoreFrame, tx, ty, tw, th);

			// 次の桁へ
			number /= 10;
		}


		g_Pos = D3DXVECTOR3(1440.0f, 300.0f, 0.0f);
		g_w = TEXTURE_WIDTH * 2 + 10.0f * g_ComboFrame;
		g_h = TEXTURE_HEIGHT * 2 + 20.0f * g_ComboFrame;
		sjdhajhjkjjkf = combonumber;
		DrawSprite(LoadTexture("data/TEXTURE/DebugMode/COMBO_texture.png"), 1440.0f, 400.0f, 250.0f + 10.0f * g_ComboFrame, 150.0f + 6.0f * g_ComboFrame, 0.0f, 0.0f, 1.0f, 1.0f);
		int xx = combonumber / 10;
		int sajsdkjk = 0;
		if (xx != 0)
		{
			sajsdkjk = 2;
			if (xx >= 10)
			{
				sajsdkjk = 3;
			}
		}
		else
		{
			sajsdkjk = 1;
		}


		for (int i = 0; i < sajsdkjk; i++)
		{
			// 今回表示する桁の数字
			float x = (float)(combonumber % 10);

			// スコアの位置やテクスチャー座標を反映
			float px = g_Pos.x - g_w * i;	// プレイヤーの表示位置X
			float py = g_Pos.y;			// プレイヤーの表示位置Y
			float pw = g_w;				// プレイヤーの表示幅
			float ph = g_h;				// プレイヤーの表示高さ

			float tw = 1.0f / 10;		// テクスチャの幅
			float th = 1.0f / 1;		// テクスチャの高さ
			float tx = x * tw;			// テクスチャの左上X座標
			float ty = 0.0f;			// テクスチャの左上Y座標

			// １枚のポリゴンの頂点とテクスチャ座標を設定
			DrawSprite(g_TexNo, px, py, pw, ph, tx, ty, tw, th);

			// 次の桁へ
			combonumber /= 10;
		}
	}
}


void AddScore(int add)
{
	g_Score += add * (sjdhajhjkjjkf * 0.01f + 1.0f);
	g_scoreBool = true;

	if (g_Score > SCORE_MAX)
	{
		g_Score = SCORE_MAX;
	}
}

void AddComboScore(int add)
{
	g_ComboScoe += add;
	kakudaisyori = true;
	if (g_ComboScoe > SCORE_MAX)
	{
		g_ComboScoe = SCORE_MAX;
	}	
	CheckComboScore();
}

void ResetCombo(void)
{
	g_ComboScoe = 0;
}

int GetScore(void)
{
	return g_Score;
}

int GetComboScore(void)
{
	return g_ComboScoreMax;
}

void CheckComboScore(void)
{
	if (g_ComboScoe >= g_ComboScoreMax)
	{
		g_ComboScoreMax = g_ComboScoe;
	}
}
