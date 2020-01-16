#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
int main()
{

	//右值引用---->引用形式----->只能引用右值
	int a = 10;
	int b = 20;

	//a可以为左值，能放到=号左侧的一定是左值
	//能放到=号右侧的不一定是右值
	a = b;

	//ra对10的右值引用，ra称为对10的别名
	int&& ra = 10;

	system("pause");
	return 0;
}
#endif
#if 0
int  main()
{
	const int a = 10;

	//a = 100; a不能出现在左侧
	//a也不是右值
	cout << &a << endl;
	//int && ra = a;

	int b = 10;
	int&& rb = b + 10;

	system("pause");
	return 0;
}
#endif

#if 0
int g_a = 10;

int& GetG_A()
{
	return g_a;
}

int main()
{
	GetG_A() = 10;
	//下面这行代码编译报错
	//int && rc = GetG_A();
	return 0;
}
#endif

#if 0
//将亡值
//值得方式返回
//使用ret--->创建一个临时变量---->函数运行结束栈空间被回收
int Add(int a, int b)
{
	int ret = a + b;
	return ret;
}

int main()
{
	int&& Ret = Add(10,20);
	return 0;
}
#endif

#if 0
//C++98引用
//1. 普通类型得引用
//2. cosnt类型的引用
int main()
{
	//98中的普通类型的引用不能引用右值
	int a = 10;
	int&ra = a;
	//int&rra = 10;	不行

	//98中的const引用既可以引用左值也可以引用右值
	const int&cral = a;
	const int& cra2 = 10;
	return 0;
}
#endif

#if 0
//c++11右值引用:只能引用右值--->C语言中的纯右值+将亡值
int main()
{
	int a = 10;
	int&& ra = move(a);
	return 0;
}
#endif

#if 0
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//移动构造函数
	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	
	
	String operator+(const String&s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str)];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		//delete[] pTemp;
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

#include<memory>
int main()
{
	auto_ptr<int> sp1(new  int);
	auto_ptr<int> sp2(sp1);
	//sp1资源给了sp2，但是sp1生命周期还没有到头，所以不能被使用
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);

	//调用移动构造
	String s4(move(s2));
	return 0;
}
#endif
#if 0
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//移动构造函数
	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	
	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
	Person& operator=(Person&&p)
	{
		return *this;
	}
#endif

private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person pp("prety", "male", 18);
	return pp;		//pp确实是右值，但是里面的成员变量是当作左值，所以用move把左值转化为右值
}
int main()
{
	Person p(GetTempPerson());
	system("pause");
	return 0;
}
#endif

void Fun(int &x)	//普通类型引用
{ 
	cout << "lvalue ref" << endl; 
}
void Fun(int &&x)	//普通类型右值引用
{ 
	cout << "rvalue ref" << endl; 
}
void Fun(const int &x)	//const类型普通引用
{
	cout << "const lvalue ref" << endl; 
}
void Fun(const int &&x)	//const类型的右值引用
{ 
	cout << "const rvalue ref" << endl; 
}

//通过函数模板作为转发函数
template<typename T>
//完美转发:t是左值---->传给Fun函数，t应该也是左值
//		   t如果是右值--->传给Fun函数，t应该是右值
void PerfectForward(T &&t)
{ 
	Fun(std::forward<T>(t)); //forward把t转化为右值。
	//Fun(t);
}

#include<vector>
int main()
{
	PerfectForward(10); // 10为右值
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}




