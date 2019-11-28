#include<iostream>
using namespace std;

#include<string>


#if 0
//普通人----买票
class Person
{
public:
	Person(const string& name,const string& gender,const int age)
		:_name(name)
		, _gender(gender)
		, _age(age)
	{}

	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

class Studnet :public Person
{
public:
	Studnet(const string& name, const string& gender, const int age,const int _stuId)
		:Person(name,gender,age)
		, _stuId(_stuId)
	{}
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuId;
	
};

class Soldier:public Person
{
public:
	Soldier(const string& name, const string& gender, const int age, const string& rank)
		:Person(name,gender,age)
		, _rank(rank)
	{}

	virtual void BuyTicket()
	{
		cout << "免费" << endl;
	}
protected:
	string _rank;
};

//必须通过基类的指针或引用来调用，所以继承必须是公有的
//多态的体现:代码编译时，不能确定到底要用哪个类的虚函数
//			 在代码运行时，根据p所指向的实际对象选择调用对应类的虚函数
//如果多态的实现条件没有完全满足的话，1.重写失败(基类函数不是虚函数,函数原型不一致)
//									 2.没有通过基类的指针或者引用的方式调用虚函数

void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person p("Tom", "男", 18);
	Studnet st("小帅", "女", 19,1000);
	Soldier so("威武", "男", 23, "班长");

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	system("pause");
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2(int )
	{
		cout << "Base::TestFunc2()" << endl;
	}
	 void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base*  TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}
};

class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::Testfun1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}
	 void TestFunc4()
	{
		 cout << "Derived::TestFunc4()" << endl;
	}

	 virtual Derived*  TestFunc5()
	 {
		 cout << "Derived::TestFunc5()" << endl;
		 return this;
	 }
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(10);
	pb->TestFunc3();
	pb->TestFunc4(); 
	pb->TestFunc5();
}
int main()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base(int b)" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};


class Derived : public Base
{
public:
	Derived(int b)
		:Base(b)
		, _p(new int[10])
	{
		cout << "Derived::Derived()" << endl;
	}
	~Derived()
	{
		delete[]_p;
		cout << "Derived::~Derived()" << endl;
	}
protected:
	int *_p;
};

void TestDestroy()
{
	Base* pb = new Derived(10);
	delete pb;
}
int main()
{
	TestDestroy();
	system("pause");
	return 0;
}
#endif

#if 0
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	 ~Student() { cout << "~Student()" << endl; }
};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多
//态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	system("pause");
	return 0;
}

void TestBuyTicket(Person *p)
{
	p->~Person();
}
void TestBuyTicket(Person p)
{
	p.~Person();
}
#endif

#if 0
class Base
{
public:
	virtual void TestFun()
	{
		cout << "Base::TestFun()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void TestFun() override
	{
		cout << "Derived::TestFun()" << endl;
	}
};

void TestVirtual(Base * pb)
{
	pb->TestFun();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(&b);
	TestVirtual(&d);
	system("pause");
	return 0;
}
#endif
#if 0
class WC
{
public:
	void GoToManRoom()
	{
		cout << "go to left"<<endl;
	}
	void GoToWoManRoom() 
	{
		cout << "go to right"<<endl;
	}
};
//作用:规范后续的接口
class Person
{
	//不能实例化对象，但可以创建该类的指针
public:
	//纯虚函数
	virtual void GoToWc(WC& wc) = 0;
	string _name;
	int _age;
};

class Man :public Person
{
public:
	void GoToWc( WC& wc)
	{
		wc.GoToManRoom();
	}
};
class WoMan :public Person
{
public:
	void GoToWc(WC& wc)
	{
		wc.GoToWoManRoom();
	}
};
#include<Windows.h>
#include<time.h>
//Monster 也是抽象类，因为该类没有重写基类中的纯虚函数
class Monster :public Person
{};
void TestWC(int n)
{
	WC wc;
	srand(time(nullptr));
	for (int i = 0; i < n; ++i)
	{
		Person* pGuard;
		if (rand() % 2 == 0)
			pGuard = new Man;
		else
			pGuard = new WoMan;
		pGuard->GoToWc(wc);
		delete pGuard;

		Sleep(1000);
	}
}
int main()
{
	//Person* p;
	TestWC(10);
	system("pause");
	return 0;
}
#endif

#if 0
//如果一个类中包含有虚函数，类的大小会多四个字节
class Base
{
public:
	Base()
	{}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
	}
	int _d;
};

int  main()
{
	cout << sizeof(Base) << endl;
	Base b;
	b._b = 1;
	cout << sizeof(Derived) << endl;
	Derived a;
	a._b = 2;
	system("pause");
	return 0;
}
#endif
#if 0
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();//调用虚函数，f=vTable[i] vTable[i]等于一个虚函数入口地址
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
// 思路：取出b、d对象的头4比特，就是虚表的指针，虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
// 1.先取b的地址，强转成一个int*的指针
// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
// 4.虚表指针传递给PrintVTable进行打印虚表
// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有
//放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，再编译就好了。
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	system("pause");
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base()
	{}
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
	 void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	int _d;
};
//虚函数的调用:通过基类的指针或者引用调用虚函数
void TestVirtual(Base *pb)
{
	pb->TestFunc1();
	pb->TestFunc2();
	pb->TestFunc3();
	pb->TestFunc4();
}
int main()
{
	Derived d;
	TestVirtual(&d);
	system("pause");
	return 0;
}
#endif

#if 0
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	system("pause");
	return 0;
}
#endif

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

int main()
{
	cout << sizeof(Derive) << endl;
	system("pause");
	return 0;
}