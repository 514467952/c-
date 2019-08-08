
#include<iostream>

using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

//回调函数
//void myPrint(int v)
//{
//	cout << v << endl;
//}

//仿函数
struct myPrint01
{
public:
	void operator()(int v)
	{
		cout << v << endl;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint01());
	
}


//for_each可以保存内部记录,有返回值
struct myPrint02
{
public:
	void operator()(int v)
	{
		cout << v << endl;
		this->m_Count++;
	}

	int m_Count;
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	myPrint02 print2 = for_each(v.begin(), v.end(), myPrint02());
	cout << print2.m_Count << endl;
}

//3 for_each可以绑定参数进行输出
struct myPrint03:public binary_function <int,int,void>
{
public:
	void operator()(int v,int start) const
	{
		cout << v+start << endl;
		
	}
};

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(myPrint03(), 10000));
}


class TransForm
{
public:
	int operator()(int val)
	{
		return val+10;
	}
};
void test04()
{
	vector<int>v; //原容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget; //目标容器
	vTarget.resize(v.size());//开辟空间
	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << endl; });
}

//transform第二种用法，把两个容器搬到第三个容器中
class TransForm2
{
public:
	int operator()(int val,int val2)
	{
		return val + val2;
	}
};

void test05()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(100 + i);
		v2.push_back(200 + i);
	}
	vector<int>vTarget;//目标容器

	vTarget.resize(v1.size());//提供空间
	transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TransForm2());
	for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << endl; });
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