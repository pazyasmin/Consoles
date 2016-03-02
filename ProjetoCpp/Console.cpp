#include "Console.h"
#include <iostream>
#include <time.h>
using namespace std;
//Construtor default...
Console::Console(): numControls (0), numGames(0), usedStorage (0), platform(UNSPECIFIED)
{
    allocDyn(njogos); 
}

Console::Console( const PLATFORM &p, double maximo,  double usado, int ncontroles, int njogos, bool estado )
{       
        this->platform = p;
        this->maxStorage = maximo;
        this->usedSpace = usado;
        this->numControls = ncontroles;
        this->numGames = njogos;
        this->allocDyn(njogos);
}   
//Construtor Cópia
Console::Console( const Console &c )
{  
        
        this->platform = c.platform;
        this->maxStorage = c.maxStorage;
        this->usedSpace = c.usedStorage;
        this->numControls = c.numControls;
        this->numGames = c.numGames;
        this->allocDyn(c.numGames);
}

//Destrutor
Console::~Console()
{       
    delete [] allGames;
}

void Console::allocDyn(const int njogos)
{
    if ( njogos > 0)
    {   
        allGames = new string [njogos];
        numGames = njogos;
        cout <<"\nNumero de jogos instalados: "<<numGames;
        int i;
        for ( i = 0 ; i <= numGames ; i++)
        {
            cout <<"\n"<< allGames[i];
        }
    }
    else
    {
        allGames = 0;
        numGames = 0;
        cout <<"\nNenhum jogo instalado.";
    }
}

ostream &operator<<( ostream &output, const Console &con)
{
    output << "\nPlataforma: " << con.platform << "\nData de lancamento: " << con.releaseDate
    << "\nData da ultima atualizacao: " << con.whenLastUpdate << "Atualizacao: " << con.whenLastUpdate
    << "\nArmazenamento: " << con.totalStorage << "\nEspaco usado: " << con.usedStorage << "\nNumero de jogos instalados"
    << con.numGames << "\nNumero de controles conectados: " << con.numControls;
}


//Getters
PLATFORM Console::getPlatform()
{
    return platform;
}

double Console::getTotalStorage()
{
    return totalStorage;
}

double Console::getUsedStorage()
{
    return usedStorage;
}

int Console::getNumGames()
{
    return numGames;
}

int Console::getNumControls()
{
    return numControls;
}
//Setters

void Console::setUsedStorage( double usado )
{
    usedStorage = usado;
}

void Console::setNumGames( int njogos )
{
    numGames = njogos;
}

void Console::setNumControls( int ncontroles )
{
    numControls = ncontroles;
}        


void insertControl( )
{
    
    //Falta implementar classe controle 
}

void ejectControl ( )
{
    //Falta implementar classe controle
    
}







