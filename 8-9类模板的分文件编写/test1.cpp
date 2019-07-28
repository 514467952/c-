#include<iostream>
#include"Person.hpp"
using namespace std;

//建议模板不要分文件编写，写到一个文件中

//类内进行声明，最后把后缀名改为.hpp约定俗成


int main()
{
	Person<string, int >p("猪八戒", 10);
	p.showPerson();


	system("pause");
	return 0;
}

