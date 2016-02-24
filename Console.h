#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include "Date.h"
#include "Xbox360.h"
using namespace std;
enum Manufac { Unspecified, Microsoft, Sony, Nintendo, Sega };
class Console
{
    
    public:
        Console( bool , const int &, const Manufac &,  const Date &, const string &);
        Console(const Console &);
        Console();
        ~Console();
       
        void powerONOFF();
        bool getPowerON();
        Manufac getManufacturer(); 
        string getNumSerie();
        Date getFabricationDate();
        float getFreeSpace();
        float getUsedSpace();
        void installGame( string );
        void uninstallGame( string );
        void allocate (const int &);

//        void insertControl();
//        void ejectControl();
//        void displayAllControls();

//Por enquanto, não armazenaremos jogos, apenas limitaremos a quantidade de instalações/desinstalações
//através da variável que corresponde ao armazenamento livre em disco

    private:     
        bool powerON;
        Manufac manufacturer; 
        string numSerie;
        Date fabricationDate;             
        const static int MAXCONTROLS = 4; //Numero de slots para controle
        const static double CAPACITY = 320; //Espaço disponível total
        bool allControls[MAXCONTROLS]; //Numero de controles conectados
        float freeSpace;              
        float usedSpace;
        string *gameList;
        int numGames;
};
#endif // CONSOLE_H
