#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

namespace bite
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";

			//��ǰ���󿪱ٿռ�
			_size = strlen(str);
			_capacity = _size ;
			_str = new char[_capacity + 1];
			//����Ԫ��
			strcpy(_str, str);

		}
		//����n���ַ�ch
		string(size_t n, char ch)
			:_size(n)
			, _capacity(n)
			, _str(new char[n + 1])
			//�˴�����new char[_capacity],��Ϊ��Ա������ʼ����ֻ������˳���йأ�_str����_capacity����������
			//�ȳ�ʼ��
		{
			memset(_str, ch, n);
			_str[n] = '\0';	//���һ��λ������Ϊ\0
		}

		//[begin,end)
		string(char* begin, char* end)
		{
			_size = end - begin;
			_capacity = _size;
			_str = new char[_size + 1];
			strncpy(_str, begin, _size);
			_str[_size] = '\0';
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				int len = strlen(s._str) ;
				char * p = new char[len + 1];
				strcpy(p, s._str);

				delete[]_str;
				_str = p;
				_size = len;
				_capacity = len;
			}

			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}



		//������ز���
		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		void resize(size_t newsize,char ch)
		{
			size_t oldsize = _size;
			if (newsize > oldsize)
			{
				//��ЧԪ������
				//�����Ԫ���ٿ���ռ��ܷ�ŵ���
				if (newsize > _capacity)
				{
					reserve(newsize);
				}

				memset(_str + _size, ch, newsize-oldsize);
				
			}

			_size = newsize;
			_str[_size] = '\0';
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = _capacity;
			if (newcapacity > oldcapacity)
			{
				//�����¿ռ�
				char * temp = new char[newcapacity + 1];
				//����Ԫ��
				strcpy(temp, _str);
				//�ͷžɿռ�
				delete[]_str;
				//ָ���¿ռ�
				_str = temp;
				_capacity = newcapacity;
			}
		}

		//Ԫ�ط�����ز���
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[]( int index)
		{
			assert(index < _size);
			return _str[index];
		}
		//Ԫ���޸Ĳ���
		void push_back(char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const string s);
		

		bool operator==(const string s);
		bool operator!=(const string s);
		bool operator>=(const string s);
		bool operator<=(const string s);
		bool operator>(const string s);
		bool operator<(const string s);
		friend ostream& operator<< (ostream& _cout, const bite::string& s)
		{
			_cout << s.c_str();
			return _cout;
		}
		friend istream operator>>(istream _cin, string s);
		//������

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//�������

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}
		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;

			for (int i = pos; i >= 0; i--)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		string substr(size_t pos = 0, size_t n = npos)
		{
			if (n == npos)
				n = _size;
			string temp(_str + pos, _str + n + pos);
			return temp;
		}

		const char* c_str()const
		{
			return _str;
		}

	private:
		size_t _capacity;  //��ǰ�ռ��ж��
		size_t _size;		//��ǰstring���ж��ٸ���Ч�ַ�
		char *_str;
		static size_t npos;
	};

	size_t string::npos = -1;
}


void TestString1()
{
	bite::string s1;
	bite::string s2("hello");
	bite::string s3(s2);
	bite::string s4(10, '$');
	bite::string s5(s2.begin(), s2.end());

	for (auto e : s2)
		cout << e;
	cout << endl;

	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i];
	}
	cout << endl;

	//bite::string::iterator it = s4.begin();
	auto it = s4.begin();
	while (it != s4.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void TestString2()
{
	bite::string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.push_back('!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(15,'$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '&');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}

void TestString3()
{
	bite::string s("hello");

	size_t pos1 = s.find('l');
	cout << pos1 << endl;

	size_t pos2 = s.rfind('l');
	cout << pos2 << endl;

	cout << s.substr(pos1, 2) << endl;
}
int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	system("pause");
	return 0;
}