#include "Gravity.h"

bool NowPlayerAir = false;
float GravityStrength__test = 0.0f;

float GRAVITY_STRENGTH_00 = 4.0f;
float GRAVITY_STRENGTH_01 = 0.1f;


void Gravity(PLAYER* p)
{
	if (p->GetPlayerOnGravity() == true)
	{
		GravityStrength__test += GRAVITY_STRENGTH_01;

		p->SetPlayerPos(MakeFloat2(p->GetPlayerPos().x, p->GetPlayerPos().y + GRAVITY_STRENGTH_00 * GravityStrength__test * GravityStrength__test));
	}
}

void ResetGravity(PLAYER* p, FIELD* q)
{

	if (CollisionTopField(p, q) == true)
	{
		if (p->GetPlayerStatus() != SLIDING)
		p->UpdateAnim(DEFAULT);
 		p->SetPlayerOnGravity(false);
		p->SetPlayerNowJump(false);

		NowPlayerAir = true;

			 
   		JumpTime = 0.0f;
		JumpFinish = 0.0f;
		JumpStartPos = 0.0f;
		GravityStrength__test = 0.0f;
	}
}

void NowPlayerSky(PLAYER* p)
{
	if (NowPlayerAir == false)
	{
		if (p->GetPlayerNowJump() == false && p->GetPlayerNowRotation() == false)
		{
			p->SetPlayerOnGravity(true);
		}
	}
	NowPlayerAir = false;
}


float GetGravityStrength__test(void) 
{
	return GravityStrength__test; 
}


void SetGravityStrength__test(float p)
{
	GravityStrength__test = p;
}

void SetGravityStrengthForStage(float a)
{
	GRAVITY_STRENGTH_00 = GRAVITY_STRENGTH_00 * a;
	GRAVITY_STRENGTH_01 = GRAVITY_STRENGTH_01 * a;
}

void ResetGravityStrengthForStage()
{
	GRAVITY_STRENGTH_00 = 4.0f;
	GRAVITY_STRENGTH_01 = 0.1f;
}