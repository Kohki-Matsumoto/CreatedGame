#include "Field.h"
#include "sprite.h"
#include "TextureManager.h"
#include "declaration.h"

FIELD::FIELD()
{
	m_TexNum = &GetFieldTextureInf(W1_S1_001)->fileNum;
	m_Size = GetFieldTextureInf(W1_S1_001)->fieldsize;
}

void FIELD::DrawField()
{
	DrawSprite(
		*GetTexNum(),
		m_Pos.x,
		m_Pos.y,
		m_Size.x,
		m_Size.y,
		0.0f,
		0.0f,
		1.0f,
		1.0f);
}
