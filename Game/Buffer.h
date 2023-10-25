#pragma once 
#include <Windows.h>

#define BufferWidth 200
#define BufferHeight 200


static HANDLE hBuffer[2];
static int screenIndex;

class Buffer
{
public:
	static void InitBuffer();
	static void FlipBuffer();
	static void ClearBuffer();
	static void WriteBuffer(int x, int y, const char* shape, int color);
	static void ReleaseBuffer();
};

