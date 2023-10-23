#pragma once
#include <string>
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Ball.h"
#include "Table.h"

using namespace std;
class Game
{
private:

	void Draw();

	void Update();

	int screen_width;

	int screen_height;

	Paddle player1;

	CpuPaddle cpu;

	Ball ball;

	Table table;

public:
	
	Game(int screen_width, int screen_height, string window_title);
	Game(const Game& other) = delete	;
	Game& operator =(const Game& other) = delete;
	~Game() noexcept;

	bool GameClose() const;

	void Tick();

};

