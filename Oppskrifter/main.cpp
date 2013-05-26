/** 
* Tittel: Karaktergivende Oppgave i C++

* Beskrivelse: 
			Du har fått i oppdrag fra kjøkkensjef S. Jeffsen på Toppen Høgfjellshotell å lage et program 
			som hjelper han å holde orden på ernæringsinformasjon knyttet til måltider som han 
			komponerer

* forfatter: Mikael Bendiksen & Lisa Marie Sørensen 
**/


#include "main.h"		// inkludering av header til main
using namespace std;	// setter namespace til std


// ---------------------------------------
//	Variabler
// ---------------------------------------

string Hodelinje1, Hodelinje2;						// variabler for å ta topheadere i CSV fil.
const string mvTabell = "matvaretabellen.csv";		// inndata fra CSV fil
const string book = "kokebok.book";					// kokebok for oppskrifter
vector <mv> matvaretabell;							// vektor av matvarer fra CSV fil
vector <oppskrift> oppskrifter;						// vektor av oppskrifter 
int valg;											// valg for meny
ifstream innfil;									// deklarerer fil-variabelen/objektet
string temp;										// input string for konvertering fra String CSV
double temp2;										// output double etter konvertering fra string CSV


// Meny print
void MenyValg()
{
		cout << endl;
		cout << "Meny "  << endl;
		cout << "1. Ny oppskrift" << endl;
		cout << "2. S" << (char)155 << "k etter oppskrift" << endl;
		cout << "3. Vis Oppskrift" << endl;
		cout << "0. Avslutt" << endl;
    
		cout << "Ditt valg: ";		
};


// lag oppskrift
void lagOppskrift()
{
	bool MakeOppskrift = true;			// Setter oppskrift whileloop aktiv
	string oppskriftNavn = "";			// string for oppskrift navn
	double tempVareID = 0;				// temp for matvareID
	double tempGram = 0;				// temp for gram
	double totalGram = 0;				// total gram i oppskrift
	double totalProtein = 0;			// total protein i oppskrift
	double totalFett = 0;				// total fett i oppskift
	double totalVitaA = 0;				// total Vitamin A
	double totalVitaC = 0;				// total Vitamin C
	double totalVitaD = 0;				// total Vitamin D
	double totalVitaE = 0;				// total Vitamin E
	double totalVann = 0;				// total Vann
	double totalkilojoule = 0;			// total Kilojoule
	double totalkolesterol = 0;			// total kolesterol
	double totalkarbohydrat = 0;		// total karbohydrat
	double totalkostfiber = 0;			// total kostfiber
	vector <string> ingre_temp_navn;	// temp vector for ingrediense navn
	vector <string> ingre_temp_mengde;  // temp vector for ingredisense mengde

	string flere_ing;	// String for å sjekke om brukeren ønsker flere ingredisenser i oppskiften

	// spør brukeren om navnet på oppskriften
	cout << "Hva heter oppskriften" << endl;
	string input = "";
	getline(cin, input);

	// en fix for å få mellomrommet mellom i navnet
	oppskriftNavn = input;
	getline(cin, oppskriftNavn);

	// while loop for ingredienser
	while(MakeOppskrift)
	{

		// brukerinput
		cout << "Hvordan vare "<< (char)155 << "nsker du " << (char)134 << " bruke i \""<< oppskriftNavn << "\" ? ( svar med matvareID )" << endl;
		cin >> tempVareID;
		cout << "Hvor mye "<< (char)155 << "nsker du " << (char)134 << " bruke? (antall)" << endl;
		cin >> tempGram;

		// finner matvare og legger til data i variabler
		for(int i=0; i < matvaretabell.size(); i++)
		{
			if(matvaretabell[i].id == tempVareID)
			{
				// setter navnet til matvaren inn i ett temp vector som holder navn
				ingre_temp_navn.push_back(matvaretabell[i].navn);
				
				// converterer input og setter mengde til matvaren inn i ett temp vector som holder mengden
				stringstream convert;
				convert << tempGram;
				ingre_temp_mengde.push_back(convert.str());

				// oppdaterer totalverdier
				totalProtein = ((double)totalProtein + ((double)matvaretabell[i].protein * tempGram));
				totalFett = ((double)totalFett + ((double)matvaretabell[i].fett * tempGram));
				totalVitaA = ((double)totalVitaA + ((double)matvaretabell[i].vitaA * tempGram));
				totalVitaC = ((double)totalVitaC + ((double)matvaretabell[i].vitaC * tempGram));
				totalVitaD = ((double)totalVitaD + ((double)matvaretabell[i].vitaD * tempGram));
				totalVitaE = ((double)totalVitaE + ((double)matvaretabell[i].vitaE * tempGram));
				totalVann = ((double)totalVann + ((double)matvaretabell[i].vann * tempGram));
				totalkilojoule = ((double)totalkilojoule + ((double)matvaretabell[i].kilojoule * tempGram));
				totalkolesterol = ((double)totalkolesterol + ((double)matvaretabell[i].kilojoule * tempGram));
				totalkarbohydrat = ((double)totalkarbohydrat + ((double)matvaretabell[i].karbohydrat * tempGram));
				totalkostfiber = ((double)totalkostfiber + ((double)matvaretabell[i].kostfiber * tempGram));
			}
		}

		// printer ut informasjon sålangt i oppskriften.
		cout << "Total Vann i oppskrift: " << totalVann << endl;
		cout << "Total Fett i oppskrift: " << totalFett << endl;
		cout << "Total Kilojoule i oppskrift: " << totalkilojoule << endl;
		cout << "Total Kolesterol i oppskrift: " << totalkolesterol << endl;
		cout << "Total Karbohydrat i oppskrift: " << totalkarbohydrat << endl;
		cout << "Total Kostfiber i oppskrift: " << totalkostfiber << endl;
		cout << "Total Protein i oppskrift: " << totalProtein << endl;
		cout << "Total Vitamin A i oppskrift: " << totalVitaA << endl;
		cout << "Total Vitamin D i oppskrift: " << totalVitaD << endl;
		cout << "Total Vitamin E i oppskrift: " << totalVitaE << endl;
		cout << "Total Vitamin C i oppskrift: " << totalVitaC << endl;

		// spør bruker om det er ønskelig med flere matvarer i oppskriften
		cout << (char)157 << "nsker du " << (char)134 << " legge til flere ingredienser? (y/n)" << endl;
		cin >> flere_ing;
		
		// setter MakeOppskrift til false om brukeren ikke ønsker flere matvarer i oppskriften
		if (flere_ing == "n")
		{
			MakeOppskrift = false;
	
			// teller antall oppskrifter i kokeboken
			ifstream inFile(book.c_str()); 
			int oppskrift_antall = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');

			// lagrer oppskriften i mappen oppskrifter
			oppskrift_antall++;
			stringstream convert;
			convert << oppskrift_antall;
				
			string lagringsfil = "oppskrifter\\" + convert.str() + ".oppskrift";
			ofstream utfil;	
			utfil.open(lagringsfil.c_str(), ios::out);
			utfil << oppskriftNavn << endl;
			utfil << "-------------------------------------------" << endl;
			utfil << "\tMatvare\t\tMengde" << endl;
			utfil << "-------------------------------------------" << endl;
			
			for(int i=0; i < ingre_temp_navn.size(); i++)
			{
				utfil << ingre_temp_navn[i] << "\t" << ingre_temp_mengde[i] << endl;
			}
			utfil.close();
			cout << "Oppskriften \"" << oppskriftNavn << "\" er lagret." << endl; 

			// legge inn i kokeboken
			utfil.open(book.c_str(), ios::app);
			utfil << oppskrift_antall << ";" << oppskriftNavn << ";" << endl;
			utfil.close();

			// funsjon for oppdatering av innleste oppskrifter med programstart
			oppskrift oppskrift;

			oppskrift.id = oppskrift_antall;
			oppskrift.navn = oppskriftNavn;
			oppskrift.TotalProtein = totalProtein;
			oppskrift.TotalFett = totalFett;
			oppskrift.TotalVitaA = totalVitaA;
			oppskrift.TotalVitaC = totalVitaC;
			oppskrift.TotalVitaD = totalVitaD;
			oppskrift.TotalVitaE = totalVitaE;
			oppskrift.TotalKilojoule = totalkilojoule;
			oppskrift.TotalKolesterol = totalkolesterol;
			oppskrift.TotalKarbohydrat = totalkarbohydrat;
			oppskrift.TotalKostfiber = totalkostfiber;

			oppskrifter.push_back(oppskrift);
		
		}
	}
}

// meny 

// NB NB NB NB NB
// bør oppdateres med sikkert input..

void meny() 
{
	valg = 0;    // setter valg til 0
    
	MenyValg();  // printer meny valg
	cin >> valg; // spør bruker etter valg

	while (valg != 0)
	{
		switch (valg)
		{
            case 1:
                cout << "Du valgte '1. Ny Oppskrift'" << endl;
				lagOppskrift();
                
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
		
		valg = 0;
		MenyValg();
		cin >> valg;	
	}

}

void open()
{
	mv mv;	// matvare objekt

	////Leser ut fra matvaretabellen
	innfil.open(mvTabell.c_str(), ios::in);
	if (innfil.fail()) 
	{
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
			// henter ut MatvareID og konverterer til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.id = temp2;

			// henter ut matvare navn
			getline ( innfil, mv.navn, ';');

			// henter ut vann fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.vann = temp2;

			// henter ut kilojoule fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.kilojoule = temp2;

			// henter ut fett fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.fett = temp2;

			// henter ut kolesterol fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.kolesterol = temp2;

			// henter ut karbohydrat fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.karbohydrat = temp2;

			// henter ut kostfiber fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.kostfiber = temp2;

			// henter ut protein fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.protein = temp2;

			// henter ut VitaminA fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.vitaA = temp2;

			// henter ut VitaminD fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.vitaD = temp2;

			// henter ut VitaminE fra matvare og konverter til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			mv.vitaE = temp2;

			// henter ut VitaminC fra matvare og konverter til double
			getline ( innfil, temp);
			temp2 = atof(temp.c_str());
			mv.vitaC = temp2;
			
			// putter matvare objekt inn i vector
			matvaretabell.push_back(mv);
		}
	}
	innfil.close(); // lokker filen


}

void main()
{
	open();

	// kjører meny system
	meny();
}