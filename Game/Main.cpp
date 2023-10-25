#include "Buffer.h"
#include "Player.h"
#include "Map.h"
#include "Shape.h"
using namespace std;

int main()
{
	ULONGLONG deltatime = GetTickCount64();

	Buffer buffer;
	buffer.InitBuffer();
	Shape shape;

	Map map1(shape.GetMapShape());
	Player player(2, 2, shape.GetPlayerShape(),RED);
	player.SetMap(&map1);

	while (true)
	{
		if (deltatime + 20 <= GetTickCount64())
		{

			player.Show();
			player.Gravity();
			player.Move();
			
			map1.Show();
			
			buffer.FlipBuffer();
			buffer.ClearBuffer();
			Sleep(30);
			deltatime = GetTickCount64();
		}
	}
	buffer.ReleaseBuffer();

	return 0;
}