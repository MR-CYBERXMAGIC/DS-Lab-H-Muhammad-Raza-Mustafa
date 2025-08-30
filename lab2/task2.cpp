#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Step 1: Ask for classroom dimensions
    cout << "Enter number of benches (rows): ";
    cin >> rows;
    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;

    // Step 2: Dynamically allocate 2D array
    int** seats = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seats[i] = new int[cols];
    }

    // Step 3: Initialize with 0 (empty seats)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 0;
        }
    }

    // Step 4: Let user fill seats
    int r, c;
    char choice;
    do {
        cout << "Enter bench number (0 to " << rows - 1 << "): ";
        cin >> r;
        cout << "Enter seat number (0 to " << cols - 1 << "): ";
        cin >> c;

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Invalid seat position!\n";
        } else {
            seats[r][c] = 1; // mark as occupied
        }

        cout << "Do you want to occupy another seat? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Step 5: Print seating chart
    cout << "\nFinal Seating Chart (0 = empty, 1 = occupied):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    // Step 6: Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}
