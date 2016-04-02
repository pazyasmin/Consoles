#include "Date.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using  namespace std;

Date::Date()
{
    day = 1; month = 1; year = 1900; hour = 0; min = 0;
}

Date::Date(int d, int m, int y)
:hour(0), min(0)
{
	day = validateDay(d, m, y); 
    month = m;
	year = y;
}
Date::~Date()
{
    
}

int Date::validateDay( int d , int m , int y) const
{
    static const int daysPerMounth[13] = {0, 31, 28, 31, 30, 30, 31, 31, 30, 31, 30, 31};

    if(d > 0 && d <= daysPerMounth[m])
		return d;
		
	if(m == 2 && d == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0) ) ) 
		return d;
		
	cout << "\nThe specified day is invalid.";
	return 1;
}

void Date::timeNow() 
{
    time_t now = time(0);
    tm *pt = localtime(&now);   
    day = pt->tm_mday;
    month = pt->tm_mon+1;
    year = pt->tm_year+1900;
    hour = pt->tm_hour;
    min = pt->tm_min;
}

void Date::displayDate() const
{
    cout << day << "/" << month << "/" << year <<"\n";
    cout << hour <<":" << min << endl;
}

ostream &operator<<(ostream &out, const Date &d)
{
    out << d.day << "/" << d.month << "/" << d.year <<"\n";
    out << d.hour <<":" << d.min << endl;
    return out;
}
