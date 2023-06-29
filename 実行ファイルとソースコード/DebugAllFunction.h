#ifndef _DEBUG_ALL_FUNCTION_H_
#define _DEBUG_ALL_FUNCTION_H_

#include "declaration.h"
#include "Var2.h"
#include "input.h"
#include "sprite.h"
#include "Texture.h"
#include "Field.h"
#include "main.h"

//FIELD* D_p_field;
#define D_MAX_FIELD		(10)

Float2 D_DrawTexture(Int2 FirstMousePos, Int2 SecondMousePos, FIELD* D_p_field);
Int2 D_GetMousePos(void);


#endif