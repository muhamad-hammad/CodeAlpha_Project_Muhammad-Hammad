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

public:
    // Constructor
    NumberGuessingGame(int range, int maxAttempts);

    // Game loop
    void playGame();

private:
    // Generate random number
    void generateRandomNumber(int range);

    // Get player's guess
    int getPlayerGuess();

    // Check if guess is correct
    bool checkGuess(int guess);

    // Print hint
    void printHint(int guess);

    // Print game over message
    void printGameOverMessage();
};

// Constructor implementation
NumberGuessingGame::NumberGuessingGame(int range, int maxAttempts) {
    // Initialize random number generator
    srand(time(0));

    // Generate random number
    generateRandomNumber(range);

    // Set maximum attempts
    this->maxAttempts = maxAttempts;
    numAttempts = 0;
}

// Game loop implementation
void NumberGuessingGame::playGame() {
    // Game loop
    while (numAttempts < maxAttempts) {
        // Get player's guess
        int guess = getPlayerGuess();

        // Check if guess is correct
        if (checkGuess(guess)) {
            // Guess is correct, end the game
            break;
        }

        // Print hint
        printHint(guess);

        numAttempts++;
    }

    // Print game over message if player didn't guess correctly
    if (numAttempts == maxAttempts) {
        printGameOverMessage();
    }
}

int main() {
    // Create game object
    NumberGuessingGame game(100, 7);  // Range: 1-100, Max attempts: 7

    // Play the game
    game.playGame();

    return 0;
}
