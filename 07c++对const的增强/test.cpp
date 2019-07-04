#include<iostream>


using namespace std;

const int m_a = 10;  //在全局区域里，受到保护，不可以被更改



/*c语言中，const修饰的变量，是伪常量，编译器是会分配内存的、
	c++中，const不会分配内存，const int m_B=20;


*/
void test07()
{

	//m_a = 100;   不允许被修改
	
	const int m_B = 20;
	//m_B = 100;	不允许被修改

	int *p = (int *)&m_B;//*p指向的是临时的那块空间，临时空间看不到,临时的空间被更改，但m_B没有被改

	*p = 200;

	printf("*p=%d,m_B=%d\n", *p, m_B);
	//c中*p 和m_B都是200
	//c++中m_B为20，没有被更改
}

int main()
{
	test07();
	system("pause");
}
