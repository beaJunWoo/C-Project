#include "Map.h"

void Map::Show()
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < strlen(map[y]); x++)
		{
			switch (map[y][x])
			{
			case '1':
				Buffer::WriteBuffer(x, y, "бс", 1);
			default:
				break;
			}

		}
	}
}