#include "Pat.h"

Pat::Pat()
{
	player = new Player;
	while (true)
	{
		cout << "���̸��� �����ּ���!" << endl;
		cout << "�̸�:";
		cin >> name;
		system("cls");
		if (name.size() <11)
		{
			cout << name << "!!" << " ���� �̸��̳׿�!!" << endl;
			break;
		}
		else
		{
			cout << "�̸��� �ʹ� ����! �ٽ� �����ּ���!\n" << endl;
		}
	}

	int select;
	cout << "������ ������ �ּ��� 1.���� 2.����" << endl;
	cin >> select;
	if (select == 1) { female = false; }
	else { female = true; }

	cout << "�����ϴ�!" << endl;

	cout << "�������� �������� �������ϴ�" << endl;
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
	cout << name <<"�� ��� �ұ�� ? " << endl;
	cout << "1.����ֱ� 2.�Ʒ��ϱ� 3.��Ա� 4.�޽� 5.���ڱ�" << endl;
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
	cout << "��� ����ٱ��?" << endl;
	cout << "1.��å���� 2.������ 3.����TV��û 4.�������Ӱ���" << endl;
	cin >> select1;
	switch (select1)
	{
	case 1:
		cout << "��å�Ϸ� ���Խ��ϴ�!!" << endl;
		cout << name << "�� �ų����!" << endl;
		cout << "�ູ��" << happy << "+����!!" << endl;
		Happiness += happy;

		cout << player->DecFatigue(1, 5) << "��ŭ ü���� �Ҹ� �߾��" << endl;
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
	cout << "�Ϸ簡 �������ϴ�." << endl;
	cout << "�Ƿε��� ȸ���Ǿ����ϴ�." << endl;
	player->SetFullFatigue();
}