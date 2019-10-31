#include<iostream>

using namespace std;

namespace bite
{
	//list:带头结点双向循环链表
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = 0)
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pNext;//下一个结点
		ListNode<T>* _pPre;//上一个结点
		T _data; //结点中的数据
	};

	//list迭代器:将结点类型的指针重新封装
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;

	public:
		//和一个结点关联起来，创建迭代器的时候，掉构造函数，用户也就将迭代器的初始值赋予给了迭代器
		list_iterator(Node* pCur)
			:_pCur(pCur)
		{}

		//按照指针的方式进行应用
		T& operator*()
		{
			//返回数据本身
			return _pCur->_data;
		}

		T& operator->()
		{
			//反会数据的地址
			return &(_pCur->_data);
		}

		//移动
		Self& operator++()
		{
			_pCur = _pCur->_pNext;
			return *this;
		}
		Self  operator++(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pCur = _pCur->_pPre;
			return *this;
		}
		Self  operator--(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}

		//4.比较
		bool operator!=(const Self& s)
		{
			return _pCur != s._pCur;
		}

		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}

		Node* _pCur;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		//T代表结点中元素的类型
		//而我们的迭代器的类型必须是结点的类型
		typedef list_iterator<T> iterator;
	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& data = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(data);
			}
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& L)
		{
			CreateHead();
			Node* pCur = L._pHead->_pNext;
			while (pCur != L._pHead)
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}

		//L1=L2;
		list<T>& operator=(const list<T>& s)
		{
			if (this != &s)
			{
				clear();			//先清空
				Node* pCur = L._pHead;
				while (pCur != _pHead)
				{
					push_back(pCur->_data);
					pCur = pCur->_pNext;
				}
			}
			return *this;
		}
		~list()
		{
			clear();	
			delete[]_pHead;
		}

	public:
		//迭代器
		iterator begin()
		{
			return	iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return  iterator(_pHead);
		}

		//容量
		size_t size()const
		{
			size_t count = 0;
			Node* pCur = _pHead;
			while (pCur!=_pHead)
			{
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}

		size_t empty()const
		{
			return _pHead->_pNext = _pHead;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				//结点增多
				for (size_t i = oldsize; i < newsize; ++i)
				{
					push_back(data);
				}
			}
			else
			{
				//结点减少
				for (size_t i = newsize; i < oldsize; ++i)
				{
					pop_back();
				}
			}
		}

		//元素访问
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back()const
		{
			return -_pHead->_pPre->_data;
		}

		//元素修改
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		
		void pop_back()
		{
			erase(--end());
		}
		
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& data)
		{
			Node* pNewNode = new Node(data);
			Node* pCur = pos._pCur;

			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;

			return iterator(pNewNode);
		}
		iterator erase(iterator pos)
		{
			Node* pDelNode = pos._pCur;
			if (pDelNode == _pHead)
				return end();

			Node* pRet = pDelNode->_pNext;//保存删除结点的下一个，用于返回
			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			delete pDelNode;

		}

		void clear()
		{
			Node* pCur = _pHead->_pNext;
			//头删
			while (pCur!=_pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}

			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}


		void swap(list<T>& L)
		{
			swap(_pHead, L._pHead);
		}

	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	protected:
		Node* _pHead;

	};
}

#include<vector>
void TestList1()
{
	bite::list<int>L1;
	bite::list<int>L2(10, 5);

	vector<int>v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int>L3(v.begin(),v.end());
	bite::list<int>L4(L3);

	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	TestList1();
	system("pause");
	return 0;
}