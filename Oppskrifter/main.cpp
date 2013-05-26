#include "main.h"

// i Hearby name you std the first of your kind!
using namespace std;


// variabler..... doooooh!
string Hodelinje1, Hodelinje2;
const string mvTabell = "matvaretabellen.csv";
vector <mv> matvaretabell;

void lagOppskrift()
{
	bool MakeOppskrift = true;

	while(MakeOppskrift)
	{
		string tempVareID = "";
		string tempGram = "";
		string totalGram = "";
		cout << "Hvordan vare "<< (char)155 << "nsker du " << (char)134 << " bruke? ( svar med matvareID )" << endl;
		cin >> tempVareID;
		cout << "Hvor mye "<< (char)155 << "nsker du " << (char)134 << " bruke? ( svar i gram )" << endl;
		cin >> tempGram;
		for(int i=0; i < matvaretabell.size(); i++)
		{
			
		}
	}
}

void main()
{
	

	mv mv;
	ifstream innfil;	//deklarerer fil-variabelen/objektet

	////Leser ut fra matvaretabellen
	innfil.open(mvTabell.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"matvaretabellen.csv\" eksisterer!" << endl;
	} 
	else 
	{
		// hopper over de 2 øverste linjene i filen.
		getline ( innfil, Hodelinje1, '\n' );
		getline ( innfil, Hodelinje2, '\n' );
		
		// så lenge filen ikke har tatt slutt så kjøres dette.
		while (!innfil.eof()) 
		{
			// henter ut informasjon fra filen og lagrer inn i et objekt.
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

	// kjører meny system
	Meny();
}