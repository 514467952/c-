#include"circle.h"
#include"point.h"


//圆类成员函数的实现
//设置半径
void Circle::setR(int r)
{
	m_R = r;
}
//获取半径
int Circle::getR()
{
	return m_R;
}

//设置圆心
void Circle::setCenter(Point p)
{
	m_Center = p;
}
//获取圆心
Point Circle::getCenter()
{
	return m_Center;
}

//利用成员函数来判断点和圆关系
void Circle::isInCircleByClass(Point &p)
{
	//获取圆心和点的距离的平方
	int  distance = (m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY());

	int rDistance = m_R*m_R;
	if (rDistance == distance)
	{
		cout << "成员函数：点在圆上" << endl;

	}
	else if (rDistance>distance)
	{
		cout << "成员函数：点在圆内" << endl;
	}
	else
	{
		cout << "成员函数：点在圆外" << endl;

	}
}
