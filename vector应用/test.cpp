#include<iostream>
#include<algorithm>
using namespace std;

#if 0
#include<vector>
void TestVector1()
{
	vector<int>v1;
	vector<int>v2(10, 5);
	vector<int>v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int>v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int>v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//c++11中给出的构造

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i]<<" " ;
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e<<" ";
	}
	cout << endl;

	//vector<int>::iterator = v4.begin();
	auto it1 = v4.begin();
	while (it1 != v4.end())
	{
		cout << *it1<<" ";
		it1++;
	}
	cout << endl;

	auto it2 = v5.rbegin();
	while (it2 != v5.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}

void TestVector2()
{
	vector<int>v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);

	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end() - 1);

	//vector里没有find方法，要想删除最后一个元素，必须用系统给的算法函数find
	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
		v5.erase(pos);

	v5.clear();
}

void TestVector3()
{
	vector<vector<int>>vv;
	//10 * 10----->6
	vv.resize(10);  //已经有了10行，但每一行还没有空间

	//给每行设置元素
	for (size_t i = 0; i < 10; ++i)
	{
		//每一行10个元素
		vv[i].resize(10,6);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout<<endl;
	}

}


int main()
{
	//TestVector1();
	//TestVector2();
	TestVector3();
	system("pause");
	return 0;
}
#endif

#if 0
#include<vector>

int main() 
{ 
	size_t sz;  
	std::vector<int> foo;  
	foo.reserve(100);  //底层空间有了但是没有有效元素	
	foo[0] = 10;    //这个式子左边就错了，不能访问

	sz = foo.capacity();  
	std::cout << "making foo grow:\n";  
	for (int i = 0; i<100; ++i) 
	{ 
		foo.push_back(i);    

		if (sz != foo.capacity()) 
		{ 
			sz = foo.capacity();      
			std::cout << "容量改变: " << sz << '\n'; 
		} 
	}

	system("pause");
	return 0;
}
#endif

#include<vector>
#if 0
int main()
{
	vector<int>v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//迭代器:类似指针的一种类型
	//类似是一种指针类型，可以将迭代器定义的对象当成是指针方式进行应用
	//作用：帮助用户透明的(用户可以不用知道该容器的底层数据结构)遍历数据
	
	auto it = v.begin();
	//v.assign(20, 8);
	v.push_back(1);  //可能会迭代器失效
	//解决方式:给it迭代器重新赋值
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	system("pause");
	return 0;
}
#endif

#if 0
//将vector所有元素清除掉
int main()
{
	vector<int>v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//v.resize(0);

	//v.clear();

	//v.erase(v.begin(), v.end());

	auto it = v.begin();
	while (it!=v.end())
	{
		v.erase(it);
		++it;
	}
	cout << v.size() << endl;

	system("pause");
	return 0;
}
#endif

#if 0
//引用会不会失效
int main()
{
	vector<int>v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int& ra = v[0];
	ra = 10;
	v.push_back(1);
	ra = 100;

	system("pause");
	return 0;
}
#endif

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		ret.resize(numRows);  //先创建numRows行

		for (size_t i = 0; i<numRows; ++i)
		{
			ret[i].resize(i + 1);
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		for (size_t i = 2; i < numRows; ++i)
		{
			//j为每一列
			for (size_t j = 1; j < i; ++j)
			{
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}

		return ret;
	}
};