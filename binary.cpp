#include <iostream>
#include <stdexcept>
#include <bitset>

using namespace std;
int z;
int x;

void convert(int z,int x){
    cout << "Liczba binarna z liczby dziesiętnej: " << bitset<20>(z)<<endl;
    cout << "Liczba dziesiętna z liczby binarnej: ";
}

int main()
{
    cout<<"podaj liczbę dziesiętną: ";
    cin >> z;
    cout << "Podaj liczbę binarną: ";
    cin >> x;
    convert(z,x);
    return 0;
}
