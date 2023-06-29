/*==============================================================================

   �e�N�X�`���̕`�� [main.cpp]
                                                         Author : 
                                                         Date   : 
--------------------------------------------------------------------------------

==============================================================================*/
#include "main.h"
#include <time.h>
#include "renderer.h"
#include "input.h"
#include "sound.h"
#include "texture.h"
#include "sprite.h"
#include "Scene.h"
#include "Game.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "fade.h"
#include "Debugmain.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define CLASS_NAME			"GameWindow"			// �E�C���h�E�̃N���X��
#define WINDOW_CAPTION		"���Y��=Brain"			// �E�C���h�E�̃L���v�V������

#define DEBUGMODEON			false					//�f�o�b�O���[�h�̃I���I�t(treu = �I��)
//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(void);
void Draw(void);


//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
HWND p_windinf;
float WindowRatio;							//�V�X�e���̃A�C�R���̊g�嗦(�ڂ������V���܂�)
#ifdef _DEBUG
int		g_CountFPS;							// FPS�J�E���^
char	g_DebugStr[2048] = WINDOW_CAPTION;	// �f�o�b�O�����\���p
#endif


//=============================================================================
// ���C���֐�
//=============================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);	// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j
	UNREFERENCED_PARAMETER(lpCmdLine);		// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j

	//�����_���V�[�h�̏�����
	srand((unsigned int)time(NULL));

	// ���Ԍv���p
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;
	
	WNDCLASSEX	wcex = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW+1),
		NULL,
		CLASS_NAME,
		NULL
	};
	HWND		hWnd;
	MSG			msg;
	
	// �E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);
	WindowRatio = (float)GetSystemMetrics(SM_CXFULLSCREEN) / (float)SCREEN_WIDTH;
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(
		CLASS_NAME,
		WINDOW_CAPTION,
		WS_POPUPWINDOW,			//������ WS_POPUPWINDOW �ɕς��邱�ƂŃt���X�N���[���ɂȂ�܂��B(�ڍׂ͒�`��Go�I)
		CW_USEDEFAULT,																		// �E�B���h�E�̍����W
		CW_USEDEFAULT,																		// �E�B���h�E�̏���W
		(int)((float)SCREEN_WIDTH * WindowRatio),																		// �E�B���h�E����
		(int)((float)SCREEN_HEIGHT * WindowRatio),																		// �E�B���h�E�c��
		NULL,
		NULL,
		hInstance,
		NULL);

	
	int x = CW_USEDEFAULT;
	x = GetSystemMetrics(SM_CYFULLSCREEN);
	x = x;
	// DirectX�̏�����(�E�B���h�E���쐬���Ă���s��)
	if(FAILED(Init(hInstance, hWnd, true)))
	{
		return -1;
	}

	// �t���[���J�E���g������
	timeBeginPeriod(1);	// ����\��ݒ�
	dwExecLastTime = dwFPSLastTime = timeGetTime();	// �V�X�e���������~���b�P�ʂŎ擾
	dwCurrentTime = dwFrameCount = 0;
	
	// �E�C���h�E�̕\��(Init()�̌�ɌĂ΂Ȃ��Ƒʖ�)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	// ���b�Z�[�W���[�v
	while(1)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{// PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();					// �V�X�e���������擾

			if ((dwCurrentTime - dwFPSLastTime) >= 1000)	// 1�b���ƂɎ��s
			{
#ifdef _DEBUG
				g_CountFPS = dwFrameCount;
#endif
				dwFPSLastTime = dwCurrentTime;				// FPS�𑪒肵��������ۑ�
				dwFrameCount = 0;							// �J�E���g���N���A
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000.0f / 60))	// 1/60�b���ƂɎ��s
			{
				dwExecLastTime = dwCurrentTime;	// ��������������ۑ�

#ifdef _DEBUG	// �f�o�b�O�ł̎�����FPS��\������
				wsprintf(g_DebugStr, WINDOW_CAPTION);
				wsprintf(&g_DebugStr[strlen(g_DebugStr)], " FPS:%d", g_CountFPS);
				SetWindowText(hWnd, g_DebugStr);
#endif

				//p_windinf = hWnd;
				Update();			// �X�V����
				Draw();				// �`�揈��

				CheckScene();

				dwFrameCount++;		// �����񐔂̃J�E���g�����Z
			}
		}
	}
	
	timeEndPeriod(1);				// ����\��߂�

	// �I������
	Uninit();

	// �E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//=============================================================================
// �v���V�[�W��
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_ESCAPE:					// [ESC]�L�[�������ꂽ
			DestroyWindow(hWnd);		// �E�B���h�E��j������悤�w������
			break;
		}
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	

	// �����_�����O�����̏�����
	InitRenderer(hInstance, hWnd, bWindow);

	// ���͏����̏�����
	InitInput(hInstance, hWnd);

	// �T�E���h�����̏�����
	InitSound(hWnd);

	

	// �X�v���C�g�̏�����
	InitSprite();


	//==============================================
	//�����艺��Init
	//==============================================
	InitTextureManager();
	InitSoundManager();
	
	InitFade();

	//SetScene(SCENE_TITLE);
	//	InitGame();
	//�V�[���̏������i�^�C�g������X�^�[�g�j
	SetFadeColor(0.0f, 0.0f, 0.0f);
	SceneFadeIn(SCENE_TITLE);
	return S_OK;
}


//=============================================================================
// �I������
//=============================================================================
void Uninit(void)
{
	// �X�v���C�g�̏I������
	UninitSprite();

	UninitFade();

	// �e�N�X�`���̉��
	UninitTexture();

	// �T�E���h�̏I������
	StopSoundAll();
	UninitSound();

	// ���͂̏I������
	UninitInput();

	// �����_�����O�̏I������
	UninitRenderer();
}

//=============================================================================
// �X�V����
//=============================================================================
void Update(void)
{

	
	//���͌n�̍X�V����
	UpdateInput();

		UpdateScene();
		//UpdateGame();
}

//=============================================================================
// �`�揈��
//=============================================================================
void Draw(void)
{
	// �o�b�N�o�b�t�@�N���A
	Clear();

	// �}�g���N�X�ݒ�
	SetWorldViewProjection2D();//���W��2D�ϊ�

	// 2D�`��Ȃ̂Ő[�x����
	SetDepthEnable(false);


		DrawScene();
		//DrawGame();

	// �o�b�N�o�b�t�@�A�t�����g�o�b�t�@����ւ�
	Present();

	

}


float frand(void)
{
	return (float)rand() / RAND_MAX;
}

HWND GetWindowInf(void)
{
	return p_windinf;
}