#include <iostream>

using namespace std;

//12.1.3 Experiment med pekare
void experimenteraMedPekare(){
    cout<<"ExpermineteraMedPekare\n";
    int x=108;
    int *pX=&x;
    cout<<"pX== "<<pX <<endl; //addresen
    cout<<"*pX== "<<*pX<<endl; //* ger värdet på den addressen pekaren pekar på.
    *pX=42;
    cout<<"Nu har jag andrat *pX"<<endl;
    cout<<"x== "<<x<<endl; //x värdet
    cout<<"pX== "<<pX <<endl; // addressen
    cout<<"*pX== "<<*pX<<endl; //* ger värdet
    cout<<"&pX== "<<&pX<<endl; //ger addressen

}
void ingangTillPekare();
void ingangTillMatrisdata();

int main()
{
    cout << "Kapitel 12 Pekare och referenser!" << endl;
  //  experimenteraMedPekare();
  //  ingangTillPekare();
    ingangTillMatrisdata();
    return 0;
}
