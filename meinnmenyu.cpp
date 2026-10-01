#include <iostream>
#include <cstdlib>
#include <ctime>
#include "zennbu.cpp.h"
using namespace std;

int main() {
    srand((unsigned int)time(nullptr)); 

    int choice = 0;
    while (true) {
        cout << "\n=== GAME MENU ===\n";
        cout << "1: じゃんけんゲーム\n";
        cout << "2: 数当て\n";
        cout << "3: 終了\n";
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

