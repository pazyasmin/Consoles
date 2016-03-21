#include "Console.h"
#include <iostream>
using  namespace std;

Console::Console()
: platform("Desconhecido"), manufacturer("Desconhecido"), releaseDate(1,1,1990), version("0.0.0"), 
numGames(0), numControllers(0), usedSpace(0) 
{
    availableSpace = Device::calcAvailableStorage();
}

Console::Console( const Console &myConsole )
{  
        platform = myConsole.platform;
        manufacturer = myConsole.manufacturer;
        releaseDate = myConsole.releaseDate;
        version = myConsole.version;
        usedSpace = myConsole.usedSpace;
        numGames = myConsole.numGames;
        numControllers = myConsole.numControllers;
        availableSpace = Device::calcAvailableStorage();

}

Console::Console(const string &plataforma , const string &fabricante, const Date &lancamento, const string &vrs, 
const float &usado): numGames(0), numControllers(0)
{       
        platform = plataforma;
        manufacturer = fabricante;
        releaseDate = lancamento;
        version = vrs;
        usedSpace = usado;
        availableSpace = Device::calcAvailableStorage();

}

Console::~Console()
{       

}

ostream &operator<<(ostream &out, const Console &myConsole)
{
    out <<"\tInformacoes de Console:\n\n";
    out <<"\nFabricante: "<< myConsole.manufacturer;
    out <<"\nPlataforma: "<< myConsole.platform;
    out <<"\nVersao: "<< myConsole.version;
    out <<"\nEspaco disponivel: "<< myConsole.availableSpace;
    out <<"\nPlataforma: "<< myConsole.platform;
    return out;
}

/*
const Console &Console::operator=(const Console &outro)
{
    if (&outro != this )
    {
        if ( numGames != outro.numGames)
        {
            delete [] allGames;
            numGames = outro.numGames;
            allGames = new int [ numGames ];
        }
        
        for ( int i = 0 ; i < numGames ; ++i)
            allGames[i] = outro.allGames [ i ];
    }
    
    return *this;
}
 
bool Console::operator==(const Console &outro) const 
{
    if ( numGames != outro.numGames)
        return false;
        
    for ( int i = 0 ; i < allGames; i++)
        if (allGames[ i ] != outro.allGames[ i ])
            return false;
    return true;
}
int &Console::operator[] ( int j )
{
    if (j < 0 || j >= numGames)
        cout << "\nElemento fora do intervalo!";
    return allGames[j];
}   

int Console::operator[](int j) const 
{
    if (j < 0 || j >= numGames)
        cout << "\nElemento fora do intervalo!";
    return allGames[j];
}   


void Console::installGame(const string &nomeJogo)
{
    if( Device::powerON ) 
    {
        if( numGames != 0 )
        {
            string * aux = new string[ numGames ];
            
            for(int i = 0; i < numGames; i++)
                aux[ i ] = allGames[ i ];
            
            delete [ ] allGames;
            
            allGames = new string[ ++numGames ] ;
            
            for(int i = 0; i < numGames - 1; i++)
                allGames[ i ] = aux[ i ];
                
            allGames[ numGames - 1 ] = nomeJogo;
                
            delete [ ] aux;
            
        }
        else
        {
            allGames = new string[++numGames];
            allGames[0] = novoJogo;
        }
    }
}

void Console::displayGames( ) const
{
    if ( numGames > 0)
    {
        cout << "Lista de jogos: \n";
        for(int i = 0; i < numResidentes; i++)
            cout << allGames[ i ] << '\n';
    }
     else
         cout << "Nenhum jogo instalado no sistema.";
    
}


void insertControl( )
{
    
    //Falta implementar classe controle 
}

void ejectControl ( )
{
    //Falta implementar classe controle
    
}




*/