#include<iostream>

using namespace std;

//1. ��ͨģ���뺯��ģ������
template <class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}


void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a=97.c=99
	//myPlus(a, c);//�����Ƶ�������
	cout << myPlus2(a, c) << endl;//10+99 ��ͨ����  ���Խ�����ʽ����ת��
}

//2. ��ͨ�����ͺ���ģ��ĵ��ù���
template<class T>
void myPrint(T a, T b)
{
	cout << "ģ����õ�myPrint" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "ģ����õ�myPrint(a,b,c)" << endl;
}

void myPrint(int a, int b)
{
	cout << "��ͨ�ĺ�������myPrint" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	//����������أ�����ʹ����ͨģ��ĵ���,���û��ʵ����ͨ���������ִ���
	//myPrint(a, b);

	//�����ǿ�Ƶ���ģ�壬��ô����ʹ�ÿղ����б�
	myPrint<>(a, b);

	//3. ����ģ����Է�������
	int c = 30;
	myPrint(a, b, c);

	//�������ģ����Բ������õ�ƥ�䣬��ô����ʹ�ú���ģ��
	char e = 'c';

	char d = 'd';

	myPrint(c, d);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}