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
//RALL:��Դ��ȡ����ʼ��
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
	T& operator*() //���ؽ����������
	{
		return *_ptr; //���ص�ǰ����
	}

	T* operator->()
	{
		return &(operator*()); //��ָ����ָ��ռ�ĵ�ַ����
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

//�Ľ�����Դ����Ȩת��
namespace bite  //�Լ�дһ�������ռ䣬Ϊ�˷�ֹ��ϵͳ��ͻ
{
	//auto_ptr ������Դ����Ȩ�޵�ת�������ǳ����
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
		//��Դ��ת��
		auto_ptr(auto_ptr<T>& ap) //Ҫ�޸����ݣ����Բ��ü�const
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap){  //�ǲ����Լ����Լ���ֵ

				if (_ptr && _owner)     //��ǰ������û�й�����Դ��Ȩ��
					delete _ptr;  //����У��ͷ�

				_ptr = ap._ptr;  //��ǰ�������ap����Դ
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

		//��ָ��һ���ķ�ʽʹ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			//��ָ����ָ��ռ�ĵ�ַ���ؾͿ���
			return &(operator*());
		}

	protected:
		T *_ptr;
		bool _owner; //��Դ�����Ĺ���Ȩ��
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