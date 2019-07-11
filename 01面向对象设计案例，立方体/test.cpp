

#include<iostream>
using namespace std;


class Cube
{

public:
	//���ó�
	void setL(int l)
	{
		m_L = l;
	}
	//��ȡ��
	int getL()const
	{
		return m_L;
	}

	//���ÿ�
	void setW(int w)
	{
		m_W = w;
	}
	//��ȡ��
	int getW()
	{
		return m_W;
	}

	//���ø�
	void setH(int h)
	{
		m_H = h;
	}
	//��ȡ��
	int getH()
	{
		return m_H;
	}

	//������������
	void getCubeS()
	{
		int s = 2 * m_L*m_W + 2 * m_L*m_H + 2 * m_H*m_W;
		cout << "����������Ϊ:" << s << endl;
	}
	//�����������
	void getCubeV()
	{
		int v = m_L*m_H*m_W;
		cout << "����������Ϊ:" << v << endl;
	}

	//ͨ����Ա�������ж��Ƿ����
	bool compareCubeByClass(Cube cub)
	{
		bool ret = m_L == cub.getL() && m_W == cub.getW() && m_H == cub.getH();
		return ret;
	}

private:
	int m_L;//��
	int m_W;//��
	int m_H;//��
};
//δʲôconst�ող�����ӣ�û����֤��Ա�������Ƿ��޸��˳�Ա����
void func(const Cube &cub){

	cub.getL();
}

//ȫ�ֺ����жϣ������������Ƿ����
bool compareCube(Cube &cub1,  Cube &cub2)
{
	if (cub1.getL() == cub2.getL() && cub1.getH() == cub2.getH() && cub1.getW() == cub2.getW())
	{
		return true;
	}
	else{
		return false;
	}
}

void test01()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	c1.getCubeS();//600
	c1.getCubeV();//1000

	//ͨ��ȫ�ֱ����ж������������Ƿ����
	Cube c2;
	c2.setH(10);
	c2.setL(10);
	c2.setW(10);
	bool ret = compareCube(c1, c2);
	if (ret)
	{
		cout << "c1��c2����ȵ�" << endl;
	}
	else{
		cout << "c1��c2�ǲ���ȵ�" << endl;
	}
	//ͨ����Ա�����ж��������Ƿ����
	bool ret2 = c1.compareCubeByClass(c2);
	if (ret2)
	{
		cout << "ͨ����Ա��c1��c2����ȵ�" << endl;
	}
	else{
		cout << "ͨ����Ա��c1��c2�ǲ���ȵ�" << endl;
	}
}

int main()
{


	test01();
	system("pause");
	return 0;
}