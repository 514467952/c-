#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!(_year > 0 &&
			_month > 0 && _month < 13 &&
			_day>0 && _day <= _GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date&d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	//距离当前日期之后的xx天是多少天
	//+ 不会改变左右操作数的内容，智能按照值的方式返回
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}
		Date temp(*this);
		temp._day += days;

		int daysofMoth = 0;
		//temp中的day已经大于本月的天数
		while (temp._day > ( daysofMoth = temp._GetDaysOfMonth(temp._year, temp._month)))
		{
			temp._day -= daysofMoth;
			temp._month++;
			if (temp._month > 12 )
			{
				temp._year++;
				temp._month = 1;
			}

		}
		return temp;
	}

	

	//距离当前日期之前的xx天是多少天
	Date operator-(int days)
	{
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp._GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	//两个日期之间差了多少天
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (*this > d)
		{
			swap(minDate, maxDate);
		}

		size_t count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}
		return count;
	}
	//两个日期之间的大小关系
	bool operator>(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	bool operator== (const Date& d) const
	{
		return _year == d._year&&
			_month == d._month&&
			_day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	friend ostream& operator<<(ostream& _cout,const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _GetDaysOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			days[2] += 1;
		}
		return days[month];
	}

	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100)
			&& (0 == year % 400))
		{
			return true;
		}

		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2019, 9, 18);
	Date d2(2020, 1, 1);
	cout << d2 - d << endl;

	d = d + 999;
	cout << d << endl;
	system("pause");
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!(_year > 0 &&
			_month > 0 && _month < 13 &&
			_day > 0 && _day <= _GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	// + 不会改变左右操作数中的内容--->只能按照值得方式返回
	// d + (-100)
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		int daysofMonth = 0;
		// temp中的day已经大于本月的天数
		while (temp._day >(daysofMonth = temp._GetDaysOfMonth(temp._year, temp._month)))
		{
			temp._day -= daysofMonth;
			temp._month++;
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = 1;
			}
		}

		return temp;
	}

	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}

			temp._day += temp._GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	// min   max
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (*this > d)
		{
			swap(minDate, maxDate);
		}

		size_t count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}

		return count;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _GetDaysOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			days[2] += 1;
		}

		return days[month];
	}

	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) ||
			(0 == year % 400))
		{
			return true;
		}

		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2019, 9, 18);
	/*Date d2(2020, 1, 1);
	cout << d2 - d1 << endl;*/

	d1 = d1 + 999;
	cout << d1 << endl;
	system("pause");
	return 0;
}