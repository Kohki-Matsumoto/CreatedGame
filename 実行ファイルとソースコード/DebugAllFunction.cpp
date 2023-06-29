#include "DebugAllFunction.h"


//float raito = (float)SCREEN_WIDTH / (float)GetSystemMetrics(SM_CXFULLSCREEN);

Float2 D_DrawTexture(Int2 FirstMousePos, Int2 SecondMousePos, FIELD* D_p_field)
{
	//D_p_field = new FIELD;
	float size_x;
	float size_y;
	float pos_x;
	float pos_y;
	if (FirstMousePos.x < SecondMousePos.x)
	{
		size_x = (float)(SecondMousePos.x - FirstMousePos.x);
		pos_x = (float)(FirstMousePos.x) + size_x / 2.0f;
	}
	else
	{
		size_x = (float)(FirstMousePos.x - SecondMousePos.x);
		pos_x = (float)(FirstMousePos.x) - size_x / 2.0f;
	}

	if (FirstMousePos.y < SecondMousePos.y)
	{
		size_y = (float)(SecondMousePos.y - FirstMousePos.y);
		pos_y = (float)(FirstMousePos.y) + size_y / 2.0f;
	}
	else
	{
		size_y = (float)(FirstMousePos.y - SecondMousePos.y);
		pos_y = (float)(FirstMousePos.y) - size_y / 2.0f;
	}

	
	//D_p_field->SetFieldPos(MakeFloat2(pos_x * raito, pos_y * raito));
	//D_p_field->SetFieldSize(MakeFloat2(size_x * raito, size_y* raito));
	//D_p_field->SetFieldPos(MakeFloat2(1000.0f * baititututu + tasuatai2, 600.0f * baititututu + tasuatai));
	//D_p_field->SetFieldSize(MakeFloat2(300.0f * baititututu, 300.0f * baititututu));
	//D_p_field->DrawField();
	//float xadkjiuu = 1000.0f * baititututu + tasuatai2;
	//xadkjiuu = xadkjiuu;
	return MakeFloat2(0.0f, 0.0f);
}

Int2 D_GetMousePos(void)
{
	POINT point;
	GetCursorPos(&point);

	return MakeInt2(point.x, point.y);
}