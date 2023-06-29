#include "SoundManager.h"
#include "LoadAllSound.h"


BGMINF g_Bgm_Num[MAX_BGM_NUM];
SEINF g_SE_Num[MAX_SE_NUM];

void InitSoundManager(void)
{
	LoadAllBGM(g_Bgm_Num);
	LoadAllSE(g_SE_Num);
}

void UnInitSoundManager(void)
{
}

BGMINF* Get_BGM_Inf(void)
{
	return g_Bgm_Num;
}

SEINF* Get_SE_Inf(void)
{
	return g_SE_Num;
}