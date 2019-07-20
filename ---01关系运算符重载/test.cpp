
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
	Person p1("С��", 10);
	Person p2("Сǿ", 15);

	Person p3("Сǿ", 15);
	/*int a = 10;
	int b = 10;
	if (a == b)
	{
		cout << "a,b���" << endl;
	}*/

	if (p1 == p2)
	{
		cout << "p1��p2���" << endl;

	}
	else
	{
		cout << "�����" << endl;
	}

	if (p3 == p2)
	{
		cout << "p3��p2���" << endl;

	}
	else
	{
		cout << "�����" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1��p2�����" << endl;
	}
	else
	{
		cout << "���" << endl;
	}

}


int main()
{

	test01();
	system("pause");
	return 0;
}