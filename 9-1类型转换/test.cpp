
#include<iostream>

using namespace std;

//��̬ת��
//��������

void test01()
{
	char a = 'a';
	double d = static_cast<double>(a);

	cout << "d=" << d << endl;

}

//������֮���ת��
class Base{};

class Child :public Base{};

class Other{};

void test02()
{
	Base * base = NULL;

	Child *child = NULL;

	//��BaseתΪChild���� ���� ����ȫ

	Child * child2 = static_cast<Child*>(base);

	//��childתΪBase* ���� ��ȫ
	Base *base2 = static_cast<Base*>(child);
	//תother����  û�и��ӹ�ϵ������ת����Ч
	//Other *other = static_cast<Other*>(base);

}

//תother����
//static_castʹ��  static_cast<Ŀ������>(ԭʼ����)


//��̬ת��

void test03()
{
	//�������Ͳ�����ת��
	char c = 'a';
	//dynamic_cast�ǳ��ϸ�ʧȥ���ȣ����Ų���ȫ��������ת��
	//double d = dynamic_cast<double>(c);
}

class Base2
{
	virtual void func(){  };
};
class Child2 : public Base2
{
	virtual void func()
	{

	}
};
class Other1{};
void test04()
{
	Base2 *base = NULL;

	Child2 *child = NULL;

	//childתBase2 *��ȫ
	Base2 *base2 = dynamic_cast<Base2*>(child);

	//baseתChild2 * ����ȫ
	//Child2 *child2 = dynamic_cast<Child2>(base);

	//������̬���

	Base2 *base3 = new Child2;
	Child2 *child3 = dynamic_cast<Child2*>(base3);

}
// dynamic_cast ��������˶�̬����ô�����û���תΪ������,����ת��



//����ת����const_cast��

void test05()
{

	const int *p = NULL;
	//ȥ��const
	int * newp = const_cast<int *>(p);

	int * p2 = NULL;

	const int * newp2 = const_cast<const int *>(p2);

	//���ܶԷ�ָ�� ���� ���õ� ��������ת��
	//const int a = 10;
	//int b = const_cast<int>(a);

	//����
	int num = 10;
	int &numRef = num;

	const int &numRef2 = static_cast<const int &>(numRef2);


	

}

//���½���ת��
	void test06()
	{
		int a = 10;
		int *p = reinterpret_cast<int *>(a);

		Base * base = NULL;
		Other * other = reinterpret_cast<Other *>(base);
		//���ȫ�����Ƽ�

	}

int main()
{

	test01();
	system("pause");
	return 0;
}