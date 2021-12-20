#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

//#################### TASK_1 ####################

class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}
	

	~Date() {}
	
	void Compare(Date& d1, Date& d2);

	int getDay() const
	{
		return m_day;
	}

	int getMonth() const
	{
		return m_month;
	}
	
	int getYear() const
	{
		return m_year;
	}
	
	void SwapDate(Date& d1, Date& d2);

	friend ostream& operator<<(ostream& out, const Date& oDate);

};

ostream& operator<<(ostream& out, const Date& oDate)
{
	out << oDate.m_day << "." << oDate.m_month << "." << oDate.m_year << endl;
	return out;
}

//#################### TASK_2 ####################

		
void Date::Compare(Date& d1 , Date& d2)
{
		if (d1.getYear() > d2.getYear())
		{
			cout << d1;
		}
		else if (d1.getYear() < d2.getYear())
		{
			cout << d2;
		}
		else {
			if (d1.getMonth() > d2.getMonth())
			{
				cout << d1;
			}
			else if (d1.getMonth() < d2.getMonth())
			{
				cout << d2;
			}
			else
			{
				if (d1.getDay() > d2.getDay())
				{
					cout << d1;
				}
				else
				{
					cout << d2;
				}

			}
		}
	}

void Date::SwapDate(Date& d1, Date& d2)
{
	swap(d1, d2);
}


int main()
{
	{

		cout << "#################### TASK_1 ####################" << endl << endl;

		unique_ptr<Date> today = make_unique<Date>(19, 12, 2021);

		cout << today->getDay() << "." << today->getMonth() << "." << today->getYear() << endl;

		cout << *today;
		
		unique_ptr<Date> date = move(today);
		bool NotEmpty = (bool)today;
		if (today)
			cout << "ptr today not null" << endl;
		else
			cout << "ptr today is null" << endl;

		bool notEmpty = (bool)date;
		if (date)
			cout << "ptr date not null" << endl;
		else
			cout << "ptr date is null" << endl;

	}
	cout << "#################### TASK_2 ####################" << endl << endl;

	unique_ptr<Date> date1 = make_unique<Date>(6, 6, 1906);
	unique_ptr<Date> date2 = make_unique<Date>(21, 12, 2021);
	cout << "Later date is: ";
	date2->Compare(*date1, *date2);
	cout << "ptr date1: " << *date1;
	cout << "ptr date2: " << *date2;
	date1->SwapDate(*date1, *date2);
	cout << "ptr date1: " << *date1;
	cout << "ptr date2: " << *date2;
	return 0;

}