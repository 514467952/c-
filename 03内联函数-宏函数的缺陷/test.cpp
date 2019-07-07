#include<iostream>

using namespace std;
//定义一个加法
#define MyAdd(x,y) ((x)+(y))

void test01()
{
	int ret = MyAdd(10, 20)*20;//预期时600  加括号((10)+(20))*20
	cout << "ret=" << ret << endl;

}

#define MyCompare(a,b) ((a)<(b))?(a):(b)
inline void mycompare(int a, int b)
{
	int ret = a < b ? a : b;
	cout << "ret=:::::" << ret << endl;
}
//1.内联函数注意事项
inline void func();//内联函数声明
void func(){};//如果函数实现的时候，没有加inline关键字，那么这个函数依然不算内联函数
//2.类内定义内联函数不是必须的，任何在类内定义的函数自动成为内联函数
//3.有些情况编译器可能考虑不会将函数进行内联编译
	/*1不能存在任何形式的循环语句
	  2不能存在过多的条件判断语句
	  3函数体不能过于庞大
	  4不能对函数进行去取地址操作*/



void test02()
{
	int a = 10;
	int b = 20;
	//int ret = MyCompare(++a, b);//预期结果11 结果是12  ((++a)<(b))?(++a):(b) ++a执行了两次
	mycompare(++a, b);
	//cout << "ret=" << ret << endl;

}
//3 宏函数没有作用域

int main()
{
	//test01();
	test02();
	
	system("pause");
	return 0;
}