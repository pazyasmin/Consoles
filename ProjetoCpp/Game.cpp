#include "Game.h"
#include "Console.h"
using  namespace std;

Game::Game()
:title(" "), platform(" "), size(0.00)
{
    
}    
Game::Game(const string &t, const string &p, const float &s)
{
}
Game::Game(const Game &game)
{
    title = game.title;
    platform = game.platform;
    size = game.size;
}
        
Game::~Game()
{
}
string Game::getTitle() const
{
    return title;
}
string Game::getPlatform() const 
{
    return platform;
}

float Game::getSize() const 
{
    return size;
}

void Game::gameInfo() const
{
    cout << "\nTitle: "<< title;
    cout << "\nPlatform: "<< platform;
    cout << "\nSize: "<< size;
}

ostream &operator<<(ostream &out, const Game &game)
{
    out << "\nTitle: "<< game.title;
    out << "\nPlatform: "<< game.platform;
    out << "\nSize: "<< game.size;
    return out;
}

const Game& Game::operator=(const Game &game)
{
    title = game.title;
    platform = game.platform;
    size = game.size;
}

bool Game::operator==(const Game &game) const
{
    if (title != game.title)
        return false;
    if (platform != game.platform)
        return false;
    if (size != game.size)
        return false;
    return true;
}