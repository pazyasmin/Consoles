#include "Device.h"
#include <iostream>
#include "windows.h" 

using namespace std;

Device::Device(): power(false), intStorage(0.00)
{
    for (int i = MAXUSBPORTS; i > 0; i--)
        extStorage[MAXUSBPORTS] = 0.00; 
}

Device::Device(const Device &myDevice)
{  
    power = myDevice.power;
    intStorage = myDevice.intStorage;
    for (int i = MAXUSBPORTS; i > 0; i--)
        extStorage[i] = myDevice.extStorage[i];
}

Device::~Device()
{       

}

ostream &operator<<(ostream &out, const Device &myDevice)
{
    out <<"\tInformacoes de Dispositivo:\n\n";
    if (myDevice.power)
    {
        out <<"Armazenamento interno: "<< myDevice.intStorage << " GB.\n";
        for (int i = myDevice.MAXUSBPORTS; i > 0; i--)
            out <<"Armazenamento externo: \nPorta "<< i << " = "<< myDevice.extStorage[i] << " GBytes.\n";
    }
    else
        out <<"Dispositivo desligado.\n";
    return out;
}

void Device::insStorageDevice(const float &ext, int porta)
{
    cout <<"\nInserindo dispositivo de armazenamento...\n\n";
    if (porta >= 0 && porta < MAXUSBPORTS)
    {
    
        if (extStorage[porta] != 0)
            cout << "Acao negada. A porta especificada esta em uso.\n";
        else
        {
            extStorage[porta] = ext;
            cout <<"Seu dispositivo de armazenamento esta pronto para uso!\n";
        }
    }
    else
    cout << "Acao negada. A porta especificada eh inexistente.\n";
}


void Device::remStorageDevice(int porta)
{
    cout <<"\nRemovendo dispositivo de armazenamento [porta "<< porta <<"]...\n\n";
    if (porta < 0 || porta > MAXUSBPORTS)
    {
    
        if (extStorage[porta] != 0.00)
        {
            extStorage[porta] = 0.00;
            cout <<"O dispositivo foi removido com sucesso!\n";
        }
        else
            cout << "Acao negada. A porta ja esta livre.\n";
    }
    else
        cout << "Acao negada. A porta especificada eh inexistente.\n";
}

float Device::calcAvailableStorage()
{
    availableStorage = intStorage;
    for (int i=MAXUSBPORTS; i>0; i--)
    {
        availableStorage += extStorage[i];
    }
    return availableStorage;
}

void Device::power_ON()
{
    if (!power)
    {
        power = true;
        cout << "\nLigando dispositivo...\n"; 
    }
    else
    {
        cout << "\nReiniciando dispositivo...\n"; 
        power = false;
        Sleep(10 * 1000);
        power = true;
        cout << "Dispositivo reiniciado.\n"; 
        power = true;
    }
}










