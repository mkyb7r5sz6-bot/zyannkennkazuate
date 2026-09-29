#ifndef KAZUATE_H
#define KAZUATE_H

#include <iostream>
using namespace std;


enum Hint {
    HINT_LOWER = 0, 
    HINT_HIGHER,    
    HINT_EQUAL     
};


enum GameStatus {
    STATUS_PLAYING,
    STATUS_CLEAR,
    STATUS_GAMEOVER
};

struct KazuateState {
    int answer;       
    int currentGuess;
    int attempts;     
    GameStatus status;
};


void playKazuate();
Hint checkGuess(int guess, int answer);

#endif
