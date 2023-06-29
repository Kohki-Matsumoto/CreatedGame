#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCORE_MAX			(999999)		// �X�R�A�̍ő�l
#define SCORE_DIGIT			(6)			// ����




//*****************************************************************************
// �v���g�^�C�v�錾
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



