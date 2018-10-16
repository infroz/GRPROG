//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_08.CPP


//   L�sningsforslag til oppgave nr.8  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  int antall = 0, tall;                     //  Definerer 3 variable.
  int totalsum = 0;            

  cout << "Skriv ett tall (negativt for � avslutte):  ";
  cin >> tall;                  

  while (tall > 0)  {                       
    ++antall;                               //  Teller opp antallet lest.
    totalsum += tall;                       //  �ker totalsummen.
    cout << "Skriv ett tall (negativt for � avslutte):  ";
    cin >> tall;
  }

  cout << "\nAntall tall lest:    " << antall;     //  Utskrift og utregning:
  cout << "\nDeres totalsum:      " << totalsum;
  cout << "\nDeres gjennomsnitt:  " << float(totalsum)/antall << '\n';
                                                   // G�r galt om antall=0 !
  return 0; 
}
