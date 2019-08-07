
#include<iostream>

using namespace std;
#include<vector>
#include<algorithm>


class CreateThen20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};



//一元谓词
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//查找第一个大于20的数字
	//第三个参数 函数对象，匿名对象
	vector<int>::iterator pos= find_if(v.begin(), v.end(),CreateThen20());
	if (pos != v.end())
	{
		cout << "找到大于20的数字为：" << *pos << endl;
	}
}
//二元谓词

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};


void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end(), MyCompare());


	//匿名函数  lambda表达式 []函数名()参数{}实现体      [](int val){cout << val << " "; }
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
}




int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}