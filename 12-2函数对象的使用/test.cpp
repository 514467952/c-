#include<iostream>
using namespace std;

class Myprint
{
public:
	void operator ()(int num)
	{
		cout << "num" << num << endl;
		count++;
	}
	int count = 0;
};

void MyPrint2(int num)
{
	cout << "num" << num << endl;
}


void test01()
{
	//MyPrint��һ���࣬�����Ǻ���
	Myprint myPrint;
	myPrint(111); //�º�������

	//MyPrint2(111);//��������

	Myprint()(1000);//�����������
}

//�������󳬳�����ͨ�����ĸ�����Ա���״̬
void  test02()
{
	Myprint myPrint;
	myPrint(111);
	myPrint(111);
	myPrint(111);
	myPrint(111);

	cout << "myPrintʹ�ô�����" << myPrint.count << endl;
}
//����������Ϊ��������
void doPrint(Myprint print, int num)
{
	print(num);
}
void test03()
{
	doPrint(Myprint(), 20);

	
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}