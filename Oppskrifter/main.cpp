#include "main.h"

using namespace std;

static string Hodelinje1, Hodelinje2;
const string mvTabell = "matvaretabellen.csv";
static string id;
static string navn;
static string vann;
static string kilojoule;
static string fett;
static string kolesterol;
static string karbohydrat;
static string kostfiber;
static string protein;
static string vitaminA;
static string vitaminD;
static string vitaminE;
static string vitaminC;

void main()
{
	//vector <Tabell> matvaretabell;

	//ifstream innfil;	//deklarerer fil-variabelen/objektet

	////Leser ut fra matvaretabellen
	//innfil.open(mvTabell.c_str(), ios::in);
	//if (innfil.fail()) {
	//	cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"matvaretabellen.csv\" eksisterer!" << endl;
	//} 
	//else 
	//{

	//	//innfil >> antall_redusertPris >> antall_fullPris >> antall_billett;
	//	getline ( innfil, Hodelinje1, '\n' );
	//	getline ( innfil, Hodelinje2, '\n' );
	//	while (!innfil.eof()) 
	//	{
	//		
	//		getline ( innfil, id, ';');
	//		
	//		getline ( innfil, navn, ';');
	//		
	//		getline ( innfil, vann, ';');
	//		
	//		getline ( innfil, kilojoule, ';');
	//		
	//		getline ( innfil, fett, ';');
	//		
	//		getline ( innfil, kolesterol, ';');
	//		
	//		getline ( innfil, karbohydrat, ';');
	//		
	//		getline ( innfil, kostfiber, ';');
	//		
	//		getline ( innfil, protein, ';');
	//		
	//		getline ( innfil, vitaminA, ';');
	//		
	//		getline ( innfil, vitaminD, ';');
	//		
	//		getline ( innfil, vitaminE, ';');
	//		
	//		getline ( innfil, vitaminC, ';');

	//		// Opprett et nytt Tabellinput og legg i vektor
	//		Tabell nyTabell(
	//			(string)id, 
	//			(string)navn, 
	//			(string)vann, 
	//			(string)kilojoule,
	//			(string)fett,
	//			(string)kolesterol,
	//			(string)karbohydrat,
	//			(string)kostfiber,
	//			(string)protein,
	//			(string)vitaminA,
	//			(string)vitaminD,
	//			(string)vitaminE,
	//			(string)vitaminC);

	//		matvaretabell.push_back(nyTabell);
	//	}
	//}
	//innfil.close();

	//cout << "Antall: " << matvaretabell.size() << endl;

	Meny();
}