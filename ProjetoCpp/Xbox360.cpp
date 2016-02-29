#include "Xbox360.h"
#include <iostream>

using std::cout;

Xbox360::Xbox360( bool kinect, const string &nome)
{
    this->kinectON = kinect;
    this->consoleName = nome ;
}

Xbox360::Xbox360()
{
    this->consoleName = "Desconhecido";
}

Xbox360::Xbox360(Xbox360 &x)
{
    this->kinectON = x.kinectON;
    this->deviceName = x.deviceName;
}

Xbox360::~Xbox360()
{
    
}

void Xbox360::setKinectON( bool )
{
     if(this->kinectON)
    {
        cout << "\nKinect liga";
    }
    else
    {
        this->kinectON = false;
        cout << "\nKinect desliga.";
    }
}

bool Xbox360::getKinectON()
{
    return kinectON;
} 


void Xbox360::displayInfo( MANUFACTURER &f, int njogos &jogos, string &serie, Date &data, Date &datb , float livre, float usado )
{
            
        cout << "\n\tInformacoes de Sistema";
        cout << "\nNumero de serie: " << serie;
        cout << "\nData de fabricacao: " << data;
        cout << "\nData de lancamento: " << datb;
        cout << "\nEspaco em disco: " << livre;
        cout << "\nEspaco em disco: " << usado;

            switch (fabricante) {
                case 1:
                    cout << "Fabricante: Microsoft Xbox\n";
                    break;
                case 2:
                    cout << "Fabricante: Sony Play Station\n";
                    break;
                case 3:
                    cout << "Fabricante: Nintendo\n";
                    break;
                case 4:
                    cout << "Fabricante: Sega\n";
                    break;
            };

}
