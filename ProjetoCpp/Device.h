#include <string>
#include <ostream>
using std::ostream;
using std::string;

#ifndef DEVICE_H
#define DEVICE_H

class Device
{
    friend ostream &operator<<(ostream &, const Device &);
    
    public: 
        Device();
        Device(const Device &);
        ~Device();
        void refreshTotalStorage();
        void insertStorageDevice(const float &, int);
        void removeStorageDevice(int);
        void displayDeviceInfo() const;
        void power_ON();
        void power_OFF();
        
        const Device &operator=(const Device &);
        bool operator==(const Device &) const;
    
    protected:
        const static int USB_PORTS = 2;
        bool power;
        string manufacturer;
        float intStorage;
        float extStorage[USB_PORTS]; 
        float totalStorage;

};

#endif // DEVICE_H


