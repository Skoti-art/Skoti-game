#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROZMIAR = 10;

void wypelnijPlansze(char plansza[ROZMIAR][ROZMIAR]) {
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            plansza[wiersz][kolumna] = '0';
        }
    }
}

void pokazPlansze(char plansza[ROZMIAR][ROZMIAR]) {
    cout << "\n   ";

    for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
        cout << kolumna + 1 << " ";
    }

    cout << endl;

    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        cout << wiersz + 1 << "  ";

        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            cout << plansza[wiersz][kolumna] << " ";
        }

        cout << endl;
    }
}

int main() {

cout<<"Witaj Graczu!!!Witaj w Statkach. Znajdz wszystkie statki przeciwnika i zniszcz je!!!Powodzenia";
    char planszaGracza[ROZMIAR][ROZMIAR];

    wypelnijPlansze(planszaGracza);

    pokazPlansze(planszaGracza);

    return 0;
}

