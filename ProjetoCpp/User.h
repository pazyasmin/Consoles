#include <string>
#include <ostream>
using std::string;
using std::ostream;

#ifndef USER_H
#define	USER_H

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
        void setName(const string &);
        void setGamertag(const string &);
        void userInfo() const;
    
        const User &operator=(const User &); 
        bool operator==(const User &) const;
    
    private: 
        string name;
        string gamertag;
};

#endif // USER_H