
#include<iostream>

using namespace std;

class Animal
{
public:


	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
	virtual void eat()
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}
	virtual void eat()
	{
		cout << "Сè�ڳ���" << endl;
	}
};

//����doSpeak ,speak�����ĵ�ַ��Ͱ󶨺��ˣ���󶨣���̬���࣬����׶ξ�ȷ�����˵�ַ
//��������ΪAniaml�����ͣ����Ե�ַ��ΪAnimal��ĵ�ַ
//��������è��speak��������ǰ�󶨺ú����ĵ�ַ��������Ҫ������ʱ����ȥȷ��������ַ
//��̬���࣬д��Speak�ŷ���Ϊ�麯��,�ٸ����������麯���������˶�̬
void doSpeak(Animal & animal)//Animal & animal = cat
{
	animal.speak();
}

//��������˼̳еĹ�ϵ�������������������ת��
void test01()
{
	Cat cat;
	doSpeak(cat);

}
void test02()
{
	
	//cout << sizeof(Animal) << endl;
	//ûдvirtualʱ��1���ֽ�
	//д����4


	//����ָ��ָ������������˶�̬
	Animal * animal = new Cat;

	//animal->speak();
	//*(int *)*(int *)animal������ַ
	((void(*)()) (*(int *)*(int *)animal))();

	//*((int *)*(int *)animal +1)è����ĵ�ַ
	((void(*)())(*((int *)*(int *)animal + 1))) ();
}  
    

//ʲô�ж�̬��
//��������û���ָ�� ָ�� �������

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}