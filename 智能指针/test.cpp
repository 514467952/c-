#include<iostream>

using namespace std;

#if 0
void TestFunc1()
{
	//...
	throw 1;
}


bool TestFunc2()
{
	return false;
}

void TestPtr()
{
	int *p = new int[10];
	FILE *pf = fopen("222.txt", "rb");
	if (nullptr == pf){
		delete[] p;
		return;
	}
	try
	{
		TestFunc1();
	}
	catch (...)
	{
		delete[]p;
		fclose(pf);
		throw;
	}

	if (!TestFunc2())
	{
		delete[]p;
		fclose(pf);
		return;
	}


	//.....
	delete[]p;
	fclose(pf);

}
#endif

#if 0
//RALL:资源获取即初始化
template<class T>

class smartptr
{
public:
	smartptr( T* ptr = nullptr)
		:_ptr(ptr)
	{

	}

	~smartptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	T& operator*() //重载解引用运算符
	{
		return *_ptr; //返回当前内容
	}

	T* operator->()
	{
		return &(operator*()); //把指针所指向空间的地址返回
	}
private:
	T *_ptr;
};

struct A
{
	int a;
	int b;
	int c;
};
void TestSmartPtr()
{
	smartptr<int>sp1(new int);
	*sp1 = 100;
	cout << *sp1 << endl;

	smartptr<A>sp2(new A);
	sp2->a = 10;
	sp2->b = 20;
	sp2->c = 30;

	smartptr<A>sp3(sp2);
	throw 1;
}

int  main()
{
	try{
		TestSmartPtr();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}
#endif

//改进：资源管理权转移
namespace bite  //自己写一个命名空间，为了防止和系统冲突
{
	//auto_ptr 利用资源管理权限的转移来解决浅拷贝
	template<class T>
	class auto_ptr
	{
		//RALL
	public:
		auto_ptr(T *_ptr = nullptr)
			:_ptr(_ptr)
			, _owner(false)
		{
			if (_ptr)
				delete _ptr;
		}
		//资源的转移
		auto_ptr(auto_ptr<T>& ap) //要修改内容，所以不用加const
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap){  //是不是自己给自己赋值

				if (_ptr && _owner)     //当前对象有没有管理资源的权限
					delete _ptr;  //如果有，释放

				_ptr = ap._ptr;  //当前对象接受ap的资源
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr && _owner)
			{
				delete _ptr;
				_owner = false;
			}
		}

		//像指针一样的方式使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			//将指针所指向空间的地址返回就可以
			return &(operator*());
		}

	protected:
		T *_ptr;
		bool _owner; //资源真正的管理权限
	};
}

void TestAuto_ptr()
{


	bite::auto_ptr<int>ap1(new int);
	bite::auto_ptr<int>ap2(ap1);

	ap1 = ap2;
}

int main()
{
	TestAuto_ptr();
	system("pause");
	return 0;
}