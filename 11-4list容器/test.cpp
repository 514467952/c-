
#include<iostream>
using namespace std;
#include<list>
#include<algorithm>
#include<string>

//验证list是双向循环链表
void test01()
{
	list<int>mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}
	list<int>::_Nodeptr node = mylist._Myhead->_Next;


	for (int i = 0; i < mylist._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == mylist._Myhead)
		{
			node = node->_Next;
		}
	}

}

//打印list，迭代器
void printList(list<int>&L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test02()
{
	list<int>L(10,10);
	list<int>L2(L.begin(), L.end());

	printList(L);
	printList(L2);
	L2.push_back(100);

	//逆序打印
	for (list<int>::reverse_iterator it = L2.rbegin(); it != L2.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//list迭代器不支持随机访问
	list<int>::iterator itBegin = L2.begin();
	//itBegin = itBegin + 1;

	//插入数据
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);

	printList(L3); //200 300 100 10 30 20

	//删除两端数据
	L3.pop_front();//头删
	L3.pop_back();//尾删
	printList(L3);//打印后结果300 100 10 30

	L3.insert(L3.begin(), 1000);//1000 300 100 10 30
	printList(L3);

	L3.push_back(10);
	L3.remove(10);//参数，直接放值,所有值等于参数的值都被删除
	printList(L3);//1000 300 100 30

}

void test03()
{
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);
	cout << "大小：" << L3.size() << endl;
	if (L3.empty())
	{
		cout << "L3为空" << endl;
	}
	else
	{
		cout << "L3不为空" << endl;
	}
	L3.resize(10);
	printList(L3);

	L3.resize(3);
	printList(L3);

	list<int>L4;
	L4.assign(L3.begin(), L3.end());

	cout << "front" << L4.front() << endl;
	cout << "back" << L4.back() << endl;
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(40);
	L.push_back(30);

	L.reverse();
	printList(L);//30 40 20 10

	//sort(L.begin(), L.end());//所有不支持随机访问的迭代器，不可以用系统提供的算法
	//如果不支持用系统提供算法，那么这个类内部会提供
	L.sort();

	printList(L);//从小到大排序
	//从大到小排序，用回调函数
	L.sort(myCompare);
	printList(L);
}

//自定义数据类型的处理
class Person
{
public:
	Person(string name, int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	//重载==让remove可以删除自定义的Person类型
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name&&this->m_Age == p.m_Age&&this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height;//身高
};

//Person的排序规则，如果年龄相同 按照身高的升序排序
bool myComparePerson(Person &p1, Person &p2)
{
	/*if (p1.m_Age > p2.m_Age)
	{
		return true;
	}
	return false;*/
	//如果年龄相同按身高排序
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height < p2.m_Height;
	}
	else
	{
		return p1.m_Age>p2.m_Age;
	}
	
}

void test05()
{
	list<Person>L;
	Person p1("曹操", 10,165);
	Person p2("锐雯", 20,170);
	Person p3("女枪", 17,177);
	Person p4("德雷克斯", 19,120);
	Person p5("MT", 18,200);
	Person p6("狗蛋", 18, 166);
	Person p7("狗剩", 18, 210);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//要求：按照年龄降序输出
	//对于自定义数据类型，必须指定排序规则
	//排序时，还要用到回调函数
	L.sort(myComparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age <<"身高: "<<it->m_Height<< endl;
	}

	cout << endl;
	//删除 狗蛋
	L.remove(p6);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << "身高: " << it->m_Height << endl;
	}
}



int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	system("pause");
	return 0;
}

