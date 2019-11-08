#include<iostream>

using namespace std;


#if 0
int main()
{
	//new 申请单个类型元素的空间----默认情况下new出的空间在堆上

	int *p1 = new int;
	int *p2 = new int(10);
	int *p3 = new int[10];
	int *p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
void Test1()
{
	int *p1 = (int *)malloc(sizeof(int)* 4);
	int *p2 = (int *)malloc(sizeof(int)* 4);

	delete p1;
	delete p2;

	int *p3 = new int;
	int *p4 = new int;
	free(p3);
	delete[]p4;

	int *p5 = new int[10];
	int *p6 = new int[10];
	free(p5);
	delete p6;
}


//自定义类型
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this <<endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _data;

};

void Test2()
{
	Test *p1 = (Test *)malloc(sizeof(Test)* 4);
	//Test *p2 = (Test *)malloc(sizeof(Test)* 4);

	delete p1;
	//delete[] p2;

	Test *p3 = new Test;
	Test *p4 = new Test;
	free(p3);
	delete[]p4;

	Test *p5 = new Test[10];
	Test *p6 = new Test[10];
	free(p5);
	delete p6;
}

int main()
{
	//Test();
	Test2();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;

}
#endif

#if 0
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _data;

};

int main()
{
	//_CrtMemBlockHeader;
	Test* pt = new Test;
	delete pt;
	system("pause");
	return 0;
}
#endif

#if 0
void* operator new(size_t size,const char* file,const char* funname,size_t line)
{
	cout << file << "-" << funname << "-" << line << "-" << size << endl;
	return malloc(size);
}

void operator delete(void *p, const char* file, const char* funname, size_t line)
{
	cout << file << "-" << funname << "-" << line << "-" << endl;
	free(p);
}
#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int *p = new int;
	delete p;
	system("pause");
	return 0;
}
#endif




#if 0
struct ListNode {
	ListNode* _next;    
	ListNode* _prev;    
	int _data;

	void* operator new(size_t n)
	{ 
		void* p = nullptr;       
		p = allocator<ListNode>().allocate(1);        
		cout << "memory pool allocate" << endl;        
		return p; 
	}

	void operator delete(void* p)    
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);        
		cout << "memory pool deallocate" << endl;
	}
};

class List {
public:    
	List()    
{ 
	_head = new ListNode;        
	_head->_next = _head;        
	_head->_prev = _head; 
}

~List()    
{
	ListNode* cur = _head->_next;        
	while (cur != _head)        
	{ 
		ListNode* next = cur->_next;            
		delete cur;            
		cur = next; 
	 }

	delete _head;        
	_head = nullptr;
}

private:    
	ListNode* _head;
};

void TestList()
{
	List l;
}
int main() {

	TestList();
	system("pause");
	return 0;
}
#endif

#if 0
class Test 
{
public:   
	Test() : _data(0)   
	{ cout << "Test():" << this << endl; }

		 
	~Test()   
	{ cout << "~Test():" << this << endl; }   
private:   
	int _data;
};
int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt)Test;

	//delete pt;
	pt->~Test();
	system("pause");
	return 0;
}
#endif

class Test
{
public:
	~Test()
	{
		delete this;
	}

};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}