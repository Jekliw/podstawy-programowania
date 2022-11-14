#include <iostream>
using namespace std;

int x, y, wynik = 0;

int licz(){
        for (int i = 1; i <= y; i++)
    {
        wynik = wynik + (x * x);
        x--;
    }
    return wynik;
}

int main()
{
    x = y = wynik = 0;
    cout << "wprowadź liczbę cegieł w podstawie piramidy: ";
    cin >> x;
    y = x;
    licz();
    cout << "Ilość cegieł w piramidzie wynosi: " << wynik;
    return 0;
}
