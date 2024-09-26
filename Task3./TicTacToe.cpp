#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';


void displayBoard() {
    cout << "Tic-Tac-Toe Game" << endl;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << board[row][col];
            if (col < SIZE - 1) cout << " | ";
        }
        if (row < SIZE - 1) cout << "\n---------\n";
    }
    cout << endl;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool checkWin() {
    
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}


bool checkDraw() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                return false;
            }
        }
    }
    return true;
}


bool updateBoard(int choice) {
    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}


void resetBoard() {
    int num = 1;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = '0' + num++;
        }
    }
}

int main() {
    char playAgain;
    do {
        bool gameOver = false;
        resetBoard();
        currentPlayer = 'X';

        while (!gameOver) {
            displayBoard();
            int choice;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9 || !updateBoard(choice)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
