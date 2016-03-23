#include <iostream>
#include "Xbox360.h"
#include <windows.h>
#define LATEST_OSVERSION "10.0.10586.1026"
using  namespace std;

//const static string Xbox360::LATEST_OSVERSION[]= "10.0.10586.1026";

Xbox360::Xbox360(): Console(22,11,2005)
{
    power = false;
    manufacturer = "Microsoft";
    intStorage = 250.00;
    totalStorage = 250.00;
    platform = "Xbox 360";
    versionOS = "1.0.0";
    usedStorage = 0.00; 
    freeStorage = 250.00; 
    nGames = 0 ; nUsers = 0;
    
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = 0.00; 
 
   for (int i=1 ; i <= CONTROLLER_SLOTS; i++)
    {
        controllers[i].setIsConnected(false);
        controllers[i].setWireless(false);
        controllers[i].setSlot(0); 
    }
    
    kinect = false;
}

Xbox360::Xbox360(const Xbox360 &x)
: Console(static_cast<Console> (x))
{
   kinect = x.kinect;
   //
    power = x.power;
    manufacturer = x.manufacturer;
    intStorage = x.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = x.extStorage[i];
 //       
    platform = x.platform;
    manufacturer = x.manufacturer;
    releaseDate = x.releaseDate;
    versionOS = x.versionOS;
    freeStorage = x.freeStorage;
    usedStorage = x.usedStorage;
    
    for (int i = 0; i < nGames; i++)
        games[i] = x.games[i];
    for (int i = 0; i < nUsers; i++)
        users[i] = x.users[i];
    
    nGames = x.nGames;
    nUsers = x.nUsers;
}

Xbox360::~Xbox360()
{
    
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

void Xbox360::xStart(const Xbox360 &x)
{
    power_ON();
    displayDeviceInfo();
    displayConsoleInfo();
    cout <<"\n\t---\\---- Xbox 360 ----//---";
    Sleep (5*1000);
    cout <<"\nLoading...";
    Sleep (5*1000);
    cout <<"\nScanning components...";
    Sleep (5*1000);
    displayXboxInfo();
    
}


void Xbox360::displayXboxInfo() const
{
    if (kinect)
        cout <<"\nKinect: ON";
    else
        cout <<"\nKinect: OFF";
}


ostream &operator<<(ostream &out, const Xbox360 &x)
{
    out << static_cast <Console> (x);
    if (x.power)
    {
        x.displayDeviceInfo();
        x.displayConsoleInfo();
        x.displayUsers();
        x.displayGames();
        if (x.kinect)
            out <<"\nKinect: ON";
                else
                    out <<"\nKinect: OFF";
    }
    return out;
}

const Xbox360& Xbox360::operator=(const Xbox360 &x)
{
    static_cast<Xbox360> ( *this ) = Xbox360( static_cast< Xbox360 > (x) );
    power = x.power;
    manufacturer = x.manufacturer;
    intStorage = x.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = x.extStorage[i];
    freeStorage = x.freeStorage;
//
    platform = x.platform;
    releaseDate = x.releaseDate;
    versionOS = x.versionOS;
    usedStorage = x.usedStorage;
    nGames = x.nGames;
    nUsers = x.nUsers;
    
    delete [] users;
    delete [] games;
    
    users = new User[nUsers];
    games = new Game[nGames];
    
    for (int i=0; i < nUsers; i++)
    {
        users[i] = x.users[i];
    }
    for (int i=0; i < nGames; i++)
    {
        games[i] = x.games[i];
    }
//
    kinect = x.kinect;
    return x;
}

bool Xbox360::operator==(const Xbox360 &x) const
{
    static_cast <Xbox360>(x);
    if (power != x.power)
        return false;
    if (manufacturer != x.manufacturer)
        return false;
    if (totalStorage != x.totalStorage)
        return false;
    if(platform != x.platform)
        return false;

    if(versionOS != x.versionOS)
        return false;
    if(usedStorage != x.usedStorage)
        return false;
    if(freeStorage != x.freeStorage)
        return false;
    if(nUsers != x.nUsers)
        return false;
    if(nGames != x.nGames)
        return false;
    
    if (kinect != x.kinect)
        return false;

	return true;
}
