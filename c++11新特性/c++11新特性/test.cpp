#include<iostream>

using namespace std;
#if 0
#include<vector>
#include<map>
int main()
{
	// �������ͱ���
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	int x6{ x1 + x2 };
	// ����
	int arr1[5] {1, 2, 3, 4, 5};
	int arr2[]{1, 2, 3, 4, 5};
	// ��̬���飬��C++98�в�֧��
	int* arr3 = new int[5]{1, 2, 3, 4, 5};
	// ��׼����
	vector<int> v{ 1, 2, 3, 4, 5 };
	map<int, int> m{ { 1, 1 }, { 2, 2, }, { 3, 3 }, { 4, 4 } };
	return 0;
}
#endif

#if 0
class Point
{
public:
	Point(int x = 0, int y = 0) 
		: _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};
int main()
{
	//���ֳ�ʼ��������
	Point p{ 1, 2 };
	Point p2(1, 2);
	return 0;
}
#endif
#if 0
namespace LXY
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(initializer_list<T>l)
			:_start(new T[l.size()])
		{
			_finish = _start;
			for (auto e : l)
			{
				*_finish++ = e;
			}
		}
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}

int main()
{
	//�����ռ䲻֧��
	//LXY::vector<int> v1{ 1, 2, 3, 4, 5 };
	LXY::vector<int> v1{ 1, 2, 3, 4, 5 };
	return 0;
}
#endif

#if 0
template<class T1,class T2>
//���ص�ʱ�򣬷���T1��T2�����У�Ӧ�÷���T1+T2���ֵ������
auto Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	return 0;
}
#endif
#if 0
template<class T1, class T2>
//���ص�ʱ�򣬷���T1��T2�����У�Ӧ�÷���T1+T2���ֵ������
//�˴�autoΪռλ��
//����ֵ����׷��
auto  Add( T1& left,  T2& right)->decltype(left+right)
{
	return left + right;
	//ret = left + right;
}

int main()
{
	int a = 1;
	double b = 2.0;
//double ret = 0;

	cout<< Add(a, b);
	return 0;
}
#endif

class Info {
public:
	Info() 
		: _type(0)
		, _name('a')
	{
		InitRSet();
	}
	Info(int type) 
		:Info()
	{
		//InitRSet();
		_type = type;
	}
	Info(char type) 
		:Info()
	{
		//InitRSet();
		_type = type;
	}
private:
	void InitRSet() 
	{
		//��ʼ����������
	}
private:
	int _type;
	char _name;
	//...
};

int main()
{
	system("pause");
	return 0;
}