#ifndef PLAYSTATION3_H
#define PLAYSTATION3_H

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
        void psMove_ON();
        void psMove_OFF();
        bool getMove() const;
        void psInfo() const;
        
        virtual bool power_ON();
        virtual bool power_OFF();
    
        bool operator==(const PlayStation3 &) const;
        const PlayStation3 &operator=(const PlayStation3 &); 
        
    private:    
        bool psMove;
};
#endif // PLAYSTATION3_H
