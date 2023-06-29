#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define SCORE_MAX			(999999)		// スコアの最大値
#define SCORE_DIGIT			(6)			// 桁数




//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitScore(void);
void UninitScore(void);
void UpdateScore(void);
void DrawScore(void);

void AddScore(int add);
void AddComboScore(int add);

void ResetCombo(void);

int GetScore(void);

int GetComboScore(void);

void CheckComboScore(void);



