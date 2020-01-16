#include<iostream>

using namespace std;
#if 0
#include<vector>
#include<map>
int main()
{
	// 内置类型变量
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	int x6{ x1 + x2 };
	// 数组
	int arr1[5] {1, 2, 3, 4, 5};
	int arr2[]{1, 2, 3, 4, 5};
	// 动态数组，在C++98中不支持
	int* arr3 = new int[5]{1, 2, 3, 4, 5};
	// 标准容器
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
	//两种初始化都可以
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
	//连续空间不支持
	//LXY::vector<int> v1{ 1, 2, 3, 4, 5 };
	LXY::vector<int> v1{ 1, 2, 3, 4, 5 };
	return 0;
}
#endif

#if 0
template<class T1,class T2>
//返回的时候，返回T1和T2都不行，应该返回T1+T2后的值的类型
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
//返回的时候，返回T1和T2都不行，应该返回T1+T2后的值的类型
//此处auto为占位符
//返回值类型追踪
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
		//初始化其他变量
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