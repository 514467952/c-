
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

//дһ��ͨ�õĿ���������Ҫ��:Ч�ʾ�����
//ȱ�ݣ�ǳ����
template<class T>
void Copy1(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//�ŵ㣺һ���������
//ȱ��:Ч�ʱȽϵ�
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
	// �˴����Խ����е���������ö�ٳ���
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
	// ͨ��typeid���Խ�T��ʵ�����Ͱ����ַ����ķ�ʽ����
	if (IsPODType(typeid(T).name()))
	{
		// T�����ͣ���������
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T�����ͣ��Զ�������---ԭ���Զ��������п��ܻ����ǳ����
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


//ȷ��T�����Ƿ�����������
//��
//����
//��Ӧ��������
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

//��Ӧ�Զ�������
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

//........���кܶ���������


template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// ͨ��typeid���Խ�T��ʵ�����Ͱ����ַ����ķ�ʽ����
	if (TypeTraits<T>::PODTYPE::Get())
	{
		// T�����ͣ���������
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T�����ͣ��Զ�������---ԭ���Զ��������п��ܻ����ǳ����
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