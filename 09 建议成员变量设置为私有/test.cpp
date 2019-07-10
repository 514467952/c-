
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	//设置年龄
	void setAge(int age)
	{
		if (age<0 || age>100)
		{
			cout << "你这个老妖精" << endl;
		}
		m_Age = age;
	}
	//获取年龄
	int getAge()
	{
		return m_Age;
	}
	//读姓名
	string getname()
	{
		return m_Name;
	}
	//写姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//只写的情人
	void setLover(string lover)
	{
		m_lover = lover;
	}

private:		//类外不可以访问  但类内可以访问

	int m_Age=0;//年龄  读写
	string m_Name;//姓名 读写
	string m_lover;//情人

};

void test01()
{
	Person p1;
	p1.setName("老王");
	cout << "p1的姓名：" << p1.getname()<<endl;
	//年龄
	p1.setAge(120);

	cout << "p1的年龄：" << p1.getAge() << endl;
	//情人 只能设置  外部不能告诉你
	p1.setLover("苍井");

}

int main()
{

	test01();

	system("pause");
	return 0;
}