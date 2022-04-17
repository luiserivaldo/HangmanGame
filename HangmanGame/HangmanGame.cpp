// HangmanGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

int gameplay() {
    // Create word list 
    std::string word; // Word selected for the game
    std::string wordList[799]; // Array to store word list

    // Read word list file and create word list array
    srand(time(NULL)); // Create random seed
    std::ifstream randomWord; // Reads the word list as a variable
    randomWord.open("words.txt"); // Opens the word list from "words.txt"
    for (int i = 0; i < 799; i++) {
        randomWord >> wordList[i];
    }

    // Select random word
    int randNum = rand() % 800; // Generate a random number used for the word selection
    word = wordList[randNum]; // Selects a random word from the array

    randomWord.close(); // Stop reading the word file

    // Display number of characters in the word (word is hidden to the player)
    std::string hiddenWord(word.length(), '-');

    // Variables for empty Hangman Visual.
    char hangmanHead = ' ';
    char hangmanLeftArm = ' ';
    char hangmanUpperBody = ' ';
    char hangmanRightArm = ' ';
    char hangmanLowerBody = ' ';
    char hangmanLeftLeg = ' ';
    char hangmanRightLeg = ' ';

    int triesLeft = 7; // Number of tries the player has.
    char userGuess; // Variable to store user input.
    bool guessIsCorrect = false;

    while (triesLeft > 0) { // Loops gameplay if player still has multiple tries left
        guessIsCorrect = false; // Reset the guess value while in the loop

        // Hangman Visual constructor
        std::cout << " _________" << std::endl;
        std::cout << "|    |    " << std::endl;
        std::cout << "|    " << hangmanHead << "   " << std::endl;
        std::cout << "|  " << hangmanLeftArm << " " << hangmanUpperBody << " " << hangmanRightArm << " " << std::endl;
        std::cout << "|    " << hangmanLowerBody << "     " << std::endl;
        std::cout << "|   " << hangmanLeftLeg << " " << hangmanRightLeg << " " << std::endl;
        std::cout << "|         " << std::endl;
        std::cout << "|_________" << std::endl;
        std::cout << std::endl;

        // std::cout << word; // TESTING: The correct word for the game
        std::cout << "\nGuess the word: " << hiddenWord << std::endl;
        std::cout << "\nYou have " << triesLeft << " tries left!" << std::endl;
        std::cout << "\nTry a letter: " << std::endl;
        std::cin >> userGuess; // Ask for input from player

        // TESTING: store previous guesses into a vector
        // std::vector<char> triedGuesses;
        // for (char i : triedGuesses) {
        //    triedGuesses.push_back(userGuess);
        //    std::cout << i << ' ';
        // }

        // Reveal correct guesses from hidden word
        for (int i = 0; i < hiddenWord.length(); i++) {
            if (word[i] == userGuess) {
                hiddenWord[i] = userGuess;
                guessIsCorrect = true;
            }
        }

        // Ends game if word is correctlyy guessed
        if (word == hiddenWord) {
            std::cout << "\nCongratulations! You won the game!" << std::endl;
            std::cout << "\nThe answer is " << word << "." << std::endl;
            break; // Close the game once finished
        }

        if (guessIsCorrect == false){
            std::cout << "\nThe letter is wrong. Please try again." << std::endl;
            int triesleft = triesLeft--; // Reduce user attempt by 1 for every failed guess
        }

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
        std::cout << "\nNo tries left. Game over!" << std::endl;
        std::cout << "The answer is " << word << "." << std::endl;
    }
    return 0;
}

int main() {
    std::cout << "Welcome to Hangman!" << std::endl;
    gameplay();
}

