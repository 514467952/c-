#include<iostream>

using namespace std;

//������ϯ��
//���� ����ģʽ Ϊ�˴������еĶ��󣬲��ұ�ֻ֤��һ������ʵ��


class ChairMan
{

	
private:
	//1. ���캯��������˽�л�
	ChairMan()
	{
		//cout << "����������ϯ" << endl;
	}
	//��������˽�л�
	ChairMan(const ChairMan&c)
	{

	}
	


public:
	//�ṩget���� ������ϯ
	static ChairMan * getInstance()
	{
		return singleMan;
	}

private:
	static ChairMan * singleMan;

};

ChairMan * ChairMan::singleMan = new ChairMan;

void test01()
{
	/*ChairMan c1;
	ChairMan *c2 = new ChairMan;
	ChairMan *c3 = new ChairMan;*/

	/*ChairMan * cm= ChairMan::singleMan;
	ChairMan * cm2 = ChairMan::singleMan;*/

	//ChairMan::singleMan = NULL;

	ChairMan *cm1= ChairMan::getInstance();
	ChairMan *cm2 = ChairMan::getInstance();
	if (cm1 == cm2)
	{
		cout << "cm1��cm2��ͬ" << endl;
	}
	else{
		cout << "cm1��cm2��ͬ" << endl;
	}

	//ChairMan *cm3 = new ChairMan(*cm2);

	//if (cm3 == cm2)
	//{
	//	cout << "cm3��cm2��ͬ" << endl;
	//}
	//else{
	//	cout << "cm3��cm2��ͬ" << endl;
	//}
}

int main()
{
	//cout << "main����" << endl;  ��ϯ����main����
	test01();
	system("pause");
	return 0;
}