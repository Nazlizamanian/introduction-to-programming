#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;

void ovaPaPekarnotation(){
    cout << "Övar på pekarnotation" << endl;
    double x = 1.0;
    double *pX=&x;
    double **ppX=&pX;
    double ***pppX=&ppX;

    **ppX=2.0;

    // ändra sedan x till 2 med hjälp av pppX
    cout << "x är nu " << x << endl;
            assert( x == 2.0);
    cout << "Övningen lyckades." << endl;
}

//12.3.1 Programmera bytVarden
void bytVarden(int *pA, int *pB){
    int gammlaA=0;
    gammlaA=*pA;
    *pA=*pB;
    *pB=gammlaA;
}
void bytVarden(double *pA, double *pB){
    double gammlaA=0;
    gammlaA=*pA;
    *pA=*pB;
    *pB=gammlaA;
}

void automattestaBytVarden(){
    cout << "Testar bytVarden" << endl;
    int a = 1;
    int b = 2;
    bytVarden(&a, &b);
    assert( a==2 && b==1 );
    double x = 1.5;
    double y = 2.5;
    bytVarden(&x, &y);
    assert( x==2.5 && y==1.5 );
    cout << "Testet av bytVarden lyckades!" << endl;
}

//12.4 Iterera med pekare
int langd(const char *str){
    const char *pCh=str;
    while(*pCh!=0)
        ++pCh; //stegrar fram pekarvariablen ett steg.
    return pCh-str;
}
void automattestaLangd(){
    assert(langd("hej")==3);
}

//12.4.1 Programmera csträngfunktionerna -igen
bool arLikaP(const char *str1, const char *str2){
    int i=0;
    while(str1[i]!='\0' &&str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            return false;
            i++;
        }
        return true;
    }
    if(str1[i]=='\0' && str2[i]=='\0'){
        return true;
    }
    return false;

}

void konverteraTillVersalerP(char *str){
    for(int i=0; str[i]!=0;i++){
        str[i]=toupper(str[i]);
    }
}
void konverteraTillRubrikP(char *str){
    str[0]=toupper(str[0]);
    for(int i=0; str[i]!='\0';i++){
        if(isalpha(str[i]) && str[i-1]==' '){
             str[i]=toupper(str[i]);
        }
        else
             str[i]=tolower(str[i]);
    }
}
void automattestaStrangfunktionerP(){
    cout << "automattestar strangfunktionerna-P" << endl;
    assert( arLikaP("abcd", "abcd") );
    assert( !arLikaP("abcd", "abcX") );
    assert( !arLikaP("abcd", "Xbcd") );
    assert( !arLikaP("abcd e", "abcd") );
    assert( !arLikaP("abcd", "abcd e") );
    char strA[] = "abc ABC 123 .,- xyz";
    char strB[] = "ABC ABC 123 .,- XYZ";
    konverteraTillVersalerP( strA );
    assert( arLikaP(strA, strB) );
    char str1[] = "this is a test";
    char str2[] = "THIS IS A TEST";
    char rubrik[] = "This Is A Test";
    char tom[] = "";
    konverteraTillRubrikP( str1 );
    konverteraTillRubrikP( str2 );
    konverteraTillRubrikP( tom );
    assert( arLikaP(str1, rubrik) );
    assert( arLikaP(str2, rubrik) );
    assert( arLikaP(tom, "") );
    cout << "testen av strangfunktionerna-P lyckades!" << endl;
}
//12.4.3 Programmera arrayfunktionerna -igen!
void skrivUtArr(const int *pBegin, const int *pEnd){
    for(const int *pData=pBegin; pData!=pEnd; pData++){
        cout<<*pData<<endl;
    }
}
void fyllMedVarde(int *pBegin, int *pEnd, int varde){
    for(int *pData=pBegin; pData!=pEnd; pData++){
        *pData=varde; //värdet som pekaren pekar på ska få nya värdet.
    }

}
void fyllMedSlumptal(int *pBegin, int *pEnd, int minst, int störst){
    for(int *pData=pBegin;pData!=pEnd; pData++){
        cout<<(rand()%(störst-minst+1))+minst<<endl;
    }
}
int minst(const int *pBegin, const int *pEnd){
     assert( pEnd - pBegin > 0);
    int minst=*pBegin;
    for(const int *pData=pBegin; pData!=pEnd; pData++){
        if(*pData<minst){
             minst=*pData;
        }
    }
    return minst;
}
int storst(const int *pBegin, const int *pEnd){
    assert( pEnd - pBegin > 0);
    int storst=*pBegin;

    if(pBegin!=pEnd){
        for(const int *pData=pBegin; pData!=pEnd;pData++){
            if(*pData>storst){
                 storst=*pData;
            }
        }
    }
    else{
        return -1;
    }
    cout<<"GG"<<storst<<endl;
    return storst;
}

bool arSorterad(const int *pBegin, const int *pEnd){
    for(const int *pData=pBegin; pData+1!=pEnd; pData++){
        if(*(pData)<=*(pData+1)){
             return false;
             }
    }
    return true;
}
bool innehaller(const int *pBegin, const int *pEnd, int x){
    for(const int *pData=pBegin; pData!=pEnd; pData++){
        if(*pData==x){
             return true;
        }
    }
    return false;
}
void testaArrayfunktionernaP(){
    cout << "testar arrayfunktionerna -P " << endl;
    const int storlek = 10;
    int arr[storlek];
    fyllMedVarde(&arr[0], &arr[storlek], 5);
    skrivUtArr(&arr[0], &arr[storlek]);
    arr[0] -= 1;
    arr[storlek-1] += 1;
    assert( arSorterad(&arr[0], &arr[storlek]) );
    arr[0] = 6;
    assert( !arSorterad(&arr[0], &arr[storlek]) );
    fyllMedSlumptal(&arr[0], &arr[storlek], -2, 2);
    skrivUtArr(&arr[0], &arr[storlek]);
    arr[1] = -3; // Detta blir det minsta värdet
    arr[storlek-1] = 3; // Detta blir det största värdet
    int m = minst(&arr[0], &arr[storlek]);
    int s = storst(&arr[0], &arr[storlek]);
    assert( m == -3 && s == 3 );
    assert( innehaller(&arr[0], &arr[storlek], 3));
    cout << "testar av arrayfunktionerna -P lyckades" << endl;
}

void ingangTillPekare(){
  //  ovaPaPekarnotation();
   // automattestaBytVarden();
    //automattestaLangd();
   // automattestaStrangfunktionerP();
  //  testaArrayfunktionernaP();
}
