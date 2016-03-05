#include <iostream>
#include "Device.h"
using  namespace std;

//Construtor default
Device::Device():deviceName("Meu dispositivo"), model("DPT-3000"), numSerie("DPT123456"), 
manufacturer(UNSPECIFIED), fabricationDate(12,4,2005), internalStorage(320.00), externalStorage (0.00), 
powerON(false)
{

}
//Construtor 
Device::Device( const string &devnome, const string &modelo, const int &nserie, const MANUFACTURER &fabricante, 
const Date &data, double interno, double externo, bool estado )
{       
        this->deviceName = devnome;
        this->model = modelo;
        this->numSerie = nserie;
        this->manufacturer = fabricante;
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

//Destrutor 
Device::~Device()
{       
   
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

//Getters
bool Device::getPowerON()
{
    return powerON;
}

string Device::getDeviceName()
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

double Device::getInternalStorage()
{
    return internalStorage;
}

double Device::getExternalStorage()
{
    return externalStorage;
}
//Setters
void Device::setPowerON( bool estado )
{
    if ( !powerON )
    {
        this->powerON = true;
        cout << "Ligando dispositivo...\n"; 
    }
    else
    {
        cout << "Reiniciando dispositivo...\n"; 
        this->powerON = false;
        Sleep(10 * 1000);
        cout << "Dispositivo reiniciado.\n"; 
        this->powerON = true;
    }
}

void Device::setManufacturer( const MANUFACTURER &manu) 
{
    manufacturer = manu;
}

void Device::setModel( const string &modelo)
{
    model = modelo;
}

void Device::setNumSerie( const string &serie )
{
    numSerie = serie;
}

void Device::setFabricationDate( const Date &fData)
{
    fabricationDate = fData;
}

void Device::setInternalStorage( double interno)
{
    internalStorage = interno;
}

void Device::setExternalStorage( double externo)
{
    externalStorage = externo;
}









