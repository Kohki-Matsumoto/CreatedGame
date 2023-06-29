#ifndef _DEBUG_ALL_CLASS_H_
#define _DEBUG_ALL_CLASS_H_
#include "Debugmain.h"

//数値を表示するためのクラス
class Debug_Num
{
private:

	int number = 0;
public:
	float size_x = (VERES_SIZE / 2.0f);
	float size_y = VERES_SIZE;
	float pos_x = 1000.0f;
	float pos_y = 600.0f;

	void DrawDebugNum(void)
	{
		int ozonx = number;
		for (int i = 0; i < 4; i++)
		{
			DrawSprite(LoadTexture("data/TEXTURE/DebugMode/numTex.png"), pos_x - size_x * i, pos_y, size_x, size_y, (float)(ozonx % 10) * 0.1f, 0.0f, 0.1f, 1.0f);
			ozonx /= 10;
		}
	}
	void Setnumber(int x) { number = x; }

	void Addnumber(int x) { number = (number * 10 + x); }
	void outnumber(void) { number /= 10; }
};

//マウスの位置を表示するクラス
class Draw_mousePos
{
private:
	float size_x = 50.0f;
	float size_y = 50.0f;
public:
	float pos_x;
	float pos_y;

	void SetPos(void);

	void DrawMOpos(void);
	//POINT point;
	//GetCursorPos(&point);
	//ScreenToClient(GetWindowInf(), &point);
};

//フィールドの編集をするためのフィールドクラス。
//privateの変数をcsvに入力するためのBase_Field_Infに入力する
class EditField
{
private:
	Float2 D_m_Pos;
	Float2 D_m_Size;
	int D_m_TexNum;
	float D_m_ScaleRatio = 1.0f;
	Float2 D_m_AddValue = { 0.0f, 0.0f };
public:
	EditField();
	EditField(Float2 Pos, Float2 Size, int TexNum) : D_m_Pos(Pos), D_m_Size(Size), D_m_TexNum(TexNum) {}
	bool UseField = false;									//現在使っているか(true = 使っている)
	bool EditSta = false;									//現在編集中かどうか(true = 編集中)
	void D_Draw_EditField(float ScaleRatio, Float2 AddValue);		//EditFieldの描画
	void D_End_EditField(void);								//編集の終了、Posに値を保存する
	void D_CpmputeInf(Int2 befpos, Int2 nowpos, float ScaleRatio, Float2 AddValue);

	//セッター
	//=============================================================
	void D_Set_TexNum(int texnum) { D_m_TexNum = D_m_TexNum; } //<--------------------------------まちがってるかなー？
	void D_Set_ScaleRatio(float scaleratio) { D_m_ScaleRatio += scaleratio; }
	void D_Set_D_m_AddValue(Float2 addvalue) { D_m_AddValue.x += addvalue.x; D_m_AddValue.y += addvalue.y; }
	//=============================================================
	
	//ゲッター
	//=============================================================
	Float2 D_Get_Pos(void) { return D_m_Pos; }
	Float2 D_Get_Size(void) { return D_m_Size; }
	int  D_Get_TexNum(void) { return  D_m_TexNum; }
	float D_Get_ScaleRatio(void) { return D_m_ScaleRatio; }
	Float2 D_Get_AddValue(void) { return D_m_AddValue; }
	//=============================================================
};

#endif