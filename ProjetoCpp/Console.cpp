#include "Console.h"
#include "Xbox360.h"
#include <iostream>
#include <time.h>
using namespace std;

//Construtor default
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
    
    
}

void ejectControl ( )
{
    
    
}







