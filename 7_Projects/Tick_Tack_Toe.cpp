/*
 * Tic-Tac-Toe Game Implementation
 * 
 * This C++ program implements a simple Tic-Tac-Toe game using object-oriented principles.
 * The game includes two types of players: Human and AI. The game board is a 3x3 grid,
 * and players take turns making moves until one player wins or the game ends in a draw.
 * 
 * Key Components:
 * 
 * 1. Abstract Base Class `Player`: 
 *    - Encapsulates the common functionality of both human and AI players.
 *    - Contains a pure virtual function `makeMove` that must be implemented by derived classes.
 * 
 * 2. Derived Class `HumanPlayer`:
 *    - Inherits from `Player` and implements the `makeMove` function to allow user input for moves.
 * 
 * 3. Derived Class `AIPlayer`:
 *    - Inherits from `Player` and implements the `makeMove` function with a basic AI strategy to place a move in the first available spot.
 * 
 * 4. `TicTacToe` Class:
 *    - Manages the game state, including the board, current player, and game flow.
 *    - Provides methods for displaying the board, checking win conditions, checking for a draw, and toggling between players.
 *    - Includes a play method that controls the game loop until a win or draw condition is met.
 * 
 * 5. Main Function:
 *    - Creates instances of `HumanPlayer` and `AIPlayer`.
 *    - Initializes a `TicTacToe` game with these players and starts the game.
 * 
 * The code demonstrates concepts of abstraction, encapsulation, inheritance, and polymorphism.
 * 
 * Author: [Your Name]
 * Date: [Date]
 */

#include <iostream>
using namespace std;

// Abstract Base Class (Abstraction)
class Player 
{
protected:
    char symbol; // Encapsulated data member for player symbol

public:
    // Constructor to initialize the symbol
    Player(char sym) : symbol(sym) {}

    // Pure virtual function for making a move (Polymorphism)
    virtual void makeMove(char board[3][3]) = 0;

    // Function to get the player symbol
    char getSymbol() const {
        return symbol;
    }
};

// Derived Class for Human Player (Inheritance)
class HumanPlayer : public Player 
{
public:
    // Constructor
    HumanPlayer(char sym) : Player(sym) {}

    // Overridden function to make a move (Polymorphism)
    void makeMove(char board[3][3]) override {
        int row, col;
        cout << "Enter your move (row and column): ";
        cin >> row >> col;
        while (board[row][col] != ' ') {
            cout << "Cell already occupied! Enter again: ";
            cin >> row >> col;
        }
        board[row][col] = symbol;
    }
};

// Derived Class for AI Player (Inheritance)
class AIPlayer : public Player 
{
public:
    // Constructor
    AIPlayer(char sym) : Player(sym) {}

    // Overridden function to make a move (Polymorphism)
    void makeMove(char board[3][3]) override 
    {
        // Simple AI: place in the first available spot
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                if (board[i][j] == ' ') {
                    board[i][j] = symbol;
                    return;
                }
            }
        }
    }
};

// Tic-Tac-Toe Game Class (Encapsulation and Abstraction)
class TicTacToe 
{
private:
    char board[3][3]; // Encapsulated data member for the game board
    Player* player1;  // Player 1 (can be Human or AI)
    Player* player2;  // Player 2 (can be Human or AI)
    Player* currentPlayer; // Pointer to the current player

public:
    // Constructor
    TicTacToe(Player* p1, Player* p2) : player1(p1), player2(p2) 
    {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) 
            {
                board[i][j] = ' ';
            }
        }
        currentPlayer = player1; // Player 1 starts the game
    }

    // Function to display the board
    void displayBoard() 
    {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------\n";
        }
    }

    // Function to check for a win
    bool checkWin(char symbol) 
    {
        for (int i = 0; i < 3; ++i) 
        {
            if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
                (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) 
                {
                    return true;
                }
        }
        if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
            (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) 
            {
                return true;
            }
        return false;
    }

    // Function to check for a draw
    bool checkDraw() 
    {
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    // Function to toggle between players
    void togglePlayer() 
    {
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    // Function to play the game
    void play() 
    {
        while (true) 
        {
            displayBoard();
            currentPlayer->makeMove(board);

            if (checkWin(currentPlayer->getSymbol())) 
            {
                displayBoard();
                cout << "Player " << currentPlayer->getSymbol() << " wins!" << endl;
                break;
            }

            if (checkDraw()) 
            {
                displayBoard();
                cout << "The game is a draw!" << endl;
                break;
            }

            togglePlayer();
        }
    }

    // Operator overloading to assign a player to another game (Operator Overloading)
    void operator=(const TicTacToe& other) 
    {
        player1 = other.player1;
        player2 = other.player2;
    }
};

int main() 
{
    // Create two players (a human and an AI)
    HumanPlayer human('X');
    AIPlayer ai('O');

    // Create a Tic-Tac-Toe game with these two players
    TicTacToe game(&human, &ai);

    // Play the game
    game.play();

    return 0;
}
