#include <iostream>
#include <stdexcept>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int copyz,copyx;
char copyc[64];

int hexcon (char c[]){
   int dlugosc= strlen(c);
   int ce=1;
   int wynik=0;
   for(int i=dlugosc-1;i>=0;i--){
      if(c[i]>='0' && c[i]<='9'){
         wynik += (c[i]-48) * ce;
         ce = ce*16;
      }
      else if(c[i]>='A'&& c[i]<='F'){
         wynik += (c[i]-55) * ce;
         ce = ce * 16;
      }
   }
   return wynik;
}

int binconv(long long x){
    int wynik = 0;
    int i = 0;
    int resz;

  while (x!=0) {
    resz = x % 10;
    x /= 10;
    wynik += resz * pow(2, i);
    ++i;
  }
  return wynik;
}

void convert(int z,int x,char* c){
    cout << "Liczba binarna z liczby dziesiętnej: " << bitset<20>(z) <<endl;
    cout << "Liczba dziesiętna z liczby binarnej: " << binconv(x)<<endl;
    cout << "Liczba szesnastkowa z liczby dziesiętnej: " << c <<endl;
}

int main()
{
    int z;
    long long x;
    char c[64];
    
    cout<<"podaj liczbę dziesiętną: ";
    cin >> z;
    cout << "Podaj liczbę binarną: ";
    cin >> x;
    cout << "Podaj liczbę szesnastkową: ";
    cin >> c;
    copyz= z;
    copyx= x;
    for(int i=0;i<=64;i++){
        c[i]=copyc[i];
    }
    hexcon(c);
    convert(z,x,c);
    return 0;
}
