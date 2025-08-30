#include <iostream>
using namespace std;

class SparseMatrix {
private:
    int **matrix;   
    int rows, cols;

public:

    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    
    void inputMatrix() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void displayNormal() {
        cout << "\nMatrix in Normal Form:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayCompressed() {
        cout << "\nMatrix in Compressed Form (row, col, value):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    cout << "(" << i << ", " << j << ", " << matrix[i][j] << ")\n";
                }
            }
        }
    }

    ~SparseMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
};

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    SparseMatrix sm(r, c);

    sm.inputMatrix();
    sm.displayNormal();
    sm.displayCompressed();

    return 0;
}
