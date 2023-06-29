#include "Debugmain.h"
#include <vector>

static int g_DebugTexNum[10];
AllKey p_allkey;
Debug_Num Debug_num;
Draw_mousePos Draw_moPos;

FIELD* D_g_p_field;
//----------------------------------------EditField* D_g_p_EditField;


Int2 BefPos;
Int2 NowPos;
float ScaleRatio = 1.0f;
Float2 AddValue = MakeFloat2(0.0f, 0.0f);
int SetChangeField = 0;
std::vector<EditField> FieldNum;

void Updatekakudaisyukusyou(void);

//----------------------------------------int countFieldNum = 0;
void InitDebugmain(void)
{
	g_DebugTexNum[0] = LoadTexture("data/TEXTURE/DebugMode/modeindication.png");
	//D_g_p_field = new FIELD[D_MAX_FIELD];
	//----------------------------------------D_g_p_EditField = new EditField[D_MAX_FIELD];
	
}
void UninitDebugmain(void)
{
	//----------------------------------------delete[] D_g_p_EditField;
}
void UpdateDebugmain(void)
{
	Updatekakudaisyukusyou();
	Draw_moPos.SetPos();
	NowPos = D_GetMousePos();
	if (IsMouseLeftTriggered() && p_allkey.GetTestmouseButton == false)
	{
		p_allkey.GetTestmouseButton = true;
		BefPos = D_GetMousePos();
		//----------------------------------------D_g_p_EditField[countFieldNum].UseField = true;
		//----------------------------------------D_g_p_EditField[countFieldNum].EditSta = true;
		FieldNum.emplace_back(MakeFloat2(0.0f,0.0f),MakeFloat2(0.0f,0.0f),0);
		FieldNum.back().UseField = true;
		FieldNum.back().EditSta = true;

	}
	else if (IsMouseLeftTriggered() && p_allkey.GetTestmouseButton == true)
	{
		p_allkey.GetTestmouseButton = false;
		SetChangeField = FieldNum.size() - 1; // 変えたいフィールドをセットする。
		//----------------------------------------D_g_p_EditField[countFieldNum].D_End_EditField();
		FieldNum.back().D_End_EditField();
		//----------------------------------------countFieldNum++;
	}
	//最初の表示
	if (p_allkey.DrawDebugTitleKey == true && GetKeyboardTrigger(DIK_RETURN))
	{
		p_allkey.DrawDebugTitleKey = false;
	}
	else
	{
		if (GetKeyboardTrigger(DIK_0)) { Debug_num.Addnumber(0); }
		if (GetKeyboardTrigger(DIK_1)) { Debug_num.Addnumber(1); }
		if (GetKeyboardTrigger(DIK_2)) { Debug_num.Addnumber(2); }
		if (GetKeyboardTrigger(DIK_3)) { Debug_num.Addnumber(3); }
		if (GetKeyboardTrigger(DIK_4)) { Debug_num.Addnumber(4); }
		if (GetKeyboardTrigger(DIK_5)) { Debug_num.Addnumber(5); }
		if (GetKeyboardTrigger(DIK_6)) { Debug_num.Addnumber(6); }
		if (GetKeyboardTrigger(DIK_7)) { Debug_num.Addnumber(7); }
		if (GetKeyboardTrigger(DIK_8)) { Debug_num.Addnumber(8); }
		if (GetKeyboardTrigger(DIK_9)) { Debug_num.Addnumber(9); }
		
		if (GetKeyboardTrigger(DIK_BACK)) { Debug_num.outnumber(); }
	}
}

void DrawDebugmain(void)
{
	//最初の表示
	if (p_allkey.DrawDebugTitleKey)
	{
		DrawSprite(g_DebugTexNum[0], (float)SCREEN_WIDTH / 2.0f, (float)SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	else
	{
		Debug_num.DrawDebugNum();
	}

	if (p_allkey.GetTestmouseButton == true)
	{
		//D_DrawTexture(BefPos, NowPos);
		//D_g_p_EditField->D_Draw_EditField(BefPos, NowPos);
		//----------------------------------------D_g_p_EditField[countFieldNum].D_CpmputeInf(BefPos, NowPos, ScaleRatio, AddValue);
		FieldNum.back().D_CpmputeInf(BefPos, NowPos, FieldNum.back().D_Get_ScaleRatio(), FieldNum.back().D_Get_AddValue());
	}

	for (int i = 0; i < FieldNum.size(); i++)
	{
		if (FieldNum[i].UseField)
		{
			FieldNum[i].D_Draw_EditField(FieldNum[i].D_Get_ScaleRatio(), FieldNum.back().D_Get_AddValue());
		}
	}

	if (IsMouseRightTriggered())
	{
		for (int i = 0; i < FieldNum.size(); i++)
		{
			if (FieldNum[i].UseField)
			{
				if (
					NowPos.x >= FieldNum[i].D_Get_Pos().x - FieldNum[i].D_Get_Size().x / 2.0f &&
					NowPos.x <= FieldNum[i].D_Get_Pos().x + FieldNum[i].D_Get_Size().x / 2.0f &&
					NowPos.y >= FieldNum[i].D_Get_Pos().y - FieldNum[i].D_Get_Size().y / 2.0f &&
					NowPos.y <= FieldNum[i].D_Get_Pos().y + FieldNum[i].D_Get_Size().y / 2.0f
					)
				{
					SetChangeField = i;
				}
			}
		}
	}

	if (GetKeyboardTrigger(DIK_R))
	{
		SetChangeField = FieldNum.size() - 1; // 変えたいフィールドをセットする。

	}

	//DrawSprite(
	//	D_g_p_EditField[0].D_Get_TexNum(),
	//	1000.0f * ScaleRatio + AddValue.x,
	//	500.0f * ScaleRatio + AddValue.y,
	//	500.0f * ScaleRatio,
	//	500.0f * ScaleRatio,
	//	0.0f, 0.0f, 1.0f, 1.0f);
	//DrawSprite(
	//	D_g_p_EditField[0].D_Get_TexNum(),
	//	800.0f * ScaleRatio + AddValue.x,
	//	450.0f * ScaleRatio + AddValue.y,
	//	300.0f * ScaleRatio,
	//	300.0f * ScaleRatio,
	//	0.0f, 0.0f, 1.0f, 1.0f);

	Draw_moPos.DrawMOpos();
}

void Updatekakudaisyukusyou(void)
{
	// Hキーを押すことで戻ること(一つ前の作業に戻る)ができます。
	if (GetKeyboardTrigger(DIK_H))
	{
		if (FieldNum.size() >= 1)
		{
			FieldNum.pop_back();
			SetChangeField += -1;
		}
	}

	if (FieldNum.size() >= 1)
	{
		if (GetMouseZ() < 0 && GetMouseZ() != 0)
		{
			if (FieldNum[SetChangeField].D_Get_ScaleRatio() > 0.3)
			{
				//----------------------------------------ScaleRatio -= 0.1f;
				FieldNum[SetChangeField].D_Set_ScaleRatio(-0.1f);
			}
		}
		if (GetMouseZ() > 0 && GetMouseZ() != 0)
		{
			if (FieldNum[SetChangeField].D_Get_ScaleRatio() < 1.5f)
			{
				//----------------------------------------ScaleRatio += 0.1f;
				FieldNum[SetChangeField].D_Set_ScaleRatio(0.1f);

			}
		}
		//DIK_LEFT DIK_RIGHT DIK_DOWN
		if (GetKeyboardPress(DIK_UP))
		{
			//----------------------------------------AddValue.y -= 10.0f;
			FieldNum[SetChangeField].D_Set_D_m_AddValue({ 0.0f, -10.0f });
		}
		if (GetKeyboardPress(DIK_DOWN))
		{
			//----------------------------------------AddValue.y += 10.0f;
			FieldNum[SetChangeField].D_Set_D_m_AddValue({ 0.0f, 10.0f });

		}
		if (GetKeyboardPress(DIK_RIGHT))
		{
			//----------------------------------------AddValue.x += 10.0f;
			FieldNum[SetChangeField].D_Set_D_m_AddValue({ 10.0f, 0.0f });

		}
		if (GetKeyboardPress(DIK_LEFT))
		{
			//----------------------------------------AddValue.x -= 10.0f;
			FieldNum[SetChangeField].D_Set_D_m_AddValue({ -10.0f, 0.0f });

		}
	}
}