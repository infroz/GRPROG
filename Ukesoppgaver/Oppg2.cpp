// Vebjørn Leiros
// intvars.cpp
// Demonstrates integer variables
#include <iostream>
using namespace std;

int main ()
{
    int var1;
    int var2;

    cout << "Enter value of var1:";
    cin >> var1;
    var2 = var1 + 10;
    cout << "var1+10 is ";
    cout << var2 << endl;
    return 0;
}