
#include<iostream>
using namespace std;
#include"aaa.h"
int main()
{
	//编译期间报错，工程有两个源文件，只编译源文件，不编译头文件
	Add(10,20);
	Sub(20, 10);
	system("pause");
	return 0;
}