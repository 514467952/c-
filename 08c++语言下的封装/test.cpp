
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	char mName[64];

	int mAge;


	void PersonEat(struct Person *p)
	{
		printf("%s �ڳ��˷�\n", p->mName);
	}

};

struct Dog
{
	char mName[64];

	int mAge;

	void DogEat(struct  Dog *dog)
	{
		printf("%s ,�ڳԹ���\n", dog->mName);
	}
};

//c++�еķ�װ �ϸ�����ת����� �����Ժ���Ϊ ����һ��
//1.���Ժ���Ϊ��Ϊһ����������ʾ�����е�����
//2.����Ȩ�� public ����Ȩ�� protected ����Ȩ�� private ˽��Ȩ��


void test01()
{
	Person p1;
	strcpy(p1.mName, "����");
	p1.PersonEat(&p1);
	//p1.DogEat();
	
}


//struct ��class��һ����˼��Ψһ��ͬ����  Ĭ��Ȩ�� ��struct��public ������classĬ��Ȩ����private
class Animal
{
	//����Ҳ�����Ȩ�ޣ�Ĭ��Ȩ����private
	void eat()
	{
		mAge = 100;
	};
	int mAge;
public:
	int mHeight;

protected: //����Ȩ�� ���ڲ����Է��ʣ�����ǰ���������Է��ʣ������ⲿ�����Է���
	int mweight;
	void setWeight(){ mweight = 100; };

};
//��ν˽��Ȩ�ޣ�����˽�г�Ա�����ԣ������������ڲ����Է��ʣ����ⲿ�����Է���
//����Ȩ�ޣ������ڲ������ⲿ�����Է���
void test02()
{
	Animal an;
	//an.eat(); //˽�в����Է���
	an.mHeight = 100;//����Ȩ�������ⲿ���Է��ʵ�
	//an.mWeight = 100;  ����Ȩ��  �����ڿ��Է��� ���ⲻ����
}
//public ���� ���� �����Է���
//protected ���ڿ��Է��� ���� �����Է��� ��������Է��ʣ�
//prviate ���ڿ��Է��� ���� �����Է��� �����಻���Է��ʣ�


int main()
{

	
	test01();
	//test02();
	system("pause");
	return 0;
}