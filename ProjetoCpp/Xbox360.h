#include "User.h"
#include <string>
#include <ostream>
#include <vector>
using std::string;
using std::ostream;

#ifndef XBOX360_H
#define XBOX360_H

class Xbox360 : public Console
{
    friend ostream &operator<<(ostream &, const Xbox360 &);
    public:
        Xbox360();
        Xbox360(const bool &, const bool &, const float &, const string &, const string &, const Date &, const float &);
        Xbox360(const Xbox360 &);
        ~Xbox360(const Xbox360 &);
        bool getKinectON(); 
        void setKinectON( bool );
        void createUser();
        void deleteUser();
        void displayUsers() const; 
        void bootXB();
        
        const Xbox360 &operator=(const Xbox360 &); 
      
    private:     
        bool kinectON;
        vector<User> users;
        const static int MAXUSERS = 10;
        const static int LATEST_OSVERSION = "10.0.10586.1026";
};

#endif // XBOX360_H
