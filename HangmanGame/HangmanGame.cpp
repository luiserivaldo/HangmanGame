// HangmanGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int gameplay() {
    // Empty Hangman Visual constructor.
    char hangmanHead = ' ';
    char hangmanLeftArm = ' ';
    char hangmanUpperBody = ' ';
    char hangmanRightArm = ' ';
    char hangmanLowerBody = ' ';
    char hangmanLeftLeg = ' ';
    char hangmanRightLeg = ' ';

    // Number of tries the player has.
    int triesLeft = 7;

    while (triesLeft > 0) {
        std::cout << " _________" << std::endl;
        std::cout << "|    |    " << std::endl;
        std::cout << "|    " << hangmanHead << "   " << std::endl;
        std::cout << "|  " << hangmanLeftArm << " " << hangmanUpperBody << " " << hangmanRightArm << " " << std::endl;
        std::cout << "|    " << hangmanLowerBody << "     " << std::endl;
        std::cout << "|   " << hangmanLeftLeg << " " << hangmanRightLeg << " " << std::endl;
        std::cout << "|         " << std::endl;
        std::cout << "|_________" << std::endl;
        std::cout << "\nYou have " << triesLeft << " tries left!" << std::endl;

        int triesleft = triesLeft--;

        // Change Hangman visual depending on tries left.
        if (triesLeft <= 6) {
            hangmanHead = 'O';
        }
        if (triesLeft <= 5) {
            hangmanUpperBody = '|';
        }
        if (triesLeft <= 4) {
            hangmanLeftArm = '/';
        }
        if (triesLeft <= 3) {
            hangmanRightArm = '\\';
        }
        if (triesLeft <= 2) {
            hangmanLowerBody = '|';
        }
        if (triesLeft <= 1) {
            hangmanLeftLeg = '/';
        }
        if (triesLeft <= 0) {
            hangmanRightLeg = '\\';
        }
    }

    if (triesLeft <= 0) {
        std::cout << " _________" << std::endl;
        std::cout << "|    |    " << std::endl;
        std::cout << "|    " << hangmanHead << "   " << std::endl;
        std::cout << "|  " << hangmanLeftArm << " " << hangmanUpperBody << " " << hangmanRightArm << " " << std::endl;
        std::cout << "|    " << hangmanLowerBody << "     " << std::endl;
        std::cout << "|   " << hangmanLeftLeg << " " << hangmanRightLeg << " " << std::endl;
        std::cout << "|         " << std::endl;
        std::cout << "|_________" << std::endl;
        std::cout << "\nNo tries left. Game over!";
    }
    return 0;
}

int main() {
    std::cout << "Welcome to Hangman!" << std::endl;
    gameplay();
}

