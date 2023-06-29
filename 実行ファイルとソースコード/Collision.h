#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Var2.h"
#include "main.h"
#include "Player.h"
#include "Field.h"

// 当たっているとき true
bool CollisionField(PLAYER* p, FIELD* q);
// フィールドの上面と当たっているかの判定 当たっているとき true
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
// フィールドが画面外にいるかどうか		画面外のとき : true
bool OffField(FIELD* q);
// 押し出し処理
void PushOutPlayer(PLAYER* p, FIELD* q);

#endif
