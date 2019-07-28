
#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>

class MyArray
{
public:
	
	//����
	explicit MyArray(int capacity) //��ֹ��ʽ����ת������ֹMyArray arr =10
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this -> m_Capacity+1];
	}

	MyArray(const MyArray &array)
	{
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T [this->m_Capacity+1];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = array[i];
		}
	}

	~MyArray()
	{
		cout << "������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

	//��ֵ���������� ��ֹǳ����
	MyArray & operator = (MyArray & array)
	{
		//���ж�ԭʼ���ݣ��о����
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T [this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = array[i];
		}
	}

	//[]����
	/*MyArray arr(10)
		arr[0] = 100;*/
	T & operator [](int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void push_Back(T val)
	{
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//��ȡ��С
	int getSize()
	{
		return m_Size;
	}
	//��ȡ����
	int getCapacity()
	{
		return m_Capacity;
	}


private:
	 T * pAddress;   //ָ�����ָ��
	int m_Capacity; //����
	int m_Size;
};