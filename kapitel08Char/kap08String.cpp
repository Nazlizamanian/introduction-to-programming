#include <string>
#include <cassert>
#include <iostream>
#include <cctype>
using namespace std;

//8.3 String
void demoAvString(){
    string str1 = "hej";
    string str2 = "hej";
    if (str1==str2)
        cout << "Hurra, man kan jämföra strängar utan att anropa ärLika!" << endl;
            else cout << "Rackans, det går fortfarande inte att jämföra strängar!" << endl;
            if (str1=="hej")
            cout << "Det gick att jämföra med en litteral!" << endl;
            else cout << "Det gick dock inte att jämföra med en litteral." << endl;
                    cout << "Strängen " << str1 << " har " << str1.size() << " tecken." << endl;
                    str2 += " då!";
               cout << str2 << endl;
}

//8.3.1 Programmera versalsträng
string versalstrang(const string str){
    string liten=str;
    for(int i=0; i<str.size();i++){
             liten[i]=toupper(str[i]);
              }
    return liten;
}
void automattestaVersalstrang(){
    cout << "testar versalStrang" << endl;
    assert( versalstrang("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ" );
    cout << "test av versalStrang lyckades!" << endl;
}

//8.3.2 Programmera rubriksträng
string rubrikstrang(const string str){
    string rubrik=str;
    bool konvertera=true;

    for(int i=0; i<str.size();i++){
             if(str[i]==str[0] && isalpha(str[i]))
                 rubrik[i]=toupper(str[i]);

             if(konvertera && isalpha(str[i])){
                 rubrik[i]=toupper(str[i]);
                 konvertera=false;
             }
             else if (str[i] == ' ')
                konvertera = true; // Aktivera konverteringsflaggan för nästa tecken
    }
    return rubrik;
}
void automattestaRubrikstrang(){
    cout << "testar rubrikstrang" << endl;
    assert( rubrikstrang("ha en BRA DAG!") == "Ha En Bra Dag!" );
    assert( rubrikstrang("") == "" );
    assert(rubrikstrang("hello, world")== "Hello, World!");
    assert(rubrikstrang("HELLO, WORLD!")== "Hello, World!");
    assert(rubrikstrang("this is a test")== "this is a test");
    cout << "test av rubrikstrang lyckades!" << endl;
}

//8.3.3 Programmera trimmad
string trimmad2(const string str){
    string trimadStrang;
    for(int i=0; i<str.size(); i++){
             if(str[i]!=' ')
                trimadStrang.push_back(str[i]);
    }

    return trimadStrang;
}
string trimmad(const string str){
    int indexTillForsta=0;
    while(indexTillForsta<(str.size()-1) && str[indexTillForsta]==' ')
             indexTillForsta+=1;

    int indexTillSista=str.size()-1;
    while(indexTillSista>0 && str[indexTillSista]==' ')//indexen ska vara större än 0 och str[i}
             indexTillSista-=1;

    string resultat;
    for(int i=indexTillForsta;i<=indexTillSista;i++){
             resultat+=str[i];
    }

    return resultat;
}
void automattestaTrimmad(){
    cout << "testar trimmad" << endl;
    assert( trimmad(" Ha en bra dag! ") == "Ha en bra dag!" );
    assert( trimmad(" A B C ") == "A B C" );
    assert( trimmad("   ") == "" );
    assert( trimmad("") == "" );
    assert( trimmad("abc") == "abc" );
    cout << "testen av trimmad lyckades!" << endl;
}
void ingangTillKap08String(){
    cout << "ingangTillKap08String." << endl;
  //  demoAvString();
  //  automattestaVersalstrang();
   automattestaRubrikstrang();

    automattestaTrimmad();
}
