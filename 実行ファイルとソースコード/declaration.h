#ifndef _DECLARATION_H_
#define _DECLARATION_H_
#include "Var2.h"


//ゲームオブジェクトタイプ
typedef enum {
	obj_PLAYER,
	obj_FIELD,
	obj_BACKGROUND
}OBJECT_TYPE;

//プレイヤーの状態
typedef enum {
	DEFAULT,
	DASH,
	JUMP,
	FALL,
	ROTATION,
	SLIDING,
	MAX_PLAYER_STATUS
}PLAYER_STATUS;





//背景画像深度
typedef enum {
	FRONT,
	FIRST,
	SECOND,
	THIRD
}OBJECT_DEPTH;

//シーンの状態
typedef enum 
{
	SCENE_NONE,			//特に何もなし		番号			0
	SCENE_TITLE,		//タイトル			番号			1
	SCENE_MENU,			//メニュー			番号			2
	SCENE_CONFIG,		//設定シーン		番号			3
	SCENE_GAME,			//ゲームシーン		番号			4
	SCENE_SUBCONFIG,	//サブ設定シーン	番号			5
	SCENE_RESULT,		//リザルトシーン	番号			6
	SCENE_MAX			//シーン最後		番号			7

}SCENE;

typedef enum
{
	JUDGEMENT_MISS,
	JUDGEMENT_GOOD,
	JUDGEMENT_PERFECT,
	INIT_JUGEMENT,
}RHYTHMJUDGEMENT;
//フェードの状態
typedef enum
{
	FADE_NONE,
	FADE_IN,
	FADE_OUT
}FADE_STATS;


typedef enum
{
	JUMP_JUMP = 1,
	JUMP_JUMP_JUMP,
	JUMP_ROTATION,
	SLIDING_JUMP,
	SLIDING_JUMP_ROTATION,
	JUMP_JUMP_ROTATION
}TRICK_NUM;

//入力されたキーの番号
typedef struct
{
	bool KEY_X;
	bool KEY_Y;
	bool KEY_A;
	bool KEY_B;
}KEYNUM;

//==============================================================
// 
// *マクロ定義一覧
//
//==============================================================

//---------------------------------
//テクスチャ関連
//---------------------------------
/*プレイヤー関連テクスチャ名*/
#define PLAYER_ANI_DEFAULT					"data/TEXTURE/PLAYER/ani/run_001.png"
#define PLAYER_ANI_DASH						"data/TEXTURE/PLAYER/ani/default_2.png"


#define PLAYER_ANI_JUMP						"data/TEXTURE/PLAYER/ani/jump_004.png"
#define PLAYER_ANI_FALL						"data/TEXTURE/PLAYER/ani/fall.png"
#define PLAYER_ANI_ROTATION					"data/TEXTURE/PLAYER/ani/rotation.png"
#define PLAYER_ANI_SLIDING					"data/TEXTURE/PLAYER/ani/sliding_003.png"

/*プレイヤー関連テクスチャの分割数(x,y)*/
#define PLAYER_ANI_DEFAULT_NUM				6,4
#define PLAYER_ANI_DASH_NUM					1,1
#define PLAYER_ANI_JUMP_NUM					6,4
#define PLAYER_ANI_FALL_NUM					1,1
#define PLAYER_ANI_ROTATION_NUM				5,3
#define PLAYER_ANI_SLIDING_NUM				5,2

//テクスチャの名前と分割数を扱う構造体
typedef struct TEXINF_PLAYER_ANI {
	int fileNum = 0;
	Int2 TexNum = MakeInt2(0,0);
}TEXINF_PLAYER_ANI;

/*フィールド関連のマクロ*/

/*フィールドのテクスチャ名*/
#define FIELD_TEXTURE_NAME_001				"data/TEXTURE/FIELD/car.png"
#define FIELD_TEXTURE_SIZE_001				490.0f, 220.0f
#define FIELD_TEXTURE_NAME_002				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_002				100.0f, 100.0f
#define FIELD_TEXTURE_NAME_003				"data/TEXTURE/FIELD/zihanki.png"
#define FIELD_TEXTURE_SIZE_003				250.0f, 220.0f
#define FIELD_TEXTURE_NAME_004				"data/TEXTURE/FIELD/W1_S1_004.png"
#define FIELD_TEXTURE_SIZE_004				250.0f, 445.0f
#define FIELD_TEXTURE_NAME_005				"data/TEXTURE/FIELD/W1_S1_005.png"
#define FIELD_TEXTURE_SIZE_005				250.0f, 1000.0f
#define FIELD_TEXTURE_NAME_006				"data/TEXTURE/FIELD/house.png"
#define FIELD_TEXTURE_SIZE_006				1000.0f, 445.0f
#define FIELD_TEXTURE_NAME_007				"data/TEXTURE/FIELD/kanban.png"
#define FIELD_TEXTURE_SIZE_007				250.0f, 110.0f
#define FIELD_TEXTURE_NAME_008				"data/TEXTURE/FIELD/shako.png"
#define FIELD_TEXTURE_SIZE_008				500.0f, 445.0f
#define FIELD_TEXTURE_NAME_009				"data/TEXTURE/FIELD/hasira.png"
#define FIELD_TEXTURE_SIZE_009				250.0f, 660.0f
//ここからステージ2用
#define FIELD_TEXTURE_NAME_010				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_010				255.0f, 220.0f
#define FIELD_TEXTURE_NAME_011				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_011				510.0f, 220.0f
#define FIELD_TEXTURE_NAME_012				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_012				765.0f, 220.0f
#define FIELD_TEXTURE_NAME_013				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_013				1020.0f, 220.0f
#define FIELD_TEXTURE_NAME_014				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_014				1275.0f, 220.0f
#define FIELD_TEXTURE_NAME_015				"data/TEXTURE/FIELD/field_001.png"
#define FIELD_TEXTURE_SIZE_015				1530.0f, 220.0f


typedef enum
{
	W1_S1_001,
	W1_S1_002,
	W1_S1_003,
	W1_S1_004,
	W1_S1_005,
	W1_S1_006,
	W1_S1_007,
	W1_S1_008,
	W1_S1_009,
	W1_S2_001,
	W1_S2_002,
	W1_S2_003,
	W1_S2_004,
	W1_S2_005,
	W1_S2_006,
	//W1_S1_010,
	//W1_S1_011,
	//W1_S1_012,
	//W1_S1_013,
	//W1_S1_014,
	//W1_S1_015,
	//W1_S1_016,
	//W1_S1_017,
	MAX_FIELD_TEXTURE_NUM,
}FIELD_TEXTURE_NUM;

typedef struct {
	int fileNum = 0;
	Float2 fieldsize;
}TEXINF_FIELD;

/*BGのテクスチャ名*/
#define BG_TEXTURE_NAME_001					"data/TEXTURE/BG/BG_002.png"
#define BG_TEXTURE_NAME_002					"data/TEXTURE/BG/BG_003.png"
#define BG_TEXTURE_NAME_003					"data/TEXTURE/BG/BG_004.png"
#define BG_TEXTURE_NAME_004					"data/TEXTURE/BG/BG_005.png"
#define BG_TEXTURE_NAME_005					"data/TEXTURE/BG/guardrail.png"
#define BG_TEXTURE_NAME_006					"data/TEXTURE/BG/tree3.png"
// #define BG_TEXTURE_NAME_007					"data/TEXTURE/BG/Future_1.png"
// #define BG_TEXTURE_NAME_008					"data/TEXTURE/BG/Future_2.png"


typedef enum
{
	BG_001,
	BG_002,
	BG_003,
	BG_004,
	BG_005,
	BG_006,
	// BG_007,
	// BG_008,
	// BG_009,
	MAX_BG_TEXTURE_NUM,
}BG_TEXTURE_NUM;

typedef struct {
	int fileNum = 0;
}TEXINF_BG;

//シーンのテクスチャ名
#define SCENE_TEXTURE_NAME_001				"data/TEXTURE/BG/Title_002.png"
#define SCENE_TEXTURE_NAME_002				"data/TEXTURE/BG/Menu_001.png"
#define SCENE_TEXTURE_NAME_003				"data/TEXTURE/BG/Result_002.png"
#define SCENE_TEXTURE_NAME_004				"data/TEXTURE/BG/Poze_002.png"

typedef struct
{
	int fileNum = 0;
}TEXINF_SCENE;

//=====================================================================================
// 
//   エフェクト関連
// 
// ====================================================================================
#define MAX_EF_NUM						(100)     //一度に表示できるエフェクトの最大数
//エフェクトのテクスチャー名
#define EF_TEXTURE_NAME_001				"data/TEXTURE/EF/JUMP_JUMP.png"
#define EF_TEXTURE_NUM_001				1,1

#define EF_TEXTURE_NAME_002				"data/TEXTURE/EF/JUMPJUMP_JUMP.png"
#define EF_TEXTURE_NUM_002				1,1

#define EF_TEXTURE_NAME_003				"data/TEXTURE/EF/JUMP_ROTATE.png"
#define EF_TEXTURE_NUM_003				1,1

#define EF_TEXTURE_NAME_004				"data/TEXTURE/EF/SLIDING_JUMP.png"
#define EF_TEXTURE_NUM_004				1,1

#define EF_TEXTURE_NAME_005				"data/TEXTURE/EF/SLIDING_JUMP_ROTATE.png"
#define EF_TEXTURE_NUM_005				1,1

#define EF_TEXTURE_NAME_006				"data/TEXTURE/EF/JUMPJUMP_ROTATE.png"
#define EF_TEXTURE_NUM_006				1,1

#define EF_TEXTURE_NAME_007				"data/TEXTURE/EF/EF_Good.png"
#define EF_TEXTURE_NUM_007				1,1

#define EF_TEXTURE_NAME_008				"data/TEXTURE/EF/EF_Miss.png"
#define EF_TEXTURE_NUM_008				1,1

#define EF_TEXTURE_NAME_009				"data/TEXTURE/EF/EF_Perfect_001.png"
#define EF_TEXTURE_NUM_009				6,4

#define EF_TEXTURE_NAME_0010			"data/TEXTURE/EF/EF_ri_A.png"
#define EF_TEXTURE_NUM_0010				1,1

#define EF_TEXTURE_NAME_0011			"data/TEXTURE/EF/EF_ri_B.png"
#define EF_TEXTURE_NUM_0011				1,1

#define EF_TEXTURE_NAME_0012			"data/TEXTURE/EF/jump_effect001.png"
#define EF_TEXTURE_NUM_0012				1,1

#define EF_TEXTURE_NAME_0013			"data/TEXTURE/EF/rotation_effect001.png"
#define EF_TEXTURE_NUM_0013				1,1

#define EF_TEXTURE_NAME_0014			"data/TEXTURE/EF/rotation_effect002.png"
#define EF_TEXTURE_NUM_0014				1,1

#define EF_TEXTURE_NAME_0015			"data/TEXTURE/EF/running_effect001.png"
#define EF_TEXTURE_NUM_0015				1,1

#define EF_TEXTURE_NAME_0016			"data/TEXTURE/EF/light.png"
#define EF_TEXTURE_NUM_0016				5,2

#define EF_TEXTURE_NAME_0017			"data/TEXTURE/EF/EF_Rhythm_Ani.png"
#define EF_TEXTURE_NUM_0017				5,2



//エフェクトの状態
typedef enum {
	DEFAULT_EFECT,
	DOUBLEJUMP_FIGURE,
	TRIPLEJUMP_FIGURE,
	JUMPROTATE_FIGURE,
	SLIDINGJUMP_FIGURE,
	SLIDINGJUMPROTATE_FIGURE,
	JUMPJUMPROTATE_FIGURE,
	GOOD_FIGURE,
	MISS_FIGURE,
	PERFECT_FIGURE,
	RING_A_EF,
	RING_B_EF,
	JUMP_EF,
	ROTATE_EF,
	ROTATE2_EF,
	RUNNING_EF,
	LIGHT_EF,
	EF_RHYTHM_ANIi,
	MAX_EF_STATUS
}EF_STATUS;




typedef struct
{
	int fileNum = 0;
	Int2 TexNum = MakeInt2(0, 0);

}EF_INF;

//---------------------------------
//サウンドファイル名
//---------------------------------
/*BGM*/
//BGMの型
typedef struct {
	int fileNum = 0;
	int samplenum = 0;
}BGMINF;

#define BGM_NAME_001						"data/SOUND/BGM/001.wav"
#define BGM_NAME_002						"data/SOUND/BGM/BBBB.wav"
#define BGM_NAME_003						"data/SOUND/BGM/stage2_bgm.wav"
#define BGM_NAME_004						"data/SOUND/BGM/.wav"
#define BGM_NAME_005						"data/SOUND/BGM/TItle_BGM.wav"

/*1テンポのサンプル数*/
#define BGM_NAME_001_SAMPLE_Num				0
#define BGM_NAME_002_SAMPLE_Num				19600
#define BGM_NAME_003_SAMPLE_Num				17640
#define BGM_NAME_004_SAMPLE_Num				0

#define BGM_MAX_TEMP_NUM_002				281
#define BGM_MAX_TEMP_NUM_003				333
//BGMの管理名※詳細はinputシートにて
typedef enum
{
	BGM_001,
	BGM_002,
	BGM_003,
	BGM_005,
	MAX_BGM_NUM,
}SOUND_BGM_NUM;

/*SE*/
//SEの型
typedef struct {
	int fileNum = 0;
}SEINF;

#define SE_NAME_001							"data/SOUND/BGM/jump.wav"
#define SE_NAME_002							"data/SOUND/BGM/SE_01.wav"
#define SE_NAME_003							"data/SOUND/SE/jump.wav"
#define SE_NAME_004							"data/SOUND/SE/sliding.wav"
#define SE_NAME_005							"data/SOUND/SE/tyakuti.wav"
#define SE_NAME_006							"data/SOUND/SE/kaiten.wav"
#define SE_NAME_007							"data/SOUND/SE/miss_001.wav"
#define SE_NAME_008							"data/SOUND/SE/good_001.wav"
#define SE_NAME_009							"data/SOUND/SE/perfect_001.wav"
#define SE_NAME_010							"data/SOUND/SE/combo_1.wav"
#define SE_NAME_011							"data/SOUND/SE/combo_2.wav"
#define SE_NAME_012							"data/SOUND/SE/combo_3.wav"
#define SE_NAME_013							"data/SOUND/SE/select.wav "
#define SE_NAME_014							"data/SOUND/SE/select_moveon.wav "
#define SE_NAME_015							"data/SOUND/SE/select_return.wav "
#define SE_NAME_016							"data/SOUND/SE/title.wav "
#define SE_NAME_017							"data/SOUND/SE/SE_go.wav "
#define SE_NAME_018							"data/SOUND/SE/SE_ready.wav "


//BGMの管理名※詳細はinputシートにて
typedef enum {
	SE_001,
	SE_002,
	SE_JUMP,
	SE_SLIDING,
	SE_TYAKUTI,
	SE_KAITEN,
	SE_miss,
	SE_good,
	SE_perfect,
	SE_combo_1,
	SE_combo_2,
	SE_combo_3,
	SE_SELECT_1,
	SE_SELECT_OK_1,
	SE_SELECT_BACK_1,
	SE_TITLE_1,
	SE_GO_1,
	SE_READY_1,
	MAX_SE_NUM,
}SOUND_SE_NUM;





//===================================================
//その他
//===================================================
#define RECEPTION_MAX_TIME			(5)







//===================================================
//ステージ情報
//===================================================
typedef enum {
	STAGE1_1,
	STAGE1_2,
	STAGE1_3,
	STAGE2_1,
	STAGE2_2,
	STAGE2_3,
	MAX_STAGE,
}STAGE_NAME;


#define MAX_STAGE_1_3FIELD		(88)
typedef struct {
	int m_max_Fieldnum = MAX_STAGE_1_3FIELD;
	int m_RhythmJudgement[MAX_STAGE_1_3FIELD][2] =
	{
		{17, JUMP},
		{25, JUMP},
		{27, JUMP},
		{32, JUMP},
		{36, JUMP},
		{40, JUMP},
		{44, JUMP},
		{48, JUMP},
		{50, SLIDING},
		{54, SLIDING},
		{58, SLIDING},
		{62, SLIDING},
		{64, SLIDING},
		{66, SLIDING},
		{68, JUMP},
		{72, JUMP},
		{74, SLIDING},
		{76, JUMP},
		{78, SLIDING},
		{79, JUMP},
		{80, JUMP},
		{84, JUMP},
		{86, JUMP},
		{87, SLIDING},
		{88, JUMP},
		{90, JUMP},
		{92, JUMP},
		{93, SLIDING},
		{94, JUMP},
		{95, JUMP},
		{96, ROTATION},
		{99, JUMP},
		{104, JUMP},
		{108, JUMP},
		{110, SLIDING},
		{111, JUMP},
		{112, JUMP},
		{116, JUMP},
		{119, SLIDING},
		{120, JUMP},
		{124, JUMP},
		{126, JUMP},
		{127, JUMP},
		{128, ROTATION},
		{137, JUMP},
		{145, JUMP},
		{153, JUMP},
		{157, JUMP},
		{164, JUMP},
		{167, SLIDING},
		{168, JUMP},
		{172, JUMP},
		{175, JUMP},
		{176, JUMP},
		{179, SLIDING},
		{180, JUMP},
		{182, JUMP},
		{184, JUMP},
		{187, SLIDING},
		{188, JUMP},
		{190, JUMP},
		{191, JUMP},
		{192, ROTATION},
		{196, SLIDING},
		{200, SLIDING},
		{204, SLIDING},
		{207, JUMP},
		{208, JUMP},
		{212, JUMP},
		{215, JUMP},
		{216, SLIDING},
		{219, SLIDING},
		{220, JUMP},
		{225, JUMP},
		{226, SLIDING},
		{227, JUMP},
		{228, JUMP},
		{229, SLIDING},
		{230, SLIDING},
		{231, JUMP},
		{232, JUMP},
		{237, JUMP},
		{238, JUMP},
		{239, SLIDING},
		{240, JUMP},
		{241, ROTATION}
	};


	float m_PlacementField[MAX_STAGE_1_3FIELD] = {			//配置するタイミングのリズム(0.1fまで)
	17.0f,
	27.0f,
	32.0f,
	36.0f,
	40.0f,
	44.0f,
	49.5f,
	53.5f,
	57.5f,
	61.5f,
	63.5f,
	65.5f,
	68.0f,
	73.5f,
	77.5f,
	79.0f,
	80.0f,
	84.0f,
	84.5f,
	85.5f,
	86.0f,
	86.5f,
	88.0f,
	92.0f,
	92.5f,
	93.0f,
	94.0f,
	99.0f,
	104.0f,
	108.0f,
	108.5f,
	109.5f,
	109.5f,
	110.5f,
	111.0f,
	112.0f,
	116.0f,
	118.5f,
	120.0f,
	124.0f,
	125.0f,
	126.0f,
	137.0f,
	145.0f,
	153.0f,
	157.0f,
	164.0f,
	166.5f,
	168.0f,
	172.0f,
	175.0f,
	176.0f,
	178.5f,
	180.0f,
	181.0f,
	182.0f,
	184.0f,
	186.5f,
	188.0f,
	189.0f,
	190.0f,
	195.5f,
	199.5f,
	203.5f,
	207.0f,
	208.0f,
	209.0f,
	212.0f,
	215.0f,
	215.5f,
	215.5f,
	218.5f,
	220.0f,
	225.0f,
	225.5f,
	226.0f,
	227.0f,
	228.5f,
	229.0f,
	229.6f,
	231.0f,
	237.0f,
	238.0f,
	238.5f,
	238.5f,
	239.5f,
	241.0f,
	241.5f
	};
	FIELD_TEXTURE_NUM m_FieldTexNum[MAX_STAGE_1_3FIELD] = { //配置するテクスチャの番号
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_003,
		W1_S1_005,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_003,
		W1_S1_001,
		W1_S1_003,
		W1_S1_006,
		W1_S1_005,
		W1_S1_009,
		W1_S1_001,
		W1_S1_005,
		W1_S1_001,
		W1_S1_008,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_005,
		W1_S1_003,
		W1_S1_008,
		W1_S1_009,
		W1_S1_003,
		W1_S1_005,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_004,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_009,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_005,
		W1_S1_005,
		W1_S1_003,
		W1_S1_001,
		W1_S1_005,
		W1_S1_001,
		W1_S1_006,
		W1_S1_005,
		W1_S1_006,
		W1_S1_005,
		W1_S1_009,
		W1_S1_001,
		W1_S1_004,
		W1_S1_008,
		W1_S1_005,
		W1_S1_004,
		W1_S1_003,
		W1_S1_008
	};
	//配置する高さ(0→地面に接触している状態, 1→スライディングで通れる高さ)
	int m_PlacementFigh[MAX_STAGE_1_3FIELD] = {
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		1,
		1,
		1,
		1,
		1,
		0,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		3,
		0,
		0,
		2,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		1,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		1,
		0,
		0,
		2,
		0,
		0,
		3,
		0,
		3,
		0,
		0,
		0,
		0,
		3,
		0,
		0,
		0,
	};

}STAGE1_3_PLACEMENT_FIELD;

#define MAX_STAGE_1_2FIELD		(79)
typedef struct {
	int m_max_Fieldnum = MAX_STAGE_1_2FIELD;
	int m_RhythmJudgement[MAX_STAGE_1_2FIELD][2] =
	{
		{17, JUMP},
		{27, JUMP},
		{32, JUMP},
		{36, JUMP},
		{40, JUMP},
		{44, JUMP},
		{50, SLIDING},
		{54, SLIDING},
		{58, SLIDING},
		{62, SLIDING},
		{66, SLIDING},
		{68, JUMP},
		{74, SLIDING},
		{79, JUMP},
		{80, JUMP},
		{84, JUMP},
		{86, JUMP},
		{88, JUMP},
		{92, JUMP},
		{94, JUMP},
		{95, JUMP},
		{99, JUMP},
		{104, JUMP},
		{108, JUMP},
		{110, SLIDING},
		{111, JUMP},
		{116, JUMP},
		{119, SLIDING},
		{120, JUMP},
		{124, JUMP},
		{126, JUMP},
		{127, JUMP},
		{137, JUMP},
		{145, JUMP},
		{153, JUMP},
		{157, JUMP},
		{164, JUMP},
		{167, SLIDING},
		{168, JUMP},
		{172, JUMP},
		{175, JUMP},
		{176, JUMP},
		{179, SLIDING},
		{180, JUMP},
		{182, JUMP},
		{184, JUMP},
		{187, SLIDING},
		{188, JUMP},
		{190, JUMP},
		{191, JUMP},
		{192, ROTATION},
		{196, SLIDING},
		{200, SLIDING},
		{204, SLIDING},
		{207, JUMP},
		{208, JUMP},
		{212, JUMP},
		{215, JUMP},
		{216, SLIDING},
		{219, SLIDING},
		{220, JUMP},
		{225, JUMP},
		{227, JUMP},
		{229, SLIDING},
		{231, JUMP},
		{237, JUMP},
		{238, JUMP},
		{239, SLIDING},
		{240, JUMP}
	};


	float m_PlacementField[MAX_STAGE_1_2FIELD] = {			//配置するタイミングのリズム(0.1fまで)
	17.0f,
	27.0f,
	32.0f,
	36.0f,
	40.0f,
	44.0f,
	49.5f,
	53.5f,
	57.5f,
	61.5f,
	65.5f,
	68.0f,
	73.5f,
	79.0f,
	80.0f,
	84.0f,
	84.5f,
	85.5f,
	86.0f,
	88.0f,
	92.0f,
	93.0f,
	94.0f,
	99.0f,
	104.0f,
	108.0f,
	108.5f,
	109.5f,
	109.5f,
	110.5f,
	111.0f,
	116.0f,
	118.5f,
	120.0f,
	124.0f,
	125.0f,
	126.0f,
	137.0f,
	145.0f,
	153.0f,
	157.0f,
	164.0f,
	166.5f,
	168.0f,
	172.0f,
	175.0f,
	176.0f,
	178.5f,
	180.0f,
	181.0f,
	182.0f,
	184.0f,
	186.5f,
	188.0f,
	189.0f,
	190.0f,
	195.5f,
	199.5f,
	203.5f,
	207.0f,
	208.0f,
	208.5f,
	212.0f,
	215.0f,
	215.5f,
	215.5f,
	218.5f,
	220.0f,
	225.0f,
	226.0f,
	227.0f,
	228.5f,
	229.0f,
	231.0f,
	237.0f,
	238.0f,
	238.5f,
	238.5f,
	239.5f,
	};
	FIELD_TEXTURE_NUM m_FieldTexNum[MAX_STAGE_1_2FIELD] = { //配置するテクスチャの番号
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_003,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_003,
		W1_S1_001,
		W1_S1_003,
		W1_S1_006,
		W1_S1_009,
		W1_S1_001,
		W1_S1_001,
		W1_S1_008,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_005,
		W1_S1_003,
		W1_S1_008,
		W1_S1_003,
		W1_S1_005,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_004,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_009,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_001,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_005,
		W1_S1_005,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_005,
		W1_S1_006,
		W1_S1_009,
		W1_S1_001,
		W1_S1_004,
		W1_S1_008,
		W1_S1_005,
		W1_S1_004,
	};
	//配置する高さ(0→地面に接触している状態, 1→スライディングで通れる高さ)
	int m_PlacementFigh[MAX_STAGE_1_2FIELD] = {
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		1,
		1,
		1,
		1,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		1,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		1,
		0,
		0,
		0,
		0,
		3,
		0,
		0,
		0,
		0,
		0,
		3,
		0,
	};

}STAGE1_2_PLACEMENT_FIELD;

#define MAX_STAGE_1_1FIELD		(66)
typedef struct {
	int m_max_Fieldnum = MAX_STAGE_1_1FIELD;
	int m_RhythmJudgement[MAX_STAGE_1_1FIELD][2] =
	{
		{17, JUMP},
		{27, JUMP},
		{32, JUMP},
		{36, JUMP},
		{40, JUMP},
		{44, JUMP},
		{50, SLIDING},
		{58, SLIDING},
		{68, JUMP},
		{74, SLIDING},
		{79, JUMP},
		{80, JUMP},
		{84, JUMP},
		{86, JUMP},
		{92, JUMP},
		{94, JUMP},
		{99, JUMP},
		{104, JUMP},
		{108, JUMP},
		{111, JUMP},
		{116, JUMP},
		{119, SLIDING},
		{124, JUMP},
		{126, JUMP},
		{137, JUMP},
		{145, JUMP},
		{153, JUMP},
		{157, JUMP},
		{164, JUMP},
		{167, SLIDING},
		{168, JUMP},
		{172, JUMP},
		{175, JUMP},
		{176, JUMP},
		{179, SLIDING},
		{180, JUMP},
		{187, SLIDING},
		{188, JUMP},
		{190, JUMP},
		{196, SLIDING},
		{200, SLIDING},
		{204, SLIDING},
		{207, JUMP},
		{208, JUMP},
		{212, JUMP},
		{215, JUMP},
		{219, SLIDING},
		{220, JUMP},
		{225, JUMP},
		{227, JUMP},
		{231, JUMP},
		{237, JUMP},
		{239, SLIDING},
	};


	float m_PlacementField[MAX_STAGE_1_1FIELD] = {			//配置するタイミングのリズム(0.1fまで)
	17.0f,
	27.0f,
	32.0f,
	36.0f,
	40.0f,
	44.0f,
	49.5f,
	57.5f,
	68.0f,
	73.5f,
	79.0f,
	80.0f,
	84.0f,
	84.5f,
	85.5f,
	86.0f,
	92.0f,
	93.0f,
	94.0f,
	99.0f,
	104.0f,
	108.0f,
	108.5f,
	109.5f,
	110.5f,
	111.0f,
	116.0f,
	118.5f,
	124.0f,
	125.0f,
	126.0f,
	137.0f,
	145.0f,
	153.0f,
	157.0f,
	164.0f,
	166.5f,
	168.0f,
	172.0f,
	175.0f,
	176.0f,
	178.5f,
	180.0f,
	186.5f,
	188.0f,
	189.0f,
	190.0f,
	195.5f,
	199.5f,
	203.5f,
	207.0f,
	208.0f,
	212.0f,
	215.0f,
	215.5f,
	218.5f,
	220.0f,
	225.0f,
	226.0f,
	227.0f,
	229.0f,
	231.0f,
	237.0f,
	238.0f,
	238.5f,
	239.0f,
	};
	FIELD_TEXTURE_NUM m_FieldTexNum[MAX_STAGE_1_1FIELD] = { //配置するテクスチャの番号
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_005,
		W1_S1_003,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_003,
		W1_S1_001,
		W1_S1_003,
		W1_S1_006,
		W1_S1_001,
		W1_S1_001,
		W1_S1_008,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_003,
		W1_S1_008,
		W1_S1_003,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_003,
		W1_S1_005,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_004,
		W1_S1_005,
		W1_S1_001,
		W1_S1_005,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_005,
		W1_S1_005,
		W1_S1_005,
		W1_S1_001,
		W1_S1_004,
		W1_S1_003,
		W1_S1_003,
		W1_S1_001,
		W1_S1_005,
		W1_S1_003,
		W1_S1_001,
		W1_S1_001,
		W1_S1_006,
		W1_S1_006,
		W1_S1_009,
		W1_S1_001,
		W1_S1_001,
		W1_S1_005,
		W1_S1_002
	};
	//配置する高さ(0→地面に接触している状態, 1→スライディングで通れる高さ)
	int m_PlacementFigh[MAX_STAGE_1_1FIELD] = {
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		1,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		1,
		0,
		0,
		0,
		1,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		0
	};

}STAGE1_1_PLACEMENT_FIELD;


#define MAX_STAGE_2_3FIELD		(178)
typedef struct {
	int m_max_Fieldnum = MAX_STAGE_2_3FIELD;
	int m_RhythmJudgement[MAX_STAGE_2_3FIELD][2] =
	{
		{16,JUMP},
		{17,ROTATION},
		{24,JUMP},
		{25,ROTATION},
		{28,JUMP},
		{30,SLIDING},
		{31,JUMP},
		{32,ROTATION},
		{38,JUMP},
		{39,JUMP},
		{40,JUMP},
		{44,SLIDING},
		{46,JUMP},
		{48,ROTATION},
		{54,JUMP},
		{56,SLIDING},
		{60,JUMP},
		{62,JUMP},
		{67,JUMP},
		{71,JUMP},
		{75,JUMP},
		{79,JUMP},
		{83,JUMP},
		{87,JUMP},
		{91,JUMP},
		{95,JUMP},
		{98,SLIDING},
		{99,JUMP},
		{102,JUMP},
		{103,SLIDING},
		{106,SLIDING},
		{107,JUMP},
		{115,JUMP},
		{119,JUMP},
		{123,JUMP},
		{127,JUMP},
		{128,SLIDING},
		{130,SLIDING},
		{132,SLIDING},
		{136,JUMP},
		{138,JUMP},
		{140,JUMP},
		{144,SLIDING},
		{146,JUMP},
		{148,SLIDING},
		{149,JUMP},
		{150,JUMP},
		{152,JUMP},
		{153,ROTATION},
		{155,SLIDING},
		{156,JUMP},
		{157,ROTATION},
		{159,SLIDING},
		{164,JUMP},
		{165,JUMP},
		{172,JUMP},
		{173,SLIDING},
		{180,SLIDING},
		{181,JUMP},
		{188,SLIDING},
		{189,JUMP},
		{190,JUMP},
		{191,ROTATION},
		{198,JUMP},
		{199,JUMP},
		{200,ROTATION},
		{204,JUMP},
		{206,JUMP},
		{208,JUMP},
		{214,JUMP},
		{216,SLIDING},
		{222,SLIDING},
		{223,ROTATION},
		{232,SLIDING},
		{233,JUMP},
		{234,SLIDING},
		{235,JUMP},
		{236,SLIDING},
		{237,JUMP},
		{238,JUMP},
		{239,ROTATION},
		{248,SLIDING},
		{250,SLIDING},
		{252,JUMP},
		{253,JUMP},
		{254,JUMP},
		{255,JUMP},
		{259,JUMP},
		{263,JUMP},
		{267,JUMP},
		{270,JUMP},
		{271,ROTATION},
		{275,JUMP},
		{279,JUMP},
		{283,JUMP},
		{286,JUMP},
		{287,ROTATION},
		{291,JUMP},
		{295,JUMP},
		{299,JUMP},
		{302,SLIDING},
		{303,JUMP},
		{305,JUMP},
		{309,JUMP},
		{313,JUMP},
		{318,JUMP},
		{319,JUMP},
		{320,ROTATION}
	};


	float m_PlacementField[MAX_STAGE_2_3FIELD] = //配置するタイミングのリズム(0.1fまで)
	{
			15.0f,
			17.5f,
			18.0f,
			21.0f,
			23.0f,
			25.5f,
			26.0f,
			28.0f,
			29.0f,
			29.5f,
			33.0f,
			33.5f,
			36.5f,
			38.0f,
			39.0f,
			39.5f,
			40.0f,
			42.5f,
			43.5f,
			45.5f,
			46.0f,
			49.0f,
			52.0f,
			54.0f,
			55.0f,
			55.5f,
			58.0f,
			60.0f,
			61.0f,
			62.0f,
			64.0f,
			67.0f,
			67.0f,
			70.0f,
			71.0f,
			73.0f,
			75.0f,
			76.0f,
			79.0f,
			79.0f,
			82.0f,
			83.0f,
			85.0f,
			87.0f,
			88.0f,
			91.0f,
			91.0f,
			94.0f,
			95.0f,
			97.0f,
			97.5f,
			99.0f,
			100.0f,
			102.0f,
			102.5f,
			103.0f,
			105.5f,
			106.0f,
			107.0f,
			109.0f,
			112.0f,
			115.0f,
			115.0f,
			118.0f,
			119.0f,
			121.0f,
			123.0f,
			124.0f,
			127.0f,
			127.0f,
			127.5f,
			129.5f,
			130.0f,
			130.0f,
			131.5f,
			133.0f,
			136.0f,
			138.0f,
			140.0f,
			140.0f,
			143.0f,
			143.5f,
			146.0f,
			147.5f,
			149.0f,
			150.0f,
			154.0f,
			154.5f,
			158.0f,
			160.0f,
			163.0f,
			164.0f,
			165.0f,
			166.0f,
			169.0f,
			172.0f,
			172.0f,
			172.5f,
			175.0f,
			178.0f,
			179.5f,
			181.0f,
			181.0f,
			184.0f,
			187.0f,
			187.5f,
			189.0f,
			192.0f,
			195.0f,
			198.0f,
			198.0f,
			201.0f,
				204.0f,
				206.0f,
				208.0f,
				208.0f,
				211.0f,
				214.0f,
				215.5f,
				217.0f,
				220.0f,
				221.5f,
				224.0f,
				227.0f,
				230.0f,
				231.5f,
				233.0f,
				233.5f,
				235.0f,
				235.5f,
				237.0f,
				241.0f,
				244.0f,
				247.0f,
				247.5f,
				249.5f,
				250.0f,
				252.0f,
				253.0f,
				254.0f,
				255.5f,
				258.5f,
				259.0f,
				261.5f,
				263.0f,
				264.5f,
				267.0f,
				267.5f,
				272.0f,
				275.0f,
				275.0f,
				278.0f,
				279.0f,
				281.0f,
				283.0f,
				284.0f,
				288.0f,
				291.0f,
				291.0f,
				294.0f,
				295.0f,
				297.0f,
				299.0f,
				300.0f,
				301.5f,
				303.0f,
				303.0f,
				305.0f,
				306.0f,
				309.0f,
				309.0f,
				312.0f,
				313.0f,
				315.0f,
				318.0f,
				321.0f,
				324.0f,
				327.0f
	};
	FIELD_TEXTURE_NUM m_FieldTexNum[MAX_STAGE_2_3FIELD] = { //配置するテクスチャの番号
	W1_S2_001,
	W1_S2_001,
	W1_S2_006,
	W1_S2_004,
	W1_S2_001,
	W1_S2_001,
	W1_S2_006,
	W1_S2_005,
	W1_S2_003,
	W1_S1_005,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_005,
	W1_S2_003,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S1_005,
	W1_S2_003,
	W1_S2_002,
	W1_S2_006,
	W1_S2_006,
	W1_S2_004,
	W1_S2_006,
	W1_S1_005,
	W1_S2_006,
	W1_S2_005,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S1_005,
	W1_S2_001,
	W1_S2_006,
	W1_S2_002,
	W1_S1_005,
	W1_S2_006,
	W1_S1_005,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_006,
	W1_S1_005,
	W1_S1_005,
	W1_S2_006,
	W1_S2_004,
	W1_S1_005,
	W1_S2_006,
	W1_S2_005,
	W1_S2_005,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S1_005,
	W1_S2_006,
	W1_S1_005,
	W1_S2_003,
	W1_S2_003,
	W1_S2_003,
	W1_S1_005,
	W1_S2_004,
	W1_S2_006,
	W1_S2_006,
	W1_S2_003,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S2_006,
	W1_S2_003,
	W1_S1_005,
	W1_S2_006,
	W1_S2_006,
	W1_S1_005,
	W1_S2_006,
	W1_S2_001,
	W1_S2_006,
	W1_S2_006,
	W1_S1_005,
	W1_S2_002,
	W1_S2_006,
	W1_S2_006,
	W1_S2_002,
	W1_S2_002,
	W1_S2_006,
		W1_S2_006,
		W1_S2_005,
		W1_S2_001,
		W1_S2_006,
		W1_S2_006,
		W1_S2_006,
		W1_S1_005,
		W1_S2_006,
		W1_S2_004,
		W1_S1_005,
		W1_S2_006,
		W1_S2_006,
		W1_S2_006,
		W1_S1_005,
		W1_S2_006,
		W1_S1_005,
		W1_S2_006,
		W1_S1_005,
		W1_S2_002,
		W1_S2_006,
		W1_S2_006,
		W1_S2_006,
		W1_S1_005,
		W1_S1_005,
		W1_S2_006,
		W1_S2_005,
		W1_S2_002,
		W1_S2_001,
		W1_S2_006,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_004,
		W1_S2_006,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_003,
		W1_S2_006,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S1_005,
		W1_S2_006,
		W1_S2_005,
		W1_S2_001,
		W1_S2_006,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_001,
		W1_S2_006,
		W1_S2_006,
		W1_S2_006
	};
	//W1_S1_005
	//W1_S2_006
	// 
	//配置する高さ(0→地面に接触している状態, 1→スライディングで通れる高さ)
	int m_PlacementFigh[MAX_STAGE_2_3FIELD] = {
		-1,	
		-1,	
		-1,	
		-1,	
		-1,	
		-1,	
		-1,	
		0,	
		-1,	
		2,	
		-1,	
		-1,	
		-1,	
		0,	
		1,	
		-1,	
		2,	
		-1,	
		1,	
		-1,	
		0,	
		-1,	
		-1,	
		0,	
		-1,	
		2,	
		-1,	
		0,	
		-1,	
		1,	
		-1,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		1,	
		0,	
		-1,	
		0,	
		2,	
		-1,	
		1,	
		-1,	
		0,	
		-1,	
		-1,	
		-1,	
		0,	
		-1,	
		0,	
		-1,	
		0,
		-1,
		-1,
		0,
		2,
		2,
		-1,
		0,
		2,
		-1,
		0,
		1,
		-1,
		2,
		-1,
		1,
		0,
		2,
		1,
		2,
		2,
		4,
		2,
		-1,
		-1,
		0,
		1,
		-1,
		-1,
		-1,
		0,
		2,
		-1,
		-1,
		1,
		-1,
		0,
		-1,
		-1,
		1,
		0,
		-1,
		-1,
		-1,
		0,
		-1,
			0,
			1,
			2,
			-1,
			-1,
			0,
			2,
			0,
			0,
			2,
			-1,
			-1,
			-1,
			1,
			0,
			2,
			1,
			3,
			2,
			-1,
			-1,
			-1,
			1,
			1,
			-1,
			0,
			1,
			2,
			-1,
			-1,
			0,
			-1,
			0,
			-1,
			0,
			-1,
			-1,
			-1,
			0,
			-1,
			0,
			-1,
			0,
			-1,
			-1,
			-1,
			0,
			-1,
			0,
			-1,
			0,
			-1,
			1,
			-1,
			0,
			1,
			-1,
			-1,
			0,
			-1,
			0,
			-1,
			0,
			-1,
			-1,
			-1


	};

}STAGE2_3_PLACEMENT_FIELD;
//ファイルのステージのデータ
#define W1_S1_INF_001 "data/STAGE_INF/CSV_Test.csv"

#endif