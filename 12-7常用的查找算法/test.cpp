
#include<iostream>
#include<vector>
using namespace std;
#include<string>
#include<algorithm>
#include<functional>

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	find(v.begin(), v.end(), 5);//查找这个容器中有没有5

	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "找到了数据：" << *pos << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

//利用find查找自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person&p)
	{
		if (this->m_Name ==p.m_Name&&this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
};
void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos= find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << "找到了数据姓名：" << (*pos).m_Name<<"年龄："<<pos->m_Age << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}



//find_if
class MyCompare:public binary_function<Person*,Person*,bool>
{
public:
	bool operator ()(Person *p1,Person *p2)const
	{
		if (p1->m_Name==p2->m_Name&&p1->m_Age==p2->m_Age)
		{
			return true;
		}
		return false;
	}
};
void test03()
{
	vector<Person *>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person *p = new Person("bbb", 21);
	vector<Person *>::iterator pos= find_if(v.begin(), v.end(),bind2nd(MyCompare(),p));

	 if (pos != v.end())
	 {
		 cout << "找到了数据姓名：" << (*pos)->m_Name << "年龄：" << (*pos)->m_Age << endl;
	 }
	 else
	 {
		 cout << "没找到" << endl;
	 }
}

void test04()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);

	vector<int>::iterator pos=adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "找到了相邻元素" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool ret=binary_search(v.begin(), v.end(), 4);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


class GreateThenFour
{
public:
	bool operator()(int v)
	{
		return v >=4;
	}
};
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num=count(v.begin(), v.end(), 4);
	cout << "4的个数为：" << num << endl;

	num =count_if(v.begin(), v.end(), GreateThenFour());
	cout << "大于等于4的个数为：" << num << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}