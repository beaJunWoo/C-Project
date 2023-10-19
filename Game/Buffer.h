#pragma once
#include <Windows.h>
#include <string>
using namespace std;

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
	void WriteBuffer(int x, int y, string &shape, int color);
	void ReleaseBuffer();
};

