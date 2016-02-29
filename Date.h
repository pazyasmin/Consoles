#ifndef DATA_H
#define	DATA_H

class Date 
{
public:
    
    Date( int = 1, int = 1, int = 1900 );
    
    void print() const;
    
    void setDay( int dia ) { day = verifyDay( dia ); }
    void setMonth( int mes ) { if ( mes >= 1 && mes <= 12 ) mes = mes; }
    void setYear( int ano ) { if ( ano >= 0 ) ano = ano; }
    
    
private:
    
    int month;
    int day;
    int year;
    
    int verifyDay( int ) const;


};

#endif	/* DATA_H */
