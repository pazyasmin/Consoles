#include "Device.h"
#include "Game.h"
#include "Controller.h"
#include "Date.h"
#include <string>
#include <ostream>
#include <vector>

using std::string;
using std::ostream;

#ifndef CONSOLE_H
#define CONSOLE_H

class Console : public Device
{
    friend ostream &operator<<(ostream &, const Console &);
    public:
        Console( ); 
        Console(const string &, const string &, const Date &, const string &, const float &);        
        Console(const Console &);
        ~Console();
        void insertController(const Controller &);
        void removeController(const int &);
        void installGame(const Game &);
        void uninstallGame (const Game &);
        void displayGames() const;
        void sistemInfo() const; 
        void format();
        void update();
        void menu();
        void play();
        
        const Console &operator=(const Console &); 
  
    protected:
        string platform;
        string manufacturer;
        Date releaseDate;
        string version;
        std::vector<Game> games;
        std::vector<Controller> controllers;
        int numGames;
        int numControllers; 
        float availableSpace; //Soma do armazenamento externo e interno
        float usedSpace;      //Espaço usado total
    
    private:
        const static int MAXSLOTS = 4;
};

#endif // CONSOLE_H
