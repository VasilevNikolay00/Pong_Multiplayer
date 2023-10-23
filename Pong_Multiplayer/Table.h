#pragma once
#include <raylib.h>
#include <vector>


using namespace std;

class Table
{
private:
	int window_width;
	int window_heigth;
	vector<int> score;
public:
	Table(int window_width, int window_heigth);
	Table(const Table& other) = delete;
	Table& operator =(const Table& other) = delete;

	void PointPlayerOne();

	void PointPlayerTwo();

	vector<int> GetScore();

	void Draw();

};

