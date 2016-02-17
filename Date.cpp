#include "Date.h"
#include <iostream>

using std::cout;

int Date:: checkDate (int day) const
{
    static const int diasPorMes [ 13 ] = [ 0, 31, 28, 31, 30, 30, 31, 31, 30, 31, 30, 31 ];
    
    if (day >  0 && day <= diasPorMes [ month ] )
        return dia;
        
    if ( month == 2 && //Fevereiro: testa se é bissexto
            day == 29 && ( year % 400 == 0 || ( year % 4 && year % 100 != 0) ) )
    return day;
    
    cout << "Dia invalido.\n";
    
    return 1;
}
