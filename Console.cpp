#include "Console.h"
#include "Xbox360.h"
#include <iostream>
#include <time.h>
using namespace std;

//Construtor
Console::Console():fabricationDate(1,1,2000) 
{
    powerON = false;
    manufacturer = 0;
    platform = 0; 
    numSerie = "00000";
    storage[2] = {320, 0};
    numGames = 0;
    numControls = 0; 
    allGames = 0;
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

MANUFACTURER Console::getManufacturer() 
{
    return manufacturer;
}
PLATFORM Console::getPlatform() 
{
    return platform;
}

string Console::getNumSerie()
{
    return numSerie;
}

Date Console::getFDate()
{
    return fabricationDate;
}

double Console::getMaxStorage()
{
    return maxStorage;
}


double Console::getUsedSpace()
{
    return usedStorage;
}

        double getUsedStorage();
        bool getPowerON();

//Setters

void Console::setPowerON()
{
    if ( !getPowerON() )
    {
        this->powerON = true;
        cout << "Ligando console...\n"; //O console é ligado
    }
    else
    {
        cout << "Reiniciando console...\n"; //O console é resetado
        this->powerON = false;
        Sleep(10 * 1000);
        cout << "Console reiniciado.\n"; //O console é resetado
        this->powerON = true;
    }
}


void Console::setManufacturer( MANUFACTURER &m) 
{
    manufacturer = m;
}

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







