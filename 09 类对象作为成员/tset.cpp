#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	Phone()
	{
		cout << "�ֻ���Ĭ�Ϲ��캯������" << endl;
	}
	Phone(string name)
	{

		cout << "�ֻ����вι���" << endl;
		m_PhoneName = name;
	}

	~Phone()
	{
		cout << "�ֻ�����������" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:
	Game()
	{
		cout << "��Ϸ��Ĭ�Ϲ��캯������" << endl;
	}

	Game(string name)
	{
		cout << "game���вι���" << endl;
		m_GameName = name;
	}

	~Game()
	{
		cout << "��Ϸ��������������" << endl;
	}
	string m_GameName;
};


class Person
{
public:

	Person()
	{
		cout << "person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(string name, string phoneName, string gameName) :m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{

		cout << "Person���вι���" << endl;
		//m_Name = name;
	}

	void playGame()
	{
		cout << m_Name << "����" << m_Phone.m_PhoneName << "�����ֻ������š�" << m_Game.m_GameName << "��Ϸ"<<endl;
	}

	
	~Person()
	{
		cout << "person�����������ĵ���" << endl;
	}
	string m_Name;//����

	Phone m_Phone;//�ֻ�

	Game m_Game;//��Ϸ
};

//�������Ϊ���Ա�������˳���Ƚ������һһ���죬Ȼ�����Լ��������෴

void test01()
{
	Person p("����","ƻ��", "��ˮ��");
	p.playGame();
	//p.m_Phone.m_PhoneName = "����";
	//p.m_Game.m_GameName = "������";

}


int main()

{
	test01();
	system("pause");
	return 0;
}