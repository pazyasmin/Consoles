#include <iostream>

using namespace std;

void xboxMenu();
void psMenu();

int main(int argc, char **argv)
{
    const int n = 2;
	
	vector<Console *> vetorConsoles(n);
	
	vetorConsoles[0] = new Xbox360();
	vetorConsoles[1] = new PlayStation3();

    
    for(int i = 0; i < n; i++)
	{
        Xbox360 *ptXB = dynamic_cast < Xbox360 * > (vetorConsoles[i]);
		PlayStation3 *ptPS = dynamic_cast < PlayStation3 * > (vetorConsoles[i]);

        if(ptXB)
        {
            ptXB->start();
            
            do
            {   
                xboxMenu();
                cin >> op;
        
                switch (op)
                {
                    case 1:
                        ptXB->power_OFF();
                        break;
                    case 2:
                        ptXB->displayGames();
                        //(...)
                    default:
                        cout << "\n\nError. Enter a valid option. ";
                 }
            }while (op != 0); 
                            
		}

		if(ptPS)
		{
            ptPS->start();
            do
            {
                psMenu();
                cin >> op;
        
                switch (op)
                {
                    case 1:
                        ptPS->power_OFF();
                        break;
                    case 2:
                        ptPS->displayGames();
                        //(...)
                    default:
                        cout << "\n\nError. Enter a valid option. ";
                 }
            }while (op != 0); 
            
        }
    
    vetorConsoles.clear();
    
	return 0;
}

void xboxMenu()
{
    cout << "\n\t__________**** Xbox 360 ****__________";
    cout << "\n\tMenu";
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
    cout <<"\n>";
}

void psMenu()
{
    cout << "\n\t__________**** PlayStation 3 ****__________";
    cout << "\n\tMenu";
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
    cout <<"\n>";
}
