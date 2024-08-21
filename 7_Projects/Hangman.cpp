
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hangman class that encapsulates the entire game logic
class Hangman {
private:
    vector<string> wordList;  // List of possible words for the game
    string secretWord;        // The word that the player needs to guess
    string guessedWord;       // The word as currently guessed by the player
    int maxAttempts;          // Maximum number of incorrect guesses allowed
    int attemptsLeft;         // Remaining number of incorrect guesses allowed
    vector<char> wrongGuesses;// List of incorrect guesses made by the player

public:
    // Constructor: Initializes the game with a word list and maximum number of attempts
    Hangman(const vector<string>& words, int maxAttempts = 6) 
    {
        wordList = words;
        this->maxAttempts = maxAttempts;
        attemptsLeft = maxAttempts;
        secretWord = getRandomWord();
        guessedWord = string(secretWord.length(), '_');
    }

    // Starts the game loop
    void startGame() {
        cout << "Welcome to Hangman!" << endl;
        while (attemptsLeft > 0 && guessedWord != secretWord) {
            displayCurrentState();
            char guess = getGuessFromPlayer();
            processGuess(guess);
        }
        endGame();
    }

private:
    // Gets a random word from the word list
    string getRandomWord() {
        srand(time(0));
        int randomIndex = rand() % wordList.size();
        return wordList[randomIndex];
    }

    // Displays the current state of the game (guessed word and remaining attempts)
    void displayCurrentState() {
        cout << "\nGuessed word: " << guessedWord << endl;
        cout << "Wrong guesses: ";
        for (char c : wrongGuesses) {
            cout << c << " ";
        }
        cout << "\nAttempts left: " << attemptsLeft << endl;
    }

    // Gets a letter guess from the player
    char getGuessFromPlayer() {
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        return tolower(guess); // Convert to lowercase to make guessing case-insensitive
    }

    // Processes the player's guess
    void processGuess(char guess) {
        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }
        if (!correctGuess) {
            wrongGuesses.push_back(guess);
            attemptsLeft--;
        }
    }

    // Ends the game and displays the result
    void endGame() {
        if (guessedWord == secretWord) {
            cout << "Congratulations! You've guessed the word: " << secretWord << endl;
        } else {
            cout << "Game over! The correct word was: " << secretWord << endl;
        }
    }
};

// Main function
int main() {
    vector<string> wordList = {"computer", "programming", "hangman", "developer", "software"}; // Word list for the game

    Hangman game(wordList); // Create a Hangman game object
    game.startGame();       // Start the game

    return 0;
}
