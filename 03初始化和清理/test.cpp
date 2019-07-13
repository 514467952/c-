#include<iostream>

using namespace std;

class Person
{
public:
	//构造函数的写法
	//与类名相同，没有返回值，不写void ，可以发生重载（可以有参数）
	//构造函数由编译器自动调用，而不是手动，而且只会调用一次
	//构造函数作用域是在public下
	Person()
	{
		cout << "构造函数" << endl;
	}

	//析构函数写法
	// 与类名相同 类名前面加一个符号“~”，也没有返回值，不写void，不可以有参数（不能发生重载）
	//自动调用，只调用一次  结束时调用
	~Person()
	{
		cout << "析构函数的调用" << endl;
	}
};
void test01()
{
	Person p1;//默认调用了构造和析构，是系统提供的两个空实现的函数

}
int main()
{

	test01();

	Person p1;
	system("pause");
	return 0;
}