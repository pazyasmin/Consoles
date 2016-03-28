#ifndef PLAYSTATION3_H
#define PLAYSTATION3_H_H

#include <string>
#include <ostream>
#include "Console.h"
using std::string;
using std::ostream;

class PlayStation3 : public Console
{
    friend ostream &operator<<(ostream &, const PlayStation3 &);
    
    public:
        PlayStation3();
        PlayStation3(const PlayStation3 &);
        ~PlayStation3();
        void kinect_ON();
        void kinect_OFF();
        bool getKinect() const;
        void psInfo() const;
        
        virtual void power_ON();
        virtual void power_OFF();
    
        
        bool operator==(const PlayStation3 &) const;
        const PlayStation3 &operator=(const PlayStation3 &); 
        
    private:    
        bool psMove;
};
#endif // PLAYSTATION3_H
