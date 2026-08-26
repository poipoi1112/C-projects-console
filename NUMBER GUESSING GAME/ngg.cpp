#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "======================== NUMBER GUESSING GAME ========================" << endl;
    cout << "I picked a number from 1-100" << endl;
    cout << "Try to guess it" << endl;

    do{
        cout << "\nWhat do you think it is? ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "You're right! CONGRATULATIONS!!! " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}