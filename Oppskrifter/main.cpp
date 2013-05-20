#include "main.h"
#include <fstream>
#include <ostream>
#include <iostream>

using namespace std;

string Hodelinje1;

void main()
{
	vector <Tabell> mv;

	ifstream innfil;
	innfil.open("matvaretabellen.csv");

	//getline(innfil,Hodelinje1,"\n");
	
	// noe fucked up her!!

	Meny();
}