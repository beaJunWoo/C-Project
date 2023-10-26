#pragma once
class Obj;
class Player;

class Engine
{
	Obj& obj;
	Player& player;
public:
	Engine(Obj& obj, Player& player);
	void ObjCrash();
};

