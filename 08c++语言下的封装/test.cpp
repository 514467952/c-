
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	char mName[64];

	int mAge;


	void PersonEat(struct Person *p)
	{
		printf("%s 在吃人饭\n", p->mName);
	}

};

struct Dog
{
	char mName[64];

	int mAge;

	void DogEat(struct  Dog *dog)
	{
		printf("%s ,在吃狗粮\n", dog->mName);
	}
};

//c++中的封装 严格类型转换检测 让属性和行为 绑定在一起
//1.属性和行为作为一个整体来表示生活中的事务
//2.控制权限 public 公有权限 protected 保护权限 private 私有权限


void test01()
{
	Person p1;
	strcpy(p1.mName, "老王");
	p1.PersonEat(&p1);
	//p1.DogEat();
	
}


//struct 和class是一个意思，唯一不同的是  默认权限 ，struct是public ，但是class默认权限是private
class Animal
{
	//如果我不声明权限，默认权限是private
	void eat()
	{
		mAge = 100;
	};
	int mAge;
public:
	int mHeight;

protected: //保护权限 类内部可以访问，（当前类的子类可以访问），类外部不可以访问
	int mweight;
	void setWeight(){ mweight = 100; };

};
//所谓私有权限，就是私有成员（属性，函数）在类内部可以访问，类外部不可以访问
//公共权限，在类内部和类外部都可以访问
void test02()
{
	Animal an;
	//an.eat(); //私有不可以访问
	an.mHeight = 100;//公有权限在类外部可以访问到
	//an.mWeight = 100;  保护权限  在类内可以访问 类外不可以
}
//public 类内 类外 都可以访问
//protected 类内可以访问 类外 不可以访问 （子类可以访问）
//prviate 类内可以访问 类外 不可以访问 （子类不可以访问）


int main()
{

	
	test01();
	//test02();
	system("pause");
	return 0;
}