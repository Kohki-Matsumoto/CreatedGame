#ifndef _GRAVITY_H_
#define _GRAVITY_H_

#include "declaration.h"
#include "Field.h"
#include "Collision.h"

// 重力の大きさ_01
// #define GRAVITY_STRENGTH_00 4.0f
// 重力の大きさ_02
// #define GRAVITY_STRENGTH_01 0.1f



void Gravity(PLAYER* p);
void ResetGravity(PLAYER* p, FIELD* q);

//=====================================
void NowPlayerSky(PLAYER* p);

float GetGravityStrength__test(void);
void SetGravityStrength__test(float p);
void SetGravityStrengthForStage(float a);
void ResetGravityStrengthForStage();

//=====================================

#endif
