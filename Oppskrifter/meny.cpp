#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int meny();
int valg;

int meny()
{
	valg = 0;
    
	cout << "Meny "  << endl;
	cout << "1. Ny oppskrift" << endl;
	cout << "2. Kj" << (char)155 << "p billetter" << endl;
	cout << "3. Vis ledige seter" << endl;
	cout << "4. Vis billettinntekter for denne forestillingen" << endl;
	cout << "0. Avslutt" << endl;
    
	cout << "Ditt valg: ";
	cin >> valg;

	while (valg != 0)
	{
		switch (valg)
		{
            case 1:
                cout << "Du valgte '1. Ny forestilling'" << endl;
                
                break;
            case 2:
                cout << "Du valgte '2. Kj" << (char)155 << "p billetter'" << endl;
                
                break;
            case 3:
                cout << "Du valgte '3. Vis ledige seter'" << endl;
                
                break;
            case 4:
                cout << "Du valgte '4. Vis billettinntekter for denne forestillingen'" << endl;
                
                break;
            default:
                cout << "Feil brukerinput! Velg p" <<  (char)134 << " nytt." << endl;
                break;
		}
	}
    
	return 0;
}