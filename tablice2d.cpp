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
void co_dwa(){
    for(int i=0;i<=4;){
        if(i==0||i==4){
            for(int z=0;z<=4;){
                tab[i][z]=1;
                z+=2;
            }
        } else if(i==2){
            tab[i][0]=1;
            tab[i][4]=1;
        }
    i+=2;
    }
}

void skos(){
    int z=0;
    int tab2[4][4];
    if(control==2){
        for(int i=0;i<=4;i++){
            tab2[i][i]=1;
            for(int i=0;i<=4;i++){
            cout<<tab2[z][i];
            }
        cout<<endl;
        z++;
        }
    } else if(control==3){
        for(int i=4;i<=0;i--){
            tab[i][i]=1;
        }
    } else{
        exit(404);
    }
    for(int i=0;i<=4;i++){
        for(int i=0;i<=4;i++){
            tab[i][z]=tab2[i][z];
        }
    z++;
    }
}

void ramka(){
    for(int i=0;i<=4;i++){
        if(i==0||i==4){
            for(int z=0;z<=4;z++){
                tab[i][z]=1;
            }
        } else{
            tab[i][0]=1;
            tab[i][4]=1;
        }
    }
}

void co_drugi(){
    if(control==5){
        for(int i=0;i<=4;){
            for(int z=0;z<=4;z++){
                tab[i][z]=1;
            }
            i+=2;
        }
    } else if(control==6){
        for(int i=0;i<=4;i++){
            for(int z=0;z<=4;){
                tab[i][z]=1;
                z+=2;
            }
        }
    }
}

void szachownica(){
    for(int i=0;i<=4;i++){
        if(i==1||i==3){
            tab[i][1]=1;
            tab[i][3]=1;
        } else{
            tab[i][0]=1;
            tab[i][2]=1;
            tab[i][4]=1;
        }
    }
}

void X(){
    int i=0,z=4;
    for(;i<=4;){
        if(i==z){
            tab[i][z]=2;
        } else{
        tab[i][i]=1;
        tab[i][z]=1;    
        }
    i++;
    z--;
    }
}

void przekontna_na_trzy(){
    int z=0;
    for(int i=0;i<=4;i++){
        if(i==0){
            while(z!=2){
                tab[i][z]=1;
                z++;
            }
        } else if(i==1||i==2||i==3){
            if(i==1){
                while(z!=3){
                    tab[i][z]=1;
                    z++;
                }
            } else if(i==2){
                while(z!=3){
                    tab[i][1+z]=1;
                    z++;
                }
            } else {
                while(z!=3){
                    tab[i][2+z]=1;
                    z++;
                }
            }
        } else{
            tab[i][i-1]=1;
            tab[i][i]=2;
        }
    z=0;
    }
}

void menu(){
        switch(control){
        case 1:
        ramka();
        break;
        case 2:
        skos();
        break;
        case 3:
        skos();
        break;
        case 4:
        co_dwa();
        break;
        case 5:
        co_drugi();
        break;
        case 6:
        co_drugi();
        break;
        case 7:
        szachownica();
        break;
        case 8:
        X();
        break;
        case 9:
        przekontna_na_trzy();
        break;
        case 10:
        break;
    }
    for(int i=0;i<=4;i++){
        for(int z=0;z<=4;z++){
            cout<<tab[i][z];
        }
        cout<<endl;
    }
}


int main()
{
    for(int i=0;i<=4;i++){
        for(int z=0;z<=4;z++){
            tab[i][z]=0;
        }
    }
    cout<<"Proszę wybrać opcje:"<<endl;
    dlugitekst();
    cin >>control;
    menu();
    return 0;
}
