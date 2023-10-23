#pragma once
#include <iostream>
#include <vector>
#include "Buffer.h"
using namespace std;

class Map
{
	vector<const char*> map;
public:
	Map(vector<const char*> map) :map(map) {}
	void Show();
	vector<const char*>  GetMap() { return map; }
};

