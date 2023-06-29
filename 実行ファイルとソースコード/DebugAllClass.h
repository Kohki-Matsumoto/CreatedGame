#ifndef _DEBUG_ALL_CLASS_H_
#define _DEBUG_ALL_CLASS_H_
#include "Debugmain.h"

//���l��\�����邽�߂̃N���X
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

//�}�E�X�̈ʒu��\������N���X
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

//�t�B�[���h�̕ҏW�����邽�߂̃t�B�[���h�N���X�B
//private�̕ϐ���csv�ɓ��͂��邽�߂�Base_Field_Inf�ɓ��͂���
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
	bool UseField = false;									//���ݎg���Ă��邩(true = �g���Ă���)
	bool EditSta = false;									//���ݕҏW�����ǂ���(true = �ҏW��)
	void D_Draw_EditField(float ScaleRatio, Float2 AddValue);		//EditField�̕`��
	void D_End_EditField(void);								//�ҏW�̏I���APos�ɒl��ۑ�����
	void D_CpmputeInf(Int2 befpos, Int2 nowpos, float ScaleRatio, Float2 AddValue);

	//�Z�b�^�[
	//=============================================================
	void D_Set_TexNum(int texnum) { D_m_TexNum = D_m_TexNum; } //<--------------------------------�܂������Ă邩�ȁ[�H
	void D_Set_ScaleRatio(float scaleratio) { D_m_ScaleRatio += scaleratio; }
	void D_Set_D_m_AddValue(Float2 addvalue) { D_m_AddValue.x += addvalue.x; D_m_AddValue.y += addvalue.y; }
	//=============================================================
	
	//�Q�b�^�[
	//=============================================================
	Float2 D_Get_Pos(void) { return D_m_Pos; }
	Float2 D_Get_Size(void) { return D_m_Size; }
	int  D_Get_TexNum(void) { return  D_m_TexNum; }
	float D_Get_ScaleRatio(void) { return D_m_ScaleRatio; }
	Float2 D_Get_AddValue(void) { return D_m_AddValue; }
	//=============================================================
};

#endif