#include <iostream>
#include <vector>
#include "Console.h"
#include "Xbox360.h"
#include "PlayStation3.h"

using namespace std;

void xboxMenu();
void psMenu();
int xbList();
int psList();

int main(int argc, char **argv)
{
    const int n = 2;
    vector<Console *> vConsoles(n);
    
    vConsoles[0] = new Xbox360();
    bool xbox = vConsoles[0] -> power_ON();
    cout << "\n\nYour Xbox 360 is ready!" << endl;
    
    vConsoles[1] = new PlayStation3();
    bool playstation = vConsoles[1] -> power_ON();
    cout << "\n\nYour PlayStation 3 is ready!";
   
    for(int i = 0; i < n; i++)
	{
        int op;
        int op2;
        do
        {
        cout << "\nChoose one of the following: ";
        cout << "\n1 - Xbox 360 \n2 - PlayStation 3 ";
        cout << "\n> ";
        cin >> op;
        }while (op != 1 && op != 2);
        
        Xbox360 *xb = dynamic_cast < Xbox360 * > (vConsoles[i]);
		PlayStation3 *ps = dynamic_cast < PlayStation3 * > (vConsoles[i]);
        
            if(xb && xbox && op == 1)
            {
                do
                {   Game jogo;
                    xboxMenu();
                    cin >> op1;
                    
                    switch (op1)
                    {
                        case 1:
                            xb->power_OFF();
                        case 2:
                            xb->play();
                            break;
                        case 3:
                            int op = xbList();
                            if (op == 1) Game jogo("Halo", "Xbox 360", 45.00);
                            if (op == 2) Game jogo("Halo 5", "Xbox 360", 60.90);
                            if (op == 3) Game jogo("Gears of War", "Xbox 360", 50.14);
                            if (op == 4) Game jogo("Dead Rising 3", "Xbox 360", 51.30);
                            xb->installGame(jogo);
                            break;
                        default:
                            cout << "\n\nError. Enter a valid option. ";
                    }
                }while (op1 != 0); 
            }
    }
}
void xboxMenu()
{
    cout << "\n\t-Xbox 360-\n";
    cout << "\nMenu";
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
    cout << "\n15. Turn on kinect";
    cout << "\n16. Turn off kinect";
    cout <<"\n > ";
}

void psMenu()
{
    cout << "\n\t-PlayStation 3-\n";
    cout << "\nMenu";
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
    cout << "\n15. Turn on PS Move";
    cout << "\n16. Turn off PS Move";
    cout <<"\n > ";
}

int xbList()
{
    int op;
    do
    {
    cout << "\nWhich game would you like to install? ";
    cout << "\n1 - Halo"; 
    cout << "\n2 - Halo 5";
    cout << "\n3 - Gears of War";
    cout <<"\n4 - Dead Rising 3";
    cin >> op;
    }while (op < 1 || op > 4);
    
    return op;
}

int psList()
{
    int op;
    do
    {
    cout << "\nWhich game would you like to install? ";
    cout << "\n1 - Bayonetta"; 
    cout << "\n2 - Metal Gear Solid 4";
    cout << "\n3 - Heavy Rain";
    cout <<"\n4 - God of War 3";
    cin >> op;
    }while (op > 0 || op <= 4);
    
    return op;
}




/*    if (op == 1) 
    {   
        ("Bayonetta", "PlayStation 3", 120.31);

    }
    if (op == 2) 
    }
        return ("Metal Gear Solid 4", "PlayStation 3", 90.87);
    if (op == 3) 
        return ("Heavy Rain", "PlayStation 3", 70.33);
    if (op == 4) 
        return ("God of War", "PlayStation 3", 40.78);
}*/