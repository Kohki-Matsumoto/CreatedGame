#include "LoadAllTexture.h"
#include "Texture.h"
#include "sprite.h"
#include <Windows.h>

int g_PlayerTextureNum[6];
void LoadAllTexture(void)
{
	////テクスチャ情報の統合(declaration.hの情報をもとに統合)
	////画像のファイル名と縦横の分割数をMakeTextureInf()でTEXINF_PLAYER_ANI型に統合
	//MakeTextureInf();

	////プレイヤーのテクスチャのロード
	//for (int i = 0; i < 6; i++)
	//{
	//	g_PlayerTextureNum[i] = LoadTexture(GetPlayerTextureInf()[i].filename);
	//}
	////フィールドのテクスチャのロード


}

void UnLoadAllTexture(void)
{

}




void LoadAllPlayerAniTexture(TEXINF_PLAYER_ANI* num)
{
	num[DEFAULT].fileNum = LoadTexture(PLAYER_ANI_DEFAULT);
	num[DEFAULT].TexNum = MakeInt2(PLAYER_ANI_DEFAULT_NUM);

	num[DASH].fileNum = LoadTexture(PLAYER_ANI_DASH);
	num[DASH].TexNum = MakeInt2(PLAYER_ANI_DASH_NUM);

	num[JUMP].fileNum = LoadTexture(PLAYER_ANI_JUMP);
	num[JUMP].TexNum = MakeInt2(PLAYER_ANI_JUMP_NUM);

	num[FALL].fileNum = LoadTexture(PLAYER_ANI_FALL);
	num[FALL].TexNum = MakeInt2(PLAYER_ANI_FALL_NUM);

	num[ROTATION].fileNum = LoadTexture(PLAYER_ANI_ROTATION);
	num[ROTATION].TexNum = MakeInt2(PLAYER_ANI_ROTATION_NUM);

	num[SLIDING].fileNum = LoadTexture(PLAYER_ANI_SLIDING);
	num[SLIDING].TexNum = MakeInt2(PLAYER_ANI_SLIDING_NUM);
}

void LoadAllFieldTexture(TEXINF_FIELD* num)
{
	num[W1_S1_001].fileNum = LoadTexture(FIELD_TEXTURE_NAME_001);
	num[W1_S1_001].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_001);
	num[W1_S1_002].fileNum = LoadTexture(FIELD_TEXTURE_NAME_002);
	num[W1_S1_002].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_002);
	num[W1_S1_003].fileNum = LoadTexture(FIELD_TEXTURE_NAME_003);
	num[W1_S1_003].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_003);
	num[W1_S1_004].fileNum = LoadTexture(FIELD_TEXTURE_NAME_004);
	num[W1_S1_004].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_004);
	num[W1_S1_005].fileNum = LoadTexture(FIELD_TEXTURE_NAME_005);
	num[W1_S1_005].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_005);
	num[W1_S1_006].fileNum = LoadTexture(FIELD_TEXTURE_NAME_006);
	num[W1_S1_006].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_006);
	num[W1_S1_007].fileNum = LoadTexture(FIELD_TEXTURE_NAME_007);
	num[W1_S1_007].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_007);
	num[W1_S1_008].fileNum = LoadTexture(FIELD_TEXTURE_NAME_008);
	num[W1_S1_008].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_008);
	num[W1_S1_009].fileNum = LoadTexture(FIELD_TEXTURE_NAME_009);
	num[W1_S1_009].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_009);
	num[W1_S2_001].fileNum = LoadTexture(FIELD_TEXTURE_NAME_010);
	num[W1_S2_001].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_010);
	num[W1_S2_002].fileNum = LoadTexture(FIELD_TEXTURE_NAME_011);
	num[W1_S2_002].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_011);
	num[W1_S2_003].fileNum = LoadTexture(FIELD_TEXTURE_NAME_012);
	num[W1_S2_003].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_012);
	num[W1_S2_004].fileNum = LoadTexture(FIELD_TEXTURE_NAME_013);
	num[W1_S2_004].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_013);
	num[W1_S2_005].fileNum = LoadTexture(FIELD_TEXTURE_NAME_014);
	num[W1_S2_005].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_014);
	num[W1_S2_006].fileNum = LoadTexture(FIELD_TEXTURE_NAME_015);
	num[W1_S2_006].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_015);
	//num[W1_S1_016].fileNum = LoadTexture(FIELD_TEXTURE_NAME_016);
	//num[W1_S1_016].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_016);
	//num[W1_S1_017].fileNum = LoadTexture(FIELD_TEXTURE_NAME_017);
	//num[W1_S1_017].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_017);
	//num[W1_S1_018].fileNum = LoadTexture(FIELD_TEXTURE_NAME_018);
	//num[W1_S1_018].fieldsize = MakeFloat2(FIELD_TEXTURE_SIZE_018);
}

void LoadAllBGTexture(TEXINF_BG* num)
{
	num[BG_001].fileNum = LoadTexture(BG_TEXTURE_NAME_001);
	num[BG_002].fileNum = LoadTexture(BG_TEXTURE_NAME_002);
	num[BG_003].fileNum = LoadTexture(BG_TEXTURE_NAME_003);
	num[BG_004].fileNum = LoadTexture(BG_TEXTURE_NAME_004);
	num[BG_005].fileNum = LoadTexture(BG_TEXTURE_NAME_005);
	num[BG_006].fileNum = LoadTexture(BG_TEXTURE_NAME_006);
	// num[BG_007].fileNum = LoadTexture(BG_TEXTURE_NAME_007);
	// num[BG_008].fileNum = LoadTexture(BG_TEXTURE_NAME_008);
	// num[BG_009].fileNum = LoadTexture(BG_TEXTURE_NAME_009);

	//num[].fileNum = LoadTexture();

}
void LoadAllSceneTexture(TEXINF_SCENE* num)
{
	num[SCENE_TITLE].fileNum = LoadTexture(SCENE_TEXTURE_NAME_001);
	num[SCENE_MENU].fileNum = LoadTexture(SCENE_TEXTURE_NAME_002);
	num[SCENE_RESULT].fileNum = LoadTexture(SCENE_TEXTURE_NAME_003);
	num[SCENE_SUBCONFIG].fileNum = LoadTexture(SCENE_TEXTURE_NAME_004);
	//num[].fileNum = LoadTexture();
	//num[].fileNum = LoadTexture();

}

void LoadAllEFTexture(EF_INF* num)
{
	num[DOUBLEJUMP_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_001);
	num[DOUBLEJUMP_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_001);

	num[TRIPLEJUMP_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_002);
	num[TRIPLEJUMP_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_002);

	num[JUMPROTATE_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_003);
	num[JUMPROTATE_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_003);
	
	num[SLIDINGJUMP_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_004);
	num[SLIDINGJUMP_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_004);

	num[SLIDINGJUMPROTATE_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_005);
	num[SLIDINGJUMPROTATE_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_005);

	num[JUMPJUMPROTATE_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_006);
	num[JUMPJUMPROTATE_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_006);

	num[GOOD_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_007);
	num[GOOD_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_007);

	num[MISS_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_008);
	num[MISS_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_008);

	num[PERFECT_FIGURE].fileNum = LoadTexture(EF_TEXTURE_NAME_009);
	num[PERFECT_FIGURE].TexNum = MakeInt2(EF_TEXTURE_NUM_009);

	num[RING_A_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0010);
	num[RING_A_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0010);
	
	num[RING_B_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0011);
	num[RING_B_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0011);

	num[JUMP_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0012);
	num[JUMP_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0012);

	num[ROTATE_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0013);
	num[ROTATE_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0013);
	
	num[ROTATE2_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0014);
	num[ROTATE2_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0014);

	num[RUNNING_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0015);
	num[RUNNING_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0015);

	num[LIGHT_EF].fileNum = LoadTexture(EF_TEXTURE_NAME_0016);
	num[LIGHT_EF].TexNum = MakeInt2(EF_TEXTURE_NUM_0016);

	num[EF_RHYTHM_ANIi].fileNum = LoadTexture(EF_TEXTURE_NAME_0017);
	num[EF_RHYTHM_ANIi].TexNum = MakeInt2(EF_TEXTURE_NUM_0017);

}