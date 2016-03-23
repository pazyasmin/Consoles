#include <string>
#include <ostream>
using std::string;
using std::ostream;

#ifndef CONTROLLER_H
#define	CONTROLLER_H

class Controller
{
    friend ostream &operator<<(ostream &, const Controller &);
    public: 
        Controller();
        Controller(const bool &, const int &);
        Controller(const Controller &);
        ~Controller();
        bool getIsConnected();
        bool setIsConnected(const bool &);
        bool getWireless();
        void setWireless(const bool &);
        int getSlot();
        void setSlot(const int &);
        const Controller &operator=(const Controller &); 
    private:
        bool isConnected;
        bool wireless;
        int slot;
};
#endif // CONTROLLER_H