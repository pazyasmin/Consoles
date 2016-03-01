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
        void setReleaseDate ( Date );
        void setLastUpdate ( Date );
        void setUpdate( string );
        bool getKinectON(); 
        Date getReleaseDate();
        Date getSystemUpdate();
        string getUpdate();
    private:     
        bool kinectON;
        string update;
        const Date releaseDate(int = 12, int = 4, int = 2005);
        Date LastUpdate (int , int , int ); 
        const static int MAXUSERS = 10;

};

#endif // XBOX360_H
