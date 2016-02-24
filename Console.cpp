#include "Console.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Date.h"
#include "Xbox360.h"
using namespace std;

using std::cout;
using std::cin;
using std::string;
using std::getline;


//Construtor

Console::Console( bool estado, const Manufac &fabricante,  const Date &data, const string &serie ) 
{       
        this->powerON = estado;
        this->usedSpace = 0;
        this->freeSpace = CAPACITY;
        this->manufacturer = fabricante;
        this->numSerie = serie;
        this->fabricationDate = data;
            for (int i = 0; i < MAXCONTROLS; i++)
            {
                allControls[i] = false;
            }
        allocate(this->numGames);
    
}   
//Construtor Cópia
Console::Console( const Console &c )
{
    this->powerON = c.powerON;
    this->manufacturer = c.manufacturer;
    this->numSerie = c.numSerie;
    this->fabricationDate = c.fabricationDate;
    for (int i = 0; i < MAXCONTROLS; i++)
    {
        allControls[i] = c.allControls[i];
    }
    this->usedSpace = c.usedSpace;
    this->freeSpace = c.freeSpace;
    this->numGames = c.numGames;
    this->gameList = c.gameList;
}

Console::Console()
{
    this->powerON = true;
    this->manufacturer = Unspecified;
    this->numSerie = "000000";
    Date date;
    this->fabricationDate = date;
    for (int i = 0; i < MAXCONTROLS; i++)
    {
        allControls[i] = false;
    }
    this->usedSpace = 0;
    this->freeSpace = CAPACITY;
    this->gameList = 0;
    this->numGames = 0;
}

Console::Console(const Console &, const Xbox360 &)
{
    
}
//Destrutor
Console::~Console()
{       
    delete [] gameList;
}

void Console::allocate( const int &njogos)
{
    if ( njogos > 0)
    {
        gameList = new string [njogos];
        numGames = njogos;
        cout <<"\nNumero de jogos instalados: "<<numGames;
        int i;
        for ( i = 0 ; i <= numGames ; i++)
        {
            cout <<"\n"<< gameList[i];
        }
    }
    else
    {
        gameList = 0;
        numGames = 0;
        cout <<"\nNenhum jogo instalado.";
    }
}

void Console::powerONOFF()
{
    if ( !getPowerON() )
    {
        this->powerON = true;
        cout << "Ligando console...\n"; //O console é ligado
    }
    else
    {
        cout << "Reiniciando console...\n"; //O console é resetado
        Sleep(10 * 1000);
        this->powerON = false;
        cout << "Console reiniciado.\n"; //O console é resetado
        this->powerON = true;
    }
}

bool Console::getPowerON()
{
    return powerON;
}

Manufac Console::getManufacturer() 
{
    return this->manufacturer;
}

string Console::getNumSerie( )
{
    return this->numSerie;
}

Date Console::getFabricationDate( )
{
    return this->fabricationDate;
}

float Console::getFreeSpace()
{
   return freeSpace;
}

float Console::getUsedSpace()
{
   return usedSpace;
}
    

void Console::installGame( string nomejogo)
{
    if( this->getFreeSpace() > 10.00 )
    {
        freeSpace -= 10.00; 
        usedSpace += 10.00;
        gameList[this->numGames] = nomejogo;
        cout << "O jogo foi instalado com sucesso!\n"
             << "Armazenamento livre: " << freeSpace << " GB \n";

    }
    else
         cout << "Espaco insuficiente!\n";
}









