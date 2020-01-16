#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
int main()
{

	//��ֵ����---->������ʽ----->ֻ��������ֵ
	int a = 10;
	int b = 20;

	//a����Ϊ��ֵ���ܷŵ�=������һ������ֵ
	//�ܷŵ�=���Ҳ�Ĳ�һ������ֵ
	a = b;

	//ra��10����ֵ���ã�ra��Ϊ��10�ı���
	int&& ra = 10;

	system("pause");
	return 0;
}
#endif
#if 0
int  main()
{
	const int a = 10;

	//a = 100; a���ܳ��������
	//aҲ������ֵ
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
	//�������д�����뱨��
	//int && rc = GetG_A();
	return 0;
}
#endif

#if 0
//����ֵ
//ֵ�÷�ʽ����
//ʹ��ret--->����һ����ʱ����---->�������н���ջ�ռ䱻����
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
//C++98����
//1. ��ͨ���͵�����
//2. cosnt���͵�����
int main()
{
	//98�е���ͨ���͵����ò���������ֵ
	int a = 10;
	int&ra = a;
	//int&rra = 10;	����

	//98�е�const���üȿ���������ֵҲ����������ֵ
	const int&cral = a;
	const int& cra2 = 10;
	return 0;
}
#endif

#if 0
//c++11��ֵ����:ֻ��������ֵ--->C�����еĴ���ֵ+����ֵ
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

	//�ƶ����캯��
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
	//sp1��Դ����sp2������sp1�������ڻ�û�е�ͷ�����Բ��ܱ�ʹ��
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);

	//�����ƶ�����
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

	//�ƶ����캯��
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
	return pp;		//ppȷʵ����ֵ����������ĳ�Ա�����ǵ�����ֵ��������move����ֵת��Ϊ��ֵ
}
int main()
{
	Person p(GetTempPerson());
	system("pause");
	return 0;
}
#endif

void Fun(int &x)	//��ͨ��������
{ 
	cout << "lvalue ref" << endl; 
}
void Fun(int &&x)	//��ͨ������ֵ����
{ 
	cout << "rvalue ref" << endl; 
}
void Fun(const int &x)	//const������ͨ����
{
	cout << "const lvalue ref" << endl; 
}
void Fun(const int &&x)	//const���͵���ֵ����
{ 
	cout << "const rvalue ref" << endl; 
}

//ͨ������ģ����Ϊת������
template<typename T>
//����ת��:t����ֵ---->����Fun������tӦ��Ҳ����ֵ
//		   t�������ֵ--->����Fun������tӦ������ֵ
void PerfectForward(T &&t)
{ 
	Fun(std::forward<T>(t)); //forward��tת��Ϊ��ֵ��
	//Fun(t);
}

#include<vector>
int main()
{
	PerfectForward(10); // 10Ϊ��ֵ
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}




