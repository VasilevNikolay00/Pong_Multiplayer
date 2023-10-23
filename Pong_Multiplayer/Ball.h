#pragma once
#include <raylib.h>
#include <iostream>
class Ball
{
private:
	float radiuis, x_location, y_location, speed_x{ 6 }, speed_y{ 6 };
	Color ball_color;

public:


	Ball(float x_location, float y_location, float radiuis, Color ball_color);

	void Draw();

	void Update();

	void SetPos(float x_location, float y_location);

	void Flip();

	float GetXlocation();

	float GetYLocation();

	float GetRadius();

};
