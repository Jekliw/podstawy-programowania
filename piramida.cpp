#include <iostream>
using namespace std;
int main()
{
    int wysokosc, x, y, wynik;
    wysokosc = y = wynik = 0;
    x = 1;
    cout << "wprowadź wysokość piramidy: ";
    cin >> wysokosc;
    for (int i = 1; i <= wysokosc; i++)
    {
        wynik = wynik + (x * x);
        x++;
    }
    cout << "Ilość cegieł w piramidzie wynosi: " << wynik;
    return 0;
}