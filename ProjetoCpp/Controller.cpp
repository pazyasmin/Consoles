#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(): wireless(false), connected(false)
{
    setPosXYZ(0, 0, 0);

}

Controller::Controller(const Controller &c) 
{  
    wireless = c.wireless;
    connected = c.connected;
    posXYZ.X = c.posXYZ.X; 
    posXYZ.Y = c.posXYZ.Y; 
    posXYZ.Z = c.posXYZ.Z; 

}

Controller::~Controller() 
{
}

bool Controller::getWireless()
{
    return wireless;
}

bool Controller::getConnected()
{
    return connected;
}

Position Controller::getPosXYZ()
{
    return posXYZ;
}

void Controller::setConnected(bool con)
{
    connected = con;
}

void Controller::setWireless(bool wir)
{
    wireless = wir;
    
}

void Controller::setPosXYZ(int x, int y, int z)
{
    posXYZ.X = x;
    posXYZ.Y = y;
    posXYZ.Z = z;
}




