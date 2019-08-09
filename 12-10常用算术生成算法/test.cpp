
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<numeric>
#include<iterator>

void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	//0~100累计和 5050
	//第三个参数 起始累加值
	int sum=accumulate(v.begin(), v.end(), 0);
	cout << "总和为：" << sum << endl;

}

void test02()
{
	vector<int>v;
	v.resize(10);

	fill(v.begin(), v.end(),1000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}