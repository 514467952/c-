
#include<iostream>
#include<iomanip>//使用控制符头文件
using namespace std;

/*
cout.put() //向缓冲区写字符
cout.write()//从buffer中写num个字节到当前输出流中
*/

void test01()
{
	//cout.put('a').put('b');

	char buf[1024] = "helloworld";

	cout.write(buf, strlen(buf));
}


void test02()
{
	//通过流成员函数
	int number = 99;
	cout.width(20);
	cout.fill('*');
	cout.setf(ios::left);//输入内容做对齐
	cout.unsetf(ios::dec);//卸载十进制
	cout.setf(ios::hex);//变为16进制
	cout.setf(ios::showbase);//强制输出整数的基数 0 0x
	cout.unsetf(ios::hex);//卸载十六进制
	cout.setf(ios::oct);//变为8进制
	cout << number << endl;

}

//控制符的方式显示
void test03()
{
	int number = 99;
	cout << setw(20)
		<< setfill('^')
		<< setiosflags(ios::showbase)//基数
		<< setiosflags(ios::left)//左对齐
		<< hex //十六进制
		<< number
		<< endl;
}



int main()
{
	test03();
	system("pause");
	return 0;
}