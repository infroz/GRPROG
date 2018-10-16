/*
    Author: Vebjørn F. Leiros
    
    Oppgave i korthet:
    lag program som skal håndtere 3 brøker
    og regneoperasjoner mellom disse
    
    Det skal utføres regneoperasjoner på
    2 av gangen.
*/

#include <iostream>;
using namespace std;

// Struct til brøk
struct Brok
{
	int teller,
		nevner;
};

void initBroek(Brok&);		// Legge til verdier
void calcBroek(Brok, Brok);	// Kalkulere svar
void inputError(char);		// Error

int main()
{
	Brok	a,
			b,
			c,
			temp1,
			temp2;
    char cmd; // Input

	// Lager 3 brøker
	cout << "\nBroek nr.1:";
	initBroek(a);
	cout << "\nBroek nr.2:";
	initBroek(b);
	cout << "\nBroek nr.3:";
	initBroek(c);

	do {
		// Meny
		cout << "\nOperere paa broekene: "
			<< "\n\tA - nr.1 og nr.2"
			<< "\n\tB - nr.1 og nr.3"
			<< "\n\tC - nr.2 og nr.3"
			<< "\n\tQ - Quit";

        // Input Håndtering
		cout << "\nInput: ";
		cin >> cmd;
		switch (toupper(cmd)) {
		case('A'): temp1 = a; temp2 = b; break;	//1 og 2
		case('B'): temp1 = a; temp2 = c; break;	//1 og 3
		case('C'): temp1 = b; temp2 = c; break;	//2 og 3
		case('Q'): break;         			// Unngå at inputerror kjører
		default: inputError(cmd); break;	// Error
		};
	} while (toupper(cmd) != 'Q');

	return 0;
}

// Funksjon for å legge inn verdier
void initBroek(Brok& broek) 
{
	int n;
	cout << "\n\tTeller: ";
	cin >> broek.teller;
	do {
		cout << "\n\tNevner(>0): ";
		cin >> n;
	} while (n <= 0);
	broek.nevner = n;
}

void calcBroek(Brok d1, Brok d2)
{
	char cmd;
	bool ikkeKalkulert = true;
	int tempTeller, tempNevner;

	cout << "\nVelg Operator (+, -, *, /): ";
	do {
		cin >> cmd;
		switch (cmd) {
		case('+'):
			tempTeller = (d1.teller * d2.nevner) + (d2.teller * d1.nevner);
			tempNevner = d1.nevner * d2.nevner;
            
			ikkeKalkulert = false;
			break; 
		case('-'):
			tempTeller = (d1.teller * d2.nevner) - (d2.teller * d1.nevner);
			tempNevner = d1.nevner * d2.nevner;
            
			ikkeKalkulert = false;
			break; 
		case('*'):
			tempTeller = d1.teller * d2.teller;
			tempNevner = d1.nevner * d2.nevner;

			ikkeKalkulert = false;
			break; 
		case('/'):
			tempTeller = d1.teller * d2.nevner;
			tempNevner = d1.nevner * d2.teller;

			ikkeKalkulert = false;
			break; 
		default: inputError(cmd); break;
		};
	} while (ikkeKalkulert);

	// Utskrift
}
// Input error, for å holde koden ryddig
void inputError(char input) 
{
	cout << "\nError in input, \"" << input << "\" is not defined.";
}