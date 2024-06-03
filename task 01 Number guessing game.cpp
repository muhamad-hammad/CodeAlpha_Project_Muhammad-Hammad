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


int main()
{
    cout << "Welcome to the Number Guessing Game!" << endl
         << "The rules are simple enough:" << endl
         << "I Think of a number and you guess it in as few attempts as possible." << endl
         << "Good luck!" << endl
         << "choose a difficulty level: \n E for Easy, M for medium, H for hard." << endl;
    char level;
    cout << "Enter your choice: ";
    cin >> level;
    switch (level)
    {
    case 'E':
    case 'e':
        cout << "I'm thinking of a number between 1 and 50. Can you guess it?" << endl;
        NumberGuessingGame game(50, 7); // Range: 1-50, Max attempts: 7
        game.playGame();
        break;
    case 'M':
    case 'm':
        cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;
        NumberGuessingGame game(100, 6); // Range: 1-100, Max attempts: 6
        game.playGame();
        break;
    case 'H':
    case 'h':
        cout << "I'm thinking of a number between 1 and 200. Can you guess it?" << endl;
        NumberGuessingGame game(200, 5); // Range: 1-200, Max attempts: 5
        game.playGame();
        break;
    default:
        break;
    }

    return 0;
}
