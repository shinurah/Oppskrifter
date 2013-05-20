#include <iostream>
using namespace std;

class Meny {
public: 
	Meny();
	void MenyValg()
	{
		cout << endl;
		cout << "Meny "  << endl;
		cout << "1. Ny oppskrift" << endl;
		cout << "2. Kj" << (char)155 << "r mordi" << endl;
		cout << "3. noob" << endl;
		cout << "4. Vis kj" << (char)155 << "rte mammaer" << endl;
		cout << "0. Avslutt" << endl;
    
		cout << "Ditt valg: ";		
	};

private:
	int valg;
};