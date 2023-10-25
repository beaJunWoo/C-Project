#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	float x;
	float y;
	Color color;
	Dir dir;
	Map* map = nullptr;
	vector<const char*> shape;

	//Engine
	bool jump = false;
	float Graivty_G = 9.81f;
	float Graivty_V = 5.0f; 
	float Gravity_Time = 0.0f;

	float Acceleration_V = 0.0f;
	float Acceleration_a = 0.4f;
	float Acceleration_Time = 0.0f;
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
	virtual void Acceleration() = 0;
};

