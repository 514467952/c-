
#include<iostream>

using namespace std;

//交换int 类型的两个文字
void mySwaoInt(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//交换double的数据
void mySwapDouble(double &a, double &b)
{
	double tmp = a;
	a = b;
	b = tmp;
}

//类型，逻辑又非常相似
//类型参数化，泛型编程--模板技术
template<class T>//告诉编译器  下面如果出现T不要报错，T是一个通用的类型

void mySwap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//template<typename T> 等价于template<class T>
template<typename T>
void mySwap2(){};

void test01()
{
	int a = 10;
	int b = 20;
	char c1 = 'c';

	//mySwaoInt(a, b);
	//1. 自动类型推导，必须有参数类型才可以推导
	//2.参数类型必须一样

	//mySwap(a, c1);//推导不出来T，所以不能运行
	mySwap(a, b);

	//2.显示指定类型
	mySwap<int >(a, b);

	//模板必须要指定出T才可以使用
	mySwap2<double>();

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	double c = 3.14;
	double d = 1.1;
	//mySwaoInt(a, b);
	mySwap(c, d);
}

int main()
{

	test01();
	system("pause");
	return 0;
}