#ifndef CONTROLLER_H
#define	CONTROLLER_H 

#include <string>
#include <ostream>
using std::string;
using std::ostream;
struct Position
{
    int X; int Y; int Z;
};

class Controller
{
   
    public: 
        Controller();
        Controller(const Controller &);
        ~Controller();
        bool getWireless();
        bool getConnected();
        Position getPosXYZ();
        void setWireless(bool);
        void setConnected(bool);
        void setPosXYZ( int, int , int );

    private:
        bool wireless;
        bool connected;
        Position posXYZ;
};
#endif // CONTROLLER_H