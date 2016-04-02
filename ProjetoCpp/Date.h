#ifndef DATA_H
#define	DATA_H
#include <iostream>
#include <ostream>
using std::ostream;

class Date 
{
    friend ostream &operator<<( ostream &, const Date &);
    public:
        static const int monthsPerYear = 12;
        Date(int, int, int );
        Date();
        ~Date();
        int validateDay(int, int, int) const;
        int validateMonth(int) const;
        int validateYear(int) const;
        void timeNow();
        void displayDate();
    private:
        int day;
        int month;
        int year;
        int hour;
        int min;
        
};
#endif	// DATE_H 
