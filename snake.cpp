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
    int scana=1,mapa=0,sglowa=3,scialo=4,owoc=5;
    int tab[wielkosc];
    for(int i=0;i!=wielkosc;i++){
        tab[i]=0;
    }
    for(int i=0;i<=y;i++){
        
    }
}

void nowagra(){
    cout << "Podaj wielkość mapy:"<<endl;
    int x,y;
    cin >> x;
    y=x;
    mapgen(wielkosc);
}

main(){
    nowagra();
    return 0;
}
