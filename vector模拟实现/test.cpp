#include<iostream>
#include<assert.h>
using namespace std;

namespace bite
{
	
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		// 构造与销毁
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}

		vector(int n, const T& data)
			:_start(new T[n])
		{
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = data;
			}

			_finish = _start + n;
			_endofstorage = _finish;
		}

		//[first,last)
		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			//计算[first,last)区间中元素的个数
			size_t n = 0;
			auto it = first;
			while (it != last)
			{
				++it;
				++n;
			}

			_start = new T[n];

			//将[first,last)区间中的元素放置到_start空间中
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = *first++;
			}

			_finish = _start + n;
			_endofstorage = _start + n;

		}

		vector(const vector<T>& v);
		vector<T>& operator=(const T& v);

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//迭代器
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		//容量操作
		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage-_start;
		}

		bool empty()const
		{
			return _endofstorage == _finish;
		}

		//如果T代表内置类型，T()---0
		//如果T代表自定义类型，T()---代表调用该类的无参构造函数
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)			//有效元素个数增多
			{
				size_t cap = capacity();
				if (newsize > cap)  //新容量必旧容量大，需要进行扩容
					reserve(newsize);
				
				for (; oldsize < newsize; ++oldsize)
					_start[oldsize] = data;
			}
			//如果减少，直接更新_finish位置
			_finish = _start + newsize;
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapcacity = capacity();
			if (oldcapcacity < newcapacity)
			{
				//1.申请新空间
				T* temp = new T[newcapacity];
				//2.拷贝元素
				//memcpy(temp, _start, size()*sizeof(T));

				//如果空间存在，_start指向的空间存在
				size_t n = size();		//记录原来的旧空间到底有多少个元素
				if (_start)
				{
					for (size_t i = 0; i < size(); ++i)
					{
						temp[i] = _start[i];
					}
					//3.释放旧空间
					delete[]_start;
				}
				_start = temp;
				_finish = _start + n;

				_endofstorage = _start + newcapacity;
			}
		}

		//元素访问的操作
		//v[0] = 100; v如果是普通类型
		T& operator[](size_t index)
		{
			assert(index <= size());
			return _start[index];
		}

		//对于const类型的变量
		const T& operator[](size_t index)const
		{
			assert(index <= size());
			return _start[index];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish-1);
		}

		const T& back()const
		{
			return *(_finish-1);
		}

		//元素修改
		void push_back(const T& data)
		{
			//检测是否需要扩容
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}
			*_finish++ = data;
		}

		void pop_back()
		{
			--_finish;
		}

		//返回值含义：反回新插入元素的位置
		iterator insert(iterator pos, const T&data)
		{
			//检测是否需要扩容
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}

			//插入元素
			//将[pos,finish)之间所有元素整体向后搬移一个位置
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}

			//插入新元素
			*pos = data;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;

			//it代表待搬移元素的位置
			auto it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++ot;
			}

			_finish--;

			return pos;
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}

void TestVector()
{
	bite::vector<int>v1;
	bite::vector<int>v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int>v3(array,array+sizeof(array)/sizeof(array[0]));

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	//bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : v3)
		e *= 2;
	
	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}

void TestVector2()
{
	bite::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;

}

void TestVector3()
{
	bite::vector<int>v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
int main()
{
	//TestVector();
	//TestVector2();
	TestVector3();
	system("pause");
	return 0;
}