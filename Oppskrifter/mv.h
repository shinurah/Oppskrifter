#include <iostream>
using namespace std;

class mv {

public: 
	mv();
	string getNavn();
	double getId();
	double getFett();
	double getKarbo();
	double getProtein();
	double getKalori();
	double getDvita();
	double getCvita();
	double getBvita();
	double getAvita();
	
private:

	string id;
	string navn;
	double fett;
	double karbo;
	double protein;
	double kalori;
	double dvitamin;
	double cvitamin;
	double bvitamin;
	double avitamin;
};