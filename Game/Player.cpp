#include "Player.h"

Player::Player(int x, int y, vector<const char*> shape)
{
	this->x = x;
	this->y = y;
	this->shape = shape;
}
void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		dir = LEFT;
		x--;
		Crash();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dir = RIGHT;
		x++;
		Crash();
	}
	if (GetAsyncKeyState(VK_UP))
	{
		dir = UP;
		y--;
		Crash();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		dir = DOWN;
		y++;
		Crash();
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
	{
		dir = STAY;
	}
}