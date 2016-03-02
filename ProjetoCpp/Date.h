#ifndef DATA_H
#define	DATA_H
#include <fstream>
//
class Date 
{
    public:
    
        Date( int = 1, int = 1, int = 1900 );
        friend ostream &operator<<( ostream &, const Date &);
        void displayDate() const;
        
        void setDay( int dia ) { day = verifyDay( dia ); }
        void setMonth( int mes ) { if ( mes >= 1 && mes <= 12 ) mes = mes; }
        void setYear( int ano ) { if ( ano >= 0 ) ano = ano; }
        
    
    private:
    
        int month;
        int day;
        int year;
        
        int verifiedDay( int ) const;



};

#endif	/* DATA_H */
