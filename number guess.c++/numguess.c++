#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits> // for std::numeric_limits

int generate_random_number() {
    static int MIN_INT = 0;
    static int MAX_INT = 100;

    srand(static_cast<unsigned int>(time(0)));

    return (rand() % (MAX_INT - MIN_INT + 1)) + MIN_INT;
}

bool check_if_equal(int correct_number, int guess) {
    if (guess == correct_number) {
        std::cout << "Congratulations! You guessed the correct number: " << guess << std::endl;
        return true;
    } else if (guess > correct_number) {
        std::cout << "The correct number is smaller than " << guess << std::endl;
    } else {
        std::cout << "The correct number is bigger than " << guess << std::endl;
    }
    return false;
}

int guess_the_number() {
    int guess = 0;
    std::cout << "Enter your guess: ";
    while (!(std::cin >> guess)) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your guess: ";
    }
    return guess;
}

int main() {
    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "You have 10 attempts to guess the number between 0 and 100." << std::endl;

    int attempts = 10;
    bool correct = false;

    while (attempts > 0 && !correct) {
        int random_number = generate_random_number();
        int guess = guess_the_number();
        correct = check_if_equal(random_number, guess);
        attempts--;
    }

    if (!correct) {
        std::cout << "Sorry, you ran out of attempts." << std::endl;
    }

    return 0;
}