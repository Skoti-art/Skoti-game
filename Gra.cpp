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
    int aktualnyWiersz = wiersz +(kierunek == 1 ? i : 0);
    int aktualnaKolumna = kolumna + (kierunek == 0 ? i : 0);
    if(aktualnyWiersz < 0 || aktualnyWiersz >= ROZMIAR || aktualnaKolumna < 0 || aktualnaKolumna >=ROZMIAR){
        return false;
    }
    for(int dw = -1;dw= 1;dw++){
        for(int dk = -1;dk <= 1; dk++){
            int sprawdzanyWiersz =aktualnyWiersz + dw;
            int sprawdzanaKolumna = aktualnaKolumna + dk;
            if(sprawdzanyWiersz < 0 || sprawdzanyWiersz >= ROZMIAR || sprawdzanaKolumna < 0 || sprawdzanaKolumna >= ROZMIAR){
                continue;
            }
            if(planszaStatkow[sprawdzanyWiersz][sprawdzanaKolumna] == 'S'){
                return false;
            }
        }
    }
}
    return true;
}
void postawStatek(char planszaStatkow[ROZMIAR][ROZMIAR], int wiersz, int kolumna, int dlugosc, int kierunek){
    for(int i = 0; i < dlugosc; i++){
        int aktualnyWiersz = wiersz +(kierunek == 1 ? i : 0);
        int aktualnaKolumna = kolumna + (kierunek == 0 ? i : 0);
        planszaStatkow[aktualnyWiersz][aktualnaKolumna] = 'S';
    }
}
//losowanie wszystkich statkow
int main() {

cout<<"Witaj Graczu!!!Witaj w Statkach. Znajdz wszystkie statki przeciwnika i zniszcz je!!!Powodzenia";
    char planszaGracza[ROZMIAR][ROZMIAR];

    wypelnijPlansze(planszaGracza);

    pokazPlansze(planszaGracza);

    return 0;
}

