#ifndef DEVICE_H
#define DEVICE_H
#include "Date.h"
#include <iostream>
#include <fstream>
#include <string>
enum MANUFACTURER{ UNSPECIFIED = 0, MICROSOFT = 1, SONY = 2, NINTENDO = 3, SEGA = 4 };

class Device 
{
    friend ostream &operator<<( ostream &, const Device &);
    
    public:
        Device ();
        Device ( const string &, const string &, const int &, const MANUFACTURER &, const Date &, 
        double , double , bool );
        Device(const Device &);
        ~Device();
        MANUFACTURER getManufacturer();
        std::string getDeviceName();
        std::string getModel();
        std::string getNumSerie();
        Date getFabricationDate();
        double getInternalStorage();
        double getExternalStorage();
        void setManufacturer ( const MANUFACTURER & );
        void setDeviceName ( const string & );
        void setNumSerie ( const string & );
        void setFabricationDate ( const Date & );
        void setInternalStorage ( double );
        void setExternalStorage ( double );
        void setPowerON ( bool ); 
    protected:
        bool powerON;
        double internalStorage;
        double externalStorage;
        const static int CONTROLSLOTS = 4;
        MANUFACTURER manufacturer; const 
        std::string deviceName; 
        std::string model; const 
        std::string numSerie; const 
        Date fabricationDate; const
};
#endif // DEVICE_H
