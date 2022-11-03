using namespace std;

#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char mapgen(int wielkosc){
    int x,y;
    x = y = (wielkosc/2)+2;
    string tab[y];
    for (int i = 0; i <= y; i++)
    {
        tab[0] = tab[0] + "#";
        cout << tab[0];
        tab[y - 1] = tab[y - 1] + "#";
        cout << tab[y - 1];
    }
    for (int i = 0; i <= y; i++)
    {
        cout << tab[i];
    }
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