
#include<iostream>
#include<string>

using namespace std;

/*设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号*/

class Student{

public://公共权限
	void setName(string name)
	{
		m_Name = name;
	}
	void setId(int id)
	{
		m_Id = id;
	}
	//打印信息
	void showInfo()
	{
		cout << "姓名： " << m_Name << "学号：" << m_Id << endl;
	}

	string m_Name;//姓名
	int m_Id;//学号

};
void test01()
{
	//创建一个学生 实例化 --- 通过类来创建对象的过程
	Student st;
	st.setName("张三");
	st.setId(1000);
	//通过st的属性打印st的信息
	cout << "st的姓名: " << st.m_Name << "st的学号:" << st.m_Id << endl;

	//通过成员函数打印St的信息
	st.showInfo();
}

int main()
{
	test01();
	system("pause");
	return 0;
}