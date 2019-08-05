
#include<iostream>

using namespace std;
#include<string>

void test01()
{
	//第一种
	pair<string, int>p(string("Tom"), 100);

	//取值
	cout << "姓名：" << p.first << endl;
	cout << "年龄：" << p.second << endl;

	//第二种创建方式
	pair<string, int>p2 = make_pair("Jerry", 200);
	cout << "姓名：" << p.first << endl;
	cout << "年龄：" << p.second << endl;
}




int main()
{
	test01();
	system("pause");
	return 0;
}