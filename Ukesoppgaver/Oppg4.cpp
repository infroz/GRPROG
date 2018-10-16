// Vebjørn Leiros
// Oppgave 4
// Program som leser inn heltall og utregner: Kvadrat av hvert tall, Summen av tallene,  Gjennomsnittet av tallene, Gjennomsnittet av kvadratene
#include <iostream>
using namespace std;

int main ()
{
    int var1;
    int var2;
    
    cout << "Skriv inn tall1" << endl;
    cin >> var1;
    cout << "Skriv inn tall2" << endl;
    cin >> var2;
    
    cout << "Tall1: " << var1 << " Tall2: " << var2 << endl;
    
    float kvadrat1 = var1 * var1;
    float kvadrat2 = var2 * var2;
    cout << "Kvadrat tall1: " << kvadrat1 << " Kvadrat tall2: " << kvadrat2 << endl;
    cout << "Sum: " << var1 + var2 << endl;
    cout << "Gjennomsnitt: " << (var1 + var2) / 2 << endl;
    cout << "Gjennomsnitt Kvadrat: " << (kvadrat1 + kvadrat2) / 2 << endl;
    return 0;
}