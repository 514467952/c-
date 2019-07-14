#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	Phone()
	{
		cout << "手机的默认构造函数调用" << endl;
	}
	Phone(string name)
	{

		cout << "手机的有参构造" << endl;
		m_PhoneName = name;
	}

	~Phone()
	{
		cout << "手机的析构函数" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:
	Game()
	{
		cout << "游戏的默认构造函数调用" << endl;
	}

	Game(string name)
	{
		cout << "game的有参构造" << endl;
		m_GameName = name;
	}

	~Game()
	{
		cout << "游戏的析构函数调用" << endl;
	}
	string m_GameName;
};


class Person
{
public:

	Person()
	{
		cout << "person的默认构造函数调用" << endl;
	}

	Person(string name, string phoneName, string gameName) :m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{

		cout << "Person的有参构造" << endl;
		//m_Name = name;
	}

	void playGame()
	{
		cout << m_Name << "拿着" << m_Phone.m_PhoneName << "》牌手机，玩着《" << m_Game.m_GameName << "游戏"<<endl;
	}

	
	~Person()
	{
		cout << "person的析构函数的调用" << endl;
	}
	string m_Name;//姓名

	Phone m_Phone;//手机

	Game m_Game;//游戏
};

//类对象作为类成员，构造的顺序：先将类对象一一构造，然后构造自己，析构相反

void test01()
{
	Person p("狗蛋","苹果", "切水果");
	p.playGame();
	//p.m_Phone.m_PhoneName = "三星";
	//p.m_Game.m_GameName = "斗地主";

}


int main()

{
	test01();
	system("pause");
	return 0;
}