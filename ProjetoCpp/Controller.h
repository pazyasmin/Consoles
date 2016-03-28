#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Controller
{
    friend ostream &operator<<(ostream &, const Controller &);
    public: 
        Controller();
        Controller(const bool &, const bool &);
        Controller(const Controller &);
        ~Controller();
        bool getWireless();
        bool getConnected();
        void setWireless(bool);
        void setConnected(bool);
        
        bool operator==(const Controller &) const; 
        const Controller &operator=(const Controller &); 
    private:
        bool wireless;
        bool connected;
};
#endif // CONTROLLER_H