#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Ball.h"
using namespace std;


int main() {

	Game game(800, 600, "Pong");


	while (!game.GameClose())
	{

		game.Tick();
	}
	
	return 0;
}