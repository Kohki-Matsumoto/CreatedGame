#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Var2.h"
#include "main.h"
#include "Player.h"
#include "Field.h"

// �������Ă���Ƃ� true
bool CollisionField(PLAYER* p, FIELD* q);
// �t�B�[���h�̏�ʂƓ������Ă��邩�̔��� �������Ă���Ƃ� true
inline bool CollisionTopField(PLAYER* p, FIELD* q)
{
	if (CollisionField(p, q))
	{
		if (q->GetFieldPos().y - p->GetPlayerPos().y <= q->GetFieldSize().y / 2.0f + p->GetPlayerSize().y / 2.0f 
			&& p->GetPlayerBefPos().y <= p->GetPlayerPos().y
			&& q->GetFieldPos().x - p->GetPlayerPos().x < q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f
			&& q->GetFieldPos().x - p->GetPlayerBefPos().x < q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f)
		{
			return true;
		}
		return false;
	}
	return false;
}
// �t�B�[���h����ʊO�ɂ��邩�ǂ���		��ʊO�̂Ƃ� : true
bool OffField(FIELD* q);
// �����o������
void PushOutPlayer(PLAYER* p, FIELD* q);

#endif
