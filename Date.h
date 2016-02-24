#ifndef DATE_H
#define DATE_H

class Date 
{
    public: 
        Date ( int = 1 , int = 1 , int = 1900 ); //Construtor default com data de lançamento
        Date(const Date &);
        ~Date ();
        
        void displayDate() const; //Imprime data em formato dia/mês/ano
        
    private:
        int month; 
        int day;
        int year; 
        static int daysPerMonth[];
        int checkDay ( int , int , int ) const; 
};
#endif //DATE_H