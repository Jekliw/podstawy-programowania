#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <set>

using namespace std;

class Gra{
public:
    int gamemode;
    bool num_input;
    Gra(int z){
        gamemode = z;
        cout<<"Pomyślnie wczytano zawartość!"<<endl;
    }
    void start(){
        while(true!=false){
        diff();
        mapgen();
        doublecontrol();
        }
    }
    void control(){
    char key;
    string num;

    cin>>key;
    if(key>=49&&key<=58){
        num = key;
        if (gitcheck(posY, posX, num)) {
            tab[posY][posX] = num;
        } else {
            cout << "zły ruch. spróbuj ponownie" << endl;
            sleep(1);
        }
    } else{
        switch(key){
            case 'w':
                posY--;
                break;
            case 's':
                posY++;
                break;
            case 'a':
                posX--;
                break;
            case 'd':
                posX++;
                break;
            }
        }
    }
    void doublecontrol(){
        control();
        if(posX<0){
            posX++;
        } else if(posX>8){
            posX--;
        } else if(posY<0){
            posY++;
        } else if(posY>8){
            posY--;
        }
    }
    bool gitcheck(int row, int col, string num) {
    for (int i = 0; i < 9; i++) {
        if (tab[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (tab[i][col] == num) {
            return false;
        }
    }
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (tab[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}
    void mapgen() {
    system("clear");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(i==posY&&j==posX){
                cout <<"["<< tab[i][j]<<"] ";
            } else{
            cout << tab[i][j];
            cout << "   ";
            }
            if (j == 2 || j == 5) {
                cout << "| ";
            }
        }
        cout << endl;
        if (i == 2 || i == 5) {
            cout << "---------------------------------------" << endl;
        }
    }
    bool win = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tab[i][j] == " ") {
                win = false;
                break;
            }
        }
        if (!win) break;
    }
    if (win) {
        cout << "Gratulacje, wygrales!" << endl;
        exit(0);
    }
}
private:
        int posX=1, posY=1;
        string tab[9][9]{
                {" "," "," ","2","6"," ","7"," ","1"},
                {"6","8"," "," ","7"," "," ","9"," "},
                {"1","9"," "," "," ","4","5"," "," "},
                {"8","2"," ","1"," "," "," ","4"," "},
                {" "," ","4","6"," ","2","9"," "," "},
                {" ","5"," "," "," ","3"," ","2","8"},
                {" "," ","9","3"," "," "," ","7","4"},
                {" ","4"," "," ","5"," "," ","3","6"},
                {"7"," ","3"," ","1","8"," "," "," "}
        };
        int roll;
        void diff(){
            switch(gamemode){
                case 1:
                    roll=30;
                    break;
                case 2:
                    roll=20;
                    break;
                case 3:
                    roll=10;
                    break;
                case 4:
                    roll=5;
                    break;
            }
        }
    };
int main()
{
        cout<<"Wybierz poziom trudności: (nie działa, żadna liczba niczym się nie różni, mapa zawsze taka sama) "<<endl<<"1.Łatwy"<<endl<<"2.Normalny"<<endl<<"3.Trudny"<<endl<<"4.Bardzo Trudny"<<endl<<"Poziom: ";
        int choice;
        cin>>choice;
        switch(choice){
                case 1:{
                Gra easy(1);
                easy.start();
                break;
                }
                case 2:{
                Gra normal(2);
                normal.start();
                break;
                }
                case 3:{
                Gra hard(3);
                hard.start();
                break;
                }
                case 4:{
                Gra vhard(4);
                vhard.start();
                break;
                }
        }
        return 0;
}

