#pragma once

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "declaration.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************



//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitFade(void);
void UninitFade(void);
void UpdateFade(void);
void DrawFade(void);

void SceneFadeIn(SCENE nextScene);
void SceneTransition(SCENE nextScene);
FADE_STATS GetFadeState(void);

void SetFadeColor(float r, float g, float b);

