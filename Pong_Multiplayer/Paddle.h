#pragma once
#include <raylib.h>
#include <iostream>
class Paddle
{
private:
	float paddle_width, paddle_height, x_location, y_location;
	Color paddle_color;

public:

	Paddle(float x_location, float y_location, float paddle_width, float paddle_height, Color paddle_color);

	void Draw();

	void Update();

	float GetXLocation();

	float GetYLocation();

	void SetXlocation(float x);
	
	void SetYlocation(float y);


	float GetWidth();


	float GetHeight();

}; 
