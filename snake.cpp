using namespace std;

#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int varinput(){
    int x,y,z=0,c=0;
    x = y = (wielkosc/2)+2;
    char tab[y];
    return 0;
}

void genmap2(int x,y,z; char tab[i];){
        for (int i = 1; i <= 1; i++)
    {
        tab[0] = 'X';
        while(z!=2){
            cout << tab[0];
            if(c==x){
                z=2;
            }
            c++;
        }
        z = c =0;
        tab[y - 1] = 'X';
        while(z!=2){
            cout << tab[y - 1];
            if(c==x){
                z=2;
            }
            c++;
        }
    }
}

char mapgen(int wielkosc){
    for(int i = 0; i <= y; i++){
        tab[i] = 0;
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
