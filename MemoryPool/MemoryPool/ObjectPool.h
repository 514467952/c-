#ifndef _OBJECT_POOL_H__
#define _OBJECT_POOL_H__

#include<iostream>
#include<malloc.h>
using namespace std;

//�����Ķ����
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//�ڴ�����
		char* _start=nullptr;
		size_t _bytesize = 0; //������ֶ��ٸ��ֽ�
		size_t _byteleft = 0; //ʣ���ֽ���
		Block* _next = nullptr;  //ָ����һ���ڴ��

		Block(size_t bytesize)
		{
			_start = (char *)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}
	};

public:
	//initnum ��һ��������ٸ�����
	ObjectPool(size_t initnum = 32)
	{
		_head = _tail = new Block(initnum*sizeof(T));
	}

	T *New()
	{
		T *obj = nullptr;
		if (_freelist != nullptr)
		{

		}
		else
		{
			
			//Block* tail = _tail;
			if (_tail->_byteleft == 0){
				Block *newblock = new Block(_tail->bytesize*2);
				_tail->_next = newblock;  //β��
				_tail = newblock;
			}

			obj = (T *)(_tail->_start + (_tail->_bytesize - _tail->byteleft));
			_tail->byteleft -= sizeof(T);
			
		}

		return obj;
	}
	void Delete(T *ptr)
	{

	}


protected:
	
	//��������
	T* _freelist=nullptr;
	//�����
	Block* _head=nullptr;
	Block* _tail=nullptr; //��ǰ�õ��ڴ��
};




void TestObjectPool()
{
	ObjectPool<int>pool;
	int *p1 = pool.New();
	int *p2 = pool.New();
}



#endif
