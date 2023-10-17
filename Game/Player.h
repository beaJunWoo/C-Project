#pragma once
#include <random>
using namespace std;
class Player
{
	int Today;
	int Fatigue;
public:
	Player();
	void SetFullFatigue() { Fatigue = 10; }
	int DecFatigue(int min, int max) { 
		int dec = rand() % min + max-min;
		return dec;
	}
};

