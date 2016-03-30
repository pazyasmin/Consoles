#include "Date.h"
#include <stdlib.h>
#include <ctime>
using  namespace std;

Date::Date()
: day(1), month(1), year(1900), hour (0), min (0)
{
    
}

Date::Date(int day, int month, int year)
:hour(0), min(0)
{
	day = day; 
	month = month;
	year = year;
}
Date::~Date()
{
    
}

int Date::validateDay( int day ) const
{
	static const int daysPerMounth[13] = {0, 31, 28, 31, 30, 30, 31, 31, 30, 31, 30, 31};
	if(day > 0 && day <= daysPerMounth[month])
		return day;
		
	if(month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ) ) 
		return day;
		
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

void Date::displayDate()
{
    cout << day << "/" << month << "/" << year <<"\n";
    cout << hour <<":" << min << endl;
}

ostream &operator<<( ostream &output, const Date &data )
{
 static string monthName[ 13 ] = { "", "January", "February",
 "March", "April", "May", "June", "July", "August",
 "September", "October", "November", "December" };
    output << monthName[ data.month ] << ' ' << data.day << ", " << data.year;
    return output; 
}