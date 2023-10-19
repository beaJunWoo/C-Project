#pragma once
#include <string>
#include "Buffer.h"
using namespace std;

class Obj
{
protected:
	int x;
	int y;
	string shape;
	Buffer* buffer;
	virtual void BufferInit() = 0;
};

