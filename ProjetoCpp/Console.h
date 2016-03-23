#include "Device.h"
#include "Date.h"
#include "Game.h"
#include "Controller.h"
#include "User.h"

#include <string>
#include <ostream>

using std::string;
using std::ostream;

#ifndef CONSOLE_H
#define CONSOLE_H

class Console : public Device
{
    friend ostream &operator<<(ostream &, const Console &);
    public:
        Console();
        Console(const Console &);
        Console (const int &, const int &, const int &);
        ~Console();
        void refreshFreeSpace();
        void refreshUsedSpace(const float &);
        void installGame(Game);
        void createUser(User);
        void insertController(Controller);
        void removeController(int);
        void displayGames() const;
        void displayUsers() const; 
        void displayConsoleInfo() const;
        void systemUpdate();
        void userLogIn();
        void menu();
        void play(Game);
        const Console &operator=(const Console &); 
	    bool operator==(const Console &) const;
    
    protected:
        const static int CONTROLLER_SLOTS = 4;
        const static int MAX_USERS = 10;
        string platform;
        Date releaseDate;
        string versionOS;
        float usedStorage;
        float freeStorage;
        Game* games;
        User* users;
        Controller controllers[CONTROLLER_SLOTS-1];     
        int nGames;
        int nUsers;
};

#endif // CONSOLE_H
