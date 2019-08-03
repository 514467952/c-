
#include<iostream>
using namespace std;
#include<stack>
/*
## stack没有迭代器
Stack所有元素的进出都必须符合“先进后出”的条件，只有stack顶端的元素，才有机会被外界取用，stack不提供遍历功能，也不提供迭代器

## stack 对象的默认构造

1. stack 采用模板类实现， stack 对象的默认构造形式： stack<T>stkT;
2.  stack<int>stkInt; //一个存放 int 的 stack 容器。 stack<float>stkFloat; //一个存放 float 的 stack 容器。
3. stack<string>stkString; //一个存放 string 的 stack 容器。
4.  ...
5.  //尖括号内还可以设置指针类型或自定义类型。

## stack 的 push()与 pop()方法

1. stack.push(elem);  //往栈头添加元素
2. stack.pop(); //从栈头移除第一个元素

## stack 对象的拷贝构造与赋值

1. stack(conststack&stk); //拷贝构造函数
2. stack&operator=(conststack&stk); //重载等号操作符

## stack 的数据存取

1.  stack.top(); //返回最后一个压入栈元素

## stack 的大小

1. stack.empty(); //判断堆栈是否为空
2. stack.size(); //返回堆栈的大小
*/

void test01()
{
	stack<int>s;
	//放入数据 push
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (s.size()!=0)
	{
		cout << "栈顶为：" << s.top() << endl;//40先出 30 20 10
		//弹出栈顶元素
		s.pop();
	}
	cout << "size= " << s.size() << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}