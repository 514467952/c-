
#include<iostream>

using namespace std;


//��������
//c++�� �������ƿ����ظ�
//������ͬһ�������򣬺���������ͬ
//������ �������� ��ͬ ���� ���� ��ͬ ���� ˳�� ��ͬ
void func()
{
	cout << "�޲�����func" << endl;
}

void func(int a)
{
	cout << "�в�����func(int a)" << endl;
}
void func(double a)
{
	cout << "�в�����func(double a)" << endl;
}
void func(double a,int b)
{
	cout << "�в�����func(double a,int b)" << endl;
}

void func(int a,double b)
{
	cout << "�в�����func(int a,double b)" << endl;
}

//����ֵ������Ϊ�������ص�������   ���У�
//int func(int a,double a)
//{
//	cout << "�в�����func(double a)" << endl;
//}

void test01()
{
	func(1.1,3);
	func(1, 3.4);
}

//���������� ������ Ĭ�ϲ���ʱ����Ҫע��������������
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

//���õ����ذ汾
void func3(int &a)  //���ñ������úϷ����ڴ�ռ�
{
	cout << " int &a" << endl;
}
void func3(const int &a)  //const Ҳ�ǿ�����Ϊ�������ص�����  int tmp=10; const int &a=tmp;
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
/*����������ͬ������ͬһ����������
��������������ͬ�����Ͳ�ͬ��˳��ͬ������������������
�����ķ���ֵ��������Ϊ������������
���������������˺�����Ĭ�ϲ�����Ҫ���������*/