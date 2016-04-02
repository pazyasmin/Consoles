#ifndef XBOX360_H
#define XBOX360_H

#include <string>
#include <ostream>
#include "Console.h"
#include "Kinect.h"
using std::string;
using std::ostream;

class Xbox360 : public Console
{
    friend ostream &operator<<(ostream &, const Xbox360 &);
    
    public:
        Xbox360();
        Xbox360(const Xbox360 &);
        ~Xbox360();
        void connectsKinect();
        void disconnectsKinect();
        
        virtual bool power_ON();
        virtual bool power_OFF();
        virtual void motionSensing();
    
        const Xbox360 &operator=(const Xbox360 &); 
        
    private:    
        Kinect kinect;
};
#endif // XBOX360_H
