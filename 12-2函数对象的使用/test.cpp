#include<iostream>
using namespace std;

class Myprint
{
public:
	void operator ()(int num)
	{
		cout << "num" << num << endl;
		count++;
	}
	int count = 0;
};

void MyPrint2(int num)
{
	cout << "num" << num << endl;
}


void test01()
{
	//MyPrint是一个类，而不是函数
	Myprint myPrint;
	myPrint(111); //仿函数调用

	//MyPrint2(111);//函数调用

	Myprint()(1000);//匿名对象调用
}

//函数对象超出了普通函数的概念，可以保存状态
void  test02()
{
	Myprint myPrint;
	myPrint(111);
	myPrint(111);
	myPrint(111);
	myPrint(111);

	cout << "myPrint使用次数：" << myPrint.count << endl;
}
//函数对象作为参数传递
void doPrint(Myprint print, int num)
{
	print(num);
}
void test03()
{
	doPrint(Myprint(), 20);

	
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}