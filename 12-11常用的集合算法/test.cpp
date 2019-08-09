
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<iterator>

void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);//0 1 2 3 4 5 6 7 8 9
		v2.push_back(i + 5);// 5 6 7 8 9 10 11 12 13 14 
	}

	vector<int>vTarget;
	vTarget.resize(min(v1.size(),v2.size()));

	vector<int>::iterator itEnd= set_intersection(v1.begin(), v1.end(),v2.begin(), v2.end(), vTarget.begin());

	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

void test02()
{

	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);//0 1 2 3 4 5 6 7 8 9
		v2.push_back(i + 5);// 5 6 7 8 9 10 11 12 13 14 
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

void test03()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);//0 1 2 3 4 5 6 7 8 9
		v2.push_back(i + 5);// 5 6 7 8 9 10 11 12 13 14 
	}

	vector<int>vTarget;
	vTarget.resize(max(v1.size(), v2.size()));

	//v1²îv2
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));

	cout << endl;

	//v2²îv1
	 itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}