#include "PSMove.h"
#include <iostream>
using  namespace std;

PSMove::PSMove()
{
    moveConnected = false;
    setMovePos(0,0,0);
}

PSMove::PSMove(const PSMove &m)
{
    moveConnected = m.moveConnected;
    movePosXYZ.X = m.movePosXYZ.X;
    movePosXYZ.Y = m.movePosXYZ.Y;
    movePosXYZ.Z = m.movePosXYZ.Z; 
}
PSMove::~PSMove()
{
}

bool PSMove::getMoveConnected()
{
    return moveConnected;
}

MPosition PSMove::getMovePos()
{
    return movePosXYZ;
}
void PSMove::setMoveConnected(bool con)
{
    moveConnected = con;
}
void PSMove::setMovePos(int x, int y, int z)
{
    movePosXYZ.X = x;
    movePosXYZ.Y = y;
    movePosXYZ.Z = z;

}

void PSMove::moveInfo() const
{
    if (moveConnected)
        cout <<"\nPlayStation Move: Connected ";
    else
            cout <<"\nPlayStation Move: Disconnected ";
    cout << "\nPlayStation Move coordinates: \n";
    cout <<"X: "<< movePosXYZ.X << " Y: " << movePosXYZ.Y << " Z: " << movePosXYZ.Z << "\n";
}


ostream &operator<<(ostream &out, const PSMove &m)
{
    if (m.moveConnected)
        out <<"\nPlayStation Move: Connected ";
        else
            out <<"\n\nPlayStation Move: Disconnected ";
    out << "\nPlayStation Move coordinates: \n";
    out <<"X: "<< m.movePosXYZ.X << " Y: " << m.movePosXYZ.Y << " Z: " << m.movePosXYZ.Z << "\n";
    return out;
}

const PSMove& PSMove::operator=(const PSMove &m)
{
    moveConnected = m.moveConnected;
    movePosXYZ.X = m.movePosXYZ.X;
    movePosXYZ.Y = m.movePosXYZ.Y;
    movePosXYZ.Z = m.movePosXYZ.Z;
}

bool PSMove::operator==(const PSMove &m) const
{
    if (moveConnected != m.moveConnected)
        return false;
    if (movePosXYZ.X != m.movePosXYZ.X);
        return false;
    if (movePosXYZ.Y != m.movePosXYZ.Y);
        return false;
    if (movePosXYZ.Z != m.movePosXYZ.Z);
        return false;

	return true;
}
