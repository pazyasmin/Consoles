#include "Game.h"
#include "Console.h"
using  namespace std;

Game::Game()
:title(" "), platform(" "), size(0.00), multiplayer (false)
{
}    
Game::Game(const string &t, const string &p, const float &sz, const bool &m)
{
}
Game::Game(const Game &g)
{
    title = g.title;
    platform = g.platform;
    size = g.size;
    multiplayer = g.multiplayer;
}
        
Game::~Game()
{
}
string Game::getTitle()
{
    return title;
}
string Game::getPlatform()
{
    return platform;
}

float Game::getSize()
{
    return size;
}
bool Game::getMultiplayer()
{
    return multiplayer;
}

void Game::gameInfo() const
{
    cout << "\nTitle: "<< title;
    cout << "\nPlatform: "<< platform;
    cout << "\nSize: "<< size;
    if (multiplayer)
        cout << "\nMultiplayer: Yes ";
    else
        cout <<"\nMultiplayer: No ";
}

ostream &operator<<(ostream &out, const Game &g)
{
    out << "\nTitle: "<< g.title;
    out << "\nPlatform: "<< g.platform;
    out << "\nSize: "<< g.size;
    if (g.multiplayer)
        out << "\nMultiplayer: Yes ";
    else
        out <<"\nMultiplayer: No ";
    return out;
}

bool Game::operator==(const Game &g) const
{
    if (title != g.title)
        return false;
    if (platform != g.platform)
        return false;
    if (size != g.size)
        return false;
    if( multiplayer != g.multiplayer)
        return false;
    return true;
}