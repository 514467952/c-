
#include<iostream>

using namespace std;
#include<string>

void test01()
{
	//��һ��
	pair<string, int>p(string("Tom"), 100);

	//ȡֵ
	cout << "������" << p.first << endl;
	cout << "���䣺" << p.second << endl;

	//�ڶ��ִ�����ʽ
	pair<string, int>p2 = make_pair("Jerry", 200);
	cout << "������" << p.first << endl;
	cout << "���䣺" << p.second << endl;
}




int main()
{
	test01();
	system("pause");
	return 0;
}