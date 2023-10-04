#include <iostream>
#include <cassert>
using namespace std;

void demoAvInbyggdStrang(){ //8.2 Inbyggda strängar (csträngar)
    cout << "demoAvInbyggdStrang............." << endl;
    char strang0[4]{72, 101, 106, 0}; //nollterminerad.
    char strang1[4]{'H', 'e', 'j', 0};
    char strang2[]{'H', 'e', 'j', 0};
    char strang3[] = "Hej";
    char strang4[]{"Hej"};
    cout << strang0 << endl;
    cout << strang1 << endl;
    cout << strang2 << endl;
    cout << strang3 << endl;
    cout << strang4 << endl;
    cout << "Hej" << endl;
}
void demoAvUtf8(){
    cout << "demoAvUtf8............." << endl;
    char strang[] = "ABC 012 ÅÄÖ";
    cout << strang << endl;
    for (int i=0; strang[i]!=0 ; ++i){
        int heltal = strang[i];
        cout << heltal << " ";
    }
    cout << endl;
}
bool arLika(const char str1[], const char str2[]){//8.2.3 Programmera ärLika
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i])
            return false;
        i++;
    }
    if(str1[i]=='\0' &&str2[i]=='\0'){
        return true;
    }
    return false;
}

void automattestaArLika(){
    cout << "automattestar arLika" << endl;
    assert( arLika("abcd", "abcd") );
    assert( !arLika("abcd", "abcX") );
    assert( !arLika("abcd", "Xbcd") );
    assert( !arLika("abcd e", "abcd") );
    assert( !arLika("abcd", "abcd e") );
    cout << "testen av arLika lyckades!" << endl;
}

//8.2.4 Programmera konverteraTillVersaler
void konverteraTillVersaler(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(islower(str[i])){
            str[i]=toupper(str[i]);
            }
    }
}
void automattestaKonverteraTillVersaler(){
    cout << "automattestar konverteraTillVersaler" << endl;
    char str1[] = "abc ABC 123 .,- xyz";
    char str2[] = "ABC ABC 123 .,- XYZ";
    konverteraTillVersaler( str1 );
    assert( arLika(str1, str2) );
    cout << "testen av konverteraTillVersaler lyckades!" << endl;
}
//8.2.5 Programmera konverteraTillRubrik
void konverteraTillRubrik(char str[]){
    str[0]=toupper(str[0]);
    for(int i=1; str[i]!='\0';i++){
            if(str[i-1]==' ')
                str[i]=toupper(str[i]);
            else
                str[i]=tolower(str[i]);
    }
}
void automattestaKonverteraTillRubrik(){
    cout << "automattestar konverteraTillRubrik" << endl;
    char str1[] = "this is a test";
    char str2[] = "THIS IS A TEST";
    char rubrik[] = "This Is A Test";
    konverteraTillRubrik( str1 );
    konverteraTillRubrik( str2 );
    assert( arLika(str1, rubrik) );
    assert( arLika(str2, rubrik) );
    cout << "testen av konverteraTillRubrik lyckades!" << endl;
}

//8.2.6 Programmera ärVokal och ärKonsonant
bool arVokal(char ch){
    ch=tolower(ch);
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y';
}
bool arKonsonant(char ch){
    ch=tolower(ch);
   return ch!='a'||ch!='e'||ch!='i'||ch!='o'||ch!='u'||ch!='y';
}
void automattestaArVokalOchArKonsonant(){
    cout << "automattestar arVokal och arKonsonant" << endl;
    char vokaler[] = "aeiouyAEIOUY";
    char konsonanter[] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    char andraTecken[] = ".,?!; ";
    for (int i=0; vokaler[i] != 0; ++i)
            assert( arVokal(vokaler[i]) );
    for (int i=0; konsonanter[i] != 0; ++i)
            assert( arKonsonant(konsonanter[i]) );
    for (int i=0; andraTecken[i] != 0; ++i)
            assert( !arVokal(andraTecken[i]) && !arKonsonant(andraTecken[i]) );
    cout << "testerna av arVokal/arKonsonant lyckades!" << endl;
}

void ingangTillKap08CStrangar(){
  //  demoAvInbyggdStrang();
    //demoAvUtf8();
    automattestaKonverteraTillVersaler();
    automattestaArLika();
    automattestaKonverteraTillRubrik();
    automattestaArVokalOchArKonsonant();
}
