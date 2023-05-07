#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gra{
public:
    int gamemode;
    Gra(int z){
        gamemode = z;
        cout<<"Pomyślnie wczytano zawartość!"<<endl;
    }
    void start(){
        while(true!=false){
        diff();
        mapgen();
        }
    }
    void mapgen() {
        system("clear");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (i == posY && j == posX) {
                    cout << "X";
                } else if (tab[i][j] != "0") { 
                    cout << tab[i][j];
                } else {
                    cout << "-";
                }
                cout << " ";
                if (j == 2 || j == 5) {
                    cout << "| ";
                }
            }
            cout << endl;
            if (i == 2 || i == 5) {
                cout << "---------------------" << endl;
            }
        }
        cout << "zycia:" << zycie << endl;
        if (checkGO(zycie)) {
            exit(0);
        }
    }
private:
    int zycie=5;
    int posX, posY;
    string tab[9][9]{
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "," "}
    };
    bool checkDup(string tab[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (tab[row][i] == std::to_string(num)) {
            return true;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (tab[i][col] == std::to_string(num)) {
            return true;
        }
    }
    int rowStart = row - (row % 3);
    int colStart = col - (col % 3);
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (tab[i][j] == std::to_string(num)) {
                return true;
            }
        }
    }
    return false;
    }
    void win(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = i+1;
        }
    }

    void randomBox(int a[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        }
    }
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
    bool checkrow(int row, int num) { 
        for (int i = 0; i < 9; i++) {
            if (tab[row][i] == std::to_string(num)) {
                return true;
            }
        }
        return false;
    }
    bool checkcol(int col, int num) {
        for (int i = 0; i < 9; i++) {
           if (tab[i][col] == std::to_string(num)) {
                return true;
            }
        }
        return false;
    }
    bool checkBox(int row, int col, int num) { 
        int Row2 = row - row % 3;
        int Col2 = col - col % 3;
        for (int i = Row2; i < Row2 + 3; i++) {
            for (int j = Col2; j < Col2 + 3; j++) {
                if (tab[i][j] == std::to_string(num)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool fincheck(int row, int col, int num) { 
    if (tab[row][col] != "0") {
        return false;
    }
    if (checkrow(row, num) || checkcol(col, num) || checkBox(row, col, num)) {  
        zycie--;
        if(checkGO(zycie)) {
            exit(0);
        }
        controlcheck();
        return false;
    }
    tab[row][col] = to_string(num);
    return true;
}

void controlcheck() {
    system("clear");
    cout << "test" << endl;
    mapgen();
}

void moveRight() {
    if (posX < 8) {
        posX++;
    }
}

void moveUp() {
    if (posY > 0) {
        posY--;
    }
}

void moveDown() {
    if (posY < 8) {
        posY++;
    }
}

        void postawliczbe(int num) { 
    if (fincheck(posY, posX, num)) {
        controlcheck(); 
     }
    }
    bool checkGO(int punkty) {
    if (punkty <= 0) {
        cout << "Przegrałeś, straciłeś wszystkie życia" << endl;
        return true;
    } else {
        return false;
    }
}

    };
int main()
{
        cout<<"Hello World";
        cout<<"Wybierz poziom trudności: "<<endl<<"1.Łatwy"<<endl<<"2.Normalny"<<endl<<"3.Trudny"<<endl<<"4.Bardzo Trudny"<<endl<<"Poziom: ";
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


