#include "Engine.h"
#include "Obj.h"
#include "Player.h"

Engine::Engine(Obj& obj, Player& player) :obj(obj), player(player) {}

void Engine::ObjCrash()
{
	if (player.GetX() < obj.GetX() + strlen(obj.GetShape()[0])*0.5 &&
		obj.GetX() < player.GetX() + strlen(player.GetShape()[0]) * 0.5 &&
		player.GetY()<obj.GetY()+obj.GetShape().size()&&
		obj.GetY() <player.GetY()+player.GetShape().size()){

		Buffer::WriteBuffer(3, 3, "Ãæµ¹Áß", 1);
		if (player.GetDir() == LEFT)
		{
			player.SetMoveDir(M_RIGHT);
			obj.SetDir(LEFT);
			obj.SetACRT_Time(player.GetACRT_TIME()*3);
			player.SetACRT_Time(player.GetACRT_TIME() * 0.8f);
		}
		if (player.GetDir() == RIGHT)
		{
			player.SetMoveDir(M_LEFT);
			obj.SetDir(RIGHT);
			obj.SetACRT_Time(player.GetACRT_TIME()*3);
			player.SetACRT_Time(player.GetACRT_TIME()*0.8f);
		}
		if (!(player.GetDir() == LEFT|| player.GetDir() == RIGHT))
		{
			if (obj.GetDir() == RIGHT)
			{
				player.SetMoveDir(M_RIGHT);
				obj.SetDir(LEFT);
				obj.SetACRT_Time(player.GetACRT_TIME() * 3);
				player.SetACRT_Time(player.GetACRT_TIME() * 0.8f);
			}
			if (obj.GetDir() == LEFT)
			{
				player.SetMoveDir(M_LEFT);
				obj.SetDir(RIGHT);
				obj.SetACRT_Time(player.GetACRT_TIME() * 3);
				player.SetACRT_Time(player.GetACRT_TIME() * 0.8f);
			}
			if (!(obj.GetDir() == RIGHT || obj.GetDir() == LEFT))
			{
				if (player.GetX() < obj.GetX())
				{
					player.SetMoveDir(M_LEFT);
					obj.SetDir(RIGHT);
					obj.SetACRT_Time(player.GetACRT_TIME() * 3);
					player.SetACRT_Time(player.GetACRT_TIME() * 0.8f);
				}
				if (player.GetX() > obj.GetX())
				{
					player.SetMoveDir(M_RIGHT);
					obj.SetDir(LEFT);
					obj.SetACRT_Time(player.GetACRT_TIME() * 3);
					player.SetACRT_Time(player.GetACRT_TIME() * 0.8f);
				}
				
			}
			else
			{
				obj.SetY(obj.GetY() - 1);
			}
		}
		else
		{
			obj.SetY(obj.GetY() - 1);
		}
	}
}
