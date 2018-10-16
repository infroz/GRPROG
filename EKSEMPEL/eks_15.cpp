//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_15.CPP

//   Programeksempel nr.15 for forelesning i  C++ -programmering. 

//   Eksemplet viser hvordan en aktuell VERDIOVERF؝RT parameter
//   til en funksjon IKKE endrer innhold selvom den formelle
//   parameteren gj�r det.  Jfr. side 169-176 i "OOP in C++".


#include <iostream>

using namespace std;

void oek(int tall);


int main()  {
  int tallet = 5;
  cout << "\nMain 1.gang, tallet:  " << tallet;           //  Skriver '5'
  oek(tallet);                                      
  cout << "\nMain 2.gang, tallet:  " << tallet << '\n';   //  Skriver '5' !!!
  return 0;                  //  Den aktuelle parameteren er VERDIOVERF�RT,
}                            //    derfor endrer ikke den aktuelle parameteren
                             //    innhold, selvom den formelle gj�r det.


void oek(int tall)  {
  cout << "\n   �K, 1.gang, tall:  " << tall;       //  Skriver '5'
  ++tall;
  cout << "\n   �K, 2.gang, tall:  " << tall;       //  Skriver '6'
}
