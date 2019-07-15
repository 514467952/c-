
#include<iostream>
#include<string>
using namespace std;

class Printer
{
private:
	//Ĭ�Ϲ��캯��˽�л�
	Printer(){ m_Count = 0; };
	//�������캯��˽�л�
	Printer(const Printer& p){};

public:
	//�����ṩ�ӿڷ���Ψһһ��ʵ��
	static Printer *getInstance()
	{
		return singlePrinter;
	}
	//��ӡ����
	void printText(string text)
	{
		cout << text << endl;
		m_Count++;
		cout << "��ӡ��ʹ���˴���Ϊ��" << m_Count << endl;
	}


private:
	static Printer *singlePrinter;
	int m_Count;		//��ӡ����

};

Printer * Printer::singlePrinter = new Printer;

void test01()
{
	//�õ���ӡ��
	Printer *ptr= Printer::getInstance();

	ptr->printText("��ְ����");
	ptr->printText("��ְ����");
	ptr->printText("��н����");
	ptr->printText("��������");
	ptr->printText("��������");
	
}


int main()
{
	test01();
	system("pause");
	return 0;
}