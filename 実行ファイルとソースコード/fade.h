#pragma once

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "declaration.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************



//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitFade(void);
void UninitFade(void);
void UpdateFade(void);
void DrawFade(void);

void SceneFadeIn(SCENE nextScene);
void SceneTransition(SCENE nextScene);
FADE_STATS GetFadeState(void);

void SetFadeColor(float r, float g, float b);

