#include <iostream>
using namespace std;

class Tabell {

public: 
	Tabell(string id, string navn, string vann, string kilojoule, string fett, string kolesterol, string karbohydrat, string kostfiber, string protein, string vitaA, string vitaD, string vitaE, string vitaC);
	
private:
	static string id;
	static string navn;
	static string vann;
	static string fett;
	static string kilojoule;
	static string kolesterol;
	static string karbohydrat;
	static string kostfiber;
	static string protein;
	static string vitaA;
	static string vitaD;
	static string vitaE;
	static string vitaC;
};