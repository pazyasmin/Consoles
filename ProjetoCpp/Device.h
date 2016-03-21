#include <string>
#include <ostream>
#include <vector>

using std::ostream;

#ifndef DEVICE_H
#define DEVICE_H

class Device
{
    friend ostream &operator<<(ostream &, const Device &);
    
    public: 
        Device();
        Device(const Device &);
        ~Device();
        void insStorageDevice(const float &, int);
        void remStorageDevice(int);
        float calcAvailableStorage();
        void power_ON();
        void power_OFF();
        const Device & operator=(const Device &);
    private:
        const static int MAXUSBPORTS = 2;
    protected:
        bool power;
        float intStorage;
        float extStorage[MAXUSBPORTS]; //Aqui, trata-se do armazenamento TOTAL do drive e não o espaço usado ou disponível.
        float availableStorage;
};

#endif // DEVICE_H


