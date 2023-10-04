#include <iostream>
#include <stdlib.h>
using namespace std;

void skrivUtArr(const int arr[], int antal){ //6.1.7 Programmera array-funktioner
    for(int i=0; i<antal; i++){
        cout<<arr[i]<<endl;
    }
}
void fyllMedVarde(int arr[], int antal, int varde){
    for(int i=0; i<antal; i++){
        arr[i]=varde;
        cout<< arr[i]<<endl;
    }
}
void fyllMedSlumptal(int arr[], int antal, int minsta, int storsta){
    for(int i=0; i<antal; i++){
        arr[i]=(rand()%(storsta+1-minsta))+minsta;
    }
}
int minst(const int arr[], int antal){
    int minsta=arr[0];
    if(antal<=1){
        return -1;
    }
    for(int i=0; i<antal;i++){
        if(arr[i]<=minsta){
            minsta=arr[i];
        }
    }
 return minsta;
}
int storst(const int arr[], int antal){
    int storsta=arr[0];
    if(antal<=1){
        return -1;
    }
    for(int i=0; i<antal; i++){
        if(arr[i]>=storsta){
            storsta=arr[i];
        }

    }
 return storsta;
}
int indexTillMinsta(const int arr[], int antal){
    int minstaVardet=arr[0];
    int minstaIndex=-1;
    if(antal<=1){
        cout<<"tom array\n";
        return -1;
    }
    for(int i=0; i<antal; i++){
        if(arr[i]<=minstaVardet){
            minstaVardet=arr[i];
            minstaIndex=i;
        }
    }
    return minstaIndex;

}
int indexTillStorsta(const int arr[], int antal){
    int storstaVardet=arr[0];
    int storstaIndex=-1;


    if(antal<=1){
        cout<<"tom array\n";
        return -1;
    }
    for(int i=0; i<antal; i++){
        if(arr[i]>=storstaVardet){
            storstaVardet=arr[i];
            storstaIndex=i;
        }
    }
    return storstaIndex;
}
bool arSorterad(const int arr[], int antal){
    for(int i=0; i<antal; i++){
        if(arr[i]<=arr[i+1])
            return true;
        return false;
    }
    return false;
}
bool innehaller(const int arr[], int antal, int x){
    for(int i=0; i<antal; i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}
void provaArrayFunktionerna(){
    cout << "provaArrayFunktionerna" << endl;
    const int storlek = 10;
    int arr[storlek];
    fyllMedVarde(arr, storlek, 5);
    skrivUtArr(arr, storlek);
    arr[0] -= 1;
    arr[storlek-1] += 1;
    if (arSorterad(arr, storlek))
        cout << "Arrayen är sorterad" << endl;
            else cout << "BUG BUG arSorterad tycks inte fungera" << endl;
    arr[0] = 6;
    if (arSorterad(arr, storlek))
        cout << "BUG arSorterad tror att arrayen är sorterad" << endl;
                fyllMedSlumptal( arr, storlek, -2, 2);
    skrivUtArr(arr, storlek);
    arr[1] = -3; // Detta blir det minsta värdet
    arr[storlek-1] = 3; // Detta blir det största värdet
    int m = minst(arr, storlek);
    int s = storst(arr, storlek);
    cout << "minst=" << m << " störst=" << s << endl;
        if (m != -3 || s != 3)
        cout << "BUG m eller s !!!!!!!!!!!" << endl;
    if (indexTillMinsta(arr, storlek) != 1)
        cout << "BUG i indexTillMinsta !!!!!!!!!!!" << endl;
    if (indexTillStorsta(arr, storlek) != (storlek-1))
        cout << "BUG i indexTillStörsta !!!!!!!!!!!" << endl;
            if (!innehaller(arr,storlek, 3))
            cout << "BUG!!!!!!!!!!!" << endl;
}
void ingangTillKap06ArrayFunktioner(){
    provaArrayFunktionerna();
}
