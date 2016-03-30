#include "Xbox360.h"
#include <iostream>
#include <windows.h>

using  namespace std;

Xbox360::Xbox360()
{
    power = false;
    manufacturer = "Microsoft";
    intStorage = 250.00;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = 0.00; 
    ethernetCard = true;
    
    platform = "Xbox 360";
    softwareVersion = 1.0;
    releaseDate = Date(22,11,2005);
    lastUpdated = Date(22,11,2005);
    storage[0] = 250.00;
    storage[1] = 0.00;
    storage[2] = 250.00;
    internetConnection = false;
    nGames = 0 ; nUsers = 0;

   for (int i=1 ; i <= CONTROLLER_SLOTS; i++)
    {
        controllers[i].setConnected(false);
        controllers[i].setWireless(false);
    }
    
    kinect = false;
}

Xbox360::Xbox360(const Xbox360 &x)//: Console(static_cast<Console> (x))
{
    power = x.power;
    manufacturer = x.manufacturer;
    intStorage = x.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = x.extStorage[i];
    ethernetCard = x.ethernetCard;

    platform = x.platform;
    softwareVersion = x.softwareVersion;
    lastUpdated = x.lastUpdated;
    storage[0] = x.storage[0];
    storage[1] = x.storage[1];
    storage[2] = x.storage[2];
    internetConnection = x.internetConnection;
    nGames = x.nGames ; nUsers = x.nGames;
    
    for (int i = 0; i < nGames; i++)
        games[i] = x.games[i];
    for (int i = 0; i < nUsers; i++)
        users[i] = x.users[i];
    
    nGames = x.nGames;
    nUsers = x.nUsers;

    kinect = x.kinect;
}

Xbox360::~Xbox360()
{
    
}

bool Xbox360::getKinect() const
{
    return kinect;
}

void Xbox360::kinect_ON()
{
     if(!kinect)
    {
        kinect = true;
        cout << "\nYour kinect has been turned on.";
    }
    else
        cout << "\nYour kinect is already turned on.";
}

void Xbox360::kinect_OFF()
{
     if(kinect)
    {
        kinect = false;
        cout << "\nYour kinect has been turned off.";
    }
    else
        cout << "\nYour kinect is already turned off.";
}

void Xbox360::xboxInfo() const
{
    consoleInfo();
    cout <<"\nKinect: " << boolalpha << getKinect();
}

bool Xbox360::power_ON()
{
    if (!power)
    {
        cout << "\n\t-Xbox 360-";    
        cout <<"\nLoading Xbox 360. Please wait...";
        Sleep (3*1000);
        cout <<"\nScanning components...";
        Sleep (3*1000);
        xboxInfo();
        Sleep (3*1000);
        power = true;
        cout << "\nYour Xbox 360 has been turned on."; 
    }
    else
    {
        cout << "\nYour Xbox 360 is already turned on.\nRestarting..."; 
        power = false;
        power_ON();
        cout << "Your Xbox 360 has been restarted!\n"; 
    }
    return true;
}

bool Xbox360::power_OFF() 
{
    if (power)
    {
        power = false;
        cout << "\nShutting down Xbox 360. Please wait...";
        Sleep (3*1000);
        cout << "\nYour Xbox 360 has been turned off."; 
    }
    else
        cout << "\nYour Xbox 360 is already turned off."; 
    return true;
}


ostream &operator<<(ostream &out, const Xbox360 &x)
{
    //out << static_cast <Console> (x);
    if (x.power)
    {
        x.consoleInfo();
        if (x.kinect)
            out <<"\nKinect: ON";
        else
            out <<"\nKinect: OFF";
    }
    return out;
}

const Xbox360& Xbox360::operator=(const Xbox360 &x)
{
    power = x.power;
    manufacturer = x.manufacturer;
    intStorage = x.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = x.extStorage[i];
    ethernetCard = x.ethernetCard;

    platform = x.platform;
    softwareVersion = x.softwareVersion;
    releaseDate = x.releaseDate;
    lastUpdated = x.lastUpdated;
    internetConnection = x.internetConnection;
    nGames = x.nGames ; 
    nUsers = x.nGames;
    
    for (int i=0; i<3 ; i++)
        storage[i] = x.storage[i];
        
    delete [] users;
    delete [] games;
    
    users = new User[nUsers];
    games = new Game[nGames];
    
    for (int i=0; i < nUsers; i++)
        users[i] = x.users[i];

    for (int i=0; i < nGames; i++)
        games[i] = x.games[i];

    kinect = x.kinect;
}

bool Xbox360::operator==(const Xbox360 &x) const
{
    if (kinect != x.kinect)
        return false;
	return true;
}
