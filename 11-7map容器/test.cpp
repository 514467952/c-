
#include<iostream>
#include<map>
using namespace std;

void test01()
{
	map<int, int>m;
	//插入值
	//4种方式
	//第一种
	m.insert(pair<int, int>(1, 10));
	//第二种
	m.insert(make_pair(2, 20));
	//第三种
	m.insert(map<int, int>::value_type(3, 30));
	//第四种 如果保证key存在，可以通过这种方式访问
	m[4] = 40;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "value" << it->second << endl;
	}

	if (m.empty())
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "size=" << m.size() << endl;
	}
}

void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	m.erase(1);
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "value" << it->second << endl;
	}

	map<int,int>::iterator pos=m.find(2);
	if (pos != m.end())
	{
		cout << "找到,key值为：" << pos->first << "value" << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	int num=m.count(3);//map的count要么0要么1
	cout << "num=" << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器
	map<int, int>::iterator ret = m.lower_bound(3);
	if (ret != m.end())
	{
		cout << "lower_bound中key" << ret->first << "value" << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器
	 ret = m.upper_bound(3);
	if (ret != m.end())
	{
		cout << "upper_bound中key" << ret->first << "value" << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	pair<map<int,int>::iterator,map<int,int>::iterator>ret2= m.equal_range(3);
	if (ret2.first != m.end())
	{
		cout << "找到了equal_range中的lower_bound的key" << ret2.first->first << "value" << ret2.first->second << endl;

	}
	else
	{
		cout << "未找到" << endl;
	}

	if (ret2.second != m.end())
	{
		cout << "找到了equal_range中的upper_bound的key" << ret2.second->first << "value" << ret2.second->second << endl;

	}
	else
	{
		cout << "未找到" << endl;
	}
}

//指定排序规则
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test03()
{
	//从大到小排序
	map<int, int,myCompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << "value:" << it->second << endl;
	}

}


int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}