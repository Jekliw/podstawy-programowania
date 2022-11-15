using namespace std;

#include <conio.h>
#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
int control=0;

char mapgen(int x, int y){
    int z=0,scana=1,mapa=0,sglowa=3,scialo=4,owoc=5;
    int tab[x][x];
    z=0;
    for(;z!=x;z++){
        if((z==0) || (z==10)){
            for(int i=0;i!=x;i++){
            tab[z][i]=1;
            } 
        }
        if((z>0) && (z<10)){
            for(int i=0;i!=x;i++){
            tab[z][0]=1;
                for(int i=1;i<=9;i++){
                    tab[z][i]=0;
                }
            tab[z][9]=1;
            }  
        }
    }
}

void nowagra(){
    int x=10,y;
    mapgen(x, y);
}

main(){
    nowagra();
    return 0;
}
