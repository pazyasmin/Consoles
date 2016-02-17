#include <string>
using std::string;

#ifndef XBOX360_H
#define XBOX360_H

#include "Date.h"
class Xbox360
{
public:
    Xbox360(const Date &);
    void printf () const;
    ~Xbox360();
    void powerOnOff();
    void kinectOnOff();
    void displayInfo();
    void newUser( string, int );
    void displayUsers ( ) const;
    void installGame();
    void uninstallGame();

private:     
    bool onoff;
    bool konoff;
    double availableStorage;
    const static int NUMUSER = 5;
    string allUsers[NUMUSER];
    static string version;
    int coordXYZ[3];
    const Date biosDate;
};

#endif // XBOX360_H
