
#include<iostream>

using namespace std;
#include<vector>
#include<algorithm>
#include<functional>
#include<string>

class MyPrint:public binary_function<int,int,void>
{
public:
	void operator()(int v, int start) const
	{
		cout << "v=" << v << "start=" << start << "v+start=" << v + start << endl;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}
	cout << "请输入一个起始值：" << endl;
	int num;
	cin >> num;

	//for_each(v.begin(), v.end(), bind2nd (MyPrint(),num));
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));

}
//第一步，绑定数据 bind2nd
//第二步，继承类 binary_function<参数类型1，参数类型2，返回值类型>
//第三步，加const修饰operator()



//取反适配器
class CreateThenFive:public unary_function<int,bool>
{
public:
	bool operator()(int v)const
	{
		return v > 5;
	}
};

void test02()
{
	//一元取反
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找大于5的数字
	//需求改为找小于5的数字
	//vector<int>::iterator pos=find_if(v.begin(), v.end(),not1 (CreateThenFive()));
	vector<int>::iterator pos=find_if(v.begin(), v.end(),not1(bind2nd(greater<int>(),5)));

	if (pos != v.end())
	{
		cout << "找到大于5的数字为：" <<*pos<< endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//一元取反适配器 not1
//继承unary_fuction<类型1，返回值类型>
//const


void MyPrint03(int v,int start)
{
	cout << v+start << endl;
}
//函数指针适配器
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//将函数指针 适配为函数对象
	//ptr_fun

	for_each(v.begin(), v.end(),bind2nd (ptr_fun (MyPrint03),100));
}

//成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "成员函数中姓名：" << m_Name << "年龄：" << m_Age << endl;
	}

	void plusAge()
	{
		this->m_Age+=100;
	}

	string m_Name;
	int m_Age;
};

void MyPrintPerson(Person &p)
{
	cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
}
void test04()
{
	vector<Person >v;
	Person p1("aaa", 10);
	Person p2("bbb", 15);
	Person p3("ccc", 18);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	//成员函数适配器
	//mem_fun_ref
	for_each(v.begin(), v.end(),mem_fun_ref (&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main()
{

	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}