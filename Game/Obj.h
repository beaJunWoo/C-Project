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
	int x;
	int y;
	Color color;
	Dir dir;
	Map* map = nullptr;
	vector<const char*> shape;

	//Engine
	bool jump = false;
	bool canJump = false;
	bool JumpControl = false;
	bool Acceleration_on = true;

	float Graivty_G = 9.81f;
	float Graivty_V = 5.0f; 
	float Gravity_Time = 0.0f;

	float Acceleration_MaxV = 3.0f;
	float Acceleration_V = 0.0f;
	float Acceleration_a = 1.5f;
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
	void SetDir(Dir dir) { this->dir = dir; }
	void SetACRT_Time(float Acceleration_Time) { this->Acceleration_Time = Acceleration_Time; }

	//Engine
	void Gravity();
	void Crash();
	void Acceleration();
};

