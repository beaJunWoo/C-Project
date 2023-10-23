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
			if (map->GetMap()[y + Y][x + X] == '1')
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
		V = 5.0f;
		Time = 0;
	}
	if (jump)
	{
		int nowY = y;
		y =y- V * Time - 0.5 * G * Time * Time;

		int Gab = y-nowY;
		V = V - G * Time;

		Time += 0.03f;

		for (int objY = 0; objY <= Gab; objY++)
		{
			for (int objX = 0; objX < strlen(shape[shape.size() - 1]) / 2; objX++)
			{
				if (y + objY >= map->GetMap().size()) { y = map->GetMap().size() - 1 - shape.size(); jump = false; break; }
				else
				{
					if (map->GetMap()[y + objY][x+objX] == '1')
					{
						y = y + objY - shape.size();
						jump = false;
						V = 0.0;
						Time = 0.0f;
						break;
					}
				}
			}
			if (!jump) { break; }
		}
		for (int objY = 0; objY <= Gab * -1; objY++)
		{
			for (int objX = 0; objX < strlen(shape[shape.size() - 1]) / 2; objX++)
			{
				if (map->GetMap()[y + objY][x + objX] == '1')
				{
					y = y + objY + shape.size();
					jump = false;
					Time = 0.0f;
					V = 0.0;
					break;
				}
			}
			if (!jump) { break; }
		}
	}
	bool is_fall = true;
	for (int i = 0; i < strlen(shape[shape.size() - 1])/2; i++)
	{
		if (map->GetMap()[y + shape.size()][x + i] == '1' && !jump) { is_fall = false; }
	}
	if (is_fall) { jump = true; }
}