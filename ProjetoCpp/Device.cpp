#include "Device.h"
#include <iostream>
#include "windows.h" 
using namespace std;

Device::Device()
:power(false), manufacturer("Unknown"), intStorage(0.00) 
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
}

Device::~Device() 
{
       
}

void Device::insertStorageDevice(const float &a, int b)
{
    if (b >= 0 && b < USB_PORTS)
    {
        if (extStorage[b] != 0.00)
            cout << "\nAction denied. The specified port is currently in use.";
        else
        {
            extStorage[b] = a;
            cout <<"\nThe storage device is ready for use!";
        }
    }
    else
        cout << "\nError. The specified port does not exist.";
}

void Device::removeStorageDevice(int b)
{
   
    if (b >= 0 && b < USB_PORTS)
    {
        if (extStorage[b] != 0.00)
        {
            extStorage[b] = 0.00;
            cout <<"\nThe storage device was successfully removed!";
        }
        else
            cout << "\nError. The specified port was already free.";
    }
    else
        cout << "\nError. The specified port does not exist.";
}

void Device::power_ON()
{
    if (!power)
    {
        power = true;
        cout << "\nThe device has been turned on."; 
    }
    else
    {
        cout << "\nThe device is already turned on.\nRestarting"; 
        power = false;
        for (int i=0; i<3; i++)
        {
            Sleep (5*1000);
            cout << ".";
        }
        power = true;
        cout << "\nThe device has been restarted."; 
    }
}

void Device::power_OFF()
{
    if (power)
    {
        power = false;
        cout << "\nThe device has been turned off."; 
    }
    else
        cout << "\nThe device is already turned off."; 
}

void Device::deviceInfo() const
{
    cout << "\n\t___* Device Status *___ ";
    if (power)
    {
        cout <<"\nThe device is turned on.";
        cout << "\n\t--- Capacity ---";
        cout <<"\nInternal Storage: "<< intStorage << " GBytes.";
        cout <<"\nExternal Storage: ";
            for (int i = 0; i < USB_PORTS; i++)
                cout << "\nPort "<< i << ": "<< extStorage[i] << " GBytes.";
    }
    else
        cout <<"\nThe device is turned off.";
}

ostream &operator<<(ostream &out, const Device &dev)
{
        out << "\n\t___* Device Status *___ ";
    if (dev.power)
    {
        out <<"\nThe device is turned on.";
        out << "\n\t--- Capacity ---";
        out <<"\nInternal Storage: "<< dev.intStorage << " GBytes.";
        out <<"\nExternal Storage: ";
        for (int i = 0; i < dev.USB_PORTS; i++)
            out << "\nPort "<< i << ": "<< dev.extStorage[i] << " GBytes.";
    }
    else
        out <<"\nThe device is turned off.";
    return out;
}

const Device& Device::operator=(const Device &dev)
{
    power = dev.power;
    manufacturer = dev.manufacturer;
    intStorage = dev.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = dev.extStorage[i];
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




