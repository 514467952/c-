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

	vector<int>v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//c++11�и����Ĺ���

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

	//vector��û��find������Ҫ��ɾ�����һ��Ԫ�أ�������ϵͳ�����㷨����find
	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
		v5.erase(pos);

	v5.clear();
}

void TestVector3()
{
	vector<vector<int>>vv;
	//10 * 10----->6
	vv.resize(10);  //�Ѿ�����10�У���ÿһ�л�û�пռ�

	//��ÿ������Ԫ��
	for (size_t i = 0; i < 10; ++i)
	{
		//ÿһ��10��Ԫ��
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
	foo.reserve(100);  //�ײ�ռ����˵���û����ЧԪ��	
	foo[0] = 10;    //���ʽ����߾ʹ��ˣ����ܷ���

	sz = foo.capacity();  
	std::cout << "making foo grow:\n";  
	for (int i = 0; i<100; ++i) 
	{ 
		foo.push_back(i);    

		if (sz != foo.capacity()) 
		{ 
			sz = foo.capacity();      
			std::cout << "�����ı�: " << sz << '\n'; 
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

	//������:����ָ���һ������
	//������һ��ָ�����ͣ����Խ�����������Ķ��󵱳���ָ�뷽ʽ����Ӧ��
	//���ã������û�͸����(�û����Բ���֪���������ĵײ����ݽṹ)��������
	
	auto it = v.begin();
	//v.assign(20, 8);
	v.push_back(1);  //���ܻ������ʧЧ
	//�����ʽ:��it���������¸�ֵ
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
//��vector����Ԫ�������
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
//���û᲻��ʧЧ
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
		ret.resize(numRows);  //�ȴ���numRows��

		for (size_t i = 0; i<numRows; ++i)
		{
			ret[i].resize(i + 1);
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		for (size_t i = 2; i < numRows; ++i)
		{
			//jΪÿһ��
			for (size_t j = 1; j < i; ++j)
			{
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}

		return ret;
	}
};