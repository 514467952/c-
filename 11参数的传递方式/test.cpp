#include<iostream>

using namespace std;

void mySwap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
	cout << "mySwap::a= " << a << endl;
	cout << "mySwap::b= " << b << endl;

}

void test01()
{
	int a = 10;
	int b = 10;
	mySwap(a, b);	//值传递
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//地址传递
void mySwap2(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void test02(){
	int a = 10;
	int b = 20;
	mySwap2(&a, &b);	//地址传递
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//引用传递  类似传地址
void mySwap3(int &a, int &b)//&a=a
{
	int tmp = a;
	a = b;
	b = tmp;
}

void test03(){
	int a = 10;
	int b = 20;
	mySwap3(a, b);	//值传递
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//引用的注意事项
//1.引用必须引用一块合法的内存空间
//2.不要返回局部变量的引用
//3.不能有NULL引用，必须是合法内存空间
//4.必须在声明引用变量时进行初始化
int &doWork()
{
	int a = 10;	//a为局部变量，引用接受返回值，应该乱码
	return a;
}
void test04()
{
	//int &a = 10;引用必须引用一块合法的内存空间
	int &ret = doWork();
	cout << "ret= " << ret << endl;//第一次10是编译器做了优化
	//如果多次打印就不行
	cout << "ret= " << ret << endl;
	cout << "ret= " << ret << endl;
	cout << "ret= " << ret << endl;
}
int &doWork02()
{
	static int a = 10;
	return a;

}
void test05()
{
	
	int& ret = doWork02();
	//如果函数的返回值是引用，那么这个函数调用可以作为左值
	doWork02() = 1000;//相当于a=1000

	cout << "ret= " << ret << endl;
	cout << "ret= " << ret << endl;
	cout << "ret= " << ret << endl;
	cout << "ret= " << ret << endl;
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