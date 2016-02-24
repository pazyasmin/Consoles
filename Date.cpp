#include<iostream>
#include "Date.h"

using namespace std;

Date::Date( int dia, int mes, int ano )
{
        this->day = checkDay(dia, mes, ano);
        if ( ano < 0)
        {
            cout << "\nAno invalido!\n";
            this->year = 1900;
            
        }
        else   
            this->year = ano;
        if ( mes > 0 && mes <= 12 )
            this->month = mes;
        else   
        {
            cout << "\nMes invalido!\n";
            this->month = 1;
        }
}

Date::Date(const Date &outra)
{
    this->day = outra.day;
    this->month = outra.month;
    this->year = outra.year;
}

Date::~Date()
{
    
}

int Date::checkDay(int dia, int mes, int ano) const
{
    static const int daysPerMonth [ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (dia > 0 && dia <= daysPerMonth[this->month])
        return dia;
    if (this->month == 2 && dia == 29 && (this->year%400==0 || (this->year%4 == 0 && this->year %100 != 0)))
        return dia;
    
     return 1;
 
}
void Date::displayDate() const
{
    cout<<"\n"<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
}

