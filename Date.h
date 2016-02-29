#ifndef DATA_H
#define	DATA_H

class Date 
{
public:
    
    Data( int = 1, int = 1, int = 1900 );
    
    void print() const;
    
    void setDia( int diaIn ) { dia = verificaDia( diaIn ); }
    void setMes( int mesIn ) { if ( mesIn >= 1 && mesIn <= 12 ) mes = mesIn; }
    void setAno( int anoIn ) { if ( anoIn >= 0 ) ano = anoIn; }
    
    
private:
    
    int mes;
    int dia;
    int ano;
    
    int verificaDia( int ) const;


};

#endif	/* DATA_H */
