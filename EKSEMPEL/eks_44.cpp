//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_44.CPP

//   Programeksempel nr.44 for forelesning i  C++ -programmering.

//   "Oppsummerende" eksempel fra kap.6 (klasser/objekter) med bruk av:
//       constructor'er, private data og funksjoner som:
//            - er public
//            - er definert inni (inline) og utenfor klassen (vha."::")
//            - ikke tar parametre
//            - tar parametre    (ogs� objekter)
//            - returnerer verdi (ogs� objekter)
//       samt generelle funksjoner som (sammen med "main") 
//       h�ndterer/opererer p� objektene.
//
//    NB: Dette er EKS_43 omskrevet til bruk av objekter istedet for
//        struct'er og funksjoner som opererer p� disse.


#include <iostream>     //  cin, cout
#include <cctype>       //  toupper

using namespace std;

                        //  Inneholder data om EN br�k og funksjoner for �
class Brok  {           //    arbeide med / endre p� / avlese / beregne den:
  private:              //  Private/skjulte/utilgjengelige data utenfra:
    int teller;         //  Br�kens teller (over br�kstreken).
    int nevner;         //  Br�kens nevner (under br�kstreken).

  public:               //  Offentlige/�pne/tilgengelige funksjoner utenfra:
                        //  3x constructor'er som initialiserer medlemmene:
    Brok()              { teller = 0;  nevner = 1; }
    Brok(int t)         { teller = t;  nevner = 1; }  // Ikke brukt!
    Brok(int t, int n)  { teller = t;  nevner = n; }

    void lesInn()  {   //  Leser inn teller og nevner for br�ken:
        char ch;       //  Dummy-variabel for � lese '/'.
        cin >> teller; //  Leser inn br�kens teller.
        cin >> ch;     //  Leser skilletegnet ('/').
        cin >> nevner; //  Leser inn br�kens nevner.
    }

    void skriv()      //  Skriver br�ken p�/til skjermen:
      {  cout << teller << '/' << nevner;  }
    //  Man kan forkorte br�ken (finne st�rste felles divisor) ved � bruke
    //  den komplette koden gitt i Ex.6-11 s.262 i l�reboka.

    float desimalt()  //  Omgj�r (og returnerer) br�ken desimalt:
      {  return (float(teller) / nevner);  }

                                //  Summerer/adderer br�ken med en annen:
    Brok sum(const Brok b)  {            //  =  (t1*n2 + t2*n1) / (n1*n2)
        Brok brok;                       //  Lager ny "tom"/nullstilt br�k.
        brok.teller = teller * b.nevner + b.teller * nevner; // Finner teller.
        brok.nevner = nevner * b.nevner;    //  Finner nevner.
        return brok;                        //  Returnerer br�ken.
    }
                                //  Subtraherer/trekker en annen fra br�ken:
    Brok diff(const Brok b)  {           // =  (t1*n2 - t2*n1) / (n1*n2)
        int tell = teller * b.nevner - b.teller * nevner;    // Finner teller.
        int nevn = nevner * b.nevner;       //  Finner nevner.
        Brok brok(tell, nevn);              //  Lager ny br�k med differansen.
        return brok;                        //  Returnerer denne.
    }

                                //  Ganger/produktet mellom br�ken og en annen:
    Brok prod(const Brok b)  {           // =  (t1*t2) / (n1*n2)
        Brok brok(teller * b.teller, nevner * b.nevner); // Br�k med produktet.
        return brok;                                     // Returnerer denne.
    }

                                // Deler/divisjon mellom br�ken og en annen:
    Brok div(const Brok b)  {   //  = (t1*n2) / (n1*t2)
                                //  Lager br�k med svaret og returnerer denne:
        return Brok(teller * b.nevner, nevner * b.teller);
    }

// NB:  I de fire siste funksjonene ovenfor ("sum", "diff", "prod" og "div")
//      er det BEVISST benyttet FIRE ULIKE m�ter �:
//          -"gjemme unna" svarets teller og nevner p�
//          - opprette en ny "Brok" med svaret og retur av denne.
//      Den siste ("div") er den mest kompakte, og er derfor � foretrekke.

      bool erLik(const Brok b)    //  Returnerer om er lik en annen br�k:
        { return (teller == b.teller  &&  nevner == b.nevner);}

      bool erUlik(const Brok b)   //  Returnerer om er ulik en annen br�k:
        { return (teller != b.teller  ||  nevner != b.nevner); }
};


                       //  Inneholder data om ETT tidspunkt og funksjoner for �
class Tidspunkt  {     //    arbeide med / endre p� / avlese / beregne den:
  private:             //  Private/skjulte/utilgjengelige data utenfra:
    int time,          //  Timer.
        min,           //  Minutter.
        sek;           //  Sekunder.

  public:               //  Offentlige/�pne/tilgengelige funksjoner utenfra:
      Tidspunkt()  {  time = min = sek = 0;  }
      Tidspunkt(int t, int m, int s)  {  time = t;  min = m;  sek = s;  }
      void hentInn();   //  For disse tre funksjonene er selve DEFINISJONEN 
      void skriv();     //  flyttet til lengre ned i koden/p� filen:
      int  antSek();
};


void skrivMeny();
char lesKommando();
void brokregning();    //  Funksjonen som styrer br�kregningen.

void tidspunkt();      //  Funksjonen som styrer tidsregningen.
int  lesInn(const int MAX);
void sorter(Tidspunkt & t1, Tidspunkt & t2);


                       //  HOVEDPROGRAMMET:
int main()  {            //                   HELT IDENTISK TIL EKS_43.CPP:
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

                             //  HELT IDENTISK TIL EKS_43.CPP:
void skrivMeny()  {          //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nF�lgende kommandoer er aktuelle:\n";
  cout << "\tB   - Br�ker\n";
  cout << "\tT   - Tidspunkt\n";
  cout << "\tQ   - Quit / avslutt\n";
}

                             //  HELT IDENTISK TIL EKS_43.CPP:
char lesKommando()  {        //  Leser brukerens valg/�nske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nGi kommando (B, T, Q):  ";  //  Ber om ett tegn.
  cin >> ch;    ch = toupper(ch);          //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}



// *********************   B R �� K R E G N I N G :   ********************

void brokregning()  {        //  Hovedfunksjonen som styrer br�kregningen:
  Brok brok1, brok2,         //  To objekter som inneholder br�ker.
       svar;                 //  Objektet som er svaret p� regnestykket.
  char oper;                 //  Operatoren mellom br�kene.
  bool ok = true;            //  Om gyldig operator er brukt eller ei.

  cout << "\nBr�kregnestykke ( t1/n1 [+, -, *, /] t2/n2 ):  ";
  brok1.lesInn();            //  Den 1.br�ken leser inn sine data.
  cin >> oper;               //  Leser operatoren (+, -, *, /) mellom br�kene.
  brok2.lesInn();            //  Den 2.br�ken leser inn sine data.

  cout << "\n\n\tBr�kene er ";
  if (brok1.erLik(brok2))   cout << "LIKE!\n";
  if (brok1.erUlik(brok2))  cout << "IKKE LIKE!\n";

  switch(oper)  {            //  Utf�rer regneoperasjon p� br�kene alt etter
                             //     hva operatoren mellom dem er:
    case '+': svar = brok1.sum(brok2);   break; // NB! Eller: brok2.sum(brok1)
    case '-': svar = brok1.diff(brok2);  break; // NB! Kan IKKE bytte disse to!
    case '*': svar = brok2.prod(brok1);  break; // NB! Eller: brok1.prod(brok2)
    case '/': svar = brok1.div(brok2);   break; // NB! Kan IKKE bytte disse to!
    default:  ok = false;  cout << "\nUgyldig operator brukt!\n";  break;
  }
  
  if (ok)  {                 //  Operatoren mellom er en av de gyldige:
     cout << "\n\n\t";       //  Skriver begge br�kene og svaret:
     brok1.skriv();   cout << "  " << oper << "  ";
     brok2.skriv();   cout << "  =  ";
     svar.skriv();    cout << "\t(= " << svar.desimalt() << ")\n";
  }
}




// *********************   T I D S P U N K T :   ********************

void Tidspunkt :: hentInn()  {   //  Fyller medlemmene med gyldige verdier:
  cout << "\n\tTime:   ";  time = lesInn(23); 
  cout << "\tMinutt: ";    min  = lesInn(59);
  cout << "\tSekund: ";    sek  = lesInn(59);
}


void Tidspunkt :: skriv()  {      //  Skriver tidspunktet p� formen tt:mm:ss :
  cout << ((time < 10) ? "0" : "") << time << ':'   //  Legger evt. til
       << ((min  < 10) ? "0" : "") << min  << ':'   //    innledende
       << ((sek  < 10) ? "0" : "") << sek;          //    null ('0'):
}

int Tidspunkt :: antSek()        //  Gj�r om tidspunktet til sekunder:
  {  return (time*3600 + min*60 + sek);  }



void tidspunkt()  {          //  Hovedfunksjon som styrer tidspunktene:
                             //  To Tidspunkt-objekter som initieres,
  Tidspunkt tid1(3, 23, 48), tid2(17, 52, 14),
            tid3;            //    og en som brukeren gir verdier til.
  tid3.hentInn();            //  Ber "tid3" lese inn sine egne verdier.
                             //  Ber de tre tidspunktene skrive ut seg selv, 
                             //     ogs� deres verdier i kun sekunder:
  cout << "\nTidspunkt nr.1: ";  tid1.skriv();   
                                 cout << "\t#sek: " << tid1.antSek();
  cout << "\nTidspunkt nr.2: ";  tid2.skriv();
                                 cout << "\t#sek: " << tid2.antSek();
  cout << "\nTidspunkt nr.3: ";  tid3.skriv();
                                 cout << "\t#sek: " << tid3.antSek();
  sorter(tid1, tid2);        //  'Tid2' er st�rst hittil.
  sorter(tid2, tid3);        //  'Tid3' ER den aller st�rste.
  sorter(tid1, tid2);        //  'Tid2' ER den nest st�rste.
  cout << "\n\nTidspunktene skrevet i �kende rekkef�lge:\n\t";
  tid1.skriv();  cout << '\t';   //  Skriver ut de sorterte objektene:
  tid2.skriv();  cout << '\t';  
  tid3.skriv();  cout << '\n';
}

                                //  HELT IDENTISK TIL EKS_43.CPP:
                                //  Leser inn og returnerer verdi i
int lesInn(const int MAX)  {    //  intervallet 0 til MAX.    
  int tall;                     //  Innskrevet tallverdi.
  cin >> tall;                  //  Leser tall.
  while (tall < 0  ||  tall > MAX)  {    //  Utenfor gyldig intervall:
     cout << "\ti intervallet (0-" << MAX << "):  ";
     cin >> tall;
  }
  return tall;                  //  Returnerer akseptert (gyldig) tall
}

                                   //  NESTEN IDENTISK TIL EKS_43.CPP:
                                   //  Bytter om (om n�dvendig) slik at 't2'
                                   //  ALLTID er st�rre eller lik 't1':
void sorter(Tidspunkt & t1, Tidspunkt & t2)  {
  int ts1 = t1.antSek(),           //  Henter t1 og t2 sine antall sekunder:
      ts2 = t2.antSek();
  Tidspunkt temp;                  //  Hjelpevariabel for � kopiere.

  if (ts1 > ts2)  {                //  't1' er st�rst:
     temp = t1;                    //  Bytter om 't1' og 't2':
     t1 = t2;
     t2 = temp;
  }
}
