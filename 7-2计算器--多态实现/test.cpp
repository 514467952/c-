
#include<iostream>

using namespace std;
/*
class Calculator
{
public:

	void setv1(int v)
	{
		this->val1 = v;
	}
	void setv2(int v)
	{
		this->val2 = v;
	}

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return val1 + val2;
		}
		else if (oper == "-")
		{
			return val1 - val2;
		}
	}

private:
	int val1;
	int val2;
};
void test01()
{
	Calculator cal;
	cal.setv1(10);
	cal.setv2(10);
	cout << cal.getResult("+") << endl;
	cout << cal.getResult("-") << endl;
}
*/

//真正的开发中，有个开发原则，开闭原则
//对扩展开放 对修改关闭


//利用多态实现计算器
class abstractCalculator
{
public:
	void setv1(int v)
	{
		this->val1 = v;
	}
	void setv2(int v)
	{
		this->val2 = v;
	}
	//virtual int getResult(){return  0;} 虚函数

	//纯虚函数
	//如果父类中有了纯虚函数  子类继承了父类，必须要实现纯虚函数
	//如果父类中 有了纯虚函数，这个父类，就无法实例化对象了
	//这个类中有了纯虚函数，通常又称为 抽象类
	virtual int getResult() = 0;

public:
	int val1;
	int val2;
};
//如果父类中有了纯虚函数  子类继承了父类，必须要实现纯虚函数
class A :public abstractCalculator
{
public:
	virtual int getResult()
	{
		//return 0;
	}

};


//加法计算器 
class PlusCaculator :public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 + val2;
	}
};
//减法计算器
class SubCalculator : public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 - val2;
	}
};

//乘法计算器
class ChengCalculator : public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1*val2;
	}
};

void test01()
{
	abstractCalculator *abc = new PlusCaculator;//加法计算器
	abc = new PlusCaculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;

	delete abc;
	abc = new SubCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;


	delete abc;
	abc = new ChengCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;

	//如果父类有了纯虚函数，不能实例化对象了
	/*abstractCalculator aaa;
	abstractCalculator *abc = new abstractCalculator;*/
}

int main()
{
	test01();
	system("pause");
	return 0;
}