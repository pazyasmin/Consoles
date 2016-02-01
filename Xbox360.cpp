#include "Xbox360.h"
#include <iostream>

using std::cout;

Xbox360::Xbox360()
{
    onoff = false;
    kinect_onoff = false;
    availableStorage = 120.00;
    version = 1.0;
    coord_xyz[3] = { 0,0,0 };
        for(int i = 0; i < 5; i++)
        listaUsuarios[i] = "---"; 
    
}

Xbox360::~Xbox360()
{
    
}

void Xbox360::power_on_off( )
{
    if ( !onoff )
    {
        power_on_off = true;
        cout << "*Console liga*\n";
    }
    else
        cout << "*Console reseta*\n";
}

void Xbox360::kinect_on_off( )
{
    if( kinect_onoff )
        cout << "*Kinect liga*\n";
    else
        cout << "*Kinect desliga*.\n";
}

void Xbox360::instalar_jogo()
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

void Xbox360::desinstalar_jogo()
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

void Xbox360::exibe_info() 
{
    cout << "Informacoes de Sistema:\n";
    cout << "Xbox360 versao "<< versao <<".\n";
    cout << "Espaco livre: "<< availableStorage <<" GB.\n";
    if (kinect_onoff)
        cout << "Kinect ligado.\n";
    else
        cout << "Kinect desligado\n";
}

void Xbox360::cadastrar_usuario( string newUser, int indice)
{
    if (onoff)
    {
        if( indice >= 0 && indice < 5)
            listaUsuarios[indice] = newUser;
        else
            cout << "Nao pode ser cadastrado.\n";
    }
    
}

void Xbox360::listar_usuarios( ) const
{
    if( onoff )
    {
        cout << "Usuarios:\n";
        for( int i = 0; i < 5; i++ )
            cout << usuarios[i] << '\n';
    }
}