#pragma once

#include<iostream>

using namespace std;


class Point
{
public:
	//成员函数的声明
	void setX(int x);
	

	void setY(int y);
	
	int getX();
	
	int getY();
	
private:
	int m_X;
	int m_y;
};