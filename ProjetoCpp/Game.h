#ifndef GAME_H
#define	GAME_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Game 
{
    friend ostream &operator<<(ostream &, const Game &);
    public: 
        Game(); 
        Game(const string &, const string &, const float &); 
        Game(const Game &); 
        ~Game(); 
        string getTitle() const; 
        string getPlatform() const; 
        float getSize() const; 
        void gameInfo() const; 
        const Game &operator=(const Game &);
        bool operator==(const Game &) const; 
    
    private: 
        string title; 
        string platform;
        float size;
};
#endif // GAME_H