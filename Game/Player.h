#pragma once
#include "Obj.h"
#include "Buffer.h"
class Player:public Obj
{
public:
	Player() {
		x = 10;
		y = 10;
		shape = "sdf";
	}
	virtual void BufferInit() {
		buffer = new Buffer;
	}
	void show() {
		buffer->WriteBuffer(x, y, shape, 1);
	}
	Buffer* GetBuffer() {
		return buffer;
	}
};

