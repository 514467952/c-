
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(Person &p)
	{
		if (this->m_Name == p.m_Name&&this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person &p)
	{
		if (this->m_Name == p.m_Name&&this->m_Age == p.m_Age)
		{
			return false;
		}
		return true;
	}


	string m_Name;
	int m_Age;
};

void test01()
{
	Person p1("小明", 10);
	Person p2("小强", 15);

	Person p3("小强", 15);
	/*int a = 10;
	int b = 10;
	if (a == b)
	{
		cout << "a,b相等" << endl;
	}*/

	if (p1 == p2)
	{
		cout << "p1和p2相等" << endl;

	}
	else
	{
		cout << "不相等" << endl;
	}

	if (p3 == p2)
	{
		cout << "p3和p2相等" << endl;

	}
	else
	{
		cout << "不相等" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1和p2不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;
	}

}


int main()
{

	test01();
	system("pause");
	return 0;
}