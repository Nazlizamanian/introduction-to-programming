#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//12.5.2 Programmera matrisfunktioner
void skrivUtMatrisdata(double **ppElement, int antalRader, int antalKolumner){
    int array[3][3] = {
        {0, 0, 0}, // Rad 0
        {0, 0, 0}, // Rad 1
        {0, 0, 0}  // Rad 2
    };
    for(int i=0; i<antalRader; i++){
        for(int j=0; j<antalKolumner; j++){
            cout<<array[i][j]<<" ";
        }
        cout <<endl;
    }
}
void nollstallMatrisdata(double **ppElement, int antalRader, int antalKolumner){
    for (int r=0; r<antalRader; ++r)
        for (int k=0; k<antalKolumner; ++k){
            ppElement[r][k] = 0;
        }
}
double **allokeradMatris(int antalRader, int antalKolumner){
    double **ppElement = new double*[antalRader];
    for (int rad=0; rad<antalRader; ++rad){
        ppElement[rad] = new double[antalKolumner];
    }
    nollstallMatrisdata(ppElement, antalRader, antalKolumner);
    return ppElement;
}
void frigorMatrisdata(double **ppElement, int antalRader){
    // TODO
}
/*double **allokeradEnhetsmatris(int n){
    // TODO
}*/
void provkorMatrisdatafunktioner(){
    cout << "Provkör matrisdatafunktioner" << endl;
        double **ppData = allokeradMatris(4, 5);
    skrivUtMatrisdata(ppData, 4,5);
    //double **ppEnhetsdata = allokeradEnhetsmatris(3);
  /*  skrivUtMatrisdata(ppEnhetsdata, 3,3);
    frigorMatrisdata(ppData, 4);
    frigorMatrisdata(ppEnhetsdata, 3);*/

    cout << "matrisdatafunktionerna provkörda" << endl;
}
void ingangTillMatrisdata(){
    provkorMatrisdatafunktioner();
}
