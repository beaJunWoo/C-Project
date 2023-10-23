#include "Buffer.h"
#include "Player.h"
#include "Map.h"
#include "Shape.h"
using namespace std;

int main()
{

	Buffer buffer;
	buffer.InitBuffer();
	Shape shape;

	Map map1(shape.GetMapShape());
	Player player(2, 2, shape.GetPlayerShape());
	player.SetMap(&map1);

	while (true)
	{

		player.Show();
		player.Move();
		map1.Show();

		buffer.FlipBuffer();
		buffer.ClearBuffer();
		Sleep(30);
	}
	buffer.ReleaseBuffer();

	return 0;
}