#include "main.h"

using namespace std;

string Hodelinje1, Hodelinje2;
const string mvTabell = "matvaretabellen.csv";
string id;
string navn;
string vann;
string kilojoule;
string fett;
string kolesterol;
string karbohydrat;
string kostfiber;
string protein;
string vitaminA;
string vitaminD;
string vitaminE;
string vitaminC;

void main()
{
	vector <mv> matvaretabell;

	mv mv;
	ifstream innfil;	//deklarerer fil-variabelen/objektet

	////Leser ut fra matvaretabellen
	innfil.open(mvTabell.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"matvaretabellen.csv\" eksisterer!" << endl;
	} 
	else 
	{

	
	//	//innfil >> antall_redusertPris >> antall_fullPris >> antall_billett;
		getline ( innfil, Hodelinje1, '\n' );
		getline ( innfil, Hodelinje2, '\n' );
		
		while (!innfil.eof()) 
		{
			
			getline ( innfil, mv.id, ';');
			getline ( innfil, mv.navn, ';');
			getline ( innfil, mv.vann, ';');
			getline ( innfil, mv.kilojoule, ';');
			getline ( innfil, mv.fett, ';');
			getline ( innfil, mv.kolesterol, ';');
			getline ( innfil, mv.karbohydrat, ';');
			getline ( innfil, mv.kostfiber, ';');
			getline ( innfil, mv.protein, ';');
			getline ( innfil, mv.vitaA, ';');
			getline ( innfil, mv.vitaD, ';');
			getline ( innfil, mv.vitaE, ';');
			getline ( innfil, mv.vitaC);

			matvaretabell.push_back(mv);
		}
	}
	innfil.close();

	cout << "Antall: " << matvaretabell.size() << endl;
	cout << matvaretabell[0].id << " " << matvaretabell[0].navn << " " << matvaretabell[0].vann << " " << matvaretabell[0].kilojoule << " " << matvaretabell[0].fett << " " << matvaretabell[0].kolesterol << " " << matvaretabell[0].karbohydrat << " " << matvaretabell[0].kostfiber << " " << matvaretabell[0].protein << " " << matvaretabell[0].vitaA << " " << matvaretabell[0].vitaD << " " << matvaretabell[0].vitaE << " " << matvaretabell[0].vitaC << endl;
	cout << matvaretabell[1].id << " " << matvaretabell[1].navn << endl;

	Meny();
}