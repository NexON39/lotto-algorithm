#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <time.h>
using namespace std;

int liczby[6], wylosowane_liczby[6], wygrane_liczby, udane_liczby[6];

int main() {
    for(;;) {
        //powitanie
        cout << "Welcome to the LOTTO drawing machine! Check your luck!" << endl;
        cout << "Made by NexON39" << endl;

        srand(time(NULL));      
        //wpisywanie liczb i walidacja danych
        for(int i=0; i<=5; i++) {
            cout << "Type " << i+1 << " number: ";
            if(!(cin >> liczby[i])) {
                cout << "The given number is not a number! Try again." << endl << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                i--;
            } else if(liczby[i]<1 || liczby[i]>49) {
                cout << "The given number is not in the range 1-49! Try again." << endl << endl;
                i--;
            }
            for(int sprawdz=0; sprawdz<i; sprawdz++) {
                if(liczby[i]==liczby[sprawdz]) {
                    cout << "You have already given such a number! Try again." << endl << endl;
                    i--;
                }
            }
        }

        //generator liczb bez powtórzeń
        for(int i=0; i<=5; i++) {
            wylosowane_liczby[i] = rand() % 49 + 1;
            for(int sprawdz=0; sprawdz<i; sprawdz++) {
                if(wylosowane_liczby[i]==wylosowane_liczby[sprawdz]) {
                    i--;
                }
            }
        }

        //wyświetlanie liczb na ekranie
        system("cls");
        cout << "Drawn numbers: ";
        for(int i=0; i<=5; i++) {
            Sleep(1000);
            if(i==5) {
                cout << wylosowane_liczby[i] << ".";
            } else {
                cout << wylosowane_liczby[i] << ", ";  
            }
        }
        cout << endl << endl;

        //zliczanie wygranych
        for(int i=0; i<=5; i++) {
            for(int sprawdz=0; sprawdz<=5; sprawdz++) {
                if(wylosowane_liczby[i]==liczby[sprawdz]) {
                    wygrane_liczby++;
                    udane_liczby[i]==wylosowane_liczby[i];
                }
            }
        }

        //wynik
        if(wygrane_liczby==0 || wygrane_liczby>=5) {
            cout << "You guessed " << wygrane_liczby << " number!";
        } else if(wygrane_liczby==1) {
            cout << "You guessed " << wygrane_liczby << " number!";
        } else if(wygrane_liczby>=2 && wygrane_liczby<=4) {
            cout << "You guessed " << wygrane_liczby << " numbers!";
        }
        cout << endl << "Your numbers: ";
        for(int i=0; i<=5; i++) {
            if(i==5) {
                cout << liczby[i] << ".";
            } else {
                cout << liczby[i] << ", ";
            }
        }
        //zapętlenie programu
        cout << endl << endl;
        cout << "Press enter to start over!";
        getchar();getchar();
        system("cls");
    }
}
