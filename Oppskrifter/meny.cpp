#include <iostream>
#include "meny.h"

using namespace std;

Meny::Meny()
{
	Meny::valg = 0;
    
	Meny::MenyValg();
	cin >> Meny::valg;

	while (Meny::valg != 0)
	{
		switch (Meny::valg)
		{
            case 1:
                cout << "Du valgte '1. Ny Oppskrift'" << endl;
                
                break;
            case 2:
                cout << "Du valgte '2. Kj" << (char)155 << "r mordi'" << endl;
                
                break;
            case 3:
                cout << "Du valgte '3. Noob'" << endl;
                
                break;
            case 4:
                cout << "Du valgte '4. Kj" << (char)155 << "rte mammaer'" << endl;
                
                break;
            default:
                cout << "Feil brukerinput! Velg p" <<  (char)134 << " nytt." << endl;
                break;
		}
		
		Meny::valg = 0;
		Meny::MenyValg();
		cin >> Meny::valg;	
	}
}