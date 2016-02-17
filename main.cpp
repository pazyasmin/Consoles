#include <stdio.h>
#include <iostream>
using std::cout;

#include "Xbox360.h"

int main(int argc, char **argv)
{
	Xbox360 Xbox;
    	Xbox.powerOnOff();

    Xbox.displayInfo();
    Xbox.displayUsers();
    return 0;
}
