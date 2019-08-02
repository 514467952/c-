
#include<iostream>

using namespace std;
#include<deque>
#include<algorithm>


void printDeque(const deque<int>&d)
{
	//iterator��ͨ������
	//reverse_iterator���������
	//const_iterator ֻ��������
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " " ;
	} 
	cout << endl;
}


void test01()
{
	deque<int >d;

	d.push_back(10);
	d.push_back(40);
	d.push_back(30);
	d.push_back(20);
	printDeque(d);


	deque<int>d2(d.begin(),d.end());
	d2.push_back(10000);

	//����
	d.swap(d2);
	printDeque(d);


	//d2������10 40 30 20 
	if (d2.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "��Ϊ��,��СΪ:" <<d2.size()<< endl;
	}
}

void test02()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);//200 100 10 30 20

	//ɾ�� ͷɾ βɾ
	d.pop_back();
	d.pop_front();
	printDeque(d);

	cout << "front" << d.front() << endl;
	cout << "back" << d.back() << endl;

	//����
	deque<int>d2;
	d2.push_back(50);
	d2.push_back(60);
	d2.insert(d2.begin(), d.begin(), d.end());
	printDeque(d2);//100 10 30 50 60
	
}


//�������
bool myCompare(int v1, int v2)
{
	return v1 > v2; 
}


//����sort
void test03()
{
	deque<int>d;
	d.push_back(5);
	d.push_back(15);
	d.push_back(3);
	d.push_back(40);
	d.push_back(7);
	
	printDeque(d);
	//����

	sort(d.begin(), d.end());
	printDeque(d);

	//�Ӵ�С
	sort(d.begin(), d.end(),myCompare);
	printDeque(d);
}



int  main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}