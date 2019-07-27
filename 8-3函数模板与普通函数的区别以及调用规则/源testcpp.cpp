#include<iostream>

using namespace std;

//1. 普通模板与函数模板区别
template <class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}


void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a=97.c=99
	//myPlus(a, c);//类型推导不出来
	cout << myPlus2(a, c) << endl;//10+99 普通函数  可以进行隐式类型转换
}

//2. 普通函数和函数模板的调用规则
template<class T>
void myPrint(T a, T b)
{
	cout << "模板调用的myPrint" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "模板调用的myPrint(a,b,c)" << endl;
}

void myPrint(int a, int b)
{
	cout << "普通的函数调用myPrint" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	//如果出现重载，优先使用普通模板的调用,如果没有实现普通函数，出现错误
	//myPrint(a, b);

	//如果想强制调用模板，那么可以使用空参数列表
	myPrint<>(a, b);

	//3. 函数模板可以发生重载
	int c = 30;
	myPrint(a, b, c);

	//如果函数模板可以产生更好的匹配，那么优先使用函数模板
	char e = 'c';

	char d = 'd';

	myPrint(c, d);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}