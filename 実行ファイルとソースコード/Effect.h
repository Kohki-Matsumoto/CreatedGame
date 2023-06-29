#pragma once
#include "declaration.h"
#include "sprite.h"
#include "TextureManager.h"
#include "Game.h"

void InitEffect(void);
void UpdateEffect(void);
void DrawEffect(void);

void SetEffect(EF_STATUS status);

class EFFECT {
public:

	Float2 Pos;
	Float2 Size;
	int framecount = 0;
	int MAX_framecount = 0;
	virtual void Draw(void) = 0;
	virtual void UpdateFrame(void) = 0;
};

class EF_Miss : public EFFECT {
	void Draw(void) override {
		DrawSprite(GetEFTexture(MISS_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
			(framecount % GetEFTexture(MISS_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.x),
			(framecount / GetEFTexture(MISS_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.y),
			1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.x,
			1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.y);
	}
	void UpdateFrame(void) override {
		framecount++;
	};
};
class EF_Good : public EFFECT {
	void Draw(void) override {
		DrawSprite(GetEFTexture(GOOD_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
			(framecount % GetEFTexture(GOOD_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(GOOD_FIGURE)->TexNum.x),
			(framecount / GetEFTexture(GOOD_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(GOOD_FIGURE)->TexNum.y),
			1.0f / (float)GetEFTexture(GOOD_FIGURE)->TexNum.x,
			1.0f / (float)GetEFTexture(GOOD_FIGURE)->TexNum.y);
	}
	void UpdateFrame(void) override {
		framecount++;
	};
};
class EF_Perfect : public EFFECT {
	void Draw(void) override {
		DrawSprite(GetEFTexture(PERFECT_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
			(framecount % GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x),
			(framecount / GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y),
			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x,
			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y);
	}
	void UpdateFrame(void) override {
		framecount++;
	};
};
//class EF_Perfect : public EFFECT {
//	void Draw(void) override {
//		DrawSprite(GetEFTexture(PERFECT_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
//			(framecount % GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x),
//			(framecount / GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y),
//			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x,
//			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y);
//	}
//};
//
//class EF_Perfect : public EFFECT {
//	void Draw(void) override {
//		DrawSprite(GetEFTexture(PERFECT_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
//			(framecount % GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x),
//			(framecount / GetEFTexture(PERFECT_FIGURE)->TexNum.x) * (1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y),
//			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.x,
//			1.0f / (float)GetEFTexture(PERFECT_FIGURE)->TexNum.y);
//	}
//};

//アクション時の内側にでるエフェクト
class RHYTHM_ANIi : public EFFECT {
	void Draw(void) override {
		DrawSprite(GetEFTexture(EF_RHYTHM_ANIi)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
			(framecount % GetEFTexture(EF_RHYTHM_ANIi)->TexNum.x) * (1.0f / (float)GetEFTexture(EF_RHYTHM_ANIi)->TexNum.x),
			(framecount / GetEFTexture(EF_RHYTHM_ANIi)->TexNum.x) * (1.0f / (float)GetEFTexture(EF_RHYTHM_ANIi)->TexNum.y),
			1.0f / (float)GetEFTexture(EF_RHYTHM_ANIi)->TexNum.x,
			1.0f / (float)GetEFTexture(EF_RHYTHM_ANIi)->TexNum.y);
	}
	void UpdateFrame(void) override {
		Pos = GetPlayerpoint()->GetPlayerPos();
		framecount++;
	};
};


class EF_Light : public EFFECT {
	void Draw(void) override {
		DrawSprite(GetEFTexture(LIGHT_EF)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
			((framecount / 1) % GetEFTexture(LIGHT_EF)->TexNum.x) * (1.0f / (float)GetEFTexture(LIGHT_EF)->TexNum.x),
			((framecount / 1) / GetEFTexture(LIGHT_EF)->TexNum.x) * (1.0f / (float)GetEFTexture(LIGHT_EF)->TexNum.y),
			1.0f / (float)GetEFTexture(LIGHT_EF)->TexNum.x,
			1.0f / (float)GetEFTexture(LIGHT_EF)->TexNum.y);
	}
	void UpdateFrame(void) override {
		framecount++;
	};
};



//DrawSprite(GetEFTexture(MISS_FIGURE)->fileNum, Pos.x, Pos.y, Size.x, Size.y,
//	framecount% GetEFTexture(MISS_FIGURE)->TexNum.x,
//	framecount / GetEFTexture(MISS_FIGURE)->TexNum.x,
//	1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.x,
//	1.0f / (float)GetEFTexture(MISS_FIGURE)->TexNum.y);