#include "Device.h"
#include <iostream>
#include "windows.h" 

using namespace std;

Device::Device()
:power(false), manufacturer(" "), intStorage(0.00), ethernetCard(false)
{
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = 0;
}

Device::Device(const Device &dev) 
{  
    power = dev.power;
    manufacturer = dev.manufacturer;
    intStorage = dev.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = dev.extStorage[i];
    ethernetCard = dev.ethernetCard;
}

Device::~Device() 
{
       
}

void Device::insertStorageDevice(const float &ext, int p)
{
    if (p < 0 || p >= USB_PORTS)
    {
     cout << "\nAction denied. The specified port does not exist.";
        return;
    }   
    
    if (extStorage[p] != 0.00)
    {
        cout << "\nAction denied. The specified port is currently in use.";
    }
    else
    {
        extStorage[p] = 1.00;
        cout <<"\nThe storage device is ready for use.";
    }
}

void Device::removeStorageDevice(int p)
{
   
    if (p < 0 || p >= USB_PORTS)
    {
        cout << "\nAction denied. The specified port does not exist.";
        return;
    }      
        
    if (extStorage[p] != 0.00)
    {
        extStorage[p] = 0.00;
        cout <<"\nThe storage device was successfully removed!";
    }
    else
        cout << "\nAction denied. The specified port is already free.";
}

void Device::deviceInfo() const
{
    cout << "\n\t-Device Status-";
    if (power)
    {
        cout <<"\nThe device is turned on ";
        cout << "\n\t-Capacity-";
        cout <<"\nInternal Storage: "<< intStorage << " GB ";
        cout <<"\nExternal Storage: ";
            for (int i = 0; i < USB_PORTS; i++)
                cout << "\nPort "<< i << ": "<< extStorage[i] << " GB ";
    }
    else
        cout <<"\nThe device is turned off";
}

ostream &operator<<(ostream &out, const Device &dev)
{
    out << "\n\t-Device Status-";
    if (dev.power)
    {
        out <<"\nThe device is turned on ";
        out << "\n\t-Capacity-";
        out <<"\nInternal Storage: "<< dev.intStorage << " GB ";
        out <<"\nExternal Storage: ";
        for (int i = 0; i < dev.USB_PORTS; i++)
            out << "\nPort "<< i << ": "<< dev.extStorage[i] << " GB ";
        
        if (dev.ethernetCard)
            cout <<"\nEthernet card: yes ";
        else
            cout <<"\nEthernet card: no ";
    }
    else
        out <<"\nThe device is turned off ";
    return out;
}

const Device& Device::operator=(const Device &dev)
{
    power = dev.power;
    manufacturer = dev.manufacturer;
    intStorage = dev.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = dev.extStorage[i];
    ethernetCard = dev.ethernetCard;
}

bool Device::operator==(const Device &dev) const
{
    if(power != dev.power)
        return false;
    if(manufacturer != dev.manufacturer)
        return false;
    if(intStorage != dev.intStorage)
        return false;
    for (int i = 0; i < USB_PORTS; i++)
    {
        if(extStorage[i] != dev.extStorage[i])
            return false;
    }
    if (ethernetCard != dev.ethernetCard)
        return false;
        
    return true;
}