#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool arSkottar(int ar){ //6.1.2 Exempel på en enkel tillämpning av arrayer
    return((ar%4==0)&& (ar!=100))|| ar==2000;
}
int antalDagar(int ar, int manad){
    const int dagarIManad[13]{0,31,28,31,30,31,30,31 ,31,30,31,30,31};
    if(manad==2 && arSkottar(ar))
        return 29;
    return dagarIManad[manad];

}
void forsokAndraVarden(int a, int arr[], int antalVarden){//6.1.4 Experiment: försök ändra värden
    a = 42;
    for (int i=0; i<antalVarden; ++i)
        arr[i] = 42;
}
void anropaForsokAndraVarden(){
    int a = 0;
    int arr[2]{0,0};
    forsokAndraVarden(a, arr, 2);
    cout << "a=" << a << ", arr[]=" << arr[0] << "," << arr[1] << endl;
}
void ingangTillKap06ArrayFunktioner();
void ingangTillKapXXVaxelpengar();
void ingangTillKap06Lottoexperiment();
void ingangTillKap0XYatzi();


int main()
{

    cout << "Kapitel 06 Arrayer!" << endl;
   // anropaForsokAndraVarden();
    //ingangTillKap06ArrayFunktioner();
    //ingangTillKapXXVaxelpengar();
   // ingangTillKap06Lottoexperiment();
    ingangTillKap0XYatzi();

    return 0;
}
