#include<iostream>

using namespace std;



#include<map>
#include<string>
void TestMap()
{
	map<string, string>m;
	m.insert(pair<string,string>("宋江","及时雨"));
	m.insert(pair<string, string>("李逵", "黑旋风"));

	//pair<iterator,bool>
	//iterator:代表map中的一个key-value的键值对
	//bool:insert插入是否成功
	auto ret = m.insert(make_pair("孙二娘","母夜叉"));
	if (ret.second){
		cout << (*ret.first).first << "--->" << ret.first->second << endl;
	}
	ret = m.insert(make_pair("李逵", "铁牛"));
	//key 已经存在不会插入
	cout << (*ret.first).first << "--->" << ret.first->second << endl;

	cout << m.size() << endl;

	cout << m["李逵"] << endl; //把value返回来
	//用户提供key---->[]返回key所对应的value
	m["李逵"] = "铁牛";  //修改value
	cout << m["李逵"] << endl;
	m["林冲"] = "豹子头";
	cout << m.size() << endl;
}


void TestMap2()
{
	int array[] = { 3, 1, 9, 4, 0, 7, 6, 2, 5 };
	map<int, int>m;
	for (auto e : array){
		m.insert(make_pair(e, e));
	}

	//测试按照迭代器方式进行遍历，能否得到一个关于key有序的序列
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.erase(5);
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	cout << endl;
}



//#include<set>


//int main()
//{
//	int array[] = { 3, 1, 3, 4, 5, 6, 7, 8, 9, 0, 9, 4, 0, 7, 6, 2, 5, 8 };
//	set<int>s;
//	for (auto e : array)
//		s.insert(e);
//	cout << s.size() << endl;
//
//	for (auto e : s)
//		cout << e << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}


#include<set>
int main()
{
	int array[] = { 3, 1, 3, 4, 5, 6, 7, 8, 9, 0, 9, 4, 0, 7, 6, 2, 5, 8 };
		multiset<int>s;
		for (auto e : array)
			s.insert(e);
		cout << s.size() << endl;
	
		for (auto e : s)
			cout << e << " ";
		cout << endl;
	system("pause");
	return 0;
}