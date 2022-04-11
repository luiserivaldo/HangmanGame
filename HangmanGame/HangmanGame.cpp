// HangmanGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

void hangmanVisual () {
    // Base Hangman Visual constructor.
    char hangmanHead = ' ';
    char hangmanLeftArm = ' ';
    char hangmanUpperBody = ' ';
    char hangmanRightArm = ' ';
    char hangmanLowerBody = ' ';
    char hangmanLeftLeg = ' ';
    char hangmanRightLeg = ' ';

    std::cout << " _________" << std::endl;
    std::cout << "|    |    " << std::endl;
    std::cout << "|    " << hangmanHead << "   "<< std::endl;
    std::cout << "|  " << hangmanLeftArm << " " << hangmanUpperBody << " " << hangmanRightArm << " " << std::endl;
    std::cout << "|    " << hangmanLowerBody << "     " << std::endl;
    std::cout << "|   " << hangmanLeftLeg << " " << hangmanRightLeg << " " << std::endl;
    std::cout << "|         " << std::endl;
    std::cout << "|_________" << std::endl;
}

int gameplay() {
    // Hangman Visual constructor. Change the char to reflect tries left.
    int triesLeft = 7;
    if (triesLeft <= 6) {
        char hangmanHead = 'O';
    }
    else if (triesLeft <= 5) {
        char hangmanLeftArm = '/';
    }
    else if (triesLeft <= 4) {
        char hangmanUpperBody = '|';
    }
    else if (triesLeft <= 3) {
        char hangmanRightArm = '\\';
    }
    else if (triesLeft <= 2) {
        char hangmanLowerBody = '|';
    }
    else if (triesLeft <= 1) {
        char hangmanLeftLeg = '/';
    }
    else if (triesLeft <= 0) {
        char hangmanRightLeg = '\\';
    }

    // Player has 7 tries to complete the game.
    hangmanVisual();
    while (triesLeft > 0) {
        hangmanVisual();
        std::cout << "\nYou have " << triesLeft << " tries left!" << std::endl;
        int triesleft = triesLeft--;
    }
    if (triesLeft <= 0) {
        hangmanVisual();
        std::cout << "\nNo tries left. Game over!";
    }

    return 0;
}

int main() {
    std::cout << "Welcome to Hangman!" << std::endl;
    gameplay();
}

