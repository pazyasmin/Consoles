#include <stdio.h>
#include <iostream>
using std::cout;

#include "Xbox360.h"

int main(int argc, char **argv)
{
	Xbox360 Xbox;
    	Xbox.power_on_off();
    //Cadastrando usuarios
    Xbox.cadastrar_usuario("Robert", 0);
    Xbox.cadastrar_usuario("Jessica", 1);
    Xbox.cadastrar_usuario("Barbara", 2);
    Xbox.cadastrar_usuario("Humbert", 3);
    Xbox.cadastrar_usuario("Jane", 4);
    
    Xbox.exibe_info();
    Xbox.listar_usuarios();
    return 0;
}
