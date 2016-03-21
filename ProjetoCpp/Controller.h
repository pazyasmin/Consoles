#include <string>
#include <ostream>
#include <vector>
using std::string;
using std::ostream;

#ifndef CONTROLLER_H
#define	CONTROLLER_H

class Controller
{
    friend ostream &operator<<(ostream &, const Controller &);
    public: 
        Controller();
        Controller(const bool &, const int &, const int &);
        Controller(const Controller &);
        ~Controller();
        bool getWireless();
        void setWireless(const bool &);
        
        const Controller &operator=(const Controller &); 
         
    private:
        bool wireless;
        std::vector <bool> buttons;
        int numButtons;
        int coordinates[3];
        int slot;
        const static int MAXBUTTONS = 15; 
};
#endif // GAME_H