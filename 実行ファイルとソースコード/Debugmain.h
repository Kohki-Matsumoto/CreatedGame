#ifndef _DEBUG_MAIN_H_
#define _DEBUG_MAIN_H_
#include "main.h"
#include "Debugmain.h"
#include "Var2.h"
#include "declaration.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Texture.h"
#include "sprite.h"
#include "input.h"
//以下Debugmain専用ヘッダー
#define VERES_SIZE			(100.0f)
#include "DebugAllKeyManager.h"
#include "DebugAllClass.h"
#include "DebugAllFunction.h"


void InitDebugmain(void);
void UninitDebugmain(void);
void UpdateDebugmain(void);
void DrawDebugmain(void);

#endif
