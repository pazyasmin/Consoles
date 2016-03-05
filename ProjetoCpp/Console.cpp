#include <iostream>
#include "Console.h"
using  namespace std;
//Construtor vazio

Console::Console():consoleName("Meu Console"), platform (UNKNOWN), releaseDate(12,4,2005), lastUpdate ("KZ.1.0"), whenLastUpdate(12,4,2005), numControls (0), numGames(0), usedStorage (0), totalStorage(320.00), 
{
    
}

//Construtor
Console::Console( const string &nomeConsole , const PLATFORM &plataforma, const Date &lancamento, const string &ultimoUpdate, const Date &qdoUltimoUpdate, 
double espacoTotal, double espacoUsado, int nControles, int nJogos )
{       
        this->consoleName = nomeConsole;
        this->platform = plataforma;
        this->releaseDate = lancamento;
        this->lastUpdate = ultimoUpdate;
        this->whenLastUpdate = qdoUltimoUpdate;
        this->totalStorage = espacoTotal;
        this->usedStorage = espacoUsado;
        this->numControls = nControles;
        this->numGames = nJogos;
        this->alocacaoDinamica( nJogos );
}   
//Construtor Cópia
Console::Console( const Console &c )
{  
        
        this->consoleName = c.consoleName;
        this->platform = c.platform;
        this->releaseDate = c.releaseDate;
        this->lastUpdate = c.lastUpdate;
        this->whenLastUpdate = c.whenLastUpdate;
        this->totalStorage = c.totalStorage;
        this->usedStorage = c.usedStorage;
        this->numControls = c.numControls;
        this->numGames = c.numGames;
        
        allGames = new string[ numGames ];
        
        for ( int i = 0 ; i < numGames ; ++i)
            allGames[ i ] = c.allGames[i];
}

//Destrutor
Console::~Console()
{       
    delete [] allGames;
}

//Método de alocação dinâmica
void Console::alocacaoDinamica(const int njogos)
{
    if ( njogos > 0)
    {   
        numGames = njogos;
        allGames = new string [ numGames ];
        cout <<"\nNumero de jogos instalados: "<<numGames;
        for ( int i = 0 ; i <= numGames ; i++)
        {
            cout <<"\n"<< allGames[ i ];
        }
    }
    else
    {
        allGames = NULL;
        numGames = 0;
        cout <<"\nNenhum jogo instalado.";
    }
}
//Overload de Operadores
ostream &operator<<( ostream &output, const Console &con)
{
    output << "\nPlataforma: " << con.platform << "\nData de lancamento: " << con.releaseDate
    << "\nData da ultima atualizacao: " << con.whenLastUpdate << "Atualizacao: " << con.whenLastUpdate
    << "\nArmazenamento: " << con.totalStorage << "\nEspaco usado: " << con.usedStorage << "\nNumero de jogos instalados"
    << con.numGames << "\nNumero de controles conectados: " << con.numControls;
}

istream &operator>> ( istream &input , Console &myConsole)
{
    input >> myConsole.consoleName;
    input >> myConsole.platform;
    input >> myConsole.releaseDate;
    input >> myConsole.lastUpdate;
    input >> myConsole.whenLastUpdate;
    input >> myConsole.totalStorage;
    input >> myConsole.usedStorage;
    input >> myConsole.numControls;
    input >> myConsole.numGames;
    for ( int i = 0; i < ( myConsole.numGames); ++i)
        input >> myConsole.allGames[i];
}

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
//Getters

string Console::getConsoleName()
{
    return consoleName;
}


PLATFORM Console::getPlatform()
{
    return platform;
}

double Console::getTotalStorage()
{
    return totalStorage;
}

double Console::getUsedStorage()
{
    return usedStorage;
}

int Console::getNumGames()
{
    return numGames;
}

int Console::getNumControls()
{
    return numControls;
}

Date Console::getReleaseDate()
{
    return releaseDate;
}

string Console::getLastUpdate()
{
    return lastUpdate;
}

Date Console::getWhenLastUpdate()
{
    return whenLastUpdate;
}
//Setters

void Console::setConsoleName( const string &nomeConsole )
{
    consoleName = nomeConsole;
}

void Console::setUsedStorage( double espacoUsado )
{
    usedStorage = espacoUsado;
}

void Console::setNumGames( int njogos )
{
    numGames = njogos;
}

void Console::setNumControls( int ncontroles )
{
    numControls = ncontroles;
}        


void Console::setReleaseDate( const Date &lancamento )
{
    releaseDate = lancamento;
}

void Console::setLastUpdate( string qualUpdate)
{
    lastUpdate = qualUpdate;
}

void Console::setWhenLastUpdate(Date quandoUpdate)
{
    lastUpdate = quandoUpdate;
}


void insertControl( )
{
    
    //Falta implementar classe controle 
}

void ejectControl ( )
{
    //Falta implementar classe controle
    
}




