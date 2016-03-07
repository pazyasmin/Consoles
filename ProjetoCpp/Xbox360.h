#ifndef XBOX360_H
#define XBOX360_H
#include <iostream>
#include <fstream>
#include <string>

class Xbox360 : public Console
{
    
    public:
        Xbox360( bool , const string &);
        Xbox360();
        ~Xbox360();
        void setKinectON( bool );
        bool getKinectON(); 
       
    private:     
        bool kinectON;

};

#endif // XBOX360_H
