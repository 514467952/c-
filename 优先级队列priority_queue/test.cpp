#include<iostream>
#include<queue>
using namespace std;


#include<vector>
#include<functional>

#if 0
int main()
{
	//���ȼ�����Ĭ��������Ǵ��
	priority_queue<int>q1;	//Ĭ�Ϲ���
	q1.push(4);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	vector<int>v{ 3, 8, 2, 6, 0, 1, 9, 5, 7, 4 };
	priority_queue<int,vector<int>,greater<int>>q2(v.begin(),v.end());	//���乹��
	cout << q2.size() << endl;
	cout << q2.top() << endl;

	q2.pop();
	cout << q2.top() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
	friend class Compare;
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//�Զ�������������Ҫ�����Լ��ıȽϹ���
	bool operator<(const Date& d)const 
	{
		return _day < d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Compare
{
public:
	bool operator()(Date* pLeft, Date* pRight)
	{
		if (pLeft->_day < pRight->_day)
			return true;

		return false;
	}
};

int main()
{
	priority_queue<Date>q;
	Date d1(2019, 10, 18);
	Date d2(2019, 10, 17);
	Date d3(2019, 10, 16);
	
	////��������ȼ������в�������Զ����������͵�Ԫ�أ�����Ԫ���ڼ�������Ԫ�صıȽ�
	////(less : greater)
	////��Ҫ���Զ������͵�Ԫ�ؽ��д��ڻ���С�ڵıȽ�
	////���У���������>����<�ķ���
	//q.push(d1);
	//q.push(d2);
	//q.push(d3);


	priority_queue<Date*,vector<Date*>,Compare>q2;
	q2.push(&d3);
	q2.push(&d1);
	q2.push(&d2);
	//�����ַ�ʽĬ����������Ĳ���ȫ�Ǵ�ѣ���Щ�����������С��
	//���ǰ�ָ���ų��˴�С�ѣ�������Ҫ��ָ������ָ���ֵ�ųɴ�С��

	system("pause");
	return 0;
}
#endif 