using namespace std;

#include <conio.h>
#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
const int scana=1,mapa=0,sglowa=3,scialo=4,owoc=5,x=11;
int z=0;
int tab[x][x];

int mapgen(int x){
    z=0;
    for(;z!=x;z++){
        if((z==0) || (z==x-1)){
            for(int i=0;i!=x;i++){
            tab[z][i]=1;
            } 
        }
        if((z>0) && (z<x-1)){
            for(int i=0;i!=x;i++){
            tab[z][0]=1;
                for(int i=1;i<=x-1;i++){
                    tab[z][i]=0;
                }
            tab[z][x-1]=1;
            }  
        }
    }
return tab[x][x];
}

int ppose(){
    int y;
    y=(x+1)/2;
    tab[y][y]=sglowa;
    return tab[x][x];
}

void nowagra(){
    mapgen(x);
    ppose();
}

int main(){
    nowagra();
    return 0;
}
