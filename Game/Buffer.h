#pragma once
#include <Windows.h>

#define BufferWidth 80
#define BufferHeight 40



class Buffer
{
	HANDLE hBuffer[2];
	int screenIndex;
public:
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
	void ReleaseBuffer();
};

