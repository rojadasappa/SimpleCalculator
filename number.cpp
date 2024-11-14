#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void playGame(int maxAttempts, int range) {
srand((unsigned int)time(NULL));
int number = (rand() % range) + 1;
int guess = 0;
int attempts = 0;

cout << "Guess the number between 1 and " << range << " (within " << maxAttempts << " attempts)!" << endl;

do {
    cout << "Enter Guess (1-" << range << "): ";
    cin >> guess;

    if (guess < 1 || guess > range) {
        cout << "Invalid input! Please guess within the range." << endl;
        continue;
        }
attempts++;

if (guess > number) {
cout << "Guess lower!" << endl;
}
else if (guess < number) {
cout << "Guess higher!" << endl;
}
else {
            cout << "Congratulations! You won in " << attempts << " attempts!" << endl;
            return;
}

    }
    while (attempts < maxAttempts);

cout << "You've used all attempts! The correct number was: " << number << endl;
}

int main() {
    char playAgain;
    do {
        int difficulty, maxAttempts, range;

        cout << "Select difficulty level:\n1. Easy\n2. Medium\n3. Hard\nChoice: ";
        cin >> difficulty;

        switch (difficulty) {
            case 1:
                maxAttempts = 10;
                range = 50;
                break;
            case 2:
                maxAttempts = 7;
                range = 100;
                break;
            case 3:
                maxAttempts = 5;
                range = 150;
                break;
            default:
                cout << "Invalid choice. Defaulting to Medium.\n";
                maxAttempts = 7;
                range = 100;
        }

        playGame(maxAttempts, range);

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;
    return 0;
}

