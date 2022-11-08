using namespace std;

#include <conio.h>
#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
int control=0;

char mapgen(int wielkosc){
    string tab[50];
    for(int i=0; i<=9; i++){
    tab[i] = "X";
    }
    cout << endl;
    int y=10;
    int x=0;
    for(int i=0; i<=9; i++){
        x=0;
        tab[x+y] = "X";
        x=9;
        tab[x+y] = "X";
        int z=2;
        y=10*z;
        z++;
    }
    for(int i=0; i<=9; i++){
    tab[40+i] = "X";
    }
    while(control=1){
        for(int i=0;i<=50;i++){
            if(tab[i]!="X"){
             tab[i]="#";
            }
        }
    }
    y=0;
    x=1;
    for(int i=0;i<=50;i++){
    cout<<tab[i];
        if(y==10*x){
            cout << endl;
            x++;
        }
    }
    return 0;
}

void nowagra(){
    cout << "Podaj wielkość mapy (przekątna):"<<endl;
    int wielkosc;
    cin >> wielkosc;
    mapgen(wielkosc);
}

main(){
    nowagra();
    return 0;
}
