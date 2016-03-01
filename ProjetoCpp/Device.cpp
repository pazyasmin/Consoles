#include "Device.h"
#include <iostream>
#include <time.h>
using namespace std;

//Construtor default
Device::Device(): deviceName("Desconhecido"), model("Desconhecido"), numSerie(0), fabricationDate(0,0,0), 
internalStorage(320.00), externalStorage (0.00)
{
    powerON = false;
    manufacturer = UNSPECIFIED;
}
//Construtor 
Device::Device( const string &devnome, const string &modelo, const int &nserie, const MANUFACTURER &manuf, const Date &data, 
const double interno, const double externo, const bool estado )
{       
        this->deviceName = devnome;
        this->model = modelo;
        this->numSerie = nserie;
        this->manufacturer = manufac;
        this->fabricationDate = data;
        this->internalStorage = interno;
        this->externalStorage = externo;
        this->powerON = estado;
}   
//Construtor Cópia
Device::Device( const Device &c )
{  
        deviceName = c.deviceName;
        model = c.model;
        numSerie = c.numSerie;
        manufacturer = c.manufacturer;
        fabricationDate = c.fabricationDate;
        internalStorage = c.internalStorage;
        externalStorage = c.externalStorage;
        powerON = c.powerON;
}

//Destrutor com desalocador
Console::~Console()
{       
    delete [] allGames;
}

//Operador <<
ostream &operator<<( ostream &output, const Device &dev)
{
    output << "\nNome: " << dev.deviceName << "\nModelo: " << dev.model 
        << "\nNumero de serie: " << dev.numSerie << "\nFabricante: " << dev.manufacturer 
        << "\nModelo"<< dev.model <<"\nSerie: " << dev.numSerie 
        << "\nData de Fabrica: " << dev.fabricationDate
        << "\nArmazenamento interno: " << dev.internalStorage
        << "\nArmazenamento externo: " << dev.externalStorage
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
bool Device::getPowerON()
{
    return powerON;
}

string Device::setDeviceName() 
{
    return deviceName;
}

MANUFACTURER Device::getManufacturer() 
{
    return manufacturer;
}

string Device::getNumSerie()
{
    return numSerie;
}

Date Device::getFabricationDate()
{
    return fabricationDate;
}

double Device::getMaxStorage()
{
    return maxStorage;
}


bool Device::getPowerON()
{
    return powerON;
}

//Setters
void Device::setPowerON()
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
        cout << "CDeviceonsole reiniciado.\n"; //O console é resetado
        this->powerON = true;
    }
}

void Device::setDeviceName( const string &nome)
{
    deviceName = nome;
}

void Device::setManufacturer( const MANUFACTURER &manu) 
{
    manufacturer = manu;
}

void Device::setModel( const string &modelo)
{
    model = modelo;
}

void Device::setNumSerie( string &s )
{
    numSerie = s;
}

void Device::setFabricationDate( Date &data)
{
    fabricationDate = data;
}

void Device::setMaxStorage( double &espaco)
{
    maxStorage = espaco;
}









