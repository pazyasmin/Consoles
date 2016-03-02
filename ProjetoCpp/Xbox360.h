#ifndef XBOX360_H
#define XBOX360_H
#include <string>
#include <fstream>
//
class Xbox360
{
    public:
        Xbox360( bool , const string &);
        friend ostream &operator<<( ostream &, const Xbox360 &);
        Xbox360();
        ~Xbox360();
        void setKinectON( bool );
        bool getKinectON(); 
       
    private:     
        bool kinectON;
        const static int MAXUSERS = 10;

};

#endif // XBOX360_H
