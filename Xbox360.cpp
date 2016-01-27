#include "Xbox360.h"
#include <iostream>
using std::cout;
Xbox360::Xbox360()
{
    onoff = false;
    kinect_onoff = false;
    hd = 120.00;
    versao = 1.0;
    coord_xyz[3] = { 0,0,0 };
}

Xbox360::~Xbox360()
{
}

void Xbox360::power_on_off( )
{
    if ( !onoff )
    {
        power_on_off = true;
        cout << "*Aparelho liga*\n";
    }
    else
        cout << "*Aparelho reseta*\n";
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
    if( hd > 10.00 )
    {
        hd -= 10.00; //para simplificar, considera-se que cada jogo ocupe 10GB
        cout << "O jogo foi instalado com sucesso.\n"
             << "Espaco livre: " << hd << " GB \n";

    }
    else
         cout << "Nao ha espaco suficiente.\n";
}

void Xbox360::desinstalar_jogo()
{
    if( hd < 120.00)
    {
        hd += 10;
        cout << "O jogo foi desinstalado com sucesso.\n"
             << "Espaco livre " << hd << " GB \n";
    }
    else
         cout << "Nao ha jogos a serem desinstalados.\n";
}

void Xbox360::exibe_info()
{
    cout << "Informacoes de Sistema:\n";
    cout << "Xbox360 versao "<< versao <<".\n";
    cout << "Espaco livre: "<< hd <<" GB.\n";
    if (kinect_onoff)
        cout << "Kinect ligado.\n";
    else
        cout << "Kinect desligado\n";
}
