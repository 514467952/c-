
#include<iostream>
#include<iomanip>//ʹ�ÿ��Ʒ�ͷ�ļ�
using namespace std;

/*
cout.put() //�򻺳���д�ַ�
cout.write()//��buffer��дnum���ֽڵ���ǰ�������
*/

void test01()
{
	//cout.put('a').put('b');

	char buf[1024] = "helloworld";

	cout.write(buf, strlen(buf));
}


void test02()
{
	//ͨ������Ա����
	int number = 99;
	cout.width(20);
	cout.fill('*');
	cout.setf(ios::left);//��������������
	cout.unsetf(ios::dec);//ж��ʮ����
	cout.setf(ios::hex);//��Ϊ16����
	cout.setf(ios::showbase);//ǿ����������Ļ��� 0 0x
	cout.unsetf(ios::hex);//ж��ʮ������
	cout.setf(ios::oct);//��Ϊ8����
	cout << number << endl;

}

//���Ʒ��ķ�ʽ��ʾ
void test03()
{
	int number = 99;
	cout << setw(20)
		<< setfill('^')
		<< setiosflags(ios::showbase)//����
		<< setiosflags(ios::left)//�����
		<< hex //ʮ������
		<< number
		<< endl;
}



int main()
{
	test03();
	system("pause");
	return 0;
}