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
        Game(const string &, const string &, const float &, const bool &);
        Game(const Game &);
        ~Game();
        string getTitle();
        string getPlatform();
        float getSize();
        bool getMultiplayer();
        void gameInfo() const;
        
        bool operator==(const Game &) const;
    
    private: 
        string title; 
        string platform;
        float size;
        bool multiplayer;
};
#endif // GAME_H