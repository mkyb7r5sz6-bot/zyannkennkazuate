#include <cstdlib>
#include "janken.cpp.h"


const char* const HAND_NAMES[] = { "Rock", "Scissors", "Paper" };

void printHand(Hand hand) 
{
    if (hand >= ROCK && hand <= PAPER) 
    {
        cout << HAND_NAMES[hand] << "\n"; 
    }
}

Result judge(Hand playerHand, Hand cpuHand) 
{
    if (playerHand == cpuHand) return DRAW;

    if ((playerHand == ROCK && cpuHand == SCISSORS) ||
        (playerHand == SCISSORS && cpuHand == PAPER) ||
        (playerHand == PAPER && cpuHand == ROCK)) {
        return WIN;
    }
    return LOSE;
}

void playJanken() 
{
    JankenState state = { "nanashi", 0, 0, 0, 1 };

    cout << "Enter your name: ";
    cin >> state.name;
    cout << "Welcome, " << state.name << "! Let's start Janken!\n";

    while (state.wins < 3 && state.losses < 3)
    {
        cout << "\n[Round " << state.round << "]\n";
        cout << "Choose your hand (0: Rock, 1: Scissors, 2: Paper): ";
        int input;
        cin >> input;

        if (input < 0 || input > 2) 
        {
            cout << "Invalid choice.\n";
            continue;
        }

        Hand playerHand = static_cast<Hand>(input);
        Hand cpuHand = static_cast<Hand>(rand() % 3);

        cout << state.name << ": "; printHand(playerHand);
        cout << "CPU: "; printHand(cpuHand);

        Result res = judge(playerHand, cpuHand);
        if (res == WIN) 
        {
            cout << "Result: You WIN this round!\n";
            state.wins++;
            state.round++;
        }
        else if (res == LOSE) 
        {
            cout << "Result: You LOSE this round!\n";
            state.losses++;
            state.round++;
        }
        else 
        {
            cout << "Result: DRAW!\n";
            state.draws++;
        }
        
    }
    
}