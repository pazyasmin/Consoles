#include "Console.h"
#include "Xbox360.h"
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

Console::Console()
: platform("Unknown"), releaseDate(1,1,1999), versionOS(" "), usedStorage(0), freeStorage(0), nGames(0), nUsers(0)
{
    for (int i=1 ; i <= CONTROLLER_SLOTS; i++)
    {
        controllers[i].setIsConnected(false);
        controllers[i].setWireless(false);
        controllers[i].setSlot(0); //Slot igual a zero indica que não está conectado a nenhum slot (1..4)
    }

}

Console::Console(const Console &c):Device(static_cast<Device>(c))
{  
//
    power = c.power;
    manufacturer = c.manufacturer;
    intStorage = c.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = c.extStorage[i];
 //       
    platform = c.platform;
    manufacturer = c.manufacturer;
    releaseDate = c.releaseDate;
    versionOS = c.versionOS;
    freeStorage = c.freeStorage;
    usedStorage = c.usedStorage;
    
    for (int i = 0; i < nGames; i++)
        games[i] = c.games[i];
    for (int i = 0; i < nUsers; i++)
        users[i] = c.users[i];
    
    nGames = c.nGames;
    nUsers = c.nUsers;
}

Console::~Console()
{       
    delete[] games;
    delete[] users;
}

void Console::refreshFreeSpace()
{
    freeStorage = totalStorage - usedStorage;
}

void Console::refreshUsedSpace(const float &sz)
{
    usedStorage = usedStorage + sz;
    refreshFreeSpace();    
}

void Console::installGame(Game g)
{
    if (!power)
    {
        cout << "\nGame could not be installed. The console is turned off. ";
        return;
    }
    if (platform != g.getPlatform())
    {
        cout <<"\nGame could not be installed. The game is not compatible with your system. ";
        return;
    }
    if (freeStorage < g.getSize())
    {
        cout <<"\nGame could not be installed. Not enough storage space.";
        return;
    }
        if(nGames != 0)
        {
            Game* aux = new Game[nGames];
            
            for(int i = 0; i < nGames; i++)
                aux[i] = games[i];
            
            delete [ ] games;
            
            games = new Game[++nGames];
            
            for(int i = 0; i < nGames-1; i++)
                games[i] = aux[i];
                
            games[nGames - 1] = g;
                
            delete [ ] aux;
        }
        else
        {
            usedStorage = 0;
            games = new Game[++nGames];
            games[0] = g;
        }

        cout <<"\n"<< g.getTitle() <<" was successfully installed on your console!";
        refreshUsedSpace(g.getSize());
}


void Console::createUser(User user)
{
    if (power){
        if(nUsers <= MAX_USERS)
        {
            if(nUsers != 0)
            {
                User* aux = new User[nUsers];
                
                for(int i = 0; i < nUsers; i++)
                    aux[i] = users[i];
                
                delete [ ] users;
                
                users = new User[++nUsers];
                
                for(int i = 0; i < nUsers-1; i++)
                    users[i] = aux[i];
                    
                users[nUsers - 1] = user;
                    
                delete [ ] aux;
            }
            else
            {
                users = new User[++nUsers];
                users[0] = user;
            }
            cout <<"\nWelcome, "<< users[nUsers-1].getGamertag() <<"!";
        }
        else
            cout <<"\nUser could not be created. You've exceeded the maximum number of users.";
    }
    else
        cout << "\nUser could not be created. The console is turned off.";
}

void Console::insertController(Controller controller)
{
    if ( controller.getSlot() > 0 && controller.getSlot() <= CONTROLLER_SLOTS )
    {
        controllers[controller.getSlot()] = controller;
    }
}

void Console::removeController(int s)
{
    if (s > 0 && s < CONTROLLER_SLOTS)
    {
        controllers[s].setWireless(false);
        controllers[s].setIsConnected(false);
        controllers[s].setSlot(0);
    }
}

void Console::displayGames() const
{
    if ( nGames > 0)
    {
        cout << "\n\t--- Installed Games ---";
        for(int i = 0; i < nGames; i++)
        {
            cout << "\nTitle: "<< games[i].getTitle();
            cout << "\nPlatform: "<< games[i].getPlatform();
            cout << "\nSize: "<< games[i].getSize();
            if (games[i].getMultiplayer())
                cout << "\nMultiplayer: Yes ";
            else
                cout <<"\nMultiplayer: No ";
        }
    }
     else
         cout << "\nThere are no games installed.";
}

void Console::displayUsers() const
{
    if ( nUsers > 0)
    {
        cout << "\n\t--- Users ---";
        for(int i = 0; i < nUsers; i++)
        {
            cout <<"\nName: " << users[i].getName();
            cout <<"\nGamertag: " << users[i].getName();
        }
    }
     else
         cout << "\nThere are no users.";
}

void Console::systemUpdate()
{
    char op;
    string latest = "LATEST_OSVERSION";
    if (versionOS != latest)
    {
        cout <<"\nThere are new updates available. Update system? (Y/N)";
        cin >> op;
            if (toupper(op) == 'Y')
                versionOS = latest;
            else 
                return;
    }
    else
        cout <<"\nThere are no updates available.";
}
void Console::menu()
{
    
}
void Console::play(Game g)
{
    char op;
    if (platform != g.getPlatform())
    {
        cout <<"\nThe specified game is not compatible with this system.";
        return;
    }
        for (int i = 0; i < nGames; i++)
        {
            if (games[i].getTitle() != g.getTitle())
            {
                cout << "\nPlay " << games[i].getTitle() << "(Y/N)?";
                cin  >> op;
                
                if (toupper(op) == 'Y')
                    cout << "\nYou're playing "<< games[i].getTitle() << "!\n";
                else 
                    cout <<"\nExiting...";
            }
            else
                cout << "\nThe game is not installed on your system.";
        }
}
void Console::displayConsoleInfo() const
{
    cout <<"\n\t--- System Info ---";
   
    if (power)
    {
        cout <<"\nPlatform: "<< platform;
        cout <<"\nRelease Date: " << releaseDate;
        cout <<"\nOS Version  "<< versionOS;
        cout <<"\nFree Space: "<< freeStorage;
        cout <<"\nUsed Space: "<< usedStorage;
        cout <<"\nNumber of games installed: "<< nGames;
        cout <<"\nNumber of users: "<< nUsers;
    }
    else
        cout <<"\nThe console is turned off.";
}

ostream &operator<<(ostream &out, const Console &cons)
{
    out << static_cast <Device>(cons);

    out <<"\n\t--- System Info ---";
   
    if (cons.power)
    {
        out <<"\nPlatform: "<< cons.platform;
        out <<"\nRelease Date: " << cons.releaseDate;
        out <<"\nOS Version  "<< cons.versionOS;
        out <<"\nFree Space: "<< cons.freeStorage;
        out <<"\nUsed Space: "<< cons.usedStorage;
        out <<"\nNumber of games installed: "<< cons.nGames;
        out <<"\nNumber of users: "<< cons.nUsers;
        cons.displayGames();
        cons.displayUsers();
    }
    else
        out <<"\nThe console is turned off.";
        
    return out;
}

const Console &Console::operator=(const Console &cons)
{
    static_cast<Device> (*this) = Device(static_cast<Device>(cons));

    power = cons.power;
    manufacturer = cons.manufacturer;
    intStorage = cons.intStorage;
    for (int i = 0; i < USB_PORTS; i++)
        extStorage[i] = cons.extStorage[i];
    freeStorage = cons.freeStorage;
//
    platform = cons.platform;
    releaseDate = cons.releaseDate;
    versionOS = cons.versionOS;
    usedStorage = cons.usedStorage;
    nGames = cons.nGames;
    nUsers = cons.nUsers;
    
    delete [] users;
    delete [] games;
    
    users = new User[nUsers];
    games = new Game[nGames];
    
    for (int i=0; i < nUsers; i++)
    {
        users[i] = cons.users[i];
    }
    for (int i=0; i < nGames; i++)
    {
        games[i] = cons.games[i];
    }
    
    return *this;
}

bool Console::operator==(const Console &cons) const
{
    static_cast <Device>(cons);
    if (power != cons.power)
        return false;
    if (manufacturer != cons.manufacturer)
        return false;
    if (totalStorage != cons.totalStorage)
        return false;
    if(platform != cons.platform)
        return false;
/*   if(releaseDate != cons.releaseDate)
        return false;
*/
    if(versionOS != cons.versionOS)
        return false;
    if(usedStorage != cons.usedStorage)
        return false;
    if(freeStorage != cons.freeStorage)
        return false;
    if(nUsers != cons.nUsers)
        return false;
    if(nGames != cons.nGames)
        return false;
/*    for(int i=0; i < nUsers; i++)
    {
    	if(users[i] != cons.users[i])
            return false;
    }    
    for (int i=0; i < nGames; i++)
    {    
        if (games[i] != cons.games[i]) 	
    	    return false;
    }*/
	return true;
}
