#include "DebugAllClass.h"

float baititututu = 1.0f;
float tasuatai = 0.0f;
float tasuatai2 = 0.0f;

float raito = (float)SCREEN_WIDTH / (float)GetSystemMetrics(SM_CXFULLSCREEN);
Debug_Num num[2];
bool tesdatad = false;

void Draw_mousePos::SetPos(void)
{
	Int2 D_intx = D_GetMousePos();

	pos_x = D_intx.x;
	pos_y = D_intx.y;
}


void Draw_mousePos::DrawMOpos(void)
{
	DrawSprite(LoadTexture("data/TEXTURE/DebugMode/halfwhite.png"), 75.0f, 50.0f, size_x * 3.0f, size_y * 2.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	num[0].size_x = size_x / 2.0f;
	num[0].size_y = size_y;
	num[0].pos_x = size_x * 2.0f + 25.0f;
	num[0].pos_y = 25.0f;
	num[0].Setnumber(pos_x);
	DrawSprite(LoadTexture("data/TEXTURE/DebugMode/X.png"), 25.0f, 25.0f, size_x, size_y, 0.0f, 0.0f, 1.0f, 1.0f);
	num[0].DrawDebugNum();

	num[1].size_x = size_x / 2.0f;
	num[1].size_y = size_y;
	num[1].pos_x = size_x * 2.0f + 25.0f;
	num[1].pos_y = 75.0f;
	num[1].Setnumber(pos_y);
	DrawSprite(LoadTexture("data/TEXTURE/DebugMode/Y.png"), 25.0f, 75.0f, size_x, size_y, 0.0f, 0.0f, 1.0f, 1.0f);
	num[1].DrawDebugNum();


}

//=================================================
//EditFieldƒNƒ‰ƒX
//=================================================
EditField::EditField()
{
	D_m_Pos = MakeFloat2(0.0f, 0.0f);
	D_m_Size = MakeFloat2(0.0f, 0.0f);
	D_m_TexNum = *GetFieldTextureInf(W1_S1_002);
}

void EditField::D_Draw_EditField(float ScaleRatio, Float2 AddValue)
{
	//befpos.x /= baititututu;
	//befpos.y /= baititututu;
	//nowpos.x /= baititututu;
	//nowpos.y /= baititututu;
	//if (GetMouseZ() < 0 && GetMouseZ() != 0)
	//{
	//	if (baititututu > 0.3)
	//	{
	//		baititututu -= 0.1f;
	//	}
	//}
	//if (GetMouseZ() > 0 && GetMouseZ() != 0)
	//{
	//	if (baititututu < 1.5f)
	//	{
	//		baititututu += 0.1f;
	//	}
	//}
	////DIK_LEFT DIK_RIGHT DIK_DOWN
	//if (GetKeyboardPress(DIK_UP))
	//{
	//	tasuatai -= 10.0f;
	//}
	//if (GetKeyboardPress(DIK_DOWN))
	//{
	//	tasuatai += 10.0f;
	//}
	//if (GetKeyboardPress(DIK_RIGHT))
	//{
	//	tasuatai2 += 10.0f;
	//}
	//if (GetKeyboardPress(DIK_LEFT))
	//{
	//	tasuatai2 -= 10.0f;
	//}
	//if (EditSta)
	//{
	//	if (befpos.x < nowpos.x)
	//	{
	//		D_m_Size.x = (float)(nowpos.x - befpos.x - tasuatai2);
	//		D_m_Pos.x = (float)(befpos.x) + D_m_Size.x / 2.0f;
	//	}
	//	else
	//	{
	//		D_m_Size.x = (float)(befpos.x - nowpos.x + tasuatai2);
	//		D_m_Pos.x = (float)(befpos.x) - D_m_Size.x / 2.0f;
	//	}

	//	if (((float)befpos.y + tasuatai) < nowpos.y)
	//	{
	//		D_m_Size.y = (float)nowpos.y - ((float)befpos.y + tasuatai);
	//		D_m_Pos.y = (float)(befpos.y) + D_m_Size.y / 2.0f + tasuatai;
	//	}
	//	else
	//	{
	//		D_m_Size.y = ((float)befpos.y + tasuatai) - (float)nowpos.y;
	//		D_m_Pos.y = (float)(befpos.y) - D_m_Size.y / 2.0f + tasuatai;
	//	}
	//}
	//DrawSprite(
	//	D_m_TexNum,
	//	D_m_Pos.x * raito * baititututu + +tasuatai2,
	//	D_m_Pos.y * raito * baititututu,
	//	D_m_Size.x * raito * baititututu,
	//	D_m_Size.y * raito * baititututu,
	//	0.0f, 0.0f, 1.0f, 1.0f);

	DrawSprite(
		D_m_TexNum,
		D_m_Pos.x * ScaleRatio + AddValue.x,
		D_m_Pos.y * ScaleRatio + AddValue.y,
		D_m_Size.x * ScaleRatio,
		D_m_Size.y * ScaleRatio,
		0.0f, 0.0f, 1.0f, 1.0f);
}

void EditField::D_End_EditField(void)
{
	EditSta = false;
}


void EditField::D_CpmputeInf(Int2 befpos, Int2 nowpos, float ScaleRatio, Float2 AddValue)
{
	//befpos.x /= baititututu;
	//befpos.y /= baititututu;
	//nowpos.x /= baititututu;
	//nowpos.y /= baititututu;6(float)
	Float2 hennkannBef = MakeFloat2(ScaleRatio * (float)befpos.x * raito - AddValue.x, ScaleRatio * (float)befpos.y * raito - AddValue.y);
	Float2 hennkannNow = MakeFloat2(ScaleRatio * (float)nowpos.x * raito - AddValue.x, ScaleRatio * (float)nowpos.y * raito - AddValue.y);

	raito;
	if (EditSta)
	{
		//((float)befpos.y * ScaleRatio) + (AddValue.y * ScaleRatio)
		if (befpos.x < nowpos.x)
		{
			D_m_Size.x = hennkannNow.x - hennkannBef.x;
			D_m_Pos.x = hennkannBef.x + D_m_Size.x / 2.0f;
		}
		else
		{
			D_m_Size.x =  hennkannBef.x - hennkannNow.x;
			D_m_Pos.x = hennkannBef.x - D_m_Size.x / 2.0f;
		}

		if (((float)befpos.y) < nowpos.y)
		{
			D_m_Size.y = hennkannNow.y - hennkannBef.y;
			D_m_Pos.y = hennkannBef.y + D_m_Size.y / 2.0f;
		}
		else
		{
			D_m_Size.y = hennkannBef.y - hennkannNow.y;
			D_m_Pos.y = hennkannBef.y - D_m_Size.y / 2.0f;
		}
	}

}
