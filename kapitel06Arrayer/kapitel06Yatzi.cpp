#include <iostream>
#include <cassert>
using namespace std;

void fyllHistogram(const int yatyhand[], int antalAvVarde[]){
    for(int i=0; i<7;i++){
        antalAvVarde[i]=0; //nollställer alla positioner
    }
    for(int i=0; i<5;i++){
        int varde=yatyhand[i];
        assert(1 <=varde && varde<=6); // så vi får rätt intervall.
        antalAvVarde[varde]+=1;
    }
}
int vardeSomPar(const int yatzyhand[]){
    int histogram[7];
    fyllHistogram(yatzyhand, histogram);

    for(int varde=6; varde>=1; varde++){
        if(histogram[varde]>=2)
            return varde*2;
        return 0;
    }
}
int vardeSomTvapar(const int yatzyhand[]){
    int antalavVarde[7];
    fyllHistogram(yatzyhand,antalavVarde); //skickar in handen + arrayen
    int par1varde=0;

    for(int varde=1; varde<=6; varde++){
        if(antalavVarde[varde]>=2){//kollar om jag har två varden i antal varden som är större än 2 är då ett par.
            if(antalavVarde[varde]>=4)
                return 4*varde;
            if(par1varde==0){
                par1varde=varde;
            }
            else{
                return 2*par1varde +2*varde;
            }
        }
    }
    return 0;
}
int vardeSomTriss(const int yatzyhand[]){
    int histogram[7];
    int varde=0;
    fyllHistogram(yatzyhand,histogram);
    for(int varde=1; varde<=6; varde++){
        if(histogram[varde]>=3){
            return varde*3;
        }
    }
    return 0;
}
int vardeSomLitenstege(const int yatzyhand[]){

}
bool arOk(bool testresultat){
    if (!testresultat)
        cout << "BUG BUG Programmet innehåller en BUG " << endl;
            else cout << "ok" << endl;
    return testresultat;
}
void testaYatzyvarden(){ // VERSION 8:e NOVEMBER 2022
    cout << "testar Yatzyvärden" << endl;
        int hand1[5]{3, 6, 4, 2, 4};
    int hand2[5]{3, 2, 4, 2, 3};
    int hand3[5]{3, 4, 4, 2, 4};
    int hand4[5]{3, 5, 4, 2, 1};
    int hand5[5]{2, 4, 5, 4, 5};
    int hand6[5]{3, 3, 3, 3, 3};
    bool ok = arOk( vardeSomPar(hand1) == 8 )
              && arOk( vardeSomPar(hand2) == 6 )
              && arOk( vardeSomPar(hand3) == 8 )
              && arOk( vardeSomPar(hand4) == 0 )
              && arOk( vardeSomPar(hand5) == 10 )
              && arOk( vardeSomPar(hand6) == 6 )
              && arOk( vardeSomTvapar(hand1) == 0 )
              && arOk( vardeSomTvapar(hand2) == 10 )
              && arOk( vardeSomTvapar(hand3) == 0 )
              && arOk( vardeSomTvapar(hand4) == 0 )
              && arOk( vardeSomTvapar(hand5) == 18 )
              && arOk( vardeSomTvapar(hand6) == 12 )
              && arOk( vardeSomTriss(hand1) == 0 )
              && arOk( vardeSomTriss(hand2) == 0 )
              && arOk( vardeSomTriss(hand3) == 12 )
              && arOk( vardeSomTriss(hand4) == 0 )
              && arOk( vardeSomTriss(hand5) == 0 )
              && arOk( vardeSomTriss(hand6) == 9 )
              && arOk( vardeSomLitenstege(hand1) == 0 )
              && arOk( vardeSomLitenstege(hand2) == 0 )
              && arOk( vardeSomLitenstege(hand3) == 0 )
              && arOk( vardeSomLitenstege(hand4) == 15 )
              && arOk( vardeSomTriss(hand5) == 0 )
              && arOk( vardeSomTriss(hand6) == 9 );
    if (ok)
        cout << "testen lyckades" << endl;
    else cout << "testen MISSLYCKADES" << endl;
}
void ingangTillKap0XYatzi(){
    testaYatzyvarden();
}
