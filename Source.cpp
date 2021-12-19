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
	Date() {}

	int day(int d)
	{
		return m_day;
	}

	int month(int m)
	{
		return m_month;
	}
	
	int year(int y)
	{
		return m_year;
	}
	friend ostream& operator<<(ostream& out, const Date& oDate);
};

ostream& operator<<(ostream& out, const Date& oDate)
{
	out << &oDate.m_day << endl;
	out << &oDate.m_month << endl;
	out << &oDate.m_year << endl;
	return out;
}

int main()
{
	cout << "#################### TASK_1 ####################" << endl << endl;

	Date today;
	cout << today.day(25);

	return 0;
}