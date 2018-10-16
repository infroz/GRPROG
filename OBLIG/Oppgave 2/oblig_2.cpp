/*
    Author: Vebjørn F. Leiros
    
    Oblig 2
    
    Oppgave:
    
    Lag et program som registrerer antall dager og, temperatur
	og nedbør per dag. Programmet skal deretter skrive ut
	gjennomsnitt av temperaturog totalt nedbør
*/

#include <iostream>

using namespace std;

int main()
{
	// Variables
		// Constants
			const int rMaxTemp = 70, rMinTemp = -70;		// Temperature Range
			const int rMaxNedbor = 200, rMinNedbor = 0;		// Nedbord Range
			const int rMaxDays = 4, rMinDays = 1;			// day range

		// other variables
			bool restart = false;
	// main program
	do {
		int days;

		do {
			cout << "Please enter number of days for current input (" 
				<< rMinDays << " - " << rMaxDays << ")\nInput:";
			cin >> days;
		} while (days > rMaxDays || days < rMinDays);
		// if Input is outside of range it will return true and restart loop

		// sum of user inputs below
		int minTemp = 0 , maxTemp = 0, nedbor = 0;

		// User input for maxTemp, minTemp and nedbor
		for (int i = 1; i <= days; i++) {
			// Loops per day, based on user input
			// minTemp
			int cMinTemp = 0;	// Current minTemp

			do {
				cout << "\nEnter minTemp day " << i << "(" 
					<< rMinTemp << " - " << rMaxTemp << "):";
				cin >> cMinTemp;
			} while (cMinTemp > rMaxTemp || cMinTemp < rMinTemp);

			minTemp += cMinTemp;

			int cMaxTemp = 0;

			do {
				cout << "\nEnter maxTemp day " << i << "(" 
					<< cMinTemp << " - " << rMaxTemp << "):";
				cin >> cMaxTemp;
			} while (cMaxTemp > rMaxTemp || cMaxTemp < cMinTemp);

			maxTemp += cMaxTemp;

			int cNedbor = 0;

			do {
				cout << "\nEnter nedbor in mm ("
					<< rMinNedbor << " - "
					<< rMaxNedbor << "):";
				cin >> cNedbor;
			} while (cNedbor > rMaxNedbor || cNedbor < rMinNedbor);

			nedbor += cNedbor;

		}

		//Calculations and end results

		int avgMaxTemp = maxTemp / days, 
			avgMinTemp = minTemp / days, 
			avgNedbor = nedbor / days;

		cout << "\nResults from input:"
			<< "\n\tAverage maxTemp: " << avgMaxTemp
			<< "\n\tAverage minTemp: " << avgMinTemp
			<< "\n\tAverage nedbor: " << avgNedbor
			<< "\n\tTotal nedbor: " << nedbor;

		// Program end
		char rInput;
		cout << "\nDo you want to run the program again? (y/n)\nInput:";

		bool error = true;
		do {
			// Switch restart - in case of user input error
			cin >> rInput;

			switch (rInput) {
				// input handling
				case 'y':
					// Case Yes, user wants to restart program
					restart = true;
					error = false;
					break;
				case 'n':
					// Case No, user does not want to restart
					restart = false;
					error = false;
					break;
				default: {
				// Error, user did not enter proper input, restart
				// switch statement
					cout << "Input error, type y or n\n";
					error = true;
					break;
				}
			}
		} while (error);

	} while (restart);

	cout << "Thank you for using the program, have a nice day";
	// Nice exit message

	return 0;
}