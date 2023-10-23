#include "CpuPaddle.h"
#include <raylib.h>

void CpuPaddle::Update(float ball_y_location)
{
	if((GetYLocation() + GetHeight() / 2) > ball_y_location && GetYLocation() != 0)
	{
		SetYlocation((GetYLocation()-5));
	}
	else if ((GetYLocation()+ GetHeight()/2) < ball_y_location && GetYLocation() != GetScreenHeight() - GetHeight())
	{
		SetYlocation((GetYLocation() + 5));
	}
	
}