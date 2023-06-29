#ifndef _FIELD_H_
#define _FIELD_H_

#include "Var2.h"
#include "declaration.h"




class FIELD
{
private:
	Float2 m_Pos;						//Field�̈ʒu���W
	Float2 m_BefPos;					//Field��1�t���[���O�̈ʒu���W
	Float2 m_Size;						//Field�̃T�C�Y(��,����)
	int* m_TexNum;						//�e�N�X�`���̃|�C���^
	bool m_ContactPlayer;				//�v���C���[�ƐڐG���Ă��邩�ǂ���
	int m_TempNum;						//�e���|�ԍ�(���e���|�ڂ��H)
	OBJECT_TYPE m_Objtype = obj_FIELD;
public:
	//�R���X�g���N�^
	FIELD();

	void DrawField();

	//�Q�b�^�[
	Float2 GetFieldPos(void) { return m_Pos; }
	Float2 GetFieldBefPos(void) { return m_BefPos; }
	Float2 GetFieldSize(void) { return m_Size; }
	int* GetTexNum(void) { return m_TexNum; }
	bool GetFieldContactPlayer(void) { return m_ContactPlayer; }
	int GetFieldTempNum(void) { return m_TempNum; }
	//�Z�b�^�[
	void SetFieldPos(Float2 Pos) { m_Pos = Pos; }
	void SetFieldBefPos(Float2 BefPos) { m_BefPos = BefPos; }
	void SetFieldSize(Float2 Size) { m_Size = Size; }
	void SetFieldTexNum(int* TexNum) { m_TexNum = TexNum; }
	void SetFieldContactPlayer(bool ContactPlayer) { m_ContactPlayer = ContactPlayer; }
	void SetFieldTempNum(int TempNum) { m_TempNum = TempNum; }
};

#endif