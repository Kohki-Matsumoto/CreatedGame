#include "Effect.h"
#include "declaration.h"
#include "sprite.h"
#include "LoadAllTexture.h"
#include "TextureManager.h"

EFFECT* g_EFStatus[MAX_EF_NUM];

EFFECT* p_EF;
void InitEffect(void)
{
	for (int i = 0; i < MAX_EF_NUM; i++)
	{
		g_EFStatus[i] = nullptr;
	}
}



void UpdateEffect(void)
{
	for (int i = 0; i < MAX_EF_NUM; i++)
	{
		if (g_EFStatus[i] != nullptr)
		{
			g_EFStatus[i]->UpdateFrame();
			if (g_EFStatus[i]->framecount > g_EFStatus[i]->MAX_framecount)
			{
				g_EFStatus[i] = nullptr;
			}
		}
	}
}

void DrawEffect(void)
{
	for (int i = 0; i < MAX_EF_NUM; i++)
	{
		if (g_EFStatus[i] != nullptr)
		{
				g_EFStatus[i]->Draw();
		}
	}
}


void SetEffect(EF_STATUS status)
{
	for (int i = 0; i < 100; i++)
	{
		if (g_EFStatus[i] == nullptr)
		{
			switch (status) {
			case MISS_FIGURE:
				p_EF = new EF_Miss;
				p_EF->Pos = MakeFloat2(500.0f, 500.0f);
				p_EF->Size = MakeFloat2(500.0f, 300.0f);
				p_EF->MAX_framecount = 10;
				g_EFStatus[i] = p_EF;
				return;
			case GOOD_FIGURE:
				p_EF = new EF_Good;
				p_EF->Pos = MakeFloat2(500.0f, 500.0f);
				p_EF->Size = MakeFloat2(500.0f, 300.0f);
				p_EF->MAX_framecount = 10;
				g_EFStatus[i] = p_EF;
				return;
			case PERFECT_FIGURE:
				p_EF = new EF_Perfect;
				p_EF->Pos = MakeFloat2(500.0f, 500.0f);
				p_EF->Size = MakeFloat2(800.0f, 600.0f);
				p_EF->MAX_framecount = 24;
				g_EFStatus[i] = p_EF;
				return;
			case LIGHT_EF:
				p_EF = new EF_Light;
				p_EF->Pos = MakeFloat2(500.0f, 500.0f);
				p_EF->Size = MakeFloat2(300.0f, 300.0f);
				p_EF->MAX_framecount = 9;
				g_EFStatus[i] = p_EF;
				return;
			case EF_RHYTHM_ANIi:
				p_EF = new RHYTHM_ANIi;
				p_EF->Pos = GetPlayerpoint()->GetPlayerPos();
				p_EF->Size = MakeFloat2(300.0f, 300.0f);
				p_EF->MAX_framecount = 9;
				g_EFStatus[i] = p_EF;
				return;
			};

		}
	}
}
