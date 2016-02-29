/*  1ª atividade de Programação II
 *  Autora: Yasmin Paz
 *  
 */
#include <iostream>
#include <string>
/*#include "Console.h"
#include "Date.h"
#include "Xbox360.h"*/
using namespace std;
int main(int argc, char **argv)
{
    Date release (22, 11, 2005);
	Console myConsole ( true, 0, Microsoft, release, "XBX360.0.0.1");
    Xbox360 myXbox (true, "Xbox360");
    
    
    return 0;
}
