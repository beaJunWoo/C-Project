#pragma once
#include <vector>
using namespace std;
class Shape
{
	vector<const char*> MapShape;
	vector<const char*> PlayerShape;
	vector<const char*> BoxShape;
public:
	Shape();
	vector<const char*> GetMapShape() { return MapShape; }
	vector<const char*> GetPlayerShape() { return PlayerShape; }
	vector<const char*> GetBoxShape() { return BoxShape; }
};

