#pragma once
#include "Obj.h"
class Player :public Obj
{
	bool Acceleration_on = true;
public:
	Player(int x, int y, vector<const char*> shape,Color color);
	void Move();
	virtual void Acceleration();
};


