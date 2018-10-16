/*
    Vebjørn Leiros

	Oppgave 6

Lag et program med følgende output:

	               Kamper     Seire      Uavgj.     Tap      Poeng  
	STORHAMAR        18        14         1          3        29  
	Lillehammer      18        12         4          2        28  
	Stavanger        18        10         3          5        23  
	VIF Hockey       18        10         2          6        22

 GRATULERER MED SERIEMESTERSKAPET, STORHAMAR !!
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	cout << setw(20) << "Kamper" << setw(10) << "Seire" << setw(10) << "Uavgj." << setw(10) << "Tap" << setw(10) << "Poeng" << endl;
	cout << setw(15) << left << "STORHAMAR"		<<  setw(10)	<< 18 << setw(10)	<< 14 << setw(10)	<< 1 << setw(10)	<< 3 << setw(10)	<< 29 << endl;
	cout << setw(15) << left << "Lillehammer"	<< setw(10)		<< 18 << setw(10)	<< 12 << setw(10)	<< 4 << setw(10)	<< 2 << setw(10)	<< 28 << endl;
	cout << setw(15) << left << "Stavanger"		<< setw(10)		<< 18 << setw(10)	<< 10 << setw(10)	<< 3 << setw(10)	<< 5 << setw(10)	<< 23 << endl;
	cout << setw(15) << left << "VIF Hockey"	<< setw(10)		<< 18 << setw(10)	<< 10 << setw(10)	<< 2 << setw(10)	<< 6 << setw(10)	<< 22 << endl;
}