#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include "LoadAllTexture.h"
#include "Var2.h"
#include "declaration.h"

void InitTextureManager(void);
void UnInitTextureManager(void);
TEXINF_FIELD* GetFieldTextureInf(FIELD_TEXTURE_NUM num);
int* GetBGTextureInf(BG_TEXTURE_NUM num);
TEXINF_PLAYER_ANI* GetPlayerAniTexture(PLAYER_STATUS num);
TEXINF_SCENE* GetSceneTexture(SCENE num);
EF_INF* GetEFTexture(EF_STATUS num);

#endif