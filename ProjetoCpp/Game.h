#include <string>
#include <ostream>
using std::string;
using std::ostream;

#ifndef GAME_H
#define	GAME_H

class Game
{
    friend ostream &operator<<(ostream &, const Game &);
    public: 
        Game();
        Game(const string &, const string &, const float &);
        Game(const Game &);
        ~Game();
        string getTitle();
        string getPlatform();
        float getReqSize();
        void setTitle(const string &);
        void setPlatform(const string &);
        void setReqSize(const float &);
        void gameInfo();
        
        const Game &operator=(const Game &); 
    
    private: 
        string title; 
        string platform;
        float reqSize;
};

#endif // GAME_H