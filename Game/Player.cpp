#include "Player.h"

Player::Player(int x, int y, vector<const char*> shape,Color color)
{
	this->x = x;
	this->y = y;
	this->shape = shape;
	this->color = color;
}
void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		
		if (!Acceleration_on)
		{
			dir = LEFT;
			x--;	
			Crash();	
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		
		if (!Acceleration_on)
		{
			dir = RIGHT;
			x++;
			Crash();
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		dir = UP;	y--;
		Crash();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		dir = DOWN;
		y++;
		Crash();
	}
	if (Acceleration_on) { Acceleration(); }
	else
	{
		if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
		{
			dir = STAY;
		}
	}
	
	
}
void Player::Acceleration()
{
	//Acceleration_V
	//Acceleration_a
	//Acceleration_Time
	if (Acceleration_on)
	{
		
		Acceleration_V = Acceleration_a * Acceleration_Time;
		if (GetAsyncKeyState(VK_LEFT))
		{ 
			if (dir == RIGHT && Acceleration_Time > 0) { Acceleration_Time -= 2.0f; }
			else
			{
				dir = LEFT;
				Acceleration_Time += 1.0f;
			}
			
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{ 
			if (dir == LEFT && Acceleration_Time > 0) { Acceleration_Time -= 2.0f; }
			else
			{
				dir = RIGHT;
				Acceleration_Time += 1.0f;
			}
			
		}
		if (!(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT)))
		{
			if (Acceleration_Time <= 0)
				dir = STAY;
		
			if (Acceleration_Time > 0)
				Acceleration_Time -= 1.0f;
		}
		if (dir == RIGHT) 
		{
			float NowX = x;
			x += Acceleration_V; 
			float NextX = x;
			float Gab = NextX - NowX+0.4;
			for (int i = 0; i <= Gab; i++)
			{
				for (int j = 0; j < shape.size(); j++)
				{
					if (map->GetMap()[(int)y+j][(int)NowX + i + (int)(strlen(shape[j]) /2.0)] == '1')
					{
						dir = LEFT;
						x = (int)NowX + i + ((double)strlen(shape[j]) / 2.0) -1;
						break;
					}
				}
				if (dir == LEFT) { break; }
			}
		}
		if (dir == LEFT) 
		{ 
			float NowX = x;
			x -= Acceleration_V;
			float NextX = x;
			float Gab = NowX -NextX  + 0.4;
			for (int i = 0; i <= Gab; i++)
			{
				for (int j = 0; j < shape.size(); j++)
				{
					if (map->GetMap()[(int)y + j][(int)NowX - i] == '1')
					{
						dir = RIGHT;
						x = (int)NowX - i+1 ;
						break;
					}
				}
				if (dir == RIGHT) { break; }
			}
			
		}
	}
}