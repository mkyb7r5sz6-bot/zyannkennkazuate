#ifndef JANKEN_H
#define JANKEN_H

#include <iostream>
using namespace std;


enum Hand {
    ROCK = 0,
    SCISSORS,
    PAPER,
    INVALID_HAND
};

enum Result {
    DRAW = 0,
    WIN = 1,
    LOSE = -1
};


struct JankenState {
    char name[50];
    int wins;
    int losses;
    int draws;
    int round;
};


void playJanken();
Result judge(Hand playerHand, Hand cpuHand);
void printHand(Hand hand);

#endif