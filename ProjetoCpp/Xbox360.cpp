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

Xbox360::Xbox360(const Xbox360 &x)
: Console(static_cast<Console> (x))
{
    power = x.power;
    manufacturer = x.manufacturer;
    intStorage = x.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = x.extStorage[i];

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

void Xbox360::getKinect() const
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

void Xbox360::xboxStart()
{
    power_ON();
    deviceInfo();
    consoleInfo();
    cout <<"\n\t________**** Xbox 360 ****_________";
    cout <<"\nLoading Xbox 360. Please wait...";
    Sleep (10*1000);
    cout <<"\nScanning components...";
    Sleep (10*1000);
    xboxInfo();
    Sleep (20*1000);
    system ("cls");
}

void Xbox360::xboxInfo() const
{
    cout <<"\nKinect: " << boolalpha << getKinect();
}

ostream &operator<<(ostream &out, const Xbox360 &x)
{
    out << static_cast <Console> (x);
    if (x.power)
    {
        x.deviceInfo();
        x.consoleInfo();
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
    return x;
}

bool Xbox360::operator==(const Xbox360 &x) const
{
    static_cast <Xbox360>(x);
    if (kinect != x.kinect)
        return false;
	return true;
}
