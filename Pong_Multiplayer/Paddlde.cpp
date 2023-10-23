#include <raylib.h>
#include <iostream>
#include "Paddle.h"

using namespace std;

	Paddle::Paddle(float x_location, float y_location, float paddle_width, float paddle_height,Color paddle_color) 
	{
		(*this).x_location = x_location;
		(*this).y_location = y_location;
		(*this).paddle_width = paddle_width;
		(*this).paddle_height = paddle_height;
		(*this).paddle_color = paddle_color;

		cout << 10/ 2;

	}

	void Paddle::Draw()
	{
		DrawRectangle(x_location, y_location , paddle_width, paddle_height, WHITE);
	}

	void Paddle::Update()
	{
		
		if (IsKeyDown(KEY_UP) && y_location != 0) 
		{
			y_location = y_location - 5;
		}
		else if (IsKeyDown(KEY_DOWN) && y_location != GetScreenHeight() - paddle_height)
		{
			y_location = y_location + 5;
		}
		
	}

	float Paddle::GetXLocation()
	{
		return x_location;
	}

	float Paddle::GetYLocation()
	{
		return y_location;
	}

	void Paddle::SetXlocation(float x)
	{
		(*this).x_location = x;
	}

	void Paddle::SetYlocation(float y)
	{
		(*this).y_location = y;
	}


	float Paddle::GetWidth()
	{
		return paddle_width;
	}

	float Paddle::GetHeight()
	{
		return paddle_height;
	}