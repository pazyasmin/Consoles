#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <fstream>
//Pré-definições plataforma...
enum PLATFORM { UNSPECIFIED = 0, XBOXONE = 1, XBOX360 = 2, PLAYSTATION3 = 3, PLAYSTATION4 = 4, WII = 5, WIIU = 6, MEGADRIVE = 7} 

class Console
{
    
    public:
        Console();
        Console( const PLATFORM &, double , double );
        friend ostream &operator<<( ostream &, const Console &);
        void allocDyn( int );
        ~Console();
        PLATFORM getPlatform();
        
        Date getReleaseDate();
        string getLastUpdate();
        Date getWhenLastUpdate();
        double getTotalStorage();
        double getUsedStorage();
        int getNumGames();
        int getNumControls();
        
        void setReleaseDate ( Date );
        void setLastUpdate ( string );
        void setWhenLastUpdate ( Date );
        void setUsedStorage( double );
        void setNumGames( int );
        void setNumControls( int );
        
        void insertControl();
        void ejectControl();
        
        
    private:     
        PLATFORM platform; 
        string update;
        const Date releaseDate;
        string lastUpdate;
        Date whenLastUpdate; 
        
        double totalStorage;
        double usedStorage;
        int numGames;
        int numControls; 
        std::string *allGames; 
    
    
            friend void friendStorage (Device &oDev, Console &oCon);
            void friendStorage(Device &oDev, Console &oCon)
            {
                oCon.totalStorage = oDev.internalStorage + oDev.externalStorage; 
            }
};
#endif // CONSOLE_H
