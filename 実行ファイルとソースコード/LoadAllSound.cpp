#include "LoadAllSound.h"

#include "sound.h"


void LoadAllBGM(BGMINF* p_bgminf)
{
	p_bgminf[BGM_001].fileNum = LoadSound(BGM_NAME_001);
	p_bgminf[BGM_001].samplenum = BGM_NAME_001_SAMPLE_Num;

	p_bgminf[BGM_002].fileNum = LoadSound(BGM_NAME_002);
	p_bgminf[BGM_002].samplenum = BGM_NAME_002_SAMPLE_Num;

	p_bgminf[BGM_003].fileNum = LoadSound(BGM_NAME_003);
	p_bgminf[BGM_003].samplenum = BGM_NAME_003_SAMPLE_Num;

	p_bgminf[BGM_005].fileNum = LoadSound(BGM_NAME_005);
	//p_bgminf[3].fileNum = LoadSound(BGM_NAME_004);
	//p_bgminf[3].samplenum = BGM_NAME_004_SAMPLE_Num;

}

void LoadAllSE(SEINF* p_seinf)
{
	p_seinf[SE_001].fileNum = LoadSound(SE_NAME_001);
	p_seinf[SE_002].fileNum = LoadSound(SE_NAME_002);
	p_seinf[SE_JUMP].fileNum = LoadSound(SE_NAME_003);
	p_seinf[SE_SLIDING].fileNum = LoadSound(SE_NAME_004);
	p_seinf[SE_TYAKUTI].fileNum = LoadSound(SE_NAME_005);
	p_seinf[SE_KAITEN].fileNum = LoadSound(SE_NAME_006);
	p_seinf[SE_miss].fileNum = LoadSound(SE_NAME_007);
	p_seinf[SE_good].fileNum = LoadSound(SE_NAME_008);
	p_seinf[SE_perfect].fileNum = LoadSound(SE_NAME_009);
	p_seinf[SE_combo_1].fileNum = LoadSound(SE_NAME_010);
	p_seinf[SE_combo_2].fileNum = LoadSound(SE_NAME_011);
	p_seinf[SE_combo_3].fileNum = LoadSound(SE_NAME_012);
	p_seinf[SE_SELECT_1].fileNum = LoadSound(SE_NAME_013);
	p_seinf[SE_SELECT_OK_1].fileNum = LoadSound(SE_NAME_014);
	p_seinf[SE_SELECT_BACK_1].fileNum = LoadSound(SE_NAME_015);
	p_seinf[SE_TITLE_1].fileNum = LoadSound(SE_NAME_016);
	p_seinf[SE_GO_1].fileNum = LoadSound(SE_NAME_017);
	p_seinf[SE_READY_1].fileNum = LoadSound(SE_NAME_018);

}