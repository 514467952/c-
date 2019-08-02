
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;//v.capacity()����������

	}

}

/*

*/

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void test02()
{
	vector<int >v;
	int arr[] = { 2, 3, 4, 1, 9 };
	vector<int>v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int >v2(v1.begin(), v1.end());
	printVector(v2);

	
	vector<int>v3(10, 100);
	printVector(v3);

	//��ֵʹ��
	vector<int>v4;
	v4.assign(v3.begin(), v3.end());
	printVector(v4);

	v4.swap(v2);

	cout << "�������v4" << endl;
	printVector(v4);

	cout << "v4�����Ĵ�С" << v4.size() << endl;

	if (v4.empty())
	{
		cout << "v4��" << endl;
	}
	else
	{
		cout << "v4����" << endl;
	}

	///v4  23419
	v4.resize(10,-1);//�ڶ���������Ĭ��ֵ��Ĭ��0
	printVector(v4);

	v4.resize(3);
	printVector(v4);
}

//����swap�����ռ�
void test03()
{
	vector<int >v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v������" << v.capacity() << endl;
	cout << "v�Ĵ�С" << v.size() << endl;

	v.resize(3);
	cout << "v������" << v.capacity() << endl;
	cout << "v�Ĵ�С" << v.size() << endl;

	//����swap
	vector<int>(v).swap(v);
	cout << "v������" << v.capacity() << endl;
	cout << "v�Ĵ�С" << v.size() << endl;

}
//reserve(int len).//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���

void test04()
{
	vector<int>v;
	v.reserve(100000);//Ԥ�����ռ�

	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	//����100000�������˶��ٴ�
}


void test05()
{
	vector<int >v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	cout << "v��front" << v.front() << endl;
	cout << "v��front" << v.back() << endl;

	v.insert(v.begin(), 2,100);//����1 ������ ����2 ����n ����3 ������������
	printVector(v);

	v.pop_back();//βɾ
	printVector(v);

	v.erase(v.begin());//ɾ��
	printVector(v);

	//v.erase(v.begin(), v.end());
	v.clear();//�����������
	if (v.empty())
	{
		cout << "Ϊ��" << endl;
	}

	
}


void test06()
{
	//�������
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	printVector(v);

	//reverse_iterator  ����ĵ�����
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	//vector��������������ʵĵ����� ֧����Ծʽ����
	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 3;
	//�������д�������������������������ʵ�����


	list<int>l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	list<int>::iterator lIt = l.begin();
	//lIt = lIt + 1;//��֧���������

}


int main()
{

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}

