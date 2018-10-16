/*
Vebjørn Leiros

Lag et program som:
 - leser inn tre tegn
 - skriver ut hvert enkelt tegns ASCII-nummer
 - leser inn to tall av typen 'float'
 - skriver ut heltallsdelen av de to tallene
*/
#include <iostream>
#include <string>
using namespace std;


int main() {
    string text;
    
    cout << "Enter 3 characters" << endl;
    cin >> text;

	cout << "You entered: " << text << endl;

	cout << "ASCII Values" << endl
		<< text[0] << ": " << int(text[0]) << endl
		<< text[1] << ": " << int(text[1]) << endl
		<< text[2] << ": " << int(text[2]) << endl;

	float num1, num2;

	cout << "Enter 1 float number: " << endl;
	cin >> num1;
	cout << "Enter another float number: " << endl;
	cin >> num2;

	cout << "Those numbers as integers are: " << endl << "Number 1: " << int(num1) << endl;
	cout << "Number 2: " << int(num2) << endl;
}