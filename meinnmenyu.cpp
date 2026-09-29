#include <iostream>
#include <cstdlib>
#include <ctime>
#include "janken.cpp.h"
#include "kazuate.cpp.h"
using namespace std;

int main() {
    srand((unsigned int)time(nullptr)); 

    int choice = 0;
    while (true) {
        cout << "\n=== GAME MENU ===\n";
        cout << "1: Janken Game\n";
        cout << "2: Guessing Game (Kazuate)\n";
        cout << "3: Exit\n";
        cout << "Select (1-3): ";
        cin >> choice;

        if (choice == 1) {
            playJanken(); 
        }
        else if (choice == 2) {
            playKazuate(); 
        }
        else if (choice == 3) {
            cout << "Good bye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please re-enter.\n";
        }
    }
    return 0;
}

