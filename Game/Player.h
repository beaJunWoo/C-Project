#pragma once
#include "Obj.h"
class Player :public Obj
{
	
public:
	Player(int x, int y, vector<const char*> shape,Color color);
	void Move();
	virtual void Acceleration();
	void Gravity();


};


