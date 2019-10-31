#include<iostream>

using namespace std;

namespace bite
{
	//list:��ͷ���˫��ѭ������
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = 0)
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pNext;//��һ�����
		ListNode<T>* _pPre;//��һ�����
		T _data; //����е�����
	};

	//list������:��������͵�ָ�����·�װ
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;

	public:
		//��һ��������������������������ʱ�򣬵����캯�����û�Ҳ�ͽ��������ĳ�ʼֵ������˵�����
		list_iterator(Node* pCur)
			:_pCur(pCur)
		{}

		//����ָ��ķ�ʽ����Ӧ��
		T& operator*()
		{
			//�������ݱ���
			return _pCur->_data;
		}

		T& operator->()
		{
			//�������ݵĵ�ַ
			return &(_pCur->_data);
		}

		//�ƶ�
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

		//4.�Ƚ�
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
		//T��������Ԫ�ص�����
		//�����ǵĵ����������ͱ����ǽ�������
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
				clear();			//�����
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
		//������
		iterator begin()
		{
			return	iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return  iterator(_pHead);
		}

		//����
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
				//�������
				for (size_t i = oldsize; i < newsize; ++i)
				{
					push_back(data);
				}
			}
			else
			{
				//������
				for (size_t i = newsize; i < oldsize; ++i)
				{
					pop_back();
				}
			}
		}

		//Ԫ�ط���
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

		//Ԫ���޸�
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

			Node* pRet = pDelNode->_pNext;//����ɾ��������һ�������ڷ���
			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			delete pDelNode;

		}

		void clear()
		{
			Node* pCur = _pHead->_pNext;
			//ͷɾ
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