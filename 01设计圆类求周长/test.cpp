#include<iostream>

using namespace std;

const double pi = 3.14;

//设计圆类，求圆的周长
//周长公式 2*pi*r

class Circle
{
public:  //公共权限

	//求圆的周长
	//在类里面写函数，成员函数
	double calculateZC()
	{
		return 2*pi*m_R;
	}

	//设置半径的成员方法
	//成员函数，可以修改成员属性
	void setR(int r)
	{
		m_R = r;
	}


	//半径  成员属性
	int m_R;
};

void test01()
{
	//通过类创建圆
	Circle cl;//圆 对象
	//cl.m_R = 10;//给这个对象来进行半径的赋值
	//通过成员函数，间接设置半径
	cl.setR(10);
	//输出cl的周长
	cout << "c1的周长" << cl.calculateZC() << endl;
}

int main()
{

	test01();
	system("pause");
	return 0;
}