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

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,

};

class Obj
{
protected:
	int x;
	int y;
	Color color;
	Dir dir;
	Map* map = nullptr;
	vector<const char*> shape;
	bool jump = false;
	float G = 9.81f;
	float V = 5.0f;
	float Time = 0.0f;
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
	void SetMap(Map* map);
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	//Engine
	void Gravity();
	void Crash();
};

