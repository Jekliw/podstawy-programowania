/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int tab[4][4],control;

void dlugitekst(){
    cout<<"1) Obramowanie jedynkami"<<endl;
    cout<<"2) Przekątna jedynkami"<<endl;
    cout<<"3) Druga przekątna jedynkami"<<endl;
    cout<<"4) Co drugi element obramowania 1"<<endl;
    cout<<"5) Co drugi rząd jedynkami"<<endl;
    cout<<"6) Co druga kolumna jedynkami"<<endl;
    cout<<"7) Co drugi skos jedynkami"<<endl;
    cout<<"8) Obie przekątne jedynkami, środek 2"<<endl;
    cout<<"9) Potrójna przekątna jedynkami"<<endl;
    cout<<"10) wiersze kolejno: 0, 1, 2, 0, 1, 2, itd."<<endl;
    cout<<"11) Skosy kolejno 0,1,2,0,1,2, itd."<<endl;
    cout<<"12) Narożne i środkowy jedynkami, co drugi skos dwójkami"<<endl;
}

void ramka(){
    for(int i=0;i<=4;i++){
        if(i==0||i==4){
            for(int z=0;z<=4;z++){
                tab[i][z]=1;
            }
        }
        else{
            tab[i][0]=1;
            tab[i][4]=1;
        }
    }
}

int main()
{
    cout<<"Proszę wybrać opcje:"<<endl;
    dlugitekst();
    cin >>control;
    switch(control){
        case 1:
        ramka();
        break;
    }
    for(int i=0;i<=4;i++){
        for(int z=0;z<=4;z++){
            cout<<tab[i][z];
        }
        cout<<endl;
    }
    return 0;
}
