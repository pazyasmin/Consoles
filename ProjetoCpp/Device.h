#ifndef DEVICE_H
#define DEVICE_H
#include <string>
#include <fstream>
#include "Date.h"
//Pré-definições plataforma
enum MANUFACTURER{ UNSPECIFIED = 0, MICROSOFT = 1, SONY = 2, NINTENDO = 3, SEGA = 4 };

class Device
{
    public:
        Device ();
        Device ( const string &, const string &, const int &, const MANUFACTURER &, const Date &);
        friend ostream &operator<<( ostream &, const Device &);
       
        std::string getDeviceName();
        std::string getModel();
        std::string getNumSerie();
        MANUFACTURER getManufacturer();
        Date setFabricationDate();
        double getInternalStorage();
        double getExternalStorage();
        void setDeviceName( const string & );
        void setModel ( const string & );
        void setNumSerie ( const string & );
        void setManufacturer ( const MANUFACTURER & );
        void setFabricationDate ( const Date & );
        void setInternalStorage ( const double &);
        void setExternalStorage ( const double &);
        void setPowerON ( bool ); 
        bool getPowerON();

                
    protected:
        std::string deviceName;
        std::string model;
        int numSerie;
        MANUFACTURER manufacturer;
        Date fabricationDate; 
        bool powerON;
                
    private:
        double internalStorage;
        double externalStorage;
        const static int CONTROLSLOTS = 4;

};
#endif // DEVICE_H
