#include <iostream>
using namespace std;

void skrivUtVaxelV2(int antalKronor){//6.1.8 Programmera Växelpengar V2
    const int antalValorer = 8;
    int valorer[antalValorer]{ 500, 200, 100, 20, 10, 5, 2, 1 };

    for(int i=0; i<antalValorer;i++){
        int antalAvValoren=antalKronor/valorer[i];
        if(antalAvValoren>0){
            cout<< antalAvValoren<<" x " <<valorer[i]<<endl;
        }
        antalKronor%=valorer[i];
    }

}
void ingangTillKapXXVaxelpengar(){
    cout << "ingangTillKapXXVaxelpengar" << endl;
    skrivUtVaxelV2(947);
}
