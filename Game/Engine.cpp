#include "Engine.h"
#include "Obj.h"
#include "Player.h"

Engine::Engine(Obj& obj, Player& player) :obj(obj), player(player) {}

void Engine::ObjCrash()
{
	if (player.GetX() < obj.GetX() + strlen(obj.GetShape()[0])/2 &&
		obj.GetX() < player.GetX() + strlen(player.GetShape()[0])/2&&
		player.GetY()<obj.GetY()+obj.GetShape().size()&&
		obj.GetY() <player.GetY()+player.GetShape().size()){

		if (player.GetMoveDir() == M_LEFT)
		{
			player.SetDir(RIGHT);
			obj.SetDir(LEFT);
			obj.SetACRT_Time(player.GetACRT_TIME()*2.0f);
		}
		if (player.GetMoveDir() == M_RIGHT)
		{
			player.SetDir(LEFT);
			obj.SetDir(RIGHT);
			obj.SetACRT_Time(player.GetACRT_TIME() * 2.0f);
		}
		if (player.GetMoveDir() == M_STAY)
		{
			
		}
	}
}
