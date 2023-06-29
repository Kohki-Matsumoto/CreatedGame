#ifndef _LOADALLTEXTURE_H_
#define _LOADALLTEXTURE_H_


#include "declaration.h"

void LoadAllTexture(void);
void UnLoadAllTexture(void);

/*�v���C���[�A�j���[�V�����摜��S�ēǂݍ���*/
void LoadAllPlayerAniTexture(TEXINF_PLAYER_ANI* num);
/*�t�B�[���h�摜��S�ēǂݍ���*/
void LoadAllFieldTexture(TEXINF_FIELD* num);
/*BG�̉摜��S�ēǂݍ���*/
void LoadAllBGTexture(TEXINF_BG* num);

void LoadAllSceneTexture(TEXINF_SCENE* num);

void LoadAllEFTexture(EF_INF* num);
#endif