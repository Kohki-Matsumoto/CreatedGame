#pragma once

#include "declaration.h"


//SCENE NextScene = NowScene;		//次のシーン

void InitScene(SCENE index);

void UninitScene(void);

void UpdateScene(void);

void DrawScene(void);

void SetScene(SCENE nextscene);

void CheckScene(void);
