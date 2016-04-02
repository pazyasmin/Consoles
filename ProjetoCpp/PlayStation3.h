#ifndef PLAYSTATION3_H
#define PLAYSTATION3_H

#include <string>
#include <ostream>
#include "Console.h"
#include "PSMove.h"
using std::string;
using std::ostream;

class PlayStation3 : public Console
{
    friend ostream &operator<<(ostream &, const PlayStation3 &);
    
    public:
        PlayStation3();
        PlayStation3(const PlayStation3 &);
        ~PlayStation3();
        void connectsPSMove();
        void disconnectsPSMove();
        
        virtual bool power_ON();
        virtual bool power_OFF();
        virtual void motionSensing();
        
        const PlayStation3 &operator=(const PlayStation3 &); 
        
    private:    
        PSMove psMove;
};
#endif // PLAYSTATION3_H
