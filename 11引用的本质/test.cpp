#include<iostream>

using namespace std;

//引用的本质在c++内部实现的是一个指针常量

//Type& ref = val;//Type* cosnt ref=&val'

//c++编译器在编译过程中使用指针作为引用的内部实现，因此引用所占的空间大小与指针相同
//只是这个过程是编译器内部实现，用户不可见。
int main()
{

	return 0;
}