
#include<iostream>
#include<string>

using namespace std;

/*���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��*/

class Student{

public://����Ȩ��
	void setName(string name)
	{
		m_Name = name;
	}
	void setId(int id)
	{
		m_Id = id;
	}
	//��ӡ��Ϣ
	void showInfo()
	{
		cout << "������ " << m_Name << "ѧ�ţ�" << m_Id << endl;
	}

	string m_Name;//����
	int m_Id;//ѧ��

};
void test01()
{
	//����һ��ѧ�� ʵ���� --- ͨ��������������Ĺ���
	Student st;
	st.setName("����");
	st.setId(1000);
	//ͨ��st�����Դ�ӡst����Ϣ
	cout << "st������: " << st.m_Name << "st��ѧ��:" << st.m_Id << endl;

	//ͨ����Ա������ӡSt����Ϣ
	st.showInfo();
}

int main()
{
	test01();
	system("pause");
	return 0;
}