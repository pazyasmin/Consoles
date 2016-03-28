#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(): wireless(false), connected(false)
{
    
}

Controller::Controller(const Controller &c) 
{  
   wireless = c.wireless;
   connected = c.connected;
}

Controller::~Controller() 
{
       
}

void Controller::setWireless(bool w)
{
    wireless = w;
    
}

bool Controller::getWireless()
{
    return wireless;
}

void Controller::setConnected(bool c)
{
    connected = c;
}

bool Controller::getConnected()
{
    return connected;
}

ostream &operator<<(ostream &out, const Controller &c)
{
    out << "\nWireless: " << boolalpha << c.wireless;
    return out;
}

const Controller& Controller::operator=(const Controller &c)
{
    wireless = c.wireless;
    connected = c.connected;
}

bool Controller::operator==(const Controller &c) const
{
    if(connected != c.connected)
        return false;
    if(wireless != c.wireless)
        return false;
    return true;
}




