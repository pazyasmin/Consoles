#ifndef DATA_H
#define	DATA_H
#include <iostream>
#include <string>

class Date 
{
    friend ostream &operator<<( ostream &, const Date &);
    public:
        static const int monthsPerYear = 12;
        Date(int dia = 1, int mes = 1, int ano = 1999);
        ~Date();
        void setDate( int , int , int );
        Date getDate();
        bool endOfMonth( int ) const;
        static bool leapYear ( int );
        
        Date &operator++();
        Date operator++( int );
        const Date &operator+=( int );
        
    private:
        int month;
        int day;
        int year;
        
        void helpIncrement();
};
#endif	// DATE_H 
