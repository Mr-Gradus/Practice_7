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
	Date (int day, int month, int year) : m_day(day), m_month(month), m_year(year) 
	{
		cout << "ctor" << endl;
	}

	~Date()
	{
		cout << "DESTRUCOR" << endl;
	}

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
	friend ostream& operator<<(ostream& out, const Date& oDate);

	void print()
	{
		cout << "today!!!" << endl;
	}

};

ostream& operator<<(ostream& out, const Date& oDate)
{
	out << oDate.m_day << "." << oDate.m_month << "." << oDate.m_year << endl;
	return out;
}



int main()
{
	cout << "#################### TASK_1 ####################" << endl << endl;

	unique_ptr<Date> today = make_unique<Date>(19, 12, 2021);
	
	cout << today->getDay() << "." << today->getMonth() << "." << today->getYear() << endl;
	
	cout << *today;
	
	
	unique_ptr<Date> date = move(today);
	bool NotEmpty = (bool)today;
	//cout << boolalpha << NotEmpty << endl;
	if (today)
		cout << "ptr today not null" << endl;
	else
		cout << "ptr today is null" << endl;
	

	bool notEmpty = (bool)date;
	if (date)
		cout << "ptr date not null" << endl;
	else
		cout << "ptr date is null" << endl;
	return 0;

}