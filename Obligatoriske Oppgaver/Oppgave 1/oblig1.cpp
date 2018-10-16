/*
    Author: Vebjørn F. Leiros
    
    Oblig 1
    
    Oppgave:
    
    Lag et program hvor bruker skriver inn og leser: ett heltall, ett flyttall og to tegn.
    Skriv disse variablene ut igjen på en linje med ett tabulatorhopp mellom hver, og i 
    motsatt rekkefølge av det de ble lest inn.
*/
#include <iostream>;

using namespace std;

int main()
{
    int heltall;
    float flyttall;
    char tegn1;
    char tegn2;
    
    cout << "Skriv inn et heltall: ";
    cin >> heltall;
    
    cout << "\nSkriv in et \"flyttall\": ";
    cin >> flyttall;
    
    cout << "\nSkriv inn et tegn: ";
    cin >> tegn1;
    
    cout << "\nSkriv inn et tegn til: ";
    cin >> tegn2;
    
    cout << "Utskrift: "<< tegn2 << "\t" << tegn1 << "\t" << flyttall << "\t" << heltall;
    
    return 0;
}