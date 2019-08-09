
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;



void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(v.size());

	copy(v.begin(), v.end(), vTarget.begin());

	//for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << " "; });

	//流迭代器方式遍历
	copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, ""));

}



class MyCompare
{
public:
	bool operator()(int v)
	{
		return v > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//把容器等中的3替换成300
	replace(v.begin(), v.end(), 3, 300);

	copy(v.begin(), v.end(), ostream_iterator <int>(cout, " "));
	cout << endl;

	//把容器中所有大于3的数字都替换成30000
	replace_if(v.begin(), v.end(), MyCompare(), 30000);
	copy(v.begin(), v.end(), ostream_iterator <int>(cout, " "));
	cout << endl;
}

void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;

	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(20);
	v2.push_back(40);
	cout << "交换前数据：" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "交换后的数据：" << endl;
	swap(v1, v2);
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}