#include "Table.h"
#include "raylib.h"
#include <vector>
#include <iostream>

using namespace std;



Table::Table(int window_width, int window_heigth)
	:
	score { 0,0 }
{
	(*this).window_width = window_width;
	(*this).window_heigth = window_heigth;
}

void Table::PointPlayerOne()
{
	score[0]++;
}

void Table::PointPlayerTwo()
{
	score[1]++;
}

void Table::Draw()
{
	DrawRectangle(GetScreenWidth() / 2, 0, 1, GetScreenHeight(), WHITE);
	DrawFPS(10, 10);
	DrawText(TextFormat("%i", score[0]), GetScreenWidth() / 4 - 20, 20, 80, WHITE);
	DrawText(TextFormat("%i", score[1]), 3 * GetScreenWidth() / 4 - 20, 20, 80, WHITE);
}



 vector<int> Table::GetScore()
{
	return score;
}



