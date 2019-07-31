
#include<iostream>
#include<string>
using namespace std;
#include<vector>
//使用系统算法的头文件
#include<algorithm>

//容器 vector








//迭代器 遍历功能 用指针理解
//普通的指针也算一种指针
void test01()
{
	int array[5] = { 1, 3, 5, 7, 8 };

	int * p = array;//指针指向数组首地址 &array[0]

	for (int i = 0; i < 5; i++)
	{
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}

}


void myPrint(int v)
{
	cout << v << endl;
}



void test02()
{
	//声明容器
	vector<int>v;//声明一个容器 这个容器中存放int类型数据 对象名称
	//向容器中加入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//遍历容器中的数据
	//利用迭代器
	vector<int >::iterator itBegin = v.begin();
	//itBegin指向是v容器的起始位置

	vector<int >::iterator itEnd = v.end();
	//itEnd指向容器中最后一个位置的下一个地址
	
	/*while (itBegin!=itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	*/


	//第二种遍历方式
	//for (int i = 0; i < 10; i++)
	/*for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << endl;
	}*/


	//第三种方式  利用算法
	for_each(v.begin(), v.end(), myPrint);


}

//操作自定义 的数据类型
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void  test03()
{
	vector<Person >v;
	Person p1("大头儿子",10);
	Person p2("小头爸爸", 30);
	Person p3("隔壁王叔叔", 30);
	Person p4("围裙妈妈", 28);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "年龄：" << it->m_Age << endl;
	}

}

//存放自定义数据类型的指针
void test04()
{
	vector<Person *>v;
	Person p1("大头儿子", 10);
	Person p2("小头爸爸", 30);
	Person p3("隔壁王叔叔", 30);
	Person p4("围裙妈妈", 28);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << "年龄：" << (*it)->m_Age << endl;
	}
}

//容器嵌套容器
void test05()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int >v2;
	vector<int >v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
		v3.push_back(i + 100);
	}

	//将小容器放入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
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