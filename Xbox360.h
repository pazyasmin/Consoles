#ifndef XBOX360_H
#define XBOX360_H
#include <string>

#include "Date.h"
#include "Console.h"

using std::string;

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
        const string consoleName;
        const static int MAXUSERS = 10;
        Date releaseDate(int , int , int );

};

#endif // XBOX360_H
