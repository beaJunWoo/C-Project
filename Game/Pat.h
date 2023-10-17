#pragma once
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class Pat
{
	string name;
	bool female;
	int age;
	int power;
	float weight;
	float Happiness;
	Player* player;
public:
	Pat();
	~Pat();
	string GetName() { return name; }
	void Info();
	void Toto();
	void Play();
	void Sleep();
	
};

