#include "Kinect.h"
#include <iostream>

using  namespace std;

Kinect::Kinect()
{
    kinectConnected = false;
    setKinectPos(0,0,0);
}

Kinect::Kinect(const Kinect &k)
{
    kinectConnected = k.kinectConnected;
    kinectPosXYZ.X = k.kinectPosXYZ.X;
    kinectPosXYZ.Y = k.kinectPosXYZ.Y;
    kinectPosXYZ.Z = k.kinectPosXYZ.Z; 
}
Kinect::~Kinect()
{
}

bool Kinect::getKinectConnected()
{
    return kinectConnected;
}

KPosition Kinect::getKinectPos()
{
    return kinectPosXYZ;
}
void Kinect::setKinectConnected(bool con)
{
    kinectConnected = con;
}
void Kinect::setKinectPos(int x, int y, int z)
{
    kinectPosXYZ.X = x;
    kinectPosXYZ.Y = y;
    kinectPosXYZ.Z = z;
}

void Kinect::kinectInfo() const
{
    if (kinectConnected)
        cout <<"\nKinect: Connected ";
        else
            cout <<"\nKinect: Disconnected ";
    cout << "\nKinect coordinates: \n";
    cout <<"X: "<< kinectPosXYZ.X << " Y: " << kinectPosXYZ.Y << " Z: " << kinectPosXYZ.Z << "\n";
}

ostream &operator<<(ostream &out, const Kinect &k)
{
    if (k.kinectConnected)
        out <<"\nKinect: Connected ";
        else
            out <<"\nKinect status: Disconnected ";
    out << "\nKinect coordinates: \n";
    out <<"X: "<< k.kinectPosXYZ.X << " Y: " << k.kinectPosXYZ.Y << " Z: " << k.kinectPosXYZ.Z << "\n";
    return out;
}

const Kinect& Kinect::operator=(const Kinect &k)
{
    kinectConnected = k.kinectConnected;
    kinectPosXYZ.X = k.kinectPosXYZ.X;
    kinectPosXYZ.Y = k.kinectPosXYZ.Y;
    kinectPosXYZ.Z = k.kinectPosXYZ.Z;
}

bool Kinect::operator==(const Kinect &k) const
{
    if (kinectConnected != k.kinectConnected)
        return false;
    if (kinectPosXYZ.X != k.kinectPosXYZ.X);
        return false;
    if (kinectPosXYZ.Y != k.kinectPosXYZ.Y);
        return false;
    if (kinectPosXYZ.Z != k.kinectPosXYZ.Z);
        return false;

	return true;
}
