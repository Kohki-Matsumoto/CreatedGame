#include "Collision.h"

bool CollisionField(PLAYER* p, FIELD* q)
{
	if (
		q->GetFieldPos().x - p->GetPlayerPos().x <= q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f &&
		p->GetPlayerPos().x - q->GetFieldPos().x <= q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f &&
		q->GetFieldPos().y - p->GetPlayerPos().y <= q->GetFieldSize().y / 2.0f + p->GetPlayerSize().y / 2.0f &&
		p->GetPlayerPos().y - q->GetFieldPos().y <= q->GetFieldSize().y / 2.0f + p->GetPlayerSize().y / 2.0f
		)
	{
		return true;
	}

	return false;
}

bool OffField(FIELD* q)
{
	if (
		q->GetFieldPos().x + q->GetFieldSize().x < 0.0f ||
		q->GetFieldPos().x - q->GetFieldSize().x > SCREEN_WIDTH ||
		q->GetFieldPos().y + q->GetFieldSize().y < 0.0f ||
		q->GetFieldPos().y - q->GetFieldSize().y > SCREEN_HEIGHT
		)
	{
		return true;
	}
	
	return false;
}

void PushOutPlayer(PLAYER* p, FIELD* q)
{
	if (CollisionField(p,q))
	{
 		if ((q->GetFieldPos().x - q->GetFieldSize().x / 2.0f - p->GetPlayerSize().x / 2.0f - (p->GetPlayerSpeed().x * -1.0f)) < p->GetPlayerBefPos().x &&
			p->GetPlayerBefPos().x < (q->GetFieldPos().x + q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f) - (p->GetPlayerSpeed().x * -1.0f))
		{
			if (p->GetPlayerBefPos().y < q->GetFieldPos().y)
			{

				q->SetFieldContactPlayer(true);
				p->SetPlayerPos(MakeFloat2(p->GetPlayerPos().x, q->GetFieldPos().y - q->GetFieldSize().y / 2.0f - p->GetPlayerSize().y / 2.0f));
			}
			else
			{
				p->SetPlayerPos(MakeFloat2(p->GetPlayerPos().x, q->GetFieldPos().y + q->GetFieldSize().y / 2.0f + p->GetPlayerSize().y / 2.0f));
			}
		}

		if ((q->GetFieldPos().y - q->GetFieldSize().y / 2.0f - p->GetPlayerSize().y / 2.0f) < p->GetPlayerBefPos().y &&
			p->GetPlayerBefPos().y < (q->GetFieldPos().y + q->GetFieldSize().y / 2.0f + p->GetPlayerSize().y / 2.0f))
		{
			if (p->GetPlayerBefPos().x < q->GetFieldPos().x)
			{
				p->SetPlayerPos(MakeFloat2(q->GetFieldPos().x - q->GetFieldSize().x / 2.0f - p->GetPlayerSize().x / 2.0f, p->GetPlayerPos().y));
			}
			else
			{
				p->SetPlayerPos(MakeFloat2(q->GetFieldPos().x + q->GetFieldSize().x / 2.0f + p->GetPlayerSize().x / 2.0f, p->GetPlayerPos().y));
			}
		}

	}
	else
	{
		q->SetFieldContactPlayer(false);

	}
}
