#include "Console.h"
#include "Xbox360.h"
#include <iostream>
#include <time.h>
using namespace std;

//Construtor
Console::Console(): numControls (0), numGames(0), usedStorage (0), platform(UNSPECIFIED)
{
    powerON = false;
}
/*
Console::Console ( const Console &, const Date &, const Xbox360 &);
{
}*/
Console::Console( const MANUFACTURER &m, const PLATFORM &p, const string &s, const Date dt, double maximo,  double usado, int ncontroles, int njogos, bool estado )
{       
        this->manufacturer = m;
        this->platform = p;
        this->numSerie = s;
        this->fabricationDate = dt;
        this->maxStorage = maximo;
        this->usedSpace = usado;
        this->numControls = ncontroles;
        this->numGames = njogos;
        this->powerON = estado;
}   
//Construtor Cópia
Console::Console( const Console &c )
{  
        this->manufacturer = c.manufacturer;
        this->numSerie = c.numSerie;
        this->platform = c.platform;
        this->numSerie = c.numSerie;
        this->fabricationDate = c.fabricationDate;
        this->maxStorage = c.maxStorage;
        this->usedSpace = c.usedStorage;
        this->numControls = c.numControls;
        this->numGames = c.numGames;
        this->powerON = c.powerON;
}

//Destrutor
Console::~Console()
{       
    delete [] allGames;
}

void Console::allocate( const int &njogos)
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

bool Console::getPowerON()
{
    return powerON;
}

double Console::getUsedSpace()
{
    return usedStorage;
}

double Console::getUsedStorage()
{
    
}

//Setters

void Console::setPlatform( PLATFORM &f) 
{
    platform = f;
}


void Console::setNumSerie( string &s )
{
    numSerie = s;
}

void Console::setFDate( Date &d)
{
    fabricationDate = d;
}

void Console::setMaxStorage( double &max)
{
    maxStorage = max;
}

void Console::setUsedStorage( double &usado)
{
    usedStorage = usado;
}

void Console::getPowerON( bool estado)
{
    powerON = estado;
}

void insertControl( )
{
    
    
}

void ejectControl ( )
{
    
    
}







