#include<iostream>
#include<queue>
using namespace std;


#include<vector>
#include<functional>

#if 0
int main()
{
	//优先级队列默认情况下是大堆
	priority_queue<int>q1;	//默认构造
	q1.push(4);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	vector<int>v{ 3, 8, 2, 6, 0, 1, 9, 5, 7, 4 };
	priority_queue<int,vector<int>,greater<int>>q2(v.begin(),v.end());	//区间构造
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

	//自定义数据类型需要给出自己的比较规则
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
	
	////如果在优先级队列中插入的是自定义数据类型的元素，插入元素期间必须进行元素的比较
	////(less : greater)
	////需要对自定义类型的元素进行大于或者小于的比较
	////类中：必须重载>或者<的符号
	//q.push(d1);
	//q.push(d2);
	//q.push(d3);


	priority_queue<Date*,vector<Date*>,Compare>q2;
	q2.push(&d3);
	q2.push(&d1);
	q2.push(&d2);
	//按这种方式默认情况给出的不完全是大堆，有些情况给出的是小堆
	//他是把指针排成了大小堆，我们需要让指针里所指向的值排成大小堆

	system("pause");
	return 0;
}
#endif 