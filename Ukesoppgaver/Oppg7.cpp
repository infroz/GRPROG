/*
    Vebjørn Leiros

	Oppgave 7

	Lag er program som skriver ut sammenhengen mellom radie og volum for en sylinder. 
	Høyden skal fast være 4, og radien skal variere fra 1 til 20. 
	Skriv kun en sammenheng pr.linje på skjermen, og bruk for-løkke
*/
#include <iostream>
using namespace std;

double pwr(float num, int by) {
	double x = num;
	int flr = 2; // Pga opphoyes i 2
	while (flr <= by) {

		x = x * num;
		flr = flr + 1;
	}

	return x;
}

int main() {
	const double PI = 3.14159265359;

    int rad = 4;
    int height() {
        int h;
        cout << "Skriv radius av sylinderet (1-20 heltall)";
        cin >> h;
        cout << endl;
        
        if (h < 1 || h > 20) {
            cout << "h er utenfor 1-20" << endl;
        }
    }
	cout << "Volume of cylinder is: \n"
		<< (PI * pwr(rad, 2) * height());
	
}