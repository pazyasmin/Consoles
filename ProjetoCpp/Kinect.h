#ifndef KINECT_H
#define KINECT_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;

struct KPosition
{
    int X; int Y; int Z;
};

class Kinect 
{

    friend ostream &operator<<(ostream &, const Kinect &);
    public:
        Kinect();
        Kinect(const Kinect &);
        ~Kinect();
        bool getKinectConnected();
        KPosition getKinectPos();
        void setKinectConnected(bool);
        void setKinectPos(int, int , int);
        void kinectInfo() const;
        
        bool operator==(const Kinect &) const;
        const Kinect &operator=(const Kinect &); 
        
    private:    
        bool kinectConnected;
        KPosition kinectPosXYZ;
};
#endif // KINECT_H
