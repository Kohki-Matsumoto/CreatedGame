#include "EF_RhythmJudge.h"


int g_EF_RhythmJudge_framecount = 0;
bool g_EF_RhythmJudge_OnOff = true;
int g_EF_RhythmJudge_time = 0;
RHYTHMJUDGEMENT g_EF_RhythmJudge;
void InitEF_RhythmJudge(void)
{
	g_EF_RhythmJudge_framecount = 0;
	g_EF_RhythmJudge_OnOff = true;
	g_EF_RhythmJudge_time = 0;
	g_EF_RhythmJudge = INIT_JUGEMENT;
}
void UninitEF_RhythmJudge(void)
{

}
void UpdateEF_RhythmJudge(void)
{
	if (g_EF_RhythmJudge_time == -1)
	{
		g_EF_RhythmJudge_OnOff = true;
	}
	else
	{
		if (g_EF_RhythmJudge_time < g_EF_RhythmJudge_framecount)
		{
			g_EF_RhythmJudge_framecount = 0;
			g_EF_RhythmJudge_time = 0;
			g_EF_RhythmJudge_OnOff = false;
		}
		g_EF_RhythmJudge_framecount++;
	}
}


void DrawEF_RhythmJudge(void)
{
	if (g_EF_RhythmJudge_OnOff)
	{
		switch (g_EF_RhythmJudge)
		{
		case 0:
			DrawSprite(LoadTexture("data/TEXTURE/EF/EF_Miss.png"), 500.0f, 300.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);
			break;
		case 1:
			DrawSprite(LoadTexture("data/TEXTURE/EF/EF_Good.png"), 500.0f, 300.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);
			break;
		case 2:
			DrawSprite(LoadTexture("data/TEXTURE/EF/EF_Perfect.png"), 500.0f, 300.0f, 500.0f, 300.0f, 0.0f, 0.0f, 1.0f, 1.0f);
			break;
		}
	}
	
}

void ActionEF_RhythmJudge(int time, RHYTHMJUDGEMENT judge)
{
	g_EF_RhythmJudge_OnOff = true;
	g_EF_RhythmJudge_time = time;
	g_EF_RhythmJudge = judge;
}