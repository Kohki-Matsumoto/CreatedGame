#ifndef _FIELD_H_
#define _FIELD_H_

#include "Var2.h"
#include "declaration.h"




class FIELD
{
private:
	Float2 m_Pos;						//Fieldの位置座標
	Float2 m_BefPos;					//Fieldの1フレーム前の位置座標
	Float2 m_Size;						//Fieldのサイズ(幅,高さ)
	int* m_TexNum;						//テクスチャのポインタ
	bool m_ContactPlayer;				//プレイヤーと接触しているかどうか
	int m_TempNum;						//テンポ番号(何テンポ目か？)
	OBJECT_TYPE m_Objtype = obj_FIELD;
public:
	//コンストラクタ
	FIELD();

	void DrawField();

	//ゲッター
	Float2 GetFieldPos(void) { return m_Pos; }
	Float2 GetFieldBefPos(void) { return m_BefPos; }
	Float2 GetFieldSize(void) { return m_Size; }
	int* GetTexNum(void) { return m_TexNum; }
	bool GetFieldContactPlayer(void) { return m_ContactPlayer; }
	int GetFieldTempNum(void) { return m_TempNum; }
	//セッター
	void SetFieldPos(Float2 Pos) { m_Pos = Pos; }
	void SetFieldBefPos(Float2 BefPos) { m_BefPos = BefPos; }
	void SetFieldSize(Float2 Size) { m_Size = Size; }
	void SetFieldTexNum(int* TexNum) { m_TexNum = TexNum; }
	void SetFieldContactPlayer(bool ContactPlayer) { m_ContactPlayer = ContactPlayer; }
	void SetFieldTempNum(int TempNum) { m_TempNum = TempNum; }
};

#endif