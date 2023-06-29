#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Var2.h"
#include "declaration.h"


#define JUMP_HEIGHT		(300.0f)			// ジャンプの高さ
// #define JUMP_TIME_FRAME (15.0f)			// ジャンプの最頂点までにかかるframe
#define JUMP_TIME		(0.5f / JUMP_TIME_FRAME)	// JUMP_TIME_FRAME 経つと最頂点まで行く。
// #define ROTATION_TIME	(30.0f)			// 回転をしている時間
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
	Float2 m_Pos;						//プレイヤーの位置座標
	Float2 m_BefPos;					//プレイヤーも1フレーム前の位置座標
	Float2 m_Size;						//プレイヤーのサイズ(幅,高さ)
	Float2 m_Speed;						//プレイヤーのスピード
	int* TexNum;						//テクスチャのポインタ
	int m_NowFrame;						//テクスチャの現在のフレーム
	bool m_OnGravity = true;			//グラビティを受けるかどうか	true : Gravityがかかる
	bool m_NowJump = false;				//今ジャンプの最中かどうか
	bool m_NowRotation = false;			//今回転の最中かどうか
	bool m_NowSliding = false;			//今スライディングの最中かどうか？

	int g_Playertmpnum_A = 0;

	int m_ActionHistory[334][3] = {};		//プレイヤーのアクション履歴保存用配列
	int m_NowTempNum = 0;					//Game.cppから現在のテンポ数を持ってくるための変数

	long int m_NowSampleNum = 0;			//現在のサンプルレート数
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
	void AddPlayerFrame(PLAYER_STATUS player_status);	//プレイヤーのテクスチャを1frameごとに1ずつ追加していく関数
	void Dojump();									//ジャンプをする関数、最頂点に行ったまでがジャンプしている状態
	void DoRotation();
	void Dosliding();								//スライディングをのアップデートの関数

	void ChangePlayerSize();		// プレイヤーのサイズをプレイヤーの状態を見て変更する関数

	void AddPlayerSpeed(void) { m_Pos.y = m_Pos.y + m_Speed.y; }

	void UpdateAnim(PLAYER_STATUS player_status);

	void RhythmJudgment(void);

    void UpdatePlayer(void);


	//ゲッター
	Float2 GetPlayerPos(void) { return m_Pos; }
	Float2 GetPlayerBefPos(void) { return m_BefPos; }
	Float2 GetPlayerSize(void) { return m_Size; }
	Float2 GetPlayerSpeed(void) { return m_Speed; }
	bool GetPlayerOnGravity(void) { return m_OnGravity; }
	bool GetPlayerNowJump(void) { return m_NowJump; }
	bool GetPlayerNowRotation(void) { return m_NowRotation; }
	PLAYER_STATUS GetPlayerStatus(void) { return m_PlayerStatus; }
	RHYTHMJUDGEMENT GetPlayertektkeks(void) { return tektkeks; }
	//セッター
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
