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
	mySwap(a, b);	//ֵ����
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//��ַ����
void mySwap2(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void test02(){
	int a = 10;
	int b = 20;
	mySwap2(&a, &b);	//��ַ����
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//���ô���  ���ƴ���ַ
void mySwap3(int &a, int &b)//&a=a
{
	int tmp = a;
	a = b;
	b = tmp;
}

void test03(){
	int a = 10;
	int b = 20;
	mySwap3(a, b);	//ֵ����
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
//���õ�ע������
//1.���ñ�������һ��Ϸ����ڴ�ռ�
//2.��Ҫ���ؾֲ�����������
//3.������NULL���ã������ǺϷ��ڴ�ռ�
//4.�������������ñ���ʱ���г�ʼ��
int &doWork()
{
	int a = 10;	//aΪ�ֲ����������ý��ܷ���ֵ��Ӧ������
	return a;
}
void test04()
{
	//int &a = 10;���ñ�������һ��Ϸ����ڴ�ռ�
	int &ret = doWork();
	cout << "ret= " << ret << endl;//��һ��10�Ǳ����������Ż�
	//�����δ�ӡ�Ͳ���
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
	//��������ķ���ֵ�����ã���ô����������ÿ�����Ϊ��ֵ
	doWork02() = 1000;//�൱��a=1000

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