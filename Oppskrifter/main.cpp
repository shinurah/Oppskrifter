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


/*
*	funsjonen MenyValg() printer ut hovedmenyens valg
*/
void MenyValg()
{
		cout << endl;

		cout << "Meny "  << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. \tNy oppskrift" << endl;
		cout << "2. \tS" << (char)155 << "k etter oppskrift" << endl;
		cout << "3. \tVis Oppskrift" << endl;
		cout << "0. \tAvslutt" << endl;
		cout << "-------------------------------------------" << endl;		
} // slutt på MenyValg()

/*
*	Funsjon som spør brukeren etter hva oppskrift skal hete, hvordan ingredienser den skal ha og hvordan mengde av ingrediensene.
*	Her blir det også lagret oppskriften i en egen fil, samt lagret inn i kokebok filen og kjørt inn i oppskrift vektoren. 
*/
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
		// validerer at riktig type input blir gjort med matvareID
		while (true) 
		{
			cout << "Hvordan vare "<< (char)155 << "nsker du " << (char)134 << " bruke i \""<< oppskriftNavn << "\" ? ( svar med matvareID )" << endl;
			getline(cin, input);

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> tempVareID)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}

		// validerer at riktig type input blir gjort i mengde
		while (true) 
		{
			cout << "Hvor mye "<< (char)155 << "nsker du " << (char)134 << " bruke? ( i gram )" << endl;
			getline(cin, input);

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> tempGram)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}
		
		

		// finner matvare og legger til data i variabler
		for(unsigned int i=0; i < matvaretabell.size(); i++)
		{
			if(matvaretabell[i].id == tempVareID) // om matvareID stemmer med input
			{
				// setter navnet til matvaren inn i ett temp vector som holder navn
				ingre_temp_navn.push_back(matvaretabell[i].navn);
				
				// converterer input og setter mengde til matvaren inn i ett temp vector som holder mengden
				stringstream convert;
				convert << tempGram;
				ingre_temp_mengde.push_back(convert.str());

				// oppdaterer totalverdier
				totalProtein = ((double)totalProtein + (((double)matvaretabell[i].protein/100) * tempGram));
				totalFett = ((double)totalFett + (((double)matvaretabell[i].fett/100) * tempGram));
				totalVitaA = ((double)totalVitaA + (((double)matvaretabell[i].vitaA/100) * tempGram));
				totalVitaC = ((double)totalVitaC + (((double)matvaretabell[i].vitaC/100) * tempGram));
				totalVitaD = ((double)totalVitaD + (((double)matvaretabell[i].vitaD/100) * tempGram));
				totalVitaE = ((double)totalVitaE + (((double)matvaretabell[i].vitaE/100) * tempGram));
				totalVann = ((double)totalVann + (((double)matvaretabell[i].vann/100) * tempGram));
				totalkilojoule = ((double)totalkilojoule + (((double)matvaretabell[i].kilojoule/100) * tempGram));
				totalkolesterol = ((double)totalkolesterol + (((double)matvaretabell[i].kilojoule/100) * tempGram));
				totalkarbohydrat = ((double)totalkarbohydrat + (((double)matvaretabell[i].karbohydrat/100) * tempGram));
				totalkostfiber = ((double)totalkostfiber + (((double)matvaretabell[i].kostfiber/100) * tempGram));
			}
			else 
			{
				cout << "Ugyldig matvareID" << endl;
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
			//ifstream inFile(book.c_str()); 
			int oppskrift_antall = oppskrifter.size();//count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');

			// lagrer oppskriften i mappen oppskrifter
			oppskrift_antall++;
			stringstream convert;
			convert << oppskrift_antall;
				
			string lagringsfil = "oppskrifter\\" + convert.str() + ".oppskrift";
			ofstream utfil;	
			utfil.open(lagringsfil.c_str(), ios::out);
			utfil << oppskriftNavn << endl;
			utfil << "-------------------------------------------" << endl;
						
			// setter alle ingrediensene inn i oppskriftfilen
			for(unsigned int i=0; i < ingre_temp_navn.size(); i++)
			{
				utfil << ingre_temp_mengde[i] << " gram av " << ingre_temp_navn[i] << endl;
			}
			utfil.close();

			cout << "Oppskriften \"" << oppskriftNavn << "\" er lagret." << endl; 

			// legge inn i kokeboken
			utfil.open(book.c_str(), ios::app);
			utfil << "\n" << oppskrift_antall << ";" << oppskriftNavn << ";" << totalProtein << ";" << totalFett << ";" 
				<< totalVitaA << ";" << totalVitaC << ";" << totalVitaD << ";" << totalVitaE << ";" << totalkilojoule 
				<< ";" << totalkolesterol << ";" << totalkarbohydrat << ";" << totalkostfiber << ";" << totalVann;
			utfil.close();

			// legger til oppskrift først i oppskrift objekt med all data, så inn i oppskrift vectoren.
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
			oppskrift.TotalVann = totalVann;

			oppskrifter.push_back(oppskrift); // pusher oppskrift objektet inn i oppskrift vectoren
		
		}
	}
}// slutt på makeOppskrift()

/*
*	Funsjon som viser oppskrifter i oppskrift vectoren og printer disse ut på skjermen slik at brukeren kan velge hvordan oppskrift
*	brukeren ønsker å se på.
*/
void visOppskrift()
{
	cout << endl;
	cout << "Oppskrifter fra kokebok" << endl;
	cout << "Antall: " << oppskrifter.size() << endl;
	cout << "-------------------------------------------" << endl;
	
	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		cout << oppskrifter[i].id << "\t - " << oppskrifter[i].navn << endl;
	}

	cout << "-------------------------------------------" << endl;
	
	if(oppskrifter.size() == 0)
	{
		cout << "Du har ingen oppskrifter i din kokebok" << endl;
	}
	else
	{
		
		int valgtOppskrift;
		string input = "";
		
		// validerer at riktig type input blir gjort
		while (true) 
		{
			cout << "Hvilken oppskrift vil du se?" << endl;
			cin >> input;

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> valgtOppskrift)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}

		// konverterer fra double til string
		stringstream convert;
		convert << valgtOppskrift;

		// genererer filnavn til oppskrift
		string filNavn = "oppskrifter\\" + convert.str() + ".oppskrift";
		innfil.open(filNavn.c_str(), ios::in);

		if (innfil.fail()) // om filen ikke eksisterer
		{
			cout << "Det oppsto en feil ved " << (char)134 << "pning av fila " << filNavn << endl;
			cout << "eller filen finnes ikke." << endl;
		}
		else 
		{
			cout << "Leser filen " << filNavn << endl;
			string innehold = "\n"; // lagrer innehold i filen til en string.
			while (!innfil.eof()) 
			{	
				getline ( innfil, temp, '\n');
				innehold = innehold + temp + "\n";
			}
			innfil.close();
			cout << innehold;
			
			// printer ut informasjon fra oppskriften.
			cout << "Total Vann i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalVann << endl;
			cout << "Total Fett i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalFett << endl;
			cout << "Total Kilojoule i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalKilojoule << endl;
			cout << "Total Kolesterol i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalKolesterol << endl;
			cout << "Total Karbohydrat i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalKarbohydrat << endl;
			cout << "Total Kostfiber i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalKostfiber << endl;
			cout << "Total Protein i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalProtein << endl;
			cout << "Total Vitamin A i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalVitaA << endl;
			cout << "Total Vitamin D i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalVitaD << endl;
			cout << "Total Vitamin E i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalVitaE << endl;
			cout << "Total Vitamin C i oppskrift: " << oppskrifter[valgtOppskrift-1].TotalVitaC << endl;			
		}
	}
}// slutt på visOppskrift()

/*
* valg 1 i søk - Retter med mer enn x (bestemmes av bruker) g protein, fett eller karbohydrater per 100g ferdig rett.
*/
void sok1()
{
	string input = "";
	int type = 0;
	double x = 0;
	cout << endl;
	cout << "--------------------------" << endl;
	cout << "1.\tProtein" << endl;
	cout << "2.\tFett" << endl;
	cout << "3.\tKarbohydrater" << endl;

	// validerer at riktig type input blir gjort på type
	while (true) 
		{
			cout << "Velg type:" << endl;
			cin >> input;

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> type)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}

	// validerer at riktig type input blir gjort på mengde
	while (true) 
		{
			cout << "Hvor mange gram?" << endl;
			cin >> input;

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> x)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}
	
	int antallTreff = 0;

	if(type == 1)
	{
		cout << endl;
		for(unsigned int i=0; i < oppskrifter.size(); i++)
		{
			if(oppskrifter[i].TotalProtein > x )
			{
				antallTreff++;
				cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
			}
		}
	}
	
	if(type == 2)
	{
		cout << endl;
		for(unsigned int i=0; i < oppskrifter.size(); i++)
		{
			if(oppskrifter[i].TotalFett > x )
			{
				antallTreff++;
				cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
			}
		}
	}
	
	if(type == 3)
	{
		cout << endl;
		for(unsigned int i=0; i < oppskrifter.size(); i++)
		{
			if(oppskrifter[i].TotalKarbohydrat > x )
			{
				antallTreff++;
				cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
			}
		}
	}
	if(type == 0)


    cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;
} // slutt på sok1()

/*
* søk valg 2 - Retter med mer enn x kalorier per 100g ferdig rett
*/
void sok2()
{
	cout << endl;
	double x;
	string input ="";
	
	// validerer at riktig type input blir gjort
	while (true) 
	{
		cout << "Hvor mange kalorier?" << endl;
		cin >> input;

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> x)
			break;
		cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
	}

	int antallTreff = 0;

	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		if(((oppskrifter[i].TotalKilojoule*1000)/4.184) > x )
		{
			antallTreff++;
			cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
		}
	}
	cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;

} // slutt på sok2()

/*
* søk valg 3 - Retter med mye D-vitamin (i forhold til daglig anbefalt inntak) som er 7.5.
*/
void sok3()
{
	cout << endl;
	int antallTreff = 0;
	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		if(oppskrifter[i].TotalVitaD > 7.5 )
		{
			antallTreff++;
			cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
		}
	}
	cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;
} // slutt på sok3()

/*
*søk valg 4 - Retter med mye E-vitamin (i forhold til daglig anbefalt inntak) som er 10.
*/
void sok4()
{
	cout << endl;
	int antallTreff = 0;
	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		if(oppskrifter[i].TotalVitaE > 10 )
		{
			antallTreff++;
			cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
		}
	}
	cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;
} // slutt på sok4()

/*
* søk valg 5 - Retter med mye A-vitamin (i forhold til daglig anbefalt inntak) som er 900.
*/
void sok5()
{
	cout << endl;
	int antallTreff = 0;
	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		if(oppskrifter[i].TotalVitaA > 900 )
		{
			antallTreff++;
			cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
		}
	}
	cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;
} // slutt på sok5()

/*
* søk valg 6 - Retter med mye C-vitamin (i forhold til daglig anbefalt inntak) som er 75.
*/
void sok6()
{
	cout << endl;
	int antallTreff = 0;
	for(unsigned int i=0; i < oppskrifter.size(); i++)
	{
		if(oppskrifter[i].TotalVitaC > 75 )
		{
			antallTreff++;
			cout << oppskrifter[i].id << " - " << oppskrifter[i].navn << endl; 
		}
	}
	cout << endl;
	cout << "Antall treff: " << antallTreff << endl;
	cout << endl;
} // slutt på sok6()

/*
*	Funsjonen sokOppskrift printer ut meny for søk oppskrift og kjører rett søkemetoder
*/
void sokOppskrift() 
{
	// printer valgalternativer
	cout << endl;
	cout << "S"<< (char)155 << "k" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1. \tRetter med mer enn x g protein, fett"<< endl;
	cout << "\teller karbohydrater per 100g ferdig rett. " << endl;
	cout << "2. \tRetter med mer enn x kalorier per 100g ferdig rett" << endl;
	cout << "3. \tRetter med mye D-vitamin (i forhold til daglig anbefalt inntak)" << endl;
	cout << "4. \tRetter med mye E-vitamin (i forhold til daglig anbefalt inntak)" << endl;
	cout << "5. \tRetter med mye A-vitamin (i forhold til daglig anbefalt inntak)" << endl;
	cout << "6. \tRetter med mye C-vitamin (i forhold til daglig anbefalt inntak)" << endl;
	cout << "0. \tAvslutt" << endl;
	cout << "-------------------------------------------" << endl;
	
	int sokvalg = 0;
	string input ="";
	
	// validerer at riktig type input blir gjort
	while (true) 
	{
		cout << "Ditt valg: " << endl;
		cin >> input;

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> sokvalg)
			break;
		cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
	}
	
	// kjører funsjon alt etter valg.
	if(sokvalg == 1) sok1();
    if(sokvalg == 2) sok2();
	if(sokvalg == 3) sok3();
	if(sokvalg == 4) sok4();
	if(sokvalg == 5) sok5();
	if(sokvalg == 6) sok6();
	
}	// slutt på sokOppskrift()


/*
*	Funsjonen meny() kjører hovedmenyen for brukerinput. her kan du velge å lage oppskrift, søke i oppskrifter og vis en spesiell oppskrift
*
*/
void meny() 
{
	valg = 0;    // setter valg til 0
    
	MenyValg();  // printer meny valg
	string input ="";
	
	while (true) 
	{
		cout << "Ditt valg: " << endl;
		cin >> input;

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> valg)
			break;
		cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
	}
	while (valg != 0)
	{
		switch (valg)
		{
            case 1:
                cout << "Du valgte '1. Ny Oppskrift'" << endl;
				lagOppskrift();
                
                break;
            case 2:
                cout << "Du valgte '2. S" << (char)155 << "k etter oppskrift'" << endl;
                sokOppskrift();
                break;
            case 3:
                cout << "Du valgte '3. Vis Oppskrift'" << endl;
                visOppskrift();
                break;
           
            default:
                cout << "Feil brukerinput! Velg p" <<  (char)134 << " nytt." << endl;
                break;
		}
		
		valg = 0;
		MenyValg();
		
		while (true) 
		{
			cout << "Ditt valg: " << endl;
			cin >> input;

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> valg)
				break;
			cout << "Ugyldig nummer, pr"<< (char)155 << "v igjen" << endl;
		}	
	}

} // slutt på meny()

/*
*	funsjonen open() henter inn data fra lagrede filer ved programstart og kjører disse inn i vectorer slik at programmet kan lese data
*	og utføre nødvendig informasjon uten at data går tapt ved lukking av programmet.
*/

void open()
{
	mv mv;					// matvare objekt
	oppskrift oppskrift;	// oppskrift objekt

	innfil.open(book.c_str(), ios::in);
	if (innfil.fail()) // printer ut om filen ikke finnes.
	{
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"kokebok.book\" eksisterer!" << endl;
	}
	else 
	{
		while (!innfil.eof()) 
		{			
			// henter ut oppskrift id og konverterer til double
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.id = temp2;

			// henger navn på oppskrift.
			getline ( innfil, oppskrift.navn, ';');

			// henger og konverterer TotalProtein fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalProtein = temp2;

			// henger og konverterer TotalFett fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalFett = temp2;

			// henger og konverterer TotalVitaA fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalVitaA = temp2;

			// henger og konverterer TotalVitaC fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalVitaC = temp2;

			// henger og konverterer TotalVitaD fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalVitaD = temp2;

			// henger og konverterer TotalVitaE fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalVitaE = temp2;

			// henger og konverterer TotalKilojoule fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalKilojoule = temp2;

			// henger og konverterer TotalKolesterol fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalKolesterol = temp2;

			// henger og konverterer Totalkarbohydrat fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalKarbohydrat = temp2;

			// henger og konverterer TotalKostfiber fra oppskrift.
			getline ( innfil, temp, ';');
			temp2 = atof(temp.c_str());
			oppskrift.TotalKostfiber = temp2;

			// henger og konverterer TotalVann fra oppskrift.
			getline ( innfil, temp);
			temp2 = atof(temp.c_str());
			oppskrift.TotalVann = temp2;
			
			// legger inn i oppskrift vector
			oppskrifter.push_back(oppskrift);
			
		}
		innfil.close();
		cout << "Henter data fra Kokebok.book" << endl;
	}



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

}	// slutt på open()

/*
*	Funsjonen main() kjøres ved programmets start
*	Den ber om å kjøre open() for å hente data fra filer og så kjører den meny() funsjonen.
*/

void main()
{
	open();		// henter ut fra filer og legger i vectorer
	meny();		// kjører meny
}	// slutt på main()