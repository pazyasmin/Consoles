#include <cstdlib>
#include <iostream>
#include <vector>
#include "Console.h"
#include "Xbox360.h"
#include "PlayStation3.h"

using namespace std;

//char xboxMenu();
//char psMenu();
//int xbList();
//int psList();

int main(int argc, char **argv)
{
    const int n = 4;
    bool xbox[2];
    bool playstation[2];
    vector<Console *> vConsoles(n);

    vConsoles[0] = new Xbox360();
    xbox[0] = vConsoles[0] -> power_ON();
    cout << "\n\nYour Xbox 360 (1) is ready!" << endl;
    
    vConsoles[1] = new Xbox360();
    xbox[1] = vConsoles[1] -> power_ON();
    cout << "\n\nYour Xbox 360 (2) is ready!" << endl;
    
    vConsoles[2] = new PlayStation3();
    playstation[0] = vConsoles[2] -> power_ON();
    cout << "\n\nYour PlayStation 3 (1) is ready!";
      
    vConsoles[3] = new PlayStation3();
    playstation[1] = vConsoles[3] -> power_ON();
    cout << "\n\nYour PlayStation 3 (2) is ready!";

    for(int i = 0; i < n; i++)
	{
        char op;
        Xbox360 *xb = dynamic_cast < Xbox360 * > (vConsoles[i]);
        PlayStation3 *ps = dynamic_cast < PlayStation3 * > (vConsoles[i]);
            
        if(xb)
        {
            if (xbox[i])
                cout << "\nThe console Xbox "<< i+1 <<" is on.";
            else
            {
                char op2;
                cout << "\nThe console Xbox "<< i+1 <<" is off.\nWould you like to turn it on? ";
                if (toupper(op2) == 'Y')
                    vConsoles[i]-> power_ON();
                else
                    continue;
                        
                cout << endl;
            }
            char op1;
            cout << "\nWould you like to update console " << i+1 << "? <Y/N> ";
            cin >> op1;

            if (toupper(op1) == 'Y')
            {
                vConsoles[i]-> update();
                vConsoles[i]-> consoleInfo();
            }
            cout << endl;
            cout << endl;
            
            char op2;
        
            cout <<"\nWould you like to connect a motion sensing device to your console? <Y/N>";
            cin >> op2;
            if (toupper(op2) == 'Y')
                xb->connectsKinect();
            
            cout <<"\nWould you like to disconnect the motion sensing device from your console? <Y/N>";
            cin >> op2;
            if (toupper(op2) == 'Y')
                xb->disconnectsKinect();
            cout << endl;
            
        }
        
        if(ps)
        {   
            if (playstation[i-1])
            cout << "\nThe console PlayStation 3"<< i-1 <<" is on.";
            else
            {
                char op2;
                cout << "\nThe console PlayStation 3 "<< i-1 <<" is off.\nWould you like to turn it on? ";
                if (toupper(op2) == 'Y')
                    vConsoles[i]-> power_ON();
                else
                    continue;
                        
                cout << endl;
            }
            char op1;
            cout << "\nWould you like to update console " << i-1 << "? <Y/N> ";
            cin >> op1;

            if (toupper(op1) == 'Y')
                vConsoles[i]-> update();
            cout << endl;
            
            char op2;
            cout <<"\nWould you like to connect a motion sensing device to your console? <Y/N>";
            cin >> op2;
            if (toupper(op2) == 'Y')
                ps->connectsPSMove();
            
            cout <<"\nWould you like to disconnect the motion sensing device from your console? <Y/N>";
            cin >> op2;
            if (toupper(op2) == 'Y')
            {
                ps->disconnectsPSMove();
            }        

        }
        
        cout << "\n\nWould you like to turn off console "<< i-1 << " now? <y/n> ";
        cin >> op;
        
        if (toupper(op) == 'Y')
        {
            cout <<"\nTurning off console...";
            vConsoles[i]->power_OFF();
        }
            

    }
    vConsoles.clear();
    cout << "The program will be terminated. Press any key to proceed...\n" << endl;
    system ("Pause");
    return 0;
}
/*
char xboxMenu()
{
    char op;
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
    cin >> op;
    return op;
}

char psMenu()
{
    char op;
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
    cin >> op;
    return op;
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




   if (op == 1) 
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
}


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
            

*/