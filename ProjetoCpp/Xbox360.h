#include <string>
#include <ostream>
#include "Console.h"
using std::string;
using std::ostream;

#ifndef XBOX360_H
#define XBOX360_H

class Xbox360 : public Console
{
    friend ostream &operator<<(ostream &, const Xbox360 &);
    public:
        Xbox360();
        Xbox360(const Xbox360 &);
        ~Xbox360();
        void kinect_ON();
        void kinect_OFF();
        void displayXboxInfo() const;
        void xStart(const Xbox360 &);
        bool operator==(const Xbox360 &) const;
        const Xbox360 &operator=(const Xbox360 &); 
      
    protected:     
        const static string LATEST_OSVERSION;//= "10.0.10586.1026";
    private:    
        bool kinect;
};

#endif // XBOX360_H
