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


#define TEXTURE_WIDTH				(32)	// �L�����T�C�Y
#define TEXTURE_HEIGHT				(64)	// 


static bool						g_Use;						// true:�g���Ă���  false:���g�p
static float					g_w, g_h;					// ���ƍ���
static D3DXVECTOR3				g_Pos;						// �|���S���̍��W
static int						g_TexNo;					// �e�N�X�`���ԍ�
bool MoveTx = false;
bool MoveEx = false;
bool rockcheck = false;
int MoveTxCount = 0;

static int						g_Score;					// �X�R�A

int g_resultScoreFrame;

void InitResult()
{
	//�e�N�X�`������
	g_TexNo = LoadTexture("data/TEXTURE/DebugMode/COMBO_SCORE_03.png");

	//������
	g_Use = true;
	g_w = TEXTURE_WIDTH;
	g_h = TEXTURE_HEIGHT;
	g_Pos = D3DXVECTOR3(800.0f, 200.0f, 0.0f);

	g_Score = 0;	// �X�R�A�̏�����

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


		// �e�N�X�`���ݒ�
		GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_TexNo));

		g_Pos = D3DXVECTOR3(-50.0f , 50.0f, 0.0f);//�����ŕ\���ʒu��ς���
		g_w = TEXTURE_WIDTH;
		g_h = TEXTURE_HEIGHT;
		// ��������������
		int number = GetScore();
		int combonumber = GetComboScore();
		for (int i = 0; i < 6; i++)
		{
			// ����\�����錅�̐���
			float x = (float)(number % 10);

			// �X�R�A�̈ʒu��e�N�X�`���[���W�𔽉f
			float px = g_Pos.x - 110.0f * i;	// �v���C���[�̕\���ʒuX
			float py = g_Pos.y;			// �v���C���[�̕\���ʒuY
			float pw = g_w;				// �v���C���[�̕\����
			float ph = g_h;				// �v���C���[�̕\������

			float tw = 1.0f / 10;		// �e�N�X�`���̕�
			float th = 1.0f / 1;		// �e�N�X�`���̍���
			float tx = x * tw;			// �e�N�X�`���̍���X���W
			float ty = 0.0f;			// �e�N�X�`���̍���Y���W

			// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�			�����͓��_�̕\��
			DrawSprite(LoadTexture("data/TEXTURE/DebugMode/ComboScoreNum.png"), px + 18.5f * MoveTxCount, SCREEN_HEIGHT / 2 +450.0f , 100.0f, 100.0f, tx, ty, tw, th);

			// ���̌���
			number /= 10;
		}


		g_Pos = D3DXVECTOR3(-50.0f, 100.0f, 0.0f);
		for (int i = 0; i < 3; i++)
		{
			// ����\�����錅�̐���
			float x = (float)(combonumber % 10);

			// �X�R�A�̈ʒu��e�N�X�`���[���W�𔽉f
			float px = g_Pos.x - 110.0f * i;	// �v���C���[�̕\���ʒuX
			float py = g_Pos.y;			// �v���C���[�̕\���ʒuY
			float pw = g_w;				// �v���C���[�̕\����
			float ph = g_h;				// �v���C���[�̕\������

			float tw = 1.0f / 10;		// �e�N�X�`���̕�
			float th = 1.0f / 1;		// �e�N�X�`���̍���
			float tx = x * tw;			// �e�N�X�`���̍���X���W
			float ty = 0.0f;			// �e�N�X�`���̍���Y���W

			// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
			DrawSprite(g_TexNo, px + 18.5f * MoveTxCount, SCREEN_HEIGHT / 3 + 450.0f, 100.0f, 100.0f, tx, ty, tw, th);//�R���{���̕\��
			// ���̌���
			combonumber /= 10;
		}
		
		DrawSprite(LoadTexture("data/TEXTURE/BG/RESULT_MAXCOMBO_001.png"), 500.0f, SCREEN_HEIGHT / 3 + 350.0f, 500.0f,150.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSprite(LoadTexture("data/TEXTURE/BG/RESULT_SCORE_001.png"), 300.0f, SCREEN_HEIGHT / 3 + 530.0f, 400.0f, 120.0f, 0.0f, 0.0f, 1.0f, 1.0f);

}


