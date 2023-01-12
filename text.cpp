#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
using namespace std::filesystem;

const int ROWS = 100;
const int COLS = 2;
string leaderboard_data[ROWS][COLS];
int current_rows = 0;
int linia = 1, nr_pytania = 0, punkty = 0;
string theme, nick, opis[10], odpa[10], odpb[10], odpc[10], odpd[10], odptrue[10], odpuser;

void create_leaderboard(string nickname, int points)
{
    leaderboard_data[current_rows][0] = nickname;
    leaderboard_data[current_rows][1] = to_string(points);
    current_rows++;
}

void sort_leaderboard()
{
    for (int i = 0; i < current_rows - 1; i++)
    {
        for (int j = 0; j < current_rows - 1 - i; j++)
        {
            if (stoi(leaderboard_data[j][1]) < stoi(leaderboard_data[j + 1][1]))
            {
                swap(leaderboard_data[j][0], leaderboard_data[j + 1][0]);
                swap(leaderboard_data[j][1], leaderboard_data[j + 1][1]);
            }
        }
    }
}

int main(){
    path filePath("path/to/QUIZ.txt");
    if (!exists(filePath))
    {
        cout << "Nie mozna znalezc pliku quizu.";
        exit(404);
    }
    ifstream plik(filePath);
    string line;
    int linia = 1, nr_pytania = 0, punkty = 0;
    string theme, nick, opis[10], odpa[10], odpb[10], odpc[10], odpd[10], odptrue[10], odpuser;

    while (getline(plik, line))
    {
        switch (linia)
        {
        case 1:
            theme = line;
            break;
        case 2:
            nick = line;
            break;
        case 3:
            opis[nr_pytania] = line;
            break;
        case 4:
            odpa[nr_pytania] = line;
            break;
        case 5:
            odpb[nr_pytania] = line;
            break;
        case 6:
            odpc[nr_pytania] = line;
            break;
        case 7:
            odpd[nr_pytania] = line;
            break;
        case 8:
            odptrue[nr_pytania] = line;
            break;
        }

        if (linia == 8)
        {
            linia = 2;
            nr_pytania++;
        }
        linia++;
    }
    cout << theme << endl
         << nick << endl;
    plik.close();
    for (int i = 0; i <= 9; i++)
    {
        cout << endl
             << opis[i] << endl;
        cout << "A. " << odpa[i] << endl
             << "B. " << odpb[i] << endl
             << "C. " << odpc[i] << endl
             << "D. " << odpd[i] << endl;
        cout << "Uwaga. Odpowiedzi trzeba przepisac razem z wielkoscia liter inaczej nie bedzie zaliczona" << endl;
        cout << endl
             << "Wprowadz odpowiedz: ";
        cin >> odpuser;
        transform(odpuser.begin(), odpuser.end(), odpuser.begin(), ::toupper);
        if (odpuser == odptrue[i])
        {
            cout << endl
                 << "Dobra odpowiedz! Zdobywasz punkt!" << endl;
            punkty++;
        }
        else
            cout << endl
                 << "Zla odpowiedz. Brak punktu. Prawidlowa odpowiedz" << odptrue[i];
    }
    cout << endl
         << endl
         << "Koniec quizu. Liczba zebranych punktow: " << punkty;
    /*zapis();*/
    return 0;
}
