// HangmanGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int hangmanVisual() {
    // Hangman Visual constructor. Change the char to reflect tries left.
    char hangmanHead = 'O';
    char hangmanLeftArm = '/';
    char hangmanUpperBody = '|';
    char hangmanRightArm = '\\';
    char hangmanLowerBody = '|';
    char hangmanLeftLeg = '/';
    char hangmanRightLeg = '\\';


    std::cout << " _________" << std::endl;
    std::cout << "|    |    " << std::endl;
    std::cout << "|    " << hangmanHead << "   "<< std::endl;
    std::cout << "|  " << hangmanLeftArm << " " << hangmanUpperBody << " " << hangmanRightArm << " " << std::endl;
    std::cout << "|    " << hangmanLowerBody << "     " << std::endl;
    std::cout << "|   " << hangmanLeftLeg << " " << hangmanRightLeg << " " << std::endl;
    std::cout << "|         " << std::endl;
    std::cout << "|_________" << std::endl;
    return 0;
}

int gameplay() {
    // Player has 7 tries to complete the game.
    int triesLeft = 6;
    while (triesLeft > 0) {
        hangmanVisual();
        int triesleft = triesLeft--;
        std::cout << triesLeft;
    }
    return 0;
}

int main() {
    std::cout << "Welcome to Hangman!" << std::endl;
    hangmanVisual();
    gameplay();
}

