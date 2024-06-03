#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Game class
class NumberGuessingGame {
private:
    int randomNumber;
    int maxAttempts;
    int numAttempts;
    // Generate random number
void generateRandomNumber(int range) {
    randomNumber = rand() % range + 1;
}

// Get player's guess
int getPlayerGuess() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

// Check if guess is correct
bool checkGuess(int guess) {
    return guess == randomNumber;
}

// Print hint
    void printHint(int guess) {
    if (guess < randomNumber * 0.5) {
        cout << "Too too low! Try again." << endl;
    } else if (guess < randomNumber) {
        cout << "Too low! Try again." << endl;
    } else if ((guess / randomNumber) < 1.1 || (randomNumber / guess) < 0.9) {
        cout << "Too too high! Try again." << endl;
    } else {
        cout << "Too high! Try again." << endl;
    }
}

// Print game over message
void printGameOverMessage() {
    cout << "Game over! The number was " << randomNumber << "." << endl;
}

public:
    // Constructor
    NumberGuessingGame(int range, int maxAttempts)
    {
        // Seed the random number generator with the current time
        srand(time(0));

        // Generate a random number within the specified range
        generateRandomNumber(range);

        // Set the maximum number of attempts allowed
        this->maxAttempts = maxAttempts;

        // Initialize the number of attempts made to 0
        numAttempts = 0;
    }

    void playGame() {
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and " << randomNumber << ". Can you guess it?" << endl;

    bool guessedCorrectly = false;

    while (!guessedCorrectly && numAttempts < maxAttempts) {
        // Get player's guess
        int guess = getPlayerGuess();

        // Check if guess is correct
        if (checkGuess(guess)) {
            cout << "Congratulations! You guessed the number correctly!" << endl;
            guessedCorrectly = true;
            break; // Exit the loop since the player guessed correctly
        }

        // Print hint
        printHint(guess);
        numAttempts++;
    }

    // Print game over message if player didn't guess correctly
    if (!guessedCorrectly) {
        printGameOverMessage();
    }
}
};


int main() {
    // Create game object
    NumberGuessingGame game(100, 7);  // Range: 1-100, Max attempts: 7

    // Play the game
    game.playGame();

    return 0;
}
