#ifndef XBOX360_H
#define XBOX360_H

#include <string>
#include <ostream>
#include "Console.h"
using std::string;
using std::ostream;

class Xbox360 : public Console
{
    friend ostream &operator<<(ostream &, const Xbox360 &);
    
    public:
        Xbox360();
        Xbox360(const Xbox360 &);
        ~Xbox360();
        void kinect_ON();
        void kinect_OFF();
        bool getKinect() const;
        void xboxInfo();
        
        virtual void power_ON();
        virtual void power_OFF();
    
        
        bool operator==(const Xbox360 &) const;
        const Xbox360 &operator=(const Xbox360 &); 
        
    private:    
        bool kinect;
};
#endif // XBOX360_H
