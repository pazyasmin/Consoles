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
    ethernetCard = true;

    platform = "PlayStation 3";
    softwareVersion = 1.0;
    releaseDate = Date(11,11,2006);
    lastUpdated = Date(11,11,2006);
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

PlayStation3::PlayStation3(const PlayStation3 &p)//: Console(static_cast<Console> (p))
{
    power = p.power;
    manufacturer = p.manufacturer;
    intStorage = p.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = p.extStorage[i];

    platform = p.platform;
    softwareVersion = p.softwareVersion;
    lastUpdated = p.lastUpdated;
    storage[0] = p.storage[0];
    storage[1] = p.storage[1];
    storage[2] = p.storage[2];
    internetConnection = p.internetConnection;
    nGames = p.nGames ; nUsers = p.nGames;
    
    for (int i = 0; i < nGames; i++)
        games[i] = p.games[i];
    for (int i = 0; i < nUsers; i++)
        users[i] = p.users[i];
    
    nGames = p.nGames;
    nUsers = p.nUsers;

    psMove = p.psMove;
}

PlayStation3::~PlayStation3()
{
    
}

bool PlayStation3::getMove() const
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

void PlayStation3::psInfo() const
{
    consoleInfo();
    cout <<"\nPS Move: " << boolalpha << getMove();
}

bool PlayStation3::power_ON()
{
    if (!power)
    {
        cout << "\n\t-PlayStation 3-";    
        cout <<"\nLoading PlayStation 3. Please wait...";
        Sleep (3*1000);
        cout <<"\nScanning components...";
        Sleep (3*1000);
        psInfo();
        Sleep (3*1000);
        power = true;
        cout << "\nYour PlayStation 3 has been turned on."; 
    }
    else
    {
        cout << "\nYour PlayStation 3 is already turned on.\nRestarting..."; 
        power = false;
        power_ON();
        cout << "\nYour PlayStation 3 has been restarted."; 
    }
    return true;
}

bool PlayStation3::power_OFF() 
{
    if (power)
    {
        power = false;
        cout << "\nShutting down Xbox 360. Please wait...";
        Sleep (3*1000);
        cout << "\nYour PlayStation 3 has been turned off."; 
    }
    else
        cout << "\nYour PlayStation 3 is already turned off."; 
    return true;
}


ostream &operator<<(ostream &out, const PlayStation3 &p)
{
   
    if (p.power)
    {
        p.consoleInfo();
        p.displayUsers();
        p.displayGames();
        if (p.psMove)
            out <<"\nPS Move: ON";
        else
            out <<"\nPS Move: OFF";
    }
    return out;
}

const PlayStation3& PlayStation3::operator=(const PlayStation3 &p)
{

    power = p.power;
    manufacturer = p.manufacturer;
    intStorage = p.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = p.extStorage[i];
    ethernetCard = p.ethernetCard;

    platform = p.platform;
    softwareVersion = p.softwareVersion;
    releaseDate = p.releaseDate;
    lastUpdated = p.lastUpdated;
    internetConnection = p.internetConnection;
    nGames = p.nGames ; 
    nUsers = p.nGames;
    
    for (int i=0; i<3 ; i++)
        storage[i] = p.storage[i];
        
    delete [] users;
    delete [] games;
    
    users = new User[nUsers];
    games = new Game[nGames];
    
    for (int i=0; i < nUsers; i++)
        users[i] = p.users[i];

    for (int i=0; i < nGames; i++)
        games[i] = p.games[i];

    psMove = p.psMove;
}

bool PlayStation3::operator==(const PlayStation3 &p) const
{
    if (psMove != p.psMove)
        return false;
	return true;
}
