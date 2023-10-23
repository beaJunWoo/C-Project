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
		Buffer::WriteBuffer(x, y + i, shape[i], 2);
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
			}
		}
	}

}
