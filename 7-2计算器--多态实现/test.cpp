
#include<iostream>

using namespace std;
/*
class Calculator
{
public:

	void setv1(int v)
	{
		this->val1 = v;
	}
	void setv2(int v)
	{
		this->val2 = v;
	}

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return val1 + val2;
		}
		else if (oper == "-")
		{
			return val1 - val2;
		}
	}

private:
	int val1;
	int val2;
};
void test01()
{
	Calculator cal;
	cal.setv1(10);
	cal.setv2(10);
	cout << cal.getResult("+") << endl;
	cout << cal.getResult("-") << endl;
}
*/

//�����Ŀ����У��и�����ԭ�򣬿���ԭ��
//����չ���� ���޸Ĺر�


//���ö�̬ʵ�ּ�����
class abstractCalculator
{
public:
	void setv1(int v)
	{
		this->val1 = v;
	}
	void setv2(int v)
	{
		this->val2 = v;
	}
	//virtual int getResult(){return  0;} �麯��

	//���麯��
	//������������˴��麯��  ����̳��˸��࣬����Ҫʵ�ִ��麯��
	//��������� ���˴��麯����������࣬���޷�ʵ����������
	//����������˴��麯����ͨ���ֳ�Ϊ ������
	virtual int getResult() = 0;

public:
	int val1;
	int val2;
};
//������������˴��麯��  ����̳��˸��࣬����Ҫʵ�ִ��麯��
class A :public abstractCalculator
{
public:
	virtual int getResult()
	{
		//return 0;
	}

};


//�ӷ������� 
class PlusCaculator :public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 + val2;
	}
};
//����������
class SubCalculator : public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 - val2;
	}
};

//�˷�������
class ChengCalculator : public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1*val2;
	}
};

void test01()
{
	abstractCalculator *abc = new PlusCaculator;//�ӷ�������
	abc = new PlusCaculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;

	delete abc;
	abc = new SubCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;


	delete abc;
	abc = new ChengCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;

	//����������˴��麯��������ʵ����������
	/*abstractCalculator aaa;
	abstractCalculator *abc = new abstractCalculator;*/
}

int main()
{
	test01();
	system("pause");
	return 0;
}