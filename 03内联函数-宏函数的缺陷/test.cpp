#include<iostream>

using namespace std;
//����һ���ӷ�
#define MyAdd(x,y) ((x)+(y))

void test01()
{
	int ret = MyAdd(10, 20)*20;//Ԥ��ʱ600  ������((10)+(20))*20
	cout << "ret=" << ret << endl;

}

#define MyCompare(a,b) ((a)<(b))?(a):(b)
inline void mycompare(int a, int b)
{
	int ret = a < b ? a : b;
	cout << "ret=:::::" << ret << endl;
}
//1.��������ע������
inline void func();//������������
void func(){};//�������ʵ�ֵ�ʱ��û�м�inline�ؼ��֣���ô���������Ȼ������������
//2.���ڶ��������������Ǳ���ģ��κ������ڶ���ĺ����Զ���Ϊ��������
//3.��Щ������������ܿ��ǲ��Ὣ����������������
	/*1���ܴ����κ���ʽ��ѭ�����
	  2���ܴ��ڹ���������ж����
	  3�����岻�ܹ����Ӵ�
	  4���ܶԺ�������ȥȡ��ַ����*/



void test02()
{
	int a = 10;
	int b = 20;
	//int ret = MyCompare(++a, b);//Ԥ�ڽ��11 �����12  ((++a)<(b))?(++a):(b) ++aִ��������
	mycompare(++a, b);
	//cout << "ret=" << ret << endl;

}
//3 �꺯��û��������

int main()
{
	//test01();
	test02();
	
	system("pause");
	return 0;
}