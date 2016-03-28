#include "PlayStation3.h"
#include <iostream>
#include <windows.h>

using namespace std;

PlayStation3::PlayStation3()
{
    power = false;
    manufacturer = "Sony";
    intStorage = 500.00;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = 0.00; 
    platform = "PlayStation 3";
    softwareVersion = 1.0;
    releaseDate = Date(11,11,2006);
    lastUpdated = Date(12,11,2006);
    storage[0] = 500.00;
    storage[1] = 0.00;
    storage[2] = 500.00;
    internetConnection = false;
    nGames = 0 ; nUsers = 0;

   for (int i=1 ; i <= CONTROLLER_SLOTS; i++)
    {
        controllers[i].setConnected(false);
        controllers[i].setWireless(false);
    }
    
    psMove = false;
}

PlayStation3::PlayStation3(const PlayStation3 &x)
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

    psMove = x.psMove;
}

PlayStation3::~PlayStation3()
{
    
}

void PlayStation3::getKinect() const
{
    return psMove;
}

void PlayStation3::psMove_ON()
{
     if(!psMove)
    {
        psMove = true;
        cout << "\nYour PlayStation Move has been turned on.";
    }
    else
        cout << "\nYour PlayStation Move is already turned on.";
}

void PlayStation3::psMove_OFF()
{
     if(psMove)
    {
        psMove = false;
        cout << "\nYour PlayStation Move has been turned off.";
    }
    else
        cout << "\nYour PlayStation Move is already turned off.";
}

void PlayStation3::start()
{
    power_ON();

    cout <<"\n\t________**** PlayStation 3 ****_________";
    cout <<"\nLoading PlayStation 3. Please wait...";
    Sleep (10*1000);
    cout <<"\nScanning components...";
    Sleep (10*1000);
    deviceInfo();
    consoleInfo();
    psInfo();
    Sleep (20*1000);
    system ("cls");
}

void PlayStation3::psInfo() const
{
    cout <<"\nPS Move: " << boolalpha << getPsMove();
}

ostream &operator<<(ostream &out, const PlayStation3 &x)
{
    out << static_cast <Console> (x);
    if (x.power)
    {
        x.deviceInfo();
        x.consoleInfo();
        x.displayUsers();
        x.displayGames();
        if (x.psMove)
            out <<"\nPS Move: ON";
        else
            out <<"\nPS Move: OFF";
    }
    return out;
}

const PlayStation3& PlayStation3::operator=(const PlayStation3 &x)
{
    static_cast<PlayStation3> ( *this ) = PlayStation3( static_cast< PlayStation3 > (x) );
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

    psMove = x.psMove;
    return x;
}

bool PlayStation3::operator==(const PlayStation3 &x) const
{
    static_cast <PlayStation3>(x);
    if (psMove != x.psMove)
        return false;
	return true;
}
