#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the maximum number (n): ";
    cin >> n;

    int lowerBound = 1;
    int upperBound = n;
    int guess;

    while (lowerBound <= upperBound) {
        guess = (lowerBound + upperBound) / 2;

        char response;
        cout << "Is your number less than " << guess << "? (y/n): ";
        cin >> response;

        if (response == 'y') {
            upperBound = guess - 1;
        } else if (response == 'n') {
            lowerBound = guess + 1;
        } else {
            cout << "Invalid response. Please enter 'y' or 'n'." << endl;
            continue;
        }

        if (lowerBound == upperBound) {
            guess = lowerBound;
            break;
        }
    }
    cout << "Your number is " << guess << "." << endl;
}
