
#include<iostream>

using namespace std;


//函数重载
//c++中 函数名称可以重复
//必须在同一个作用域，函数名称相同
//函数的 参数个数 不同 或者 类型 不同 或者 顺序 不同
void func()
{
	cout << "无参数的func" << endl;
}

void func(int a)
{
	cout << "有参数的func(int a)" << endl;
}
void func(double a)
{
	cout << "有参数的func(double a)" << endl;
}
void func(double a,int b)
{
	cout << "有参数的func(double a,int b)" << endl;
}

void func(int a,double b)
{
	cout << "有参数的func(int a,double b)" << endl;
}

//函数值可以作为函数重载的条件吗？   不行，
//int func(int a,double a)
//{
//	cout << "有参数的func(double a)" << endl;
//}

void test01()
{
	func(1.1,3);
	func(1, 3.4);
}

//当函数重载 碰到了 默认参数时候，需要注意避免二义性问题
void func2(int a, int b = 10)
{

}
void func2(int a)
{

}

void test02()
{
	//func2(10);
}

//引用的重载版本
void func3(int &a)  //引用必须引用合法的内存空间
{
	cout << " int &a" << endl;
}
void func3(const int &a)  //const 也是可以作为函数重载的条件  int tmp=10; const int &a=tmp;
{
	cout << "const int &a" << endl;
}
void test03()
{
	int a = 10;
	func3(10);
}

int main()
{
	//test01();
	test03();
	system("pause");
	return 0;
}
/*函数名称相同，又在同一个作用域下
函数参数个数不同，类型不同，顺序不同都可以满足重载条件
函数的返回值不可以作为函数重载条件
当函数重载碰到了函数的默认参数，要避免二义性*/