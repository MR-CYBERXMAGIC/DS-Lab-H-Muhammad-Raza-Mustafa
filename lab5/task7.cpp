#include <iostream>
using namespace std;

#define MAX 20  

int board[MAX][MAX];  

void printSolution(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, int N) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive function to solve N-Queens
void solveNQueens(int row, int N) {
    if (row == N) {
        printSolution(N);  
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, N)) {
            board[row][col] = 1;  
            solveNQueens(row + 1, N);
            board[row][col] = 0;  
        }
    }
}

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;

    if (N < 1 || N > MAX) {
        cout << "Please enter N between 1 and " << MAX << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    cout << "All possible solutions for " << N << "-Queens:\n\n";
    solveNQueens(0, N);

    return 0;
}
