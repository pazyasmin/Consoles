#include "Device.h"
#include <iostream>
#include "windows.h" 
using namespace std;

Device::Device(): power(false), manufacturer("Unknown Device")
{
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = 0.00; 
    intStorage = 0.00
    totalStorage = 0.00;
}

Device::Device(const Device &dev)
{  
    power = dev.power;
    manufacturer = dev.manufacturer;
    intStorage = dev.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = dev.extStorage[i];
    totalStorage = dev.totalStorage;
}

Device::~Device()
{       
}

void Device::insertStorageDevice(const float &ee, int p)
{
    if (p > 0 && p <= USB_PORTS)
    {
        if (extStorage[p] != 0.00)
            cout << "\nAction denied. The specified port is currently in use.";
        else
        {
            extStorage[p] = ee;
            cout <<"\nThe storage device is ready for use!";
            refreshTotalStorage();
        }
    }
    else
        cout << "\nAction denied. The specified port does not exist.";
}

void Device::removeStorageDevice(int p)
{
   
    if (p < 1 || p > USB_PORTS)
    {
        if (extStorage[p] != 0.00)
        {
            extStorage[p] = 0.00;
            cout <<"\nThe storage device was successfully removed!";
        }
        else
            cout << "\nAction denied. The specified port was already free.";
    }
    else
        cout << "\nAction denied. The specified port does not exist.";
}

void Device::refreshTotalStorage()
{
    totalStorage = intStorage;
    for (int i = 0; i < USB_PORTS; i++)
    {
        totalStorage += extStorage[i];
    }
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
        for (int i=1; i<=3; i++)
        {
            Sleep (10*2000);
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

void Device::displayDeviceInfo()
{
    cout << "\n\t--- Device Status --- ";
    if (power)
    {
        cout <<"\nThe device is turned on.";
        cout << "\n\t--- Capacity ---";
        cout <<"\nInternal Storage: "<< intStorage << " GBytes.";
        cout <<"\nExternal Storage: ";
            for (int i = 0; i < dev.USB_PORTS; i++)
                cout << "\nPort "<< i << ": "<< extStorage[i] << " GBytes.";
        cout <<"\nTotal Storage: "<< totalStorage << " GBytes.";
    }
    else
        cout <<"\nThe device is turned off.";
}

ostream &operator<<(ostream &out, const Device &dev)
{
    out << "\n\t--- Device Status --- ";
    if (dev.power)
    {
        out <<"\nThe device is turned on.";
        out << "\n\t--- Capacity ---";
        out <<"\nInternal Storage: "<< dev.intStorage << " GBytes.";
        out <<"\nExternal Storage: ";
            for (int i = 0; i < dev.USB_PORTS; i++)
                out << "\nPort "<< i << ": "<< dev.extStorage[i] << " GBytes.";
        out <<"\nTotal Storage: "<< dev.totalStorage << " GBytes.";
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
    totalStorage = dev.totalStorage;
    return;
}

bool Device::operator==(const Device &dev) const{
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
    return true;
}




