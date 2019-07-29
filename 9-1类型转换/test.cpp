
#include<iostream>

using namespace std;

//静态转换
//基础类型

void test01()
{
	char a = 'a';
	double d = static_cast<double>(a);

	cout << "d=" << d << endl;

}

//父与子之间的转换
class Base{};

class Child :public Base{};

class Other{};

void test02()
{
	Base * base = NULL;

	Child *child = NULL;

	//把Base转为Child类型 向下 不安全

	Child * child2 = static_cast<Child*>(base);

	//把child转为Base* 向上 安全
	Base *base2 = static_cast<Base*>(child);
	//转other类型  没有父子关系，类型转换无效
	//Other *other = static_cast<Other*>(base);

}

//转other类型
//static_cast使用  static_cast<目标类型>(原始对象)


//动态转换

void test03()
{
	//基础类型不可以转换
	char c = 'a';
	//dynamic_cast非常严格，失去精度，过着不安全都不可以转换
	//double d = dynamic_cast<double>(c);
}

class Base2
{
	virtual void func(){  };
};
class Child2 : public Base2
{
	virtual void func()
	{

	}
};
class Other1{};
void test04()
{
	Base2 *base = NULL;

	Child2 *child = NULL;

	//child转Base2 *安全
	Base2 *base2 = dynamic_cast<Base2*>(child);

	//base转Child2 * 不安全
	//Child2 *child2 = dynamic_cast<Child2>(base);

	//发生多态情况

	Base2 *base3 = new Child2;
	Child2 *child3 = dynamic_cast<Child2*>(base3);

}
// dynamic_cast 如果发生了多态，那么可以让基类转为派生类,向下转换



//常量转换（const_cast）

void test05()
{

	const int *p = NULL;
	//去除const
	int * newp = const_cast<int *>(p);

	int * p2 = NULL;

	const int * newp2 = const_cast<const int *>(p2);

	//不能对非指针 或者 引用的 变量进行转换
	//const int a = 10;
	//int b = const_cast<int>(a);

	//引用
	int num = 10;
	int &numRef = num;

	const int &numRef2 = static_cast<const int &>(numRef2);


	

}

//重新解释转换
	void test06()
	{
		int a = 10;
		int *p = reinterpret_cast<int *>(a);

		Base * base = NULL;
		Other * other = reinterpret_cast<Other *>(base);
		//最不安全，不推荐

	}

int main()
{

	test01();
	system("pause");
	return 0;
}