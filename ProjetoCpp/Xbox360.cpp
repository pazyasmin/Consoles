#include <iostream>
#include "Xbox360.h"
using  namespace std;
//
Xbox360::Xbox360()
{

}

Xbox360::Xbox360(Xbox360 &x)
{
    this->kinectON = x.kinectON;
}

Xbox360::~Xbox360()
{
    
}

void Xbox360::setKinectON( bool )
{
     if(this->kinectON)
    {
        cout << "\nKinect liga";
    }
    else
    {
        this->kinectON = false;
        cout << "\nKinect desliga.";
    }
}

bool Xbox360::getKinectON()
{
    return kinectON;
} 

ostream &operator<<( ostream &output, const Xbox360 &con)
{
    output << "\nStatus Kinect: " << con.kinectON() 
}