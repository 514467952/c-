#ifndef _OBJECT_POOL_H__
#define _OBJECT_POOL_H__

#include<iostream>
#include<malloc.h>
using namespace std;

//定长的对象池
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//内存块管理
		char* _start=nullptr;
		size_t _bytesize = 0; //这个块又多少个字节
		size_t _byteleft = 0; //剩余字节数
		Block* _next = nullptr;  //指向下一个内存块

		Block(size_t bytesize)
		{
			_start = (char *)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}
	};

public:
	//initnum 第一次申请多少个对象
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
				_tail->_next = newblock;  //尾插
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
	
	//自由链表
	T* _freelist=nullptr;
	//块管理
	Block* _head=nullptr;
	Block* _tail=nullptr; //当前用的内存块
};




void TestObjectPool()
{
	ObjectPool<int>pool;
	int *p1 = pool.New();
	int *p2 = pool.New();
}



#endif
