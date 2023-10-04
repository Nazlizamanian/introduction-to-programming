#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*******************************************************************
* ANROP: bool hasNumber = innehaller(v, tal);
* UPPGIFT: Returnerar true omm vektorn v innehåller angivet tal.
*******************************************************************/
bool innehaller(const vector<int> v, int tal){
    for(int i=0; i<v.size();i++){
        if(v[i]==tal){
            return true;
        }
    }
    return false;
}

/*******************************************************************
* ANROP: vector<int> lottorad = lottoradFranAnvandare();
* UPPGIFT: Returnerar en rad med 7 olika tal mellan 1 och 35 som
* användaren knappat in.
*******************************************************************/
vector<int> lottoradFranAnvandare(){

}
/*******************************************************************
* ANROP: vector<int> lottorad = slumplottorad();
* UPPGIFT: Returnerar en rad med 7 olika slumptal mellan 1 och 35.
*******************************************************************/
vector<int> slumplottorad(){
    // TODO
}
/*******************************************************************
* ANROP: int antal = antalMatch(rad1, rad2);
* UPPGIFT: Returnerar antalet tal som finns i bägge vektorerna
*******************************************************************/
int antalMatch( const vector<int> v1, const vector<int> v2){
    // TODO
}
/*******************************************************************
* ANROP: korTusenExperiment( anvandarensLottorad )
* UPPGIFT: Kör 1000 experiment med användarens rad och skriver sedan
* ut hur många rätt användaren fick i genomsnitt och som mest.
* Denna info skrivs ut på EN rad.
*******************************************************************/
void korTusenExperiment( const vector<int> anvandarensRad){
    // TODO
}
/*******************************************************************
* ANROP: lottoexperimentera();
* UPPGIFT: Ber användaren knappa in en lottorad och kör sedan
* 20 x 1000 experiment med denna rad och skriver ut
* statistik i terminalfönstret.
*******************************************************************/
void lottoexperimentera( ){
    vector<int> anvandarrad = lottoradFranAnvandare();
    for (int i=0; i<20 ; i+=1){
        korTusenExperiment( anvandarrad );
    }
}
void ingangTillKap06Lottoexperiment(){
    lottoexperimentera();
}
