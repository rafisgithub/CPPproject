#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  // Generate a random number between 1 and 100
  int number = rand() % 100 + 1;

  while (true) {
    cout << "Enter your guess: ";
    int guess;
    cin >> guess;

    if (guess == number) {
      cout << "You won!" << endl;
      break;
    } else if (guess < number) {
      cout << "Your guess is too low." << endl;
    } else {
      cout << "Your guess is too high." << endl;
    }
  }

  return 0;
}

