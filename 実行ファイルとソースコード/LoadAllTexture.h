#ifndef _LOADALLTEXTURE_H_
#define _LOADALLTEXTURE_H_


#include "declaration.h"

void LoadAllTexture(void);
void UnLoadAllTexture(void);

/*プレイヤーアニメーション画像を全て読み込む*/
void LoadAllPlayerAniTexture(TEXINF_PLAYER_ANI* num);
/*フィールド画像を全て読み込む*/
void LoadAllFieldTexture(TEXINF_FIELD* num);
/*BGの画像を全て読み込む*/
void LoadAllBGTexture(TEXINF_BG* num);

void LoadAllSceneTexture(TEXINF_SCENE* num);

void LoadAllEFTexture(EF_INF* num);
#endif