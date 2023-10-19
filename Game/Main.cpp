#include "Buffer.h"
#include "Player.h"
using namespace std;
int main()
{
	Player player;
	player.BufferInit();
	player.GetBuffer()->InitBuffer();

	while (true)
	{

		player.show();
	
		Sleep(1000);
		player.GetBuffer()->FlipBuffer();
		player.GetBuffer()->ClearBuffer();
		
	}
	player.GetBuffer()->ReleaseBuffer();



	return 0;
}