#include <iostream>
#include <Windows.h>
using namespace std;

enum Dir
{
	LEFT,
	RIGHT,
	STAY
};
void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Obj
{
	float x;
	float y;
	Dir dir;
	float m;
	const char* shape;
};

struct Box
{
	int x;
	int y;
	Dir dir;
	int J;
	const char* shape;
};


int main()
{
	Obj obj;
	obj.x = 10;
	obj.y = 10;
	obj.shape = "¿Ê";
	obj.dir = STAY;
	obj.m = 10;

	Box box;
	box.x = 15;
	box.y = 10;
	box.dir = STAY;
	box.shape = "¡á";


	float V = 0.0;
	float a = 0.4f;
	float time = 0.0f;
	

	bool move = false;
	ULONGLONG deltatime = GetTickCount64();



	while (true)
	{
		if (deltatime + 50 <= GetTickCount64())
		{
			system("cls");
			SetPosition(obj.x, obj.y);
			cout << obj.shape << endl;

			SetPosition(box.x, box.y);
			cout << box.shape << endl;


			cout << "¿¡³ÊÁö:" << 0.5 * obj.m * V * V;

			if (obj.x >= box.x) { box.dir = RIGHT;  V = V / 0.5; obj.dir = LEFT; }
			if (box.dir == RIGHT) { 
				box.x += V;
				if (V <= 0.1) { box.dir = STAY; }
			}
			cout << "¹Ú½º »óÅÂ:" << box.dir << endl;
			V = a * time;

			if (GetAsyncKeyState(VK_LEFT))
			{
				if (obj.dir == RIGHT && time>0) { time -= 2.0f; }
				else
				{
					obj.dir = LEFT;
					time += 1.0f;
				}
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				if (obj.dir == LEFT && time > 0) { time -= 2.0f; }
				else
				{
					obj.dir = RIGHT;
					time += 1.0f;
				}
			}
			if (!(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT)))
			{
				if (time <= 0)
				{
					obj.dir = STAY;
				}
				
				if (time > 0)
				{
					time -= 1.0f;
				}
			}
			if(obj.dir==RIGHT){ obj.x += V; }
			if(obj.dir==LEFT){ obj.x -= V; }
			cout << fixed;
			cout.precision(5);
			cout << "Èû:" << V << endl;
			cout << obj.dir << endl;

			deltatime = GetTickCount64();
		}
	}
	return 0;
}