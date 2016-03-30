#include "User.h"
#include <iostream>
using namespace std;

User::User(): name(" "), gamertag(" ")
{
}

User::User(const string &nm, const string &gtag)
{
    
}

User::User(const User &u)
{  
    name = u.name;
    gamertag = u.gamertag;
}

User::~User()
{ 
      
}

string User::getName() 
{
    return name;
}

string User::getGamertag() 
{
    return gamertag;
}


void User::setName(string nm)
{
    name = nm;
}

void User::setGamertag(string gtag)
{
    gamertag = gtag;
}

void User::userInfo() const
{
    cout <<"\nName: " << name;
    cout <<"\nGamertag: " << gamertag;
}


ostream &operator<<(ostream &out, const User &u)
{
    out <<"\nName: " << u.name;
    out << "\nGamertag: " << u.gamertag;
    return out;
}

const User& User::operator=(const User &u)
{
    name = u.name;
    gamertag = u.gamertag;
    return u;
}

bool User::operator==(const User &u) const
{
    if(name != u.name)
        return false;
    if(gamertag != u.gamertag)
        return false;
    return true;
}




