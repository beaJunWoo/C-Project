#include "Buffer.h"
#include "Player.h"
#include "Map.h"
#include "Shape.h"
#include "Engine.h"
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

	Obj box(5,5,shape.GetBoxShape());
	box.SetMap(&map1);

	Engine engine(box, player);

	while (true)
	{
		if (deltatime + 5  <= GetTickCount64())
		{
			box.Show();
			box.Gravity();

			player.Show();
			player.Gravity();
			player.Move();
			
			engine.ObjCrash();
			box.Acceleration();

			map1.Show();
			
			buffer.FlipBuffer();
			buffer.ClearBuffer();

			deltatime = GetTickCount64();
		}
	}
	buffer.ReleaseBuffer();

	return 0;
}