#include <iostream>
#include <stdexcept>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int copyz,copyx,copyc;
int i=0;
int d;
const char* ct;

void dectohex(long int c) {
   char tab[100];
   long int i = 0;
   while(c!=0) {
      long int w = 0;
      w = c % 16;
      if(w < 10) {
         tab[i] = w + 48;
         i++;
      } else {
         tab[i] = w + 55;
         i++;
      }
      c = c/16;
   }
   for(int j=i-1; j>=0; j--)
   cout << tab[j];
}

int binconv(long long x){
    long int wynik = 0;
    long int i = 0;
    long int resz;

  while (x!=0) {
    resz = x % 10;
    x /= 10;
    wynik += resz * pow(2, i);
    ++i;
  }
  return wynik;
}

void dectobinconv(int z){
   int bin[100], num=z;
   int i = 0;
   while (z > 0) {
      bin[i] = z % 2;
      z = z / 2;
      i++;
   }
   for (int j=i-1;j>=0;j--){
   cout << bin[j];
   }
}

void convert(long int z,long int x,long int c){
    cout << "Liczba binarna z liczby dziesiętnej: "; dectobinconv(z); cout<<endl;
    cout << "Liczba dziesiętna z liczby binarnej: " << binconv(x)<<endl;
    cout << "Liczba szesnastkowa z liczby dziesiętnej: "; dectohex(z); cout<<endl;
    cout << "Liczba szesnastkowa z liczby binarnej: "; dectohex(binconv(x)); cout<<endl;
}

int main()
{
    long int z,c;
    long long x;
    
    cout<<"podaj liczbę dziesiętną: ";
    cin >> z;
    cout << "Podaj liczbę binarną: ";
    cin >> x;
    cout << "Podaj liczbę szesnastkową: ";
    cin >> c;
    copyz= z;
    copyx= x;
    copyc= c;
    convert(z,x,c);
    return 0;
}
