#include "Date.h"
#include <iostream>
using std::cout;

Date::Date(int d, int m, int a) 
{
    if ( m > 0 && m <= 12 ) 
        month = m;
    
    if ( a < 0 )
        year = 1900;
    else
        year = a;
   
    day = verifyDay(d);

}

void Date::displayDate() const
{
   cout << month << '/' << day << '/' << year;
   
}

int Date::verifiedDay(int diaTeste) const
{
    static const int daysPerMonth[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( diaTeste > 0 && diaTeste <= daysPerMonth[ month ] )
        return diaTeste;
    
    if ( month == 2 && diaTeste == 29 && ( year % 400 == 0 ||
            ( year % 4 == 0 && year % 100 != 0 ) ) )
        return diaTeste;
    
    cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
    return 1; 

    
}
