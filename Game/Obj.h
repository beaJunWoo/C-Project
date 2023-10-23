#pragma once
#include <vector>
#include "Buffer.h"
#include "Map.h"
using namespace std;

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	STAY
};


class Obj
{
protected:
	int x;
	int y;
	Dir dir;
	Map* map = nullptr;
	vector<const char*> shape;

public:
	Obj() {}
	Obj(int x, int y, vector<const char*> shape);
	~Obj();

public:
	int GetX() { return x; }
	int GetY() { return y; }
	Dir GetDir() { return dir; }
	vector<const char*> GetShape() { return shape; }

	void Show();
	void Move();
	void SetMap(Map* map);
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	void Crash();
};

