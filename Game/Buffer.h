#pragma once 
#include <Windows.h>

#define BufferWidth 80
#define BufferHeight 40


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

