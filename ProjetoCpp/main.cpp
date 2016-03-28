#include <iostream>
#include "Device.h"
#include "Console.h"
#include "Xbox360.h"

using namespace std;
void xboxMenu();
void psMenu();
void menuConsole();
void deviceConsole();
void consoleXbox360();
void consolePlayStation3();

int main(int argc, char **argv)
{
    int op;
	
	cout << "\nChoose one of the following devices:";
    cout <<"\n1 - Console 
	cin >> op;
	
	switch(op)
	{
		case 1:
			deviceConsole();
			break;
		default:
			cout << "\nError. Enter a valid option.\n";
	}
    return 0;
}
    
void deviceConsole()
{    
    int op;
    cout << "\nChoose one of the following: \n
    cout <<"\n 1 - Xbox 360 \n 2 - PlayStation 3 ";
    cin >> opt;
    vector <Console *> consoles;
    
    if (op == 1)
    consoles.push_back (new Xbox360());
    else 
        if (op == 2)
            consoles.push_back(new PlayStation3());

}
/*
    do
    {   cout << "___**** MENU XBOX 360 ****___";
        menuConsole();
        xboxMenu();
        cin >> op;
        
        switch (op)
        {
            case 1:
                myXbox.power_OFF();
                break;
            case 2:
                myXbox.displayGames();

            default:
                cout << "\n\nError. Enter a valid option. ";
         }
    }while (op != 0); 
        
	return 0;
}

void consolePlayStation3()
{
    
}

void xboxMenu()
{
    cout << "\n15. Turn on kinect";
    cout << "\n16. Turn off kinect";
    cout <<"\n>";
}

void psMenu()
{
    cout << "\n15. Turn on PS Move";
    cout << "\n16. Turn off PS Move";
    cout <<"\n>";
}

void menuConsole()
{
       
        cout << "\nChoose one of the following:\n";
        cout << "\n0 - Exit";
        cout << "\n1 - Turn off console";
        cout << "\n2 - Play game";
        cout << "\n3 - Install game";
        cout << "\n4 - Uninstall game";
        cout << "\n5 - Create user";
        cout << "\n6 - Delete user";
        cout << "\n7 - Insert controller";
        cout << "\n8 - Remove controller";
        cout << "\n9 - Show games";
        cout << "\n10 - Show users";
        cout << "\n11 - Show controllers";
        cout << "\n12 - Insert storage device";
        cout << "\n13 - Remove storage device";
        cout << "\n14 - Connect to the Internet";
        cout << "\n15 - Show system info";
}
*/