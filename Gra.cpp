#include <iostream>
#include<iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROZMIAR = 10;
const int ILE_STATKOW = 10;
void wypelnijPlansze(char plansza[ROZMIAR][ROZMIAR],char znak) {
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            plansza[wiersz][kolumna] = '0';
        }
    }
}

void pokazPlansze(char plansza[ROZMIAR][ROZMIAR]) {
    cout << "\n   ";
    for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
        if (kolumna + 1 < 10) {
            cout << " " << kolumna + 1 << " ";
        } else {
            cout << kolumna + 1 << " ";
        }
    }
    cout << endl;
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        if (wiersz + 1 < 10) {
            cout << "  " << wiersz + 1 << "  ";
        } else {
            cout << " " << wiersz + 1 << "  ";
        }
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            cout << plansza[wiersz][kolumna] << "  ";
        }
        cout << endl;
    }
}
bool CzyPoleJestNaPlanszy(int wiersz, int kolumna){
    if(wiersz >= 0 && wiersz < ROZMIAR && kolumna >=0 && kolumna < ROZMIAR){
        return true;
    }
    return false;
}
bool CzyMoznaPostawic(char planszaStatkow[ROZMIAR][ROZMIAR], int wiersz, int kolumna, int dlugosc, int kierunek){
for(int i = 0;i<dlugosc; i++){
    int aktualnyWiersz = wiersz +(kierunek == 1 ? i : 0);
    int aktualnaKolumna = kolumna + (kierunek == 0 ? i : 0);
    if (CzyPoleJestNaPlanszy(aktualnyWiersz, aktualnaKolumna) == false) {
        return false;
    }
    for (int zmianaWiersza = -1; zmianaWiersza <= 1; zmianaWiersza++) {
        for (int zmianaKolumny = -1; zmianaKolumny <= 1; zmianaKolumny++) {
            int sprawdzanyWiersz = aktualnyWiersz + zmianaWiersza;
            int sprawdzanaKolumna = aktualnaKolumna + zmianaKolumny;
            if (CzyPoleJestNaPlanszy(sprawdzanyWiersz, sprawdzanaKolumna)) {
                if (planszaStatkow[sprawdzanyWiersz][sprawdzanaKolumna] == 'S') {
                }
            }
        }
    }
}
    return true;
}
void postawStatek(char planszaStatkow[ROZMIAR][ROZMIAR], int wiersz, int kolumna, int dlugosc, int kierunek, int numerStatku){
    char znakStatku;
    if (numerStatku < 10) {
        znakStatku = '0' + numerStatku;
    } else {
        znakStatku = 'A';
    }
    for(int i = 0; i < dlugosc; i++){
        int aktualnyWiersz = wiersz +(kierunek == 1 ? i : 0);
        int aktualnaKolumna = kolumna + (kierunek == 0 ? i : 0);
        planszaStatkow[aktualnyWiersz][aktualnaKolumna] = znakStatku;
    }
}
void losujStatek(char planszaStatkow[ROZMIAR][ROZMIAR], int dlugosc, int numerStatku) {
    int wiersz;
    int kolumna;
    int kierunek;
    while (true) {
        wiersz = rand() % ROZMIAR;
        kolumna = rand() % ROZMIAR;
        kierunek = rand() % 2;
        if (CzyMoznaPostawic(planszaStatkow, wiersz, kolumna, dlugosc, kierunek)) {
            postawStatek(planszaStatkow, wiersz, kolumna, dlugosc, kierunek, numerStatku);
            return;
        }
    }
}
void losujWszystkieStatki(char planszaStatkow[ROZMIAR][ROZMIAR], int dlugosciStatkow[ILE_STATKOW]) {
    int numerStatku = 1;
    dlugosciStatkow[1] = 4;
    losujStatek(planszaStatkow, 4, numerStatku);
    numerStatku++;
    dlugosciStatkow[2] = 3;
    losujStatek(planszaStatkow, 3, numerStatku);
    numerStatku++;
    dlugosciStatkow[3] = 3;
    losujStatek(planszaStatkow, 3, numerStatku);
    numerStatku++;
    dlugosciStatkow[4] = 2;
    losujStatek(planszaStatkow, 2, numerStatku);
    numerStatku++;
    dlugosciStatkow[5] = 2;
    losujStatek(planszaStatkow, 2, numerStatku);
    numerStatku++;
    dlugosciStatkow[6] = 2;
    losujStatek(planszaStatkow, 2, numerStatku);
    numerStatku++;
    dlugosciStatkow[7] = 1;
    losujStatek(planszaStatkow, 1, numerStatku);
    numerStatku++;
    dlugosciStatkow[8] = 1;
    losujStatek(planszaStatkow, 1, numerStatku);
    numerStatku++;
    dlugosciStatkow[9] = 1;
    losujStatek(planszaStatkow, 1, numerStatku);
    numerStatku++;
}
void pokazPlanszeTestowa(char planszaStatkow[ROZMIAR][ROZMIAR]) {
    cout << "\nPlansza testowa ze statkami:";
    cout << "\n    ";
    for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
        if (kolumna + 1 < 10) {
            cout << " " << kolumna + 1 << " ";
        } else {
            cout << kolumna + 1 << " ";
        }
    }
    cout << endl;
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        if (wiersz + 1 < 10) {
            cout << "  " << wiersz + 1 << "  ";
        } else {
            cout << " " << wiersz + 1 << "  ";
        }
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            if (planszaStatkow[wiersz][kolumna] == '.') {
                cout << ".  ";
            } else {
                cout << "S  ";
            }
        }
        cout << endl;
    }
}
bool czyStatekZatopiony(char planszaStatkow[ROZMIAR][ROZMIAR], char planszaGracza[ROZMIAR][ROZMIAR], int numerStatku) {
    char znakStatku = '0' + numerStatku;
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            if (planszaStatkow[wiersz][kolumna] == znakStatku && planszaGracza[wiersz][kolumna] != 'X') {
                return false;
            }
        }
    }
    return true;
}
void oznaczZatopiony(char planszaStatkow[ROZMIAR][ROZMIAR], char planszaGracza[ROZMIAR][ROZMIAR], int numerStatku) {
    char znakStatku = '0' + numerStatku;
    for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            if (planszaStatkow[wiersz][kolumna] == znakStatku) {
                planszaGracza[wiersz][kolumna] = '#';
            }
        }
    }
}
void radar(char planszaStatkow[ROZMIAR][ROZMIAR], int wiersz, int kolumna) {
    bool znaleziono = false;
    for (int zmianaWiersza = -1; zmianaWiersza <= 1; zmianaWiersza++) {
        for (int zmianaKolumny = -1; zmianaKolumny <= 1; zmianaKolumny++) {
            if (zmianaWiersza == 0 && zmianaKolumny == 0) {
                continue;
            }
            int sprawdzanyWiersz = wiersz + zmianaWiersza;
            int sprawdzanaKolumna = kolumna + zmianaKolumny;
            if (CzyPoleJestNaPlanszy(sprawdzanyWiersz, sprawdzanaKolumna)) {
                if (planszaStatkow[sprawdzanyWiersz][sprawdzanaKolumna] != '.') {
                    znaleziono = true;
                }
            }
        }
    }
    if (znaleziono) {
        cout << "Radar: w poblizu znajduje sie statek.\n";
    } else {
        cout << "Radar: w poblizu nie ma statku.\n";
    }
}
bool czyWszystkieStatkiZatopione(bool zatopioneStatki[ILE_STATKOW]) {
    for (int i = 1; i < ILE_STATKOW; i++) {
        if (zatopioneStatki[i] == false) {
            return false;
        }
    }
    return true;
}
void pokazLegende() {
    cout << "\nLegenda:";
    cout << "\n0 - nieodkryte pole";
    cout << "\n* - pudlo";
    cout << "\nX - trafiony statek";
    cout << "\n# - zatopiony statek";
    cout << endl;
}
int main() {
    srand(time(NULL));
    char planszaGracza[ROZMIAR][ROZMIAR];
    char planszaStatkow[ROZMIAR][ROZMIAR];
    int dlugosciStatkow[ILE_STATKOW];
    bool zatopioneStatki[ILE_STATKOW];
    for (int i = 0; i < ILE_STATKOW; i++) {
        dlugosciStatkow[i] = 0;
        zatopioneStatki[i] = false;
    }
    wypelnijPlansze(planszaGracza, '0');
    wypelnijPlansze(planszaStatkow, '.');
    losujWszystkieStatki(planszaStatkow, dlugosciStatkow);
    char wyborTestu;
    cout << "Czy pokazac plansze testowa ze statkami? t/n: ";
    cin >> wyborTestu;
    if (wyborTestu == 't' || wyborTestu == 'T') {
        pokazPlanszeTestowa(planszaStatkow);
    }
    int liczbaStrzalow = 0;
    while (czyWszystkieStatkiZatopione(zatopioneStatki) == false) {
        pokazPlansze(planszaGracza);
        pokazLegende();
        int wiersz;
        int kolumna;
        cout << "\nPodaj wiersz od 1 do 10: ";
        cin >> wiersz;
        cout << "Podaj kolumne od 1 do 10: ";
        cin >> kolumna;
        wiersz--;
        kolumna--;
        if (CzyPoleJestNaPlanszy(wiersz, kolumna) == false) {
            cout << "Podales pole poza plansza. Sprobuj jeszcze raz.\n";
            continue;
        }
        if (planszaGracza[wiersz][kolumna] == '*' ||
            planszaGracza[wiersz][kolumna] == 'X' ||
            planszaGracza[wiersz][kolumna] == '#') {
            cout << "To pole bylo juz sprawdzone. Wybierz inne pole.\n";
            continue;
        }
        liczbaStrzalow++;
        if (planszaStatkow[wiersz][kolumna] == '.') {
            cout << "\nPudlo!\n";
            planszaGracza[wiersz][kolumna] = '*';
        } else {
            cout << "\nTrafiony!\n";
            planszaGracza[wiersz][kolumna] = 'X';
            int numerStatku = planszaStatkow[wiersz][kolumna] - '0';
            if (czyStatekZatopiony(planszaStatkow, planszaGracza, numerStatku)) {
                cout << "Zatopiony!\n";
                oznaczZatopiony(planszaStatkow, planszaGracza, numerStatku);
                zatopioneStatki[numerStatku] = true;
            }
        }
        radar(planszaStatkow, wiersz, kolumna);
    }
    pokazPlansze(planszaGracza);
    cout << "\nGratulacje! Zatopiles wszystkie statki!\n";
    cout << "Liczba strzalow: " << liczbaStrzalow << endl;
    return 0;
}


