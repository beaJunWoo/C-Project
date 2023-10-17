#include "Pat.h"

Pat::Pat()
{
	player = new Player;
	while (true)
	{
		cout << "펫이름을 지어주세요!" << endl;
		cout << "이름:";
		cin >> name;
		system("cls");
		if (name.size() <11)
		{
			cout << name << "!!" << " 좋은 이름이네요!!" << endl;
			break;
		}
		else
		{
			cout << "이름이 너무 길어요! 다시 적어주세요!\n" << endl;
		}
	}

	int select;
	cout << "성별을 선택해 주세요 1.수컷 2.암컷" << endl;
	cin >> select;
	if (select == 1) { female = false; }
	else { female = true; }

	cout << "좋습니다!" << endl;

	cout << "나머지는 랜덤으로 정해집니다" << endl;
	age = rand() % 5 + 1;
	power = rand() % 10 + 20;
	weight = (float)(rand() % 10 + 10);
	Happiness = 20;
}
Pat::~Pat()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}
void Pat::Info()
{

}

void Pat::Toto()
{
	cout << name <<"랑 어떤걸 할까요 ? " << endl;
	cout << "1.놀아주기 2.훈련하기 3.밥먹기 4.휴식 5.잠자기" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		Play();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
		Sleep();
	default:
		break;
	}
}
void Pat::Play()
{
	int select1 = 0;
	float happy = (float)(rand()%10/10);
	cout << "어떻게 놀아줄까요?" << endl;
	cout << "1.산책가기 2.공놀이 3.동물TV시청 4.동물모임가기" << endl;
	cin >> select1;
	switch (select1)
	{
	case 1:
		cout << "산책하러 나왔습니다!!" << endl;
		cout << name << "이 신났어요!" << endl;
		cout << "행복도" << happy << "+증가!!" << endl;
		Happiness += happy;

		cout << player->DecFatigue(1, 5) << "만큼 체력을 소모 했어요" << endl;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}
void Pat::Sleep()
{
	cout << "하루가 지났습니다." << endl;
	cout << "피로도가 회복되었습니다." << endl;
	player->SetFullFatigue();
}