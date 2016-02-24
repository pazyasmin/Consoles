#ifndef XBOX360_H
#define XBOX360_H
#include <string>
#include "Date.h"
using std::string;

class Xbox360
{
    public:
        Xbox360( bool , const string &);
        ~Xbox360();
        void setKinectON( bool );
        bool getKinectON(); 
        void displayInfo();
//        void updateSystem( );
    private:     
        bool kinectON;
        const string consoleName;
        const static int MAXUSERS = 10;
        Date releaseDate(int , int , int );
        //Falta implementar: 
        //string allUsers[MAXUSERS];
        //Jogos 
        //Controle
        //Kinect
        //int coordXYZ[3];
};

#endif // XBOX360_H
