#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include "Xbox360.h"

//Pré-definições plataforma
enum PLATFORM { UNSPECIFIED = 0, XBOXONE = 1, XBOX360 = 2, PLAYSTATION3 = 3, PLAYSTATION4 = 4, WII = 5, WIIU = 6, MEGADRIVE = 7} 

class Console
{
    
    public:
        Console();
        Console( const PLATFORM &, double , double );
        ~Console();
        PLATFORM getPlatform();
        double getTotalStorage();
        double getUsedStorage();
        int getNumGames( int );
        int getNumControls( int );
        void setPlatform( MANUFACTURER );
        void setTotalStorage( double );
        void setUsedStorage( double );
        void setNumGames();
        void setNumControls();
        
    private:     
        PLATFORM platform; 
        double totalStorage;
        double usedStorage;
        std::string *allGames;    
        int numGames;
        int numControls; 
    
            friend void friendStorage (Device &oDev, Console &oCon);
            void friendStorage(Device &oDev, Console &oCon)
            {
                oCon.totalStorage = oDev.internalStorage + oDev.externalStorage; 
            }
};
#endif // CONSOLE_H
