#ifndef XBOX360_H
#define XBOX360_H

class Xbox360
{
    double versao;
    double hd;
    int coord_xyz[3];
    bool onoff;
    bool kinect_onoff;
public:
    Xbox360();
    ~Xbox360();
    void power_on_off();
    void kinect_on_off();
    void instalar_jogo();
    void desinstalar_jogo();
};

#endif // XBOX360_H
//