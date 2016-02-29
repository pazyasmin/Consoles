#ifndef XBOX360_H
#define XBOX360_H
#include <string>
#include "Date.h"
#include "Console.h"

class Xbox360
{
    public:
        Xbox360( bool , const string &);
        Xbox360();
        ~Xbox360();
        void setKinectON( bool );
        bool getKinectON(); 
        void displayInfo() const;
        void updateSystem( );
    private:     
        bool kinectON;
        string deviceName; 
        const static int MAXUSERS = 10;
        const Date releaseDate(int = 12, int = 4, int = 2005);
        Date lastUpdate (int , int , int ); 

};

#endif // XBOX360_H
