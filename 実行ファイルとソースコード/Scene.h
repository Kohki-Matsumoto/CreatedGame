#pragma once

#include "declaration.h"


//SCENE NextScene = NowScene;		//���̃V�[��

void InitScene(SCENE index);

void UninitScene(void);

void UpdateScene(void);

void DrawScene(void);

void SetScene(SCENE nextscene);

void CheckScene(void);
