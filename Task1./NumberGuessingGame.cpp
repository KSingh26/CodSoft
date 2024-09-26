#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

void playGame() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        
        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number: " << randomNumber << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }
    } while (userGuess != randomNumber);
}

int main() {
    char playAgain;

    do {
        playGame();
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye!" << endl;
    return 0;
}
