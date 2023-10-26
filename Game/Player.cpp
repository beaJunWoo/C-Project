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
		dir = LEFT;
		if (!Acceleration_on)
		{
			
			x--;	
			Crash();	
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dir = RIGHT;
		if (!Acceleration_on)
		{
			
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
			if (movedir == M_RIGHT && Acceleration_Time > 0) { Acceleration_Time -= 0.4f; }
			else
			{
				movedir = M_LEFT;
				if(Acceleration_MaxV> Acceleration_V)
					Acceleration_Time += 0.2f;
			}
			
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{ 
			if (movedir == M_LEFT && Acceleration_Time > 0) { Acceleration_Time -= 0.4f; }
			else
			{
				movedir = M_RIGHT;
				if (Acceleration_MaxV > Acceleration_V)
					Acceleration_Time += 0.2f;
			}
			
		}
		if (!(GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState(VK_RIGHT)))
		{
			if (Acceleration_Time <= 0)
				movedir = M_STAY;
		
			if (Acceleration_Time > 0)
				Acceleration_Time -= 0.2f;
		}
		if (movedir == M_RIGHT)
		{
			float NowX = x;
			if(Acceleration_V>0)
				x += Acceleration_V; 
			float NextX = x;
			float Gab = NextX - NowX+0.4;
			for (int i = 0; i <= Gab; i++)
			{
				for (int j = 0; j < shape.size(); j++)
				{
					if (map->GetMap()[(int)y+j][(int)NowX + i + (int)(strlen(shape[j]) /2.0)] == '1')
					{
						movedir = M_LEFT;
						x = (int)NowX + i + ((double)strlen(shape[j]) / 2.0) -1;
						break;
					}
				}
				if (movedir == M_LEFT) { break; }
			}
		}
		if (movedir == M_LEFT)
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
						movedir = M_RIGHT;
						x = (int)NowX - i+1 ;
						break;
					}
				}
				if (movedir == M_RIGHT) { break; }
			}
		}
	}
}

void Player::Gravity()
{
	if (GetAsyncKeyState(VK_SPACE) && !jump && canJump)
	{
		jump = true;
		Graivty_V = 5.0f;
		Gravity_Time = 0.0f;
	}
	if (jump)
	{
		Gravity_Time += 0.1;
		float NowY = y + shape.size();
		y = y - Graivty_V * Gravity_Time + 0.5f * Graivty_G * Gravity_Time * Gravity_Time;
		float NextY = y + shape.size();
		float Gab = NextY - NowY;
		if (Gab < 0)
		{
			for (int i = 0; i < (int)Gab * -1; i++)
			{
				for (int j = 0; j < strlen(shape[0]) / 2; j++)
				{
					if (map->GetMap()[(int)NowY - i - shape.size() - 1][(int)(x + j)] == '1')
					{
						y = NowY - i - shape.size();
						jump = false;
						Graivty_V = 0.0f;
						Gravity_Time = 0.0f;
						break;
					}
				}
				if (!jump) { break; }
			}
		}
		if (Gab > 0)
		{
			for (int i = 0; i < (int)Gab; i++)
			{
				for (int j = 0; j < strlen(shape[shape.size() - 1]) / 2; j++)
				{
					if (map->GetMap()[(int)NowY + i][(int)x + j] == '1')
					{
						y = NowY - shape.size() + i;
						jump = false;
						Graivty_V = 0.0f;
						Gravity_Time = 0.0f;
						break;
					}
				}
				if (!jump) { break; }
			}
		}

	}
	bool OnAir = true;
	for (int j = 0; j < strlen(shape[shape.size() - 1]) / 2; j++)
	{
		if (map->GetMap()[(int)y + shape.size()][(int)x + j] == '1')
		{
			OnAir = false;
			break;
		}
	}
	if (OnAir) { jump = true; }
	else
		canJump = true;
}
