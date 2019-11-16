
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		this->_str = new char[strlen(str) + 1];
		strcpy(this->_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(this->_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}

		return *this;
	}

	~String()
	{
		delete[]_str;
	}

private:
	char* _str;
};

//写一个通用的拷贝函数，要求:效率尽量高
//缺陷：浅拷贝
template<class T>
void Copy1(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//优点：一定不会出错
//缺陷:效率比较低
template<class T>
void Copy2(T* dst, T*src, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}


bool IsPODType(const char* strType)
{
	// 此处可以将所有的内置类型枚举出来
	const char* strTypes[] = { "char", "short", "int", "long", "long long", "float", "double" };
	for (auto e : strTypes)
	{
		if (strcmp(strType, e) == 0)
			return true;
	}

	return false;
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// 通过typeid可以将T的实际类型按照字符串的方式返回
	if (IsPODType(typeid(T).name()))
	{
		// T的类型：内置类型
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}



void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];

	Copy(array2, array1, 10);

	String s1[3] = { "111", "222", "333" };
	String s2[3];
	//Copy2(s2, s1, 3);
}
int main()
{
	TestCopy();
	system("pause");
	return 0;
}
#endif

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		this->_str = new char[strlen(str) + 1];
		strcpy(this->_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(this->_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}

		return *this;
	}

	~String()
	{
		delete[]_str;
	}

private:
	char* _str;
};


//确认T到底是否是内置类型
//是
//不是
//对应内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

//对应自定义类型
struct FalseType
{
	static bool Get()
	{
		return true;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;

};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

//........还有很多内置类型


template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// 通过typeid可以将T的实际类型按照字符串的方式返回
	if (TypeTraits<T>::PODTYPE::Get())
	{
		// T的类型：内置类型
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];

	Copy(array2, array1, 10);

	String s1[3] = { "111", "222", "333" };
	String s2[3];
	//Copy2(s2, s1, 3);
}
int main()
{
	TestCopy();
	system("pause");
	return 0;
}