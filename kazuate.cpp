#include "kazuate.cpp.h"
#include <cstdlib>


const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const int MAX_ATTEMPTS = 10;


const char* const HINT_MESSAGES[] = {
    "Too high! Try a smaller number.", 
    "Too low! Try a larger number.",  
    "Correct! You found the number!"   
};


Hint checkGuess(int guess, int answer) {
    if (guess > answer) {
        return HINT_LOWER;
    }
    else if (guess < answer) {
        return HINT_HIGHER;
    }
    else {
        return HINT_EQUAL;
    }
}

void playKazuate() {
    
    KazuateState game;
    game.answer = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
    game.attempts = 0;
    game.status = STATUS_PLAYING;

    cout << "\n=========================================\n";
    cout << "Welcome to the Guessing Game (Kazuate)!\n";
    cout << "I have chosen a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
    cout << "Can you guess it within " << MAX_ATTEMPTS << " attempts?\n";
    cout << "=========================================\n";

    while (game.status == STATUS_PLAYING) {
        game.attempts++;
        cout << "\n[Attempt " << game.attempts << " / " << MAX_ATTEMPTS << "]\n";
        cout << "Enter your guess: ";
        cin >> game.currentGuess;

      
        if (game.currentGuess < MIN_NUMBER || game.currentGuess > MAX_NUMBER) {
            cout << "Invalid input. Please guess between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
            game.attempts--; 
            continue;
        }

    
        Hint hint = checkGuess(game.currentGuess, game.answer);
        cout << HINT_MESSAGES[hint] << "\n"; 

        if (hint == HINT_EQUAL) {
            game.status = STATUS_CLEAR;
        }
        else if (game.attempts >= MAX_ATTEMPTS) {
            game.status = STATUS_GAMEOVER;
        }
    }


    cout << "\n=========================================\n";
    if (game.status == STATUS_CLEAR) {
        cout << "CONGRATULATIONS!\n";
        cout << "You cleared the game in " << game.attempts << " attempts!\n";
    }
    else {
        cout << "GAME OVER\n";
        cout << "The correct number was: " << game.answer << "\n";
        cout << "Better luck next time!\n";
    }
    cout << "=========================================\n";
}