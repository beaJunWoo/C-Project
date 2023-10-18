#include "Buffer.h"

using namespace std;
int main()
{
	Buffer buffer;
	buffer.InitBuffer();

	while (true)
	{
		buffer.WriteBuffer(1, 1, "¿Ê", 1);
		buffer.FlipBuffer();
		buffer.ClearBuffer();
		Sleep(10);
	}
	buffer.ReleaseBuffer();



	return 0;
}