#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame
{
private:
    int randomNumber;
    int maxAttempts;
    int numAttempts;

    void generateRandomNumber(int range)
    {
        randomNumber = rand() % range + 1;
    }

    int getPlayerGuess()
    {
        int guess;
        cout << "Enter your guess: ";
        cin >> guess;
        return guess;
    }

    bool checkGuess(int guess)
    {
        return guess == randomNumber;
    }

    void printHint(int guess)
    {
        int difference = abs(randomNumber - guess);

        if (difference >= 30)
        {
            cout << "Too too low! Try again." << endl;
        }
        else if (difference >= 20)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (difference >= 10)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (difference > 5)
        {
            cout << "Too too high! Try again." << endl;
        }
        else
        {
            cout << "Very close! Try again." << endl;
        }
    }

    void printGameOverMessage()
    {
        cout << "Game over! The number was " << randomNumber << "." << endl;
    }

public:
    NumberGuessingGame(int range, int maxAttempts)
    {
        srand(time(0));
        generateRandomNumber(range);
        this->maxAttempts = maxAttempts;
        numAttempts = 0;
    }

    void playGame()
    {
        bool guessedCorrectly = false;

        while (!guessedCorrectly && numAttempts < maxAttempts)
        {
            int guess = getPlayerGuess();

            if (checkGuess(guess))
            {
                cout << "Congratulations! You guessed the number correctly!" << endl;
                guessedCorrectly = true;
                break;
            }

            printHint(guess);
            numAttempts++;
        }

        if (!guessedCorrectly)
        {
            printGameOverMessage();
        }
    }
};

int main()
{
    cout << "Welcome to the Number Guessing Game!" << endl
         << "The rules are simple enough:" << endl
         << "I Think of a number and you guess it in as few attempts as possible." << endl
         << "If you guess it correctly, you win!" << endl
         << "If you guess don't, I'll give you a hint." << endl
         << "You have limited attempts to guess the number." << endl
         << "If you run out of attempts, you lose." << endl
         << "Good luck!" << endl;
    char level;
    char eogame;
    do
    {
        cout << "choose a difficulty level: \n E for Easy, M for medium, H for hard." << endl;
        cout << "Enter your choice: ";
        cin >> level;
        char end;
        int flag = 0;
        do
        {
            switch (level)
            {
            case 'E':
            case 'e':
            {
                cout << "I'm thinking of a number between 1 and 50. Can you guess it?" << endl;
                do
                {
                    NumberGuessingGame game(50, 7);
                    game.playGame();
                    cout << "Do you want to play again in same level? (y/n)" << endl;
                    cin >> end;
                } while (end == 'y' || end == 'Y');
            }
            break;
            case 'M':
            case 'm':
            {
                cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;
                do
                {
                    NumberGuessingGame game(100, 6);
                    game.playGame();
                    cout << "Do you want to play again in same level? (y/n)" << endl;
                    cin >> end;
                } while (end == 'y' || end == 'Y');
            }
            break;
            case 'H':
            case 'h':
            {
                cout << "I'm thinking of a number between 1 and 200. Can you guess it?" << endl;
                do
                {
                    NumberGuessingGame game(200, 5);
                    game.playGame();
                    cout << "Do you want to play again in same level? (y/n)" << endl;
                    cin >> end;
                } while (end == 'y' || end == 'Y');
            }
            break;
            default:
                cout << "Invalid choice. \nAgain! " << endl;
                flag = 1;
                break;
            }
        } while (flag == 1);

        cout << "Do you wana end the game?";
        cin >> eogame;
    } while ((eogame == 'n' || eogame == 'N') && (eogame != 'y' || eogame != 'Y'));

    return 0;
}
