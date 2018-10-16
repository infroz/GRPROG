//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_43.CPP

//   Programeksempel nr.43 for forelesning i  C++ -programmering.

//   "Oppsummerende" eksempel fra kap.5 (funksjoner) med bruk av:
//    verdi-/referanseoverf�ring, return og overloading.


#include <iostream>    //  cin, cout
#include <cctype>      //  toupper

using namespace std;

struct Brok  {         //  Inneholder data om EN br�k:
  int teller;          //  Dets teller (over br�kstreken).
  int nevner;          //  Dets nevner (under br�kstreken).
};


struct Tidspunkt  {    //  Inneholder data om ETT tidspunkt:
  int time,            //  Timer.
      min,             //  Minutter.
      sek;             //  Sekunder.
};


void skrivMeny();
char lesKommando();

void brokregning();    //  Funksjoner som har med br�kregningen � gj�re:
void lesInn(Brok & brok);
void lesInn(int & t, int & n);
void skriv(const Brok b);
float desimalt(const Brok b);
Brok sum(const Brok b1, const Brok b2);
Brok diff(const Brok b1, const Brok b2);
Brok prod(const Brok b1, const Brok b2);
Brok div(const Brok b1, const Brok b2);

void tidspunkt();      //  Funksjoner som har med tidsregningen � gj�re:
int  lesInn(const int MAX);
void skriv(const Tidspunkt t);
int  antSek(const Tidspunkt t);
void sorter(Tidspunkt & t1, Tidspunkt & t2);


                       //  HOVEDPROGRAMMET:
int main()  {
  char valg;             //  Brukerens valg/�nske/kommando.

  skrivMeny();           //  Skriver/viser bruker-menyen.
  valg = lesKommando();  //  Leser brukerens valg/�nske/kommando.

  while (valg != 'Q')  { //  S� lenge ikke avslutte:
    switch (valg)  {
      case 'B':  brokregning();  break;
      case 'T':  tidspunkt();    break;
      default:   skrivMeny();   break;
    }
    valg = lesKommando(); //  Leser igjen brukerens valg/�nske/kommando.
  }
  cout << "\n\n";
  return 0;
}


void skrivMeny()  {         //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nF�lgende kommandoer er aktuelle:\n";
  cout << "\tB   - Br�ker\n";
  cout << "\tT   - Tidspunkt\n";
  cout << "\tQ   - Quit / avslutt\n";
}


char lesKommando()  {        //  Leser brukerens valg/�nske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nGi kommando (B, T, Q):  ";  //  Ber om ett tegn.
  cin >> ch;    ch = toupper(ch);          //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}



// *********************   B R � K R E G N I N G :   ********************

void brokregning()  {        //  Hovedfunksjon som styrer br�kregningen:
  Brok brok1, brok2,         //  To struct'er som inneholder br�ker.
       svar;                 //  Br�ken som er svaret p� regnestykket.
  char oper;                 //  Operatoren mellom br�kene.
  bool ok = true;            //  Om gyldig operator er brukt eller ei.

  cout << "\nBr�kregnestykke ( t1/n1 [+, -, *, /] t2/n2 ):  ";
  lesInn(brok1);            //  Leser inn den f�rste br�ken.
  cin >> oper;               //  Leser operatoren (+, -, *, /) mellom br�kene.
  lesInn(brok2.teller, brok2.nevner);  // Leser inn den andre br�ken.

  switch(oper)  {            //  Utf�rer regneoperasjon p� br�kene alt etter
    case '+': svar = sum(brok1, brok2);   break;   //  hva operatoren mellom
    case '-': svar = diff(brok1, brok2);  break;   //  dem er:
    case '*': svar = prod(brok1, brok2);  break;
    case '/': svar = div(brok1, brok2);   break;
    default:  ok   = false;  cout << "\nUgyldig operator brukt!\n";  break;
  }
  
  if (ok)  {                 //  Operatoren mellom er en av de gyldige:
     cout << "\n\n\t";       //  Skriver begge br�kene og svaret:
     skriv(brok1);   cout << "  " << oper << "  ";
     skriv(brok2);   cout << "  =  ";
     skriv(svar);    cout << "\t(= " << desimalt(svar) << ")\n";
  }
}

                             //  Leser inn og oppdaterer direkte medsendt
void lesInn(Brok & brok)  {  //     (referanse overf�rt) struct:
  char ch;                   //  Dummy-variabel for � lese '/'.
  cin >> brok.teller;        //  Leser inn br�kens teller.
  cin >> ch;                 //  Leser skilletegnet ('/').
  cin >> brok.nevner;        //  Leser inn br�kens nevner.
}

                             //  Leser inn og oppdaterer direkte medsendte
void lesInn(int & t, int & n)  {  //  (referanse overf�rt) enkelt-variable:
  char ch;                   //  Dummy-variabel for � lese '/'.
  cin >> t;                  //  Leser inn teller.
  cin >> ch;                 //  Leser skilletegnet ('/').
  cin >> n;                  //  Leser inn nevner.
}

                             //  Skriver en br�k p� skjermen:
void skriv(const Brok b)  {    //  'b' avleses kun, derfor 'const'.
  cout << b.teller << '/' << b.nevner;
}

                             //  Omgj�r (og returnerer) en br�k desimalt:
float desimalt(const Brok b)  {    //  'b' avleses kun, derfor 'const'.
  return ( float(b.teller) / b.nevner );
}

                             //  Summerer/adderer/legger sammen to br�ker:
Brok sum(const Brok b1, const Brok b2)  {  //  =  (t1*n2 + t2*n1) / (n1*n2)
  Brok b;                    //  Finner svaret p� regnestykket:
  b.teller = b1.teller * b2.nevner  +  b2.teller * b1.nevner;
  b.nevner = b1.nevner * b2.nevner;
  return b;                  
}

                             //  Subtraherer/trekker fra hverandre to br�ker:
Brok diff(const Brok b1, const Brok b2)  {  // =  (t1*n2 - t2*n1) / (n1*n2)
  Brok b;                    //  Finner svaret p� regnestykket:
  b.teller = b1.teller * b2.nevner  -  b2.teller * b1.nevner;
  b.nevner = b1.nevner * b2.nevner;
  return b;
}

                             //  Ganger/produktet mellom to br�ker:
Brok prod(const Brok b1, const Brok b2)  {  // =  (t1*t2) / (n1*n2)
  Brok b;                    //  Finner svaret p� regnestykket:
  b.teller = b1.teller * b2.teller;
  b.nevner = b1.nevner * b2.nevner;
  return b;
}

                             // Deler/divisjon mellom to br�ker:
Brok div(const Brok b1, const Brok b2)  {  //  = (t1*n2) / (n1*t2)
  Brok b;                    //  Finner svaret p� regnestykket:
  b.teller = b1.teller * b2.nevner;
  b.nevner = b1.nevner * b2.teller;
  return b;
}



// *********************   T I D S P U N K T :   ********************

void tidspunkt()  {          //  Hovedfunksjon som styrer tidspunktene:
                             //  To Tidspunkt-struct'er som initieres,
  Tidspunkt tid1 = {3, 23, 48}, tid2 = {17, 52, 14},  
            tid3;            //    og en som brukeren gir verdier til.
  cout << "\n\tTime:   ";  tid3.time = lesInn(23);  //  Fyller 'tid3'
  cout << "\tMinutt: ";    tid3.min  = lesInn(59);  //    med gyldige
  cout << "\tSekund: ";    tid3.sek  = lesInn(59);  //    verdier.
                             //  Skriver de tre tidspunktene, ogs� deres
                             //     verdier konvertert til kun sekunder:
  cout << "\nTidspunkt nr.1: ";  skriv(tid1);   
                                 cout << "\t#sek: " << antSek(tid1);
  cout << "\nTidspunkt nr.2: ";  skriv(tid2);
                                 cout << "\t#sek: " << antSek(tid2);
  cout << "\nTidspunkt nr.3: ";  skriv(tid3);
                                 cout << "\t#sek: " << antSek(tid3);
  sorter(tid1, tid2);        //  'Tid2' er st�rst hittil.
  sorter(tid2, tid3);        //  'Tid3' ER den aller st�rste.
  sorter(tid1, tid2);        //  'Tid2' ER den nest st�rste.
  cout << "\n\nTidspunktene skrevet i �kende rekkef�lge:\n\t";
  skriv(tid1);  cout << '\t';   //  Skriver ut de sorterte verdiene:
  skriv(tid2);  cout << '\t';  
  skriv(tid3);  cout << '\n';
}

                               //  Leser inn og returnerer verdi i intervallet
int lesInn(const int MAX)  {   //  0 til MAX.
  int tall;                    //  Innskrevet tallverdi.
  cin >> tall;                 //  Leser tall.
  while (tall < 0  ||  tall > MAX)  {    //  Utenfor gyldig intervall:
     cout << "\ti intervallet (0-" << MAX << "):  ";
     cin >> tall;
  }
  return tall;               //  Returnerer akseptert (gyldig) tall
}


void skriv(const Tidspunkt t)  {   //  Skriver tidspunktet p� formen tt:mm:ss:
  if (t.time < 10)  cout << '0';   //  Legger evt. til innledende null ('0').
  cout << t.time << ':'; 
  if (t.min < 10)  cout << '0';
  cout << t.min << ':';
  if (t.sek < 10)  cout << '0';
  cout << t.sek;
}


int antSek(const Tidspunkt t)  {  //  Gj�r om tidspunkt til sekunder:
  return (t.time*3600 + t.min*60 + t.sek);
}

                                   //  Bytter om (om n�dvendig) slik at 't2'
                                   //     ALLTID er st�rre eller lik 't1':
void sorter(Tidspunkt & t1, Tidspunkt & t2)  {
  int ts1 = antSek(t1),            //  Omgj�r t1 og t2 til antall sekunder:
      ts2 = antSek(t2);
  Tidspunkt temp;                  //  Hjelpevariabel for � kopiere.

  if (ts1 > ts2)  {                //  't1' er st�rst:
     temp = t1;                    //  Bytter om 't1' og 't2':
     t1 = t2;
     t2 = temp;
  }
}
