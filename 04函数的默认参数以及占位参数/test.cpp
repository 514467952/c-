
#include<iostream>

using namespace std;
//函数的默认参数，参数后面=....

//函数参数注意事项，如果有一个位置有了默认参数，那么从这个位置开始，从左往后都必须有默认参数

//传入参数，如果有参数，就用传入的参数，没有参数就用默认值

//如果函数声明里面有了默认参数，那么函数实现时候必须没有
//函数声明和实现里 只能有一个有默认参数，不要同时出现默认参数
void myFunc(int a = 10, int b = 10);
void myFunc(int a , int b ){}

void func(int a, int b=10,int c=1)
{
	cout << "a+b+c=" << a + b + c<< endl;

}

void test01()
{
	//func();
	func(1,2);

}

//函数 占位参数
//如果有占位参数，函数调用时必须提供这个参数，但是用不到参数
//占位参数，没有什么大用途
//占位参数 可以有默认值
void func2(int a,int=1)
{

}
void test02()
{
	func2(10, 1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}