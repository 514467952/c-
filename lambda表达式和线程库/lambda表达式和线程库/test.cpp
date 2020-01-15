#include<iostream>
using namespace std;
#include <algorithm>
#include <functional>
#if 0
int main()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };
	// 默认按照小于比较，排出来结果是升序
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	// 如果需要降序，需要改变元素的比较规则
	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
	return 0;
}
#endif

#if 0
struct Goods
{
	string _name;
	double _price;
};
struct Compare
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};
int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	//sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods&left, const Goods& right)
													{
															return left._price < right._price; 
													});
	return 0;
}
#endif

#if 0
int g_a = 10;
int main()
{
	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	[]{};
	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
	int a = 3, b = 4;
	[=,&g_a]{return a + 3; };	//想要在a的基础上+3返回。
	//但是这个lambda表达式没有用
	//因为没有取名字

	// 省略了返回值类型，无返回值类型
	//不知道lambda表达式的类型就用auto
	//[&]以引用的方式捕获当前主函数的变量  a=3;b=13;
	//[=]以值得方式进行捕获			a=3;b=4;
	auto fun1 = [=](int c)mutable{b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;


	// 各部分都很完善的lambda函数
	// [=] 以值的方式捕获所有的变量
	// [&] 以引用的方式捕获所有的变量
	// [=,&b] 对于b变量以引用得方式捕获，对于其它变量用值的方式
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;

	// 复制捕捉x
	// 以值得方式捕获x，函数内修改不会影响外部
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;
	return 0;
}
#endif

#if 0
void(*PF)();//没有返回值也没有参数得函数指针
int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };
	//f1 = f2; // 编译失败--->提示找不到operator=()
	// 允许使用一个lambda表达式拷贝构造一个新的副本
	auto f3(f2);
	f3();
	// 可以将lambda表达式赋值给相同类型的函数指针
	PF = f2;
	PF();
	return 0;
}
#endif

#if 0
class Rate
{
public:
	Rate(double rate) 
		: _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};
int main()
{
	// 函数对象
	double rate = 0.49;
	Rate r1(rate); //定义一个对象将利率传进去
	r1(10000, 2);	//对象调用自身的方法，跟函数调用比较像都是 名字()
	// 仿函数
	//=捕获rate
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);

	int array[] = { 1, 2, 3, 4, 5 };
	for_each(array, array + 5, [](int&c){c *= 2; });
	for_each(array, array + 5, [](int c){cout << c<<" "; });
	system("pause");
	return 0;
}
#endif

#if 0
#include<thread>
void ThreadFunc(int a)
{
	cout << "Thread1" << a << endl;
}
class TF
{
public:
	void operator()()
	{
		cout << "Thread3" << endl;
	}
};

int main()
{
	TF tf;
	//线程函数尾函数指针
	thread t1(ThreadFunc, 10);
	//线程函数为lambda表达式
	thread t2([]{cout << "Thread2" << endl; });
	//线程函数为函数对象
	thread t3(tf);

	t1.join();
	t2.join();
	t3.join();
	cout << "Main thread!" << endl;

	system("pause");
	return 0;
}
#endif
#if 0
#include<thread>
void ThreadFunc1(int& x)
{
	cout << &x << " " << x << endl;
	x += 10;
}

void ThreadFunc2(int*x)
{
	*x += 10;
}

int main()
{
	int a = 10;

	//在线程函数中对a修改，不会影响外部实参，因为:线程函数虽然是引用方式，但其实际引用的是线程栈中的拷贝
	thread t1(ThreadFunc1, a);
	t1.join();
	cout << &a <<" "<< a << endl;

	//地址的拷贝
	thread t3(ThreadFunc2, &a);
	t3.join();
	cout << a << endl;

	system("pause");
	return 0;
}
#endif


#include <iostream>
using namespace std;
#include <thread>
#include<atomic>

//unsigned long sum = 0L;
atomic_long sum{0}; //定义原子类型变量

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		sum++;
	}
}
int main()
{
	size_t begin = clock();
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	//两个线程每个每回都循环10000000次，每次加1
	//如果没问题应该是20000000
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	size_t end = clock();
	cout << end - begin << endl; //计算时间
	system("pause");
	return 0;
}
