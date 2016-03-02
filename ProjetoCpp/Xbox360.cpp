#include "Xbox360.h"
#include <iostream>

using namespace std;

Xbox360::Xbox360()
{

}

Xbox360::Xbox360(Xbox360 &x)
{
    this->kinectON = x.kinectON;
    this->deviceName = x.deviceName;
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

