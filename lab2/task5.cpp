#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    // Copy Constructor (Deep Copy)
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Assignment Operator (Deep Copy)
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocateMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // Input Matrix
    void input() {
        cout << "Enter elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Display Matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Addition
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Subtraction
    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Destructor
    ~Matrix() {
        deallocateMemory();
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    Matrix A(r, c), B(r, c);

    cout << "Enter Matrix A:\n";
    A.input();

    cout << "Enter Matrix B:\n";
    B.input();

    try {
        cout << "\nMatrix A + Matrix B:\n";
        Matrix sum = A + B;
        sum.display();

        cout << "\nMatrix A - Matrix B:\n";
        Matrix diff = A - B;
        diff.display();
    }
    catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
