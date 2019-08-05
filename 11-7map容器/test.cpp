
#include<iostream>
#include<map>
using namespace std;

void test01()
{
	map<int, int>m;
	//����ֵ
	//4�ַ�ʽ
	//��һ��
	m.insert(pair<int, int>(1, 10));
	//�ڶ���
	m.insert(make_pair(2, 20));
	//������
	m.insert(map<int, int>::value_type(3, 30));
	//������ �����֤key���ڣ�����ͨ�����ַ�ʽ����
	m[4] = 40;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "value" << it->second << endl;
	}

	if (m.empty())
	{
		cout << "��" << endl;
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
		cout << "�ҵ�,keyֵΪ��" << pos->first << "value" << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	int num=m.count(3);//map��countҪô0Ҫô1
	cout << "num=" << num << endl;

	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�����
	map<int, int>::iterator ret = m.lower_bound(3);
	if (ret != m.end())
	{
		cout << "lower_bound��key" << ret->first << "value" << ret->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�����
	 ret = m.upper_bound(3);
	if (ret != m.end())
	{
		cout << "upper_bound��key" << ret->first << "value" << ret->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	pair<map<int,int>::iterator,map<int,int>::iterator>ret2= m.equal_range(3);
	if (ret2.first != m.end())
	{
		cout << "�ҵ���equal_range�е�lower_bound��key" << ret2.first->first << "value" << ret2.first->second << endl;

	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	if (ret2.second != m.end())
	{
		cout << "�ҵ���equal_range�е�upper_bound��key" << ret2.second->first << "value" << ret2.second->second << endl;

	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//ָ���������
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
	//�Ӵ�С����
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