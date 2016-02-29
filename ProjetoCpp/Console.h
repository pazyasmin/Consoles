#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include "Date.h"
#include "Xbox360.h"

//Pré-definições de fabricante e plataforma
enum MANUFACTURER { UNSPECIFIED = 0, MICROSOFT = 1, SONY = 2, NINTENDO = 3, SEGA = 4 };
enum PLATFORM { UNSPECIFIED = 0, XBOXONE = 1, XBOX360 = 2, PLAYSTATION3 = 3, PLAYSTATION4 = 4, WII = 5, WIIU = 6, MEGADRIVE = 7} 

class Console
{
    
    public:
        Console();
        Console( const MANUFACTURER &, const PLATFORM &, const string &, const Date &, double , int , int , bool );
        Console( const Console &, const Date &, const Xbox360 & );
        ~Console();
        //Setters
        void setManufacturer ( const MANUFACTURER & );
        void setPlatform ( const PLATFORM & );
        void setNumSerie ( const string & );
        void setFDate ( const Date & );
        void setMaxStorage( double );
        void setUsedStorage( double );
        void setPowerON (); 
        //Getters
        MANUFACTURER getManufacturer(); 
        PLATFORM getPlatform();
        std::string getNumSerie ();
        Date getFDate();
        double getMaxStorage();
        double getUsedStorage();
        bool getPowerON();
        void insertControl( );
        void ejectControl ( );
    private:     
        const static int MAXCONTROLS = 4; //Numero máximo de slots para controles
        MANUFACTURER manufacturer;
        PLATFORM platform; 
        std::string numSerie;
        Date fabricationDate;             
        double maxStorage; double usedStorage;
        bool powerON;
        std::string *allGames;    
        int numGames;
        int numControls; 

};
#endif // CONSOLE_H
