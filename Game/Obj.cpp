#include "Obj.h"


Obj::Obj(int x, int y, vector<const char*> shape) :x(x), y(y), shape(shape)
{
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

void Obj::Gravity()
{
	if (GetAsyncKeyState(VK_SPACE) && !jump)
	{
		jump = true;
		Graivty_V =10.0f;
		Gravity_Time = 0.0f;
	}
	if (jump)
	{
		Gravity_Time += 0.1;
		float NowY = y + shape.size();
		y = y - Graivty_V * Gravity_Time + 0.5f + Graivty_G * Gravity_Time * Gravity_Time;
		float NextY =y + shape.size();
		float Gab = NextY -NowY+0.4;

		if (Gab > 0)
		{
			for (int i = 0; i < (int)Gab; i++)
			{
				for (int j = 0; j < strlen(shape[shape.size() - 1])/2; j++)
				{
					if (map->GetMap()[(int)NowY + i ][(int)x+j] == '1')
					{
						y = NowY -shape.size() + i;
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
		if (map->GetMap()[(int)y+ shape.size()][(int)x + j] == '1')
		{
			OnAir = false;
			break;
		}
	}
	if (OnAir) { jump = true; }
}

