
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	//��������
	void setAge(int age)
	{
		if (age<0 || age>100)
		{
			cout << "�����������" << endl;
		}
		m_Age = age;
	}
	//��ȡ����
	int getAge()
	{
		return m_Age;
	}
	//������
	string getname()
	{
		return m_Name;
	}
	//д����
	void setName(string name)
	{
		m_Name = name;
	}
	//ֻд������
	void setLover(string lover)
	{
		m_lover = lover;
	}

private:		//���ⲻ���Է���  �����ڿ��Է���

	int m_Age=0;//����  ��д
	string m_Name;//���� ��д
	string m_lover;//����

};

void test01()
{
	Person p1;
	p1.setName("����");
	cout << "p1��������" << p1.getname()<<endl;
	//����
	p1.setAge(120);

	cout << "p1�����䣺" << p1.getAge() << endl;
	//���� ֻ������  �ⲿ���ܸ�����
	p1.setLover("�Ծ�");

}

int main()
{

	test01();

	system("pause");
	return 0;
}