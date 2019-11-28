#include<iostream>
using namespace std;

#include<string>


#if 0
//��ͨ��----��Ʊ
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
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "���" << endl;
	}
protected:
	string _rank;
};

//����ͨ�������ָ������������ã����Լ̳б����ǹ��е�
//��̬������:�������ʱ������ȷ������Ҫ���ĸ�����麯��
//			 �ڴ�������ʱ������p��ָ���ʵ�ʶ���ѡ����ö�Ӧ����麯��
//�����̬��ʵ������û����ȫ����Ļ���1.��дʧ��(���ຯ�������麯��,����ԭ�Ͳ�һ��)
//									 2.û��ͨ�������ָ��������õķ�ʽ�����麯��

void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person p("Tom", "��", 18);
	Studnet st("С˧", "Ů", 19,1000);
	Soldier so("����", "��", 23, "�೤");

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
// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�
//̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//����:�淶�����Ľӿ�
class Person
{
	//����ʵ�������󣬵����Դ��������ָ��
public:
	//���麯��
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
//Monster Ҳ�ǳ����࣬��Ϊ����û����д�����еĴ��麯��
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
//���һ�����а������麯������Ĵ�С����ĸ��ֽ�
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
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();//�����麯����f=vTable[i] vTable[i]����һ���麯����ڵ�ַ
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
// ˼·��ȡ��b��d�����ͷ4���أ���������ָ�룬�麯��������һ�����麯��ָ���ָ�����飬���������������һ��nullptr
// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û��
//��nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼���� - ���� - �������������ٱ���ͺ��ˡ�
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
//�麯���ĵ���:ͨ�������ָ��������õ����麯��
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
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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