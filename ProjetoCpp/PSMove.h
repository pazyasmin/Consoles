#ifndef PSMOVE_H
#define PSMOVE_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;

struct MPosition
{
    int X; int Y; int Z;
};

class PSMove
{    

    friend ostream &operator<<(ostream &, const PSMove &);
    public:
        PSMove();
        PSMove(const PSMove &);
        ~PSMove();
        bool getMoveConnected();
        MPosition getMovePos();
        void setMoveConnected(bool);
        void setMovePos(int, int , int);
        void moveInfo() const;
        
        bool operator==(const PSMove &) const;
        const PSMove &operator=(const PSMove &); 
        
    private:   
        bool moveConnected;
        MPosition movePosXYZ; 
};
#endif // PSMOVE_H
