#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
typedef enum { UNKNOWN , XBOXONE, XBOX360 , PLAYSTATION3 , PLAYSTATION4 , WII , WIIU , MEGADRIVE } PLATFORM;

class Console : public Device
{
    //Overload de operadores
    friend ostream &operator<<( ostream &, const Console & );
    friend istream &operator>>( istream &, Console & );
    
    public:
        Console(); //Construtor vazio
        Console( const string & , const PLATFORM &, const Date &, const string &, const Date &, double , double, int , int ); //Construtor 
        Console (); //
        Console(const Console &);//Construtor de cópia
        ~Console();//Destrutor
        PLATFORM getPlatform();
        std::string getConsoleName();
        Date getReleaseDate();
        std::string getLastUpdate();
        Date getWhenLastUpdate();
        double getTotalStorage();
        double getUsedStorage();
        int getNumGames() const ;
        int getNumControls() const ;
        void setConsoleName( const string & );
        void setReleaseDate ( Date );
        void setLastUpdate ( string );
        void setWhenLastUpdate ( Date );
        void setUsedStorage( double );
        void setNumGames( int );
        void setNumControls( int );
        void installGame ( const string & );
        void displayGames() const;
        void insertControl();
        void ejectControl();
        void alocacaoDinamica( int );
        //Overload de Operadores
        const Console &operator=( const Console &); //Atribuição
        bool operator== ( const Console &) const; //Igualdade
        bool operator!=( const Console &direita ) const //Desigualdade
        {
            return !( *this == direita );
        }
        int &operator[] (int);
        int operator[] ( int ) const; //
        
    private:     
        std::string consoleName;
        PLATFORM platform; 
        Date releaseDate;
        std::string lastUpdate;
        Date whenLastUpdate; 
        double totalStorage;
        double usedStorage;
        int numGames;
        int numControls; 
        std::string *allGames; 
        const static int MAXUSERS = 10;
};
#endif // CONSOLE_H
