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
//�ȉ�Debugmain��p�w�b�_�[
#define VERES_SIZE			(100.0f)
#include "DebugAllKeyManager.h"
#include "DebugAllClass.h"
#include "DebugAllFunction.h"


void InitDebugmain(void);
void UninitDebugmain(void);
void UpdateDebugmain(void);
void DrawDebugmain(void);

#endif
