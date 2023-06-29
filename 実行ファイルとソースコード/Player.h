#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Var2.h"
#include "declaration.h"


#define JUMP_HEIGHT		(300.0f)			// �W�����v�̍���
// #define JUMP_TIME_FRAME (15.0f)			// �W�����v�̍Œ��_�܂łɂ�����frame
#define JUMP_TIME		(0.5f / JUMP_TIME_FRAME)	// JUMP_TIME_FRAME �o�ƍŒ��_�܂ōs���B
// #define ROTATION_TIME	(30.0f)			// ��]�����Ă��鎞��
#define ROTATION_JUMP_HEIGHT (80.0f)
// #define ROTATION_JUMP_TIME (0.5f / ROTATION_TIME)
#define SLIDING_TIME	30.0f

#define JUMP_SHIFT_X 1
#define JUMP_SHIFT_Y 4

#define DRAW_EF_TIME        (10)


static float JumpTime = 0.0f;
static float JumpFinish = 0.0f;
static float JumpStartPos = 0.0f;
static float RotationTime = 0.0f;
static float RotationStartPos = 0.0f;
static float RotateFinish = 0.0f;
static float SlidingTime = 0.0f;



void SetPlayerStatusForStage(float ChangeMagnification);
void ResetPlayerStatusForStage();

class PLAYER
{
private:
	Float2 m_Pos;						//�v���C���[�̈ʒu���W
	Float2 m_BefPos;					//�v���C���[��1�t���[���O�̈ʒu���W
	Float2 m_Size;						//�v���C���[�̃T�C�Y(��,����)
	Float2 m_Speed;						//�v���C���[�̃X�s�[�h
	int* TexNum;						//�e�N�X�`���̃|�C���^
	int m_NowFrame;						//�e�N�X�`���̌��݂̃t���[��
	bool m_OnGravity = true;			//�O���r�e�B���󂯂邩�ǂ���	true : Gravity��������
	bool m_NowJump = false;				//���W�����v�̍Œ����ǂ���
	bool m_NowRotation = false;			//����]�̍Œ����ǂ���
	bool m_NowSliding = false;			//���X���C�f�B���O�̍Œ����ǂ����H

	int g_Playertmpnum_A = 0;

	int m_ActionHistory[334][3] = {};		//�v���C���[�̃A�N�V��������ۑ��p�z��
	int m_NowTempNum = 0;					//Game.cpp���猻�݂̃e���|���������Ă��邽�߂̕ϐ�

	long int m_NowSampleNum = 0;			//���݂̃T���v�����[�g��
	bool m_tyakuti = false;
	PLAYER_STATUS m_BefPlayerStatus;
	OBJECT_TYPE m_Objtype = obj_PLAYER;
	//=====================================
	int tahuasodhiooiask = 0;
	RHYTHMJUDGEMENT tektkeks = INIT_JUGEMENT;
	//=====================================
public:
	//bool xakjsydoiu = false;
    bool KeepSlidingSwitch = false;
	PLAYER_STATUS m_PlayerStatus = DEFAULT;
	void InitPlayer() {
		JumpTime = 0.0f;
		JumpFinish = 0.0f;
		JumpStartPos = 0.0f;
		RotationTime = 0.0f;
		RotationStartPos = 0.0f;
		RotateFinish = 0.0f;
		SlidingTime = 0.0f;

		g_Playertmpnum_A = 0;

		m_Pos = MakeFloat2(0.0f, 0.0f);					
		m_BefPos = MakeFloat2(0.0f, 0.0f);
		m_Size = MakeFloat2(0.0f, 0.0f);
		m_Speed = MakeFloat2(0.0f, 0.0f);
		m_NowFrame = 0;					
		m_OnGravity = true;		
		m_NowJump = false;			
		m_NowRotation = false;		
		m_NowSliding = false;		
		m_NowTempNum = 0;			

		for (int i = 0; i < 334; i++)
		{
			m_ActionHistory[1][0] = 0;
			m_ActionHistory[1][1] = 0;
			m_ActionHistory[1][2] = 0;
		}

		m_NowSampleNum = 0;	
		m_tyakuti = false;
	}
	void DrawPlayer(PLAYER_STATUS player_status);
	void AddPlayerFrame(PLAYER_STATUS player_status);	//�v���C���[�̃e�N�X�`����1frame���Ƃ�1���ǉ����Ă����֐�
	void Dojump();									//�W�����v������֐��A�Œ��_�ɍs�����܂ł��W�����v���Ă�����
	void DoRotation();
	void Dosliding();								//�X���C�f�B���O���̃A�b�v�f�[�g�̊֐�

	void ChangePlayerSize();		// �v���C���[�̃T�C�Y���v���C���[�̏�Ԃ����ĕύX����֐�

	void AddPlayerSpeed(void) { m_Pos.y = m_Pos.y + m_Speed.y; }

	void UpdateAnim(PLAYER_STATUS player_status);

	void RhythmJudgment(void);

    void UpdatePlayer(void);


	//�Q�b�^�[
	Float2 GetPlayerPos(void) { return m_Pos; }
	Float2 GetPlayerBefPos(void) { return m_BefPos; }
	Float2 GetPlayerSize(void) { return m_Size; }
	Float2 GetPlayerSpeed(void) { return m_Speed; }
	bool GetPlayerOnGravity(void) { return m_OnGravity; }
	bool GetPlayerNowJump(void) { return m_NowJump; }
	bool GetPlayerNowRotation(void) { return m_NowRotation; }
	PLAYER_STATUS GetPlayerStatus(void) { return m_PlayerStatus; }
	RHYTHMJUDGEMENT GetPlayertektkeks(void) { return tektkeks; }
	//�Z�b�^�[
	void SetPlayerPos(Float2 Pos) { m_Pos = Pos; }
	void SetPlayerBefPos(Float2 BefPos) { m_BefPos = BefPos; }
	void SetPlayerSize(Float2 Size) { m_Size = Size; }
	void SetPlayerSpeed(Float2 Speed) { m_Speed = Speed; }
	void SetPlayerOnGravity(bool OnGravity) { m_OnGravity = OnGravity; }
	void SetPlayerNowJump(bool NowJump) { m_NowJump = NowJump; }
	void SetPlayerNowRotation(bool NowRotation) { m_NowRotation = NowRotation; }
	void SetPlayerNowSliding(bool NowSliding) { m_NowSliding = NowSliding; }
	void SetPlayerStatus(PLAYER_STATUS PlayerStatus) { m_BefPlayerStatus = PlayerStatus; }
	void SetPlayertempnum(int nkalks) { m_NowTempNum = nkalks; }
	void SetPlayerNowSampleNum(long int num) { m_NowSampleNum = num; }


    int Getg_Playertmpnum(void);
};




#endif
