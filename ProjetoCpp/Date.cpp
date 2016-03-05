#include <iostream>
#include "Date.h"
using  namespace std;
//

Date::Date( int dia, int mes, int ano ) 
{
    setDate ( dia , mes, ano ); 
}

Date::~Date()
{
    
}
void Date::setDate(int dia, int mes, int ano )
{
    if ( mes > 0 && mes <= monthsPerYear ) 
        month = mes;
    else
        cout << "\nMes invalido ("<< mes << ")";
    if ( ano >= 1900  && ano <= 2100 )
        year = ano;
    else
    {
        cout << "\nAno invalido ("<< ano << ")";
        year = 1900;
    }
    
    static const int daysPerMonth[ monthsPerYear + 1] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (( month == 2 && leapYear( ano ) && dia >= 1 && dia <= 29 ) || (dia >=1 && dia <= daysPerMonth [ month ] ) )
        day = dia;    
    else 
        cout << "Dia invalido (" << dia << ")";
}

Date Date::getDate()
{
   return ( day , month, year );
}

bool Date::leapYear( int anoTeste)
{
    if ( anoTeste % 400 == 0) || (anoTeste % 100 != 0 && anoTeste % 4 == 0)
        return true; 
    else
        return false;    
}

bool Date::endOfMonth ( int diaTeste ) const 
{
    if ( month == 2 && leapYear( ano ) )
        return diaTeste == 29;
    else 
        return diaTeste == daysPerMonth[ month ];
}
//Overload de Operadores
Date &Date::operator++()
{
    helpIncrement();
    return *this; 
} 

Date Date::operator++( int )
{
    Date temp = *this; 
    helpIncrement();
    return temp; 
}

const Date &Date::operator+=( int maisUmDia )
{
    for ( int i = 0; i < maisUmDia; ++i )
    helpIncrement();
    return *this; 
} 

void Date::helpIncrement()
{
    if ( !endOfMonth( day ) )
        ++day; 
    else
        if ( month < 12 ) // day is end of month and month < 12
        {
            ++month; 
            day = 1;
        }
        else 
        {
            ++year; 
            month = 1;
            day = 1;
        }
} 

ostream &operator<<( ostream &output, const Date &d )
{
 static string monthName[ 13 ] = { "", "Janeiro", "Fevereiro",
 "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto",
 "Setembro", "Outubro", "Novembro", "Dezembro" };
    output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
    return output; 
}