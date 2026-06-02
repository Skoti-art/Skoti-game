#include <iostream>
#include<iomanip>
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
        cout << setw(2)<<wiersz + 1<<" ";

        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            cout << plansza[wiersz][kolumna] << " ";
        }

        cout << endl;
    }
}
bool czymoznaPostawic(char planszaStatkow[ROZMIAR][ROZMIAR], int wiersz, int kolumna, int dlugosc, int kierunek){
for(int i = 0;i<dlugosc; i++){
    int aktualnyWiersz = wiersz +(kierunek ++ 1 ? i : 0);
    int aktualnaKolumna = kolumna + (kierunek)
}
}
int main() {

cout<<"Witaj Graczu!!!Witaj w Statkach. Znajdz wszystkie statki przeciwnika i zniszcz je!!!Powodzenia";
    char planszaGracza[ROZMIAR][ROZMIAR];

    wypelnijPlansze(planszaGracza);

    pokazPlansze(planszaGracza);

    return 0;
}

