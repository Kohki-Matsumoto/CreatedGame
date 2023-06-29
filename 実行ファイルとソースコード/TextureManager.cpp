//========================================================
//
// *全テクスチャの管理
//
//========================================================
#include "TextureManager.h"
TEXINF_PLAYER_ANI	g_PlayerTexture[MAX_PLAYER_STATUS];
TEXINF_FIELD		g_FieldTexture[MAX_FIELD_TEXTURE_NUM];
TEXINF_BG			g_BGTexture[MAX_BG_TEXTURE_NUM];
TEXINF_SCENE		g_SceneTexture[SCENE_MAX];
EF_INF			g_EFTexture[MAX_EF_STATUS];
void InitTextureManager(void)
{
	LoadAllPlayerAniTexture(g_PlayerTexture);
	LoadAllFieldTexture(g_FieldTexture);
	LoadAllBGTexture(g_BGTexture);
	LoadAllSceneTexture(g_SceneTexture);
	LoadAllEFTexture(g_EFTexture);
}
void UnInitTextureManager(void)
{




}

TEXINF_FIELD* GetFieldTextureInf(FIELD_TEXTURE_NUM num)
{
	return &g_FieldTexture[num];
}

int* GetBGTextureInf(BG_TEXTURE_NUM num)
{
	return &g_BGTexture[num].fileNum;
}

TEXINF_PLAYER_ANI* GetPlayerAniTexture(PLAYER_STATUS num)
{
	return &g_PlayerTexture[num];
}

TEXINF_SCENE* GetSceneTexture(SCENE num)
{
	return &g_SceneTexture[num];
}

EF_INF* GetEFTexture(EF_STATUS num)
{
	return &g_EFTexture[num];
}
