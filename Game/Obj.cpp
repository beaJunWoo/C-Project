#include "Obj.h"


Obj::Obj(int x, int y, vector<const char*> shape) :x(x), y(y), shape(shape)
{
	color = WHITE;
}
Obj::~Obj()
{
	map = nullptr;
}
void Obj::Show()
{
	for (int i = 0; i < shape.size(); i++)
	{
		Buffer::WriteBuffer(x, y + i, shape[i], color);
	}
}

void Obj::SetMap(Map* map)
{
	this->map = map;
}

void Obj::Crash()
{
	for (int Y = 0; Y < shape.size(); Y++)
	{
		for (int X = 0; X < strlen(shape[Y]) / 2; X++)
		{
			if (map->GetMap()[(int)y + Y][(int)x + X] == '1')
			{
				if (dir == LEFT) { x++; }
				if (dir == RIGHT) { x--; }
				if (dir == UP) { y++; }
				if (dir == DOWN) { y--; }
				break;
			}
		}
	}

}

void Obj::Acceleration()
{
	
	//Acceleration_V
	//Acceleration_a
	//Acceleration_Time
	if (Acceleration_on)
	{

		
		x += Acceleration_V;
		if (dir == RIGHT)
		{
			float NowX = x;
			if (Acceleration_V > 0)
			Acceleration_V = Acceleration_a * Acceleration_Time;
			float NextX = x;
			float Gab = NextX - NowX + 0.4;
			for (int i = 0; i <= Gab; i++)
			{
				for (int j = 0; j < shape.size(); j++)
				{
					if (map->GetMap()[(int)y + j][(int)NowX + i + (int)(strlen(shape[j]) / 2.0)] == '1')
					{
						dir = LEFT;
						x = (int)NowX + i + ((double)strlen(shape[j]) / 2.0) - 1;
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
			float Gab = NowX - NextX + 0.4;
			for (int i = 0; i <= Gab; i++)
			{
				for (int j = 0; j < shape.size(); j++)
				{
					if (map->GetMap()[(int)y + j][(int)NowX - i] == '1')
					{
						dir = RIGHT;
						x = (int)NowX - i + 1;
						break;
					}
				}
				if (dir == RIGHT) { break; }
			}
		}
	}
	
}

void Obj::Gravity()
{
	if (!jump && canJump&& JumpControl)
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

