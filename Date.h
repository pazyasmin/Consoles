#ifndef DATE_H
#define DATE_H

class DATE_H

{
    public:
        Date ( int = 1, int = 1, int = 1900 );
        void printf () const; 
        ~Date ();
    private: 
        int month;
        int day;
        int year;
        
        int checkDate ( int ) const; 
};

#endif