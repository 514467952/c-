#pragma once

#include<iostream>

using namespace std;
#include"point.h"

//Բ��
class Circle
{
public:
	//Բ���Ա����������
	//���ð뾶
	void setR(int r);

		//��ȡ�뾶
		int getR();


		//����Բ��
		void setCenter(Point p);

		//��ȡԲ��
		Point getCenter();


		//���ó�Ա�������жϵ��Բ��ϵ
		void isInCircleByClass(Point &p);


private:
	int m_R;//�뾶
	Point m_Center;//Բ��
};
