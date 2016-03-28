#include <iostream>
#include "Device.h"
#include "Console.h"
#include "Xbox360.h"

using namespace std;
void xboxMenu();
void menuConsole();
void funcXbox360();
void funcPlayStation3();

int main(int argc, char **argv)
{
    int op;
	
	cout << "\nChoose one of the following: 
    cout <<"\n1 - Xbox 360 
    cout <<"\n2 - Play Station 3";
	cin >> op;
	
	switch(op)
	{
		case 1:
			funcXbox360();
			break;
			
		case 2:
			funcPlayStation3();
			break;
		default:
			cout << "\nError. Enter a valid option.\n";
	}
    return 0;
}
    
void funcXbox360()
{    
    int op;
    Xbox360 myXbox;
    myXbox.xboxStart();
	
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

                break;
                
            case 3:
                
                break;
                
            case 4:
                
            default:
                cout << "\n\nError. Enter a valid option. ";
         }
    }while (op != 0); 
        
	return 0;
}

void funcPlayStation3()
{
    
}

void xboxMenu()
{
    cout << "\n15. Turn on kinect";
    cout << "\n16. Turn off kinect";
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