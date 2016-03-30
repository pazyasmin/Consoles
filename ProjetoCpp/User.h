#ifndef USER_H
#define	USER_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;

class User
{
    friend ostream &operator<<(ostream &, const User &);
    public: 
        User();
        User(const string &, const string &);
        User(const User &);
        ~User();
        string getName();
        string getGamertag();
        void setName(string);
        void setGamertag(string);
        void userInfo() const;
    
        const User &operator=(const User &); 
        bool operator==(const User &) const;
    
    private: 
        string name;
        string gamertag;
};

#endif // USER_H