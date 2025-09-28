#include <iostream>
using namespace std;

#define N 5  

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if (x, y) is valid to move
bool isSafe(int maze[N][N], int visited[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function to solve the maze
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], int visited[N][N]) {
    
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, visited, x, y)) {
        sol[x][y] = 1;
        visited[x][y] = 1;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol, visited))
            return true;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol, visited))
            return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y, sol, visited))
            return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1, sol, visited))
            return true;

        // Backtrack
        sol[x][y] = 0;
        visited[x][y] = 0;
    }

    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    int visited[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol, visited)) {
        cout << "No solution exists!" << endl;
        return false;
    }

    printSolution(sol);
    return true;
}

int main() {

    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1}
    };

    solveMaze(maze);

    return 0;
}
