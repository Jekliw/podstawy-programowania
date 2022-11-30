#include <iostream> /*tym razem tylko jedna biblioteka a nie 5*/
/*w razie pytania czemu każda funkcja oprócz main to void, te funkcje i tak zwracają
wszystko na int globalny przez co nie czułem potrzeby by funkcja miała zwracać cokolwiek*/
using namespace std;

int tab[5][5]; /*zmienne globalne bym nie musiał tego wpisywać w funkcjach co chwilę*/
int control;  /*funkcja kontrolna dla punktów które dzielą jedną funkcje ponieważ 
            były bardzo podobne a robienie kolejnych funkcji to tylko strata linijek*/

void dlugitekst(){ /*długi tekst*/
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
void co_dwa(){/*punkt 4. To było pierwsze zadanie które zrobiło mi większy problem,
                teraz nie pamiętam o co mi chodziło*/
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

void skos(){ /*punkt 2 i 3. Przez źle ustawione tablice męczyłem się z tym prawie 2 dni by
            odkryć że trzeba było zmienić 4 na 5...*/
    if(control==2){
        for(int i=0;i<=4;i++){
            tab[i][i]=1;
        }
    } else if(control==3){
        int z=4;
        for(int i=0;i<=4;i++){
            tab[i][z]=1;
            z--;
        }
    } else{
        exit(404); /*to jest tylko po to w razie jakby coś nagle poszło nie tak*/
    }
}

void ramka(){ /*punkt 1. Większość funkcji to modyfikacja tego kodu.*/
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

void co_drugi(){ /*punkt 5 i 6. jedno to jest kopia drugiego tylko zamienione int++*/
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

void szachownica(){/*punkt 7. nie miałem na to sensownego pomysłu*/
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

void X(){/*punkt 8. skończyły mi się pomysły na nazwy funkcji a to było adekwatne*/
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

void przekontna_na_trzy(){/*punkt 9. minimalny problem tu był bo 
                            przypadkowo na końcu zamiast tab[i][i]=1; dałem tab[i][i]=2;*/
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
            tab[i][i]=1;
        }
    z=0;
    }
}

void zmienne_wiersze(){/*punkt 10. to jest kopia punktu 1 zrobiona 3 razy.
                        wartość ster jest po to by kontrolowała kolejność*/
    int ster=0;
    for(int i=0;i<=4;i++){
        if(ster==3){
            ster=0;
        }
        switch(ster){ /*gdy to pisałem to zdałem sobie sprawę że zamiast if mogłem pisać switch.
                        no cóż.*/
            case 0:
            for(int z=0;z<=4;z++){
                tab[i][z]=0;
            }
            break;
            case 1:
            for(int z=0;z<=4;z++){
                tab[i][z]=1;
            }
            break;
            case 2:
            for(int z=0;z<=4;z++){
                tab[i][z]=2;
            }
            break;
        }
        ster++;
    }
}

void pseudo_kod1(){ /*nienwaidzę tego - 23:33*/ /*przecież to wygląda jak kod do 10 :O - 23:34*/ 
    int x=0,y=0;        /*jednak nie - 23:37*/ /*nienwaidzę tego - 23:45*/ /*zrobione -??:??*/
    for(int i=0;i<=4;i++){
        switch(y){
            case 0:
            x=0;
            for(int z=0;z<=4;z++){
                tab[i][z]=x;
                x+=1;
                if(x==3){
                    x=0;
                }
            }
            break;
            case 1:
            x=1;
            for(int z=0;z<=4;z++){
                tab[i][z]=x;
                x+=1;
                if(x==3){
                    x=0;
                }
            }
            break;
            case 2:
            x=2;
            for(int z=0;z<=4;z++){
                tab[i][z]=x;
                x+=1;
                if(x==3){
                    x=0;
                }
            }
            break;
        }
    y++;
    if(y==3){
        y=0;
    }
}}

void menu(){ /*tu jest jedynie funkcja wybierania innych funkcji, długie i nic ciekawego*/
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
        zmienne_wiersze();
        break;
        case 11: /*to jest część której nienawidzę*/
        pseudo_kod1();
        break;
        case 12: /*zrobić na lekcji*/
        pseudo_kod2();
        break;
    }
        for(int i=0;i<=4;i++){
            for(int z=0;z<=4;z++){
                cout<<tab[i][z];
            }
            cout<<endl;
         }
}

int main(){
    for(int i=0;i<=4;i++){ /*przeczyszczenie tablicy z losowych wartości na same zera, 
                            zrobione w razie czego*/
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
