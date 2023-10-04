#include <iostream>

using namespace std;

void experimenteraMedChar(){ //8.1Datatypen Char
    cout << "experimenteraMedChar....." << endl;
    char ch1 = 'R';
    char ch2 = 82;
    int i1 = 'R';
    int i2 = 82;
    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << i1 << endl;
    cout << i2 << endl;
}
void skrivNagraAsciiTecken(){
    cout << "skrivNagraAsciiTecken" << endl;
    const char tabulator = 9;
    for (int asciital = 'a'-5; asciital<='z'+5; ++asciital){
        char tecken = asciital;
        cout << asciital << tabulator << tecken << endl;
    }
}

void ingangTillKap08CStrangar();
void ingangTillKap08String();

void k(){
double x = 25;
double gissning = 1;

for (int i = 0; i < 10; i += 1) {
    double kvot = x/gissning;
    gissning=(gissning + kvot )/ 2;
}

cout << gissning;
}
int main()
{
k();
    cout << "Kapitel 08Char!" << endl;
   // experimenteraMedChar();
   // skrivNagraAsciiTecken();

   // ingangTillKap08CStrangar();
    ingangTillKap08String();
    return 0;
}
