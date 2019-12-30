#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

#if 0
namespace LYC
{
	class String
	{
	public:
		String(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		String & operator=(const String& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1]; //����ռ�
				strcpy(temp, s._str); //����Ԫ��
				delete[] _str; //�ͷžɿռ�
				_str = temp;	//ԭָ��ָ���¿ռ�
			}
		}

		~String()
		{
			if (_str )
				delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
		int size;
		int capacity;
	};
}
#endif




namespace  LXY
{
	class String
	{
	
	public:
		
		String(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}	
		
		String(const String& s)
		{
			if (s._str != nullptr)
			{
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[]_str;
				_str = temp;
			}
			return *this;
		}

		bool operator==(const String& s)
		{
			if (this != &s)
			{
				if (strcmp(_str, s._str) == 0)
				{
					return true;
				}
				return false;
			}
			return true;
		}
		
		bool operator!=(const String& s)
		{
			if (this != &s)
			{
				if (strcmp(_str, s._str) != 0)
				{
					return true;
				}
				return false;
			}
			return true;
		}

		friend ostream& operator<< (ostream&_cout, const LXY::String& str)
		{
			_cout << str._str;
			return _cout;
		}
		~String()
		{
			if (_str)
				delete[] _str;
			_str = nullptr;
		}
	private:
		char * _str;
	};
}
int main()
{

	//LYC::String str("123");
	LXY::String str("���");
	LXY::String str1(str);

	if (str == str1)
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "����ͬ" << endl;
	}
	if (str != str1)
	{
		cout << "����ͬ" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}

	cout << str<<endl;
	system("pause");
	return 0;
}
