#include <raylib.h>
#include <iostream>
#include "Ball.h"

using namespace std;


	Ball::Ball(float x_location, float y_location, float radiuis, Color ball_color) {
		(*this).radiuis = radiuis;
		(*this).x_location = x_location;
		(*this).y_location = y_location;
		(*this).ball_color = ball_color;
	}

	void Ball::Draw()
	{
		DrawCircle(x_location, y_location, radiuis, WHITE);
	}

	void Ball::Update()
	{	
		x_location += speed_x;
		y_location += speed_y;
		if (x_location + radiuis >= GetScreenWidth() || x_location - radiuis <=0) {
			speed_x *= -1;
		}
		if (y_location + radiuis >= GetScreenHeight() || y_location - radiuis <= 0) {
			speed_y *= -1;
		}
	}

	void Ball::SetPos(float x_location, float y_location) {
		(*this).x_location = x_location;
		(*this).y_location = y_location;
	}
	
	void Ball::Flip() {
		speed_x *= -1;
	}

	float Ball::GetXlocation()
	{
		return x_location;
	}

	float Ball::GetYLocation()
	{
		return y_location;
	}

	float Ball::GetRadius()
	{
		return radiuis;
	}
