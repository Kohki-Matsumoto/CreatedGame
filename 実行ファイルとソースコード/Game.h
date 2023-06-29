#ifndef _GAME_H_
#define _GAME_H_

#include "declaration.h"
#include "Player.h"
#include "Field.h"

void InitGame(void);
void UnInitGame(void);
void UpdateGame(void);
void DrawGame(void);

void ResetGame(void);
void PushButton(void);
void Playertransition(void);
void KeepSliding(PLAYER* p, FIELD* q);


PLAYER* GetPlayerpoint(void);
void GamePause(bool pause);
void ResetGame(void);
void GameStart(void);

int* GetStageRhythm(int num);
int* GetStageRhythmAction(int num);
FIELD_TEXTURE_NUM* GetStageFieldTexNum(int num);
int* GetStageFieldHigh(int num);
float* GetStageFieldTemp(int num);
int GetStageBGMSample(void);

void SetStageNum(STAGE_NAME num);
void GameResultProcess();

void PlayerStatusChangeForStage();


#endif