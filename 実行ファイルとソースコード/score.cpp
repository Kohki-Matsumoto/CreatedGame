
#include "score.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_WIDTH				(64)	// �L�����T�C�Y
#define TEXTURE_HEIGHT				(128)	// 


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static bool						g_Use;						// true:�g���Ă���  false:���g�p
static float					g_w, g_h;					// ���ƍ���
static D3DXVECTOR3				g_Pos;						// �|���S���̍��W
static int						g_TexNo;					// �e�N�X�`���ԍ�

static int						g_Score;					// �X�R�A
static int						g_ComboScoe = 0;			//�R���{
static int						g_ComboScoreMax;			//�R���{�̍ő�l	

bool kakudaisyori = false;
int g_ComboFrame = 0;

bool g_scoreBool = false;
int g_ScoreFrame = 0;

int sjdhajhjkjjkf = 0;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitScore(void)
{
	//�e�N�X�`������
	g_TexNo = LoadTexture("data/TEXTURE/DebugMode/COMBO_SCORE_03.png");

	//������
	g_Use = true;
	g_w = TEXTURE_WIDTH;
	g_h = TEXTURE_HEIGHT;
	g_Pos = D3DXVECTOR3(800.0f, 200.0f, 0.0f);

	g_Score = 0;	// �X�R�A�̏�����
	g_ComboScoe = 0;//�R���{�̏�����
	g_ComboScoreMax = 0;//�R���{�̍ő�l�̏�����

	kakudaisyori = false;
	g_ComboFrame = 0;

	g_scoreBool = false;
	g_ScoreFrame = 0;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitScore(void)
{
	
}

//=============================================================================
// �X�V����
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
// �`�揈��
//=============================================================================
void DrawScore(void)
{
	//�L�����t���O��ON�Ȃ�`�悷��
	if (g_Use)
	{
		// �e�N�X�`���ݒ�
		GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));

		g_Pos = D3DXVECTOR3(SCREEN_WIDTH - 50.0f, 50.0f, 0.0f);
		g_w = TEXTURE_WIDTH;
		g_h = TEXTURE_HEIGHT;
		// ��������������
		int number = g_Score;
		int combonumber = g_ComboScoe;
		for (int i = 0; i < 6; i++)
		{
			// ����\�����錅�̐���
			float x = (float)(number % 10);

			// �X�R�A�̈ʒu��e�N�X�`���[���W�𔽉f
			float px = g_Pos.x - g_w * i;	// �v���C���[�̕\���ʒuX
			float py = g_Pos.y;			// �v���C���[�̕\���ʒuY
			float pw = g_w;				// �v���C���[�̕\����
			float ph = g_h;				// �v���C���[�̕\������

			float tw = 1.0f / 10;		// �e�N�X�`���̕�
			float th = 1.0f / 1;		// �e�N�X�`���̍���
			float tx = x * tw;			// �e�N�X�`���̍���X���W
			float ty = 0.0f;			// �e�N�X�`���̍���Y���W

			// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
			DrawSprite(LoadTexture("data/TEXTURE/DebugMode/ComboScoreNum.png"), px, py, pw + 10.0f * g_ScoreFrame, ph + 10.0f * g_ScoreFrame, tx, ty, tw, th);

			// ���̌���
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
			// ����\�����錅�̐���
			float x = (float)(combonumber % 10);

			// �X�R�A�̈ʒu��e�N�X�`���[���W�𔽉f
			float px = g_Pos.x - g_w * i;	// �v���C���[�̕\���ʒuX
			float py = g_Pos.y;			// �v���C���[�̕\���ʒuY
			float pw = g_w;				// �v���C���[�̕\����
			float ph = g_h;				// �v���C���[�̕\������

			float tw = 1.0f / 10;		// �e�N�X�`���̕�
			float th = 1.0f / 1;		// �e�N�X�`���̍���
			float tx = x * tw;			// �e�N�X�`���̍���X���W
			float ty = 0.0f;			// �e�N�X�`���̍���Y���W

			// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
			DrawSprite(g_TexNo, px, py, pw, ph, tx, ty, tw, th);

			// ���̌���
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
