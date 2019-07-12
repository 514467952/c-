#include<iostream>

using namespace std;
#include"circle.h"
#include"point.h"



//利用全局函数 判断点和圆的关系
void isCircle(Circle &c, Point &p)
{
	//获取圆心和点的距离的平方
	int  distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());

	int rDistance = c.getR()*c.getR();

	if (rDistance == distance)
	{
		cout << "点在圆上" << endl;

	}
	else if (rDistance>distance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;

	}
}



void test01()
{
	Point p1;
	p1.setX(10);
	p1.setY(9);

	Circle c1;
	Point center;
	center.setX(10);
	center.setY(0);
	c1.setCenter(center);
	c1.setR(10);

	//利用全局判断点和圆的关系
	isCircle(c1, p1);
	//利用成员函数判断
	c1.isInCircleByClass(p1);
}

int main()

{
	test01();

	system("pause");
	return 0;
}