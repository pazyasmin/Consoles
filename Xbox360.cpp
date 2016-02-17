#include "Xbox360.h"
#include <iostream>

using std::cout;

int Xbox360::version = "XBOX360.1.0";

Xbox360::Xbox360()
{
    onoff = false;
    konoff = false;
    availableStorage = 120.00;
        for(int i = 0; i < 5; i++)
            allUsers[5] = "---"; 
    
}

Xbox360::Xbox360(const Xbox360 &x)
{
    availableStorage = x.availableStorage;
    coordXYZ = x.coordXYZ;
    onoff = x.onoff;
    konoff = x.konoff;
    for (i = 0; i < NUMUSER; i++)
    {
        allUsers[i] = x.allUsers[i];
    }
}

Xbox360::~Xbox360()
{
    
}

void Xbox360::powerOnOff( )
{
    if ( !onoff )
    {
        onoff = true;
        cout << "*Console liga*\n";
    }
    else
        cout << "*Console reseta*\n";
}

void Xbox360::kinectOnOff( )
{
    if( konoff )
    {
        konoff = true;
        cout << "*Kinect liga*\n";
    }
    else
    {
        konoff = false;
        cout << "*Kinect desliga*.\n";
    }
}

void Xbox360::installGame()
{
    if( availableStorage > 10.00 )
    {
        availableStorage -= 10.00; 
        cout << "O jogo foi instalado com sucesso.\n"
             << "Espaco livre: " << availableStorage << " GB \n";

    }
    else
         cout << "Nao ha espaco suficiente.\n";
}

void Xbox360::uninstallGame()
{
    if( availableStorage < 120.00)
    {
        availableStorage += 10;
        cout << "O jogo foi desinstalado com sucesso.\n"
             << "Espaco livre " << availableStorage << " GB \n";
    }
    else
         cout << "Nao ha jogos a serem desinstalados.\n";
}

void Xbox360::displayInfo() 
{
    cout << "Informacoes de Sistema:\n";
    cout << "Xbox360 versao "<< version <<".\n";
    cout << "Espaco livre: "<< availableStorage <<" GB.\n";
    if (konoff)
        cout << "Kinect ligado.\n";
    else
        cout << "Kinect desligado\n";
}

void Xbox360::newUser( string usuario, int indice)
{
    if (onoff)
    {
        if( indice >= 0 && indice < 5)
            allUsers[indice] = usuario;
        else
            cout << "Nao pode ser cadastrado.\n";
    }
    
}

void Xbox360::displayUsers( ) const
{
    if( onoff )
    {
        cout << "Usuarios:\n";
        for( int i = 0; i < 5; i++ )
            cout << allUsers[i] << '\n';
    }
}

Xbox360::Xbox360(int day, int month, int year):biosDate(day, month, year)
{
    
}

