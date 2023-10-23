#include "Game.h"
#include <raylib.h>
#include <assert.h>


int screen_width;
int screen_height;
bool pause = false;
bool game_over = false;

Game::Game(int screen_width, int screen_height, string window_title) 
:
player1(0, 300, 10, 100, WHITE),
cpu(screen_width-10, screen_height / 2 - 200.0, 10, 100, WHITE),
ball(screen_width / 2.0, screen_height / 2.0, 10, WHITE),
table(screen_width, screen_height)
{
	(*this).screen_width = screen_width;
	(*this).screen_height = screen_height;

	assert(!GetWindowHandle());
	InitWindow(screen_width, screen_height, window_title.c_str());
	SetTargetFPS(75);
}
 

Game::~Game() noexcept {
	assert(GetWindowHandle());
	CloseWindow();
}

bool Game::GameClose() const
{
	return WindowShouldClose();
}


void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game::Draw()
{
	ClearBackground(BLACK);
	table.Draw();
	player1.Draw();
	cpu.Draw();
	ball.Draw();
	if (!pause)
	{
		cpu.Update(ball.GetYLocation());
		ball.Update();
		player1.Update();
	}
	else
	{
		if (game_over)
		{
			if (table.GetScore().operator[](0) == 9)
			{
				DrawText(TextFormat("%s", "Winner is Player 1"), GetScreenWidth() / 3.5 , GetScreenHeight() / 2, GetScreenWidth() / 20, YELLOW);
			}
			else if(table.GetScore().operator[](1) == 9)
			{
				DrawText(TextFormat("%s", "Winner is Player 2"), GetScreenWidth() / 3.5, GetScreenHeight() / 2, GetScreenWidth() / 20, YELLOW);
			}
		}
	}
}

void Game::Update()
{

	if (CheckCollisionCircleRec(Vector2{ ball.GetXlocation(), ball.GetYLocation() }, ball.GetRadius(), Rectangle{ player1.GetXLocation(),player1.GetYLocation(),player1.GetWidth(),player1.GetHeight() }))
	{
		ball.Flip();
	}
	else if (CheckCollisionCircleRec(Vector2{ ball.GetXlocation(), ball.GetYLocation() }, ball.GetRadius(), Rectangle{ cpu.GetXLocation(),cpu.GetYLocation(),cpu.GetWidth(),cpu.GetHeight() }))
	{
		ball.Flip();
	}


	if (ball.GetXlocation() + ball.GetRadius() >= GetScreenWidth() || ball.GetXlocation() - ball.GetRadius() <= 0) {
		if (ball.GetXlocation() + ball.GetRadius() >= GetScreenWidth())
		{
			table.PointPlayerOne();
			ball.SetPos(GetScreenWidth() / 2, GetScreenHeight() / 2);
		}
		else if (ball.GetXlocation() - ball.GetRadius() <= 0)
		{
			table.PointPlayerTwo();
			ball.SetPos(GetScreenWidth() / 2, GetScreenHeight() / 2);
		}

		if (table.GetScore().operator[](1) == 9 || table.GetScore().operator[](0) == 9)
		{
			pause = true;
			game_over = true;
		}
	}
	
	cout << player1.GetXLocation() << player1.GetYLocation() << cpu.GetXLocation() << cpu.GetYLocation() << ball.GetXlocation() << ball.GetYLocation() << endl;
}

