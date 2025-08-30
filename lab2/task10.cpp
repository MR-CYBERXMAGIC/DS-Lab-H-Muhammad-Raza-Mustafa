#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    int **books;       
    int *bookCounts;   
    string *categories; 
    int rows;          

public:
 
    Library(int r) {
        rows = r;
        books = new int*[rows];
        bookCounts = new int[rows];
        categories = new string[rows];
    }

    void inputData() {
        for (int i = 0; i < rows; i++) {
            cout << "\nEnter category name for row " << i + 1 << ": ";
            cin >> categories[i];

            cout << "Enter number of books in category " << categories[i] << ": ";
            cin >> bookCounts[i];

            books[i] = new int[bookCounts[i]];

            cout << "Enter Book IDs:\n";
            for (int j = 0; j < bookCounts[i]; j++) {
                cin >> books[i][j];
            }
        }
    }

    // Search for book
    void searchBook(int id) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < bookCounts[i]; j++) {
                if (books[i][j] == id) {
                    cout << "\nBook ID " << id << " is available in category: " 
                         << categories[i] << endl;
                    return;
                }
            }
        }
        cout << "\nBook ID " << id << " is NOT available in the library.\n";
    }

    void display() {
        cout << "\n--- Library Records ---\n";
        for (int i = 0; i < rows; i++) {
            cout << categories[i] << ": ";
            for (int j = 0; j < bookCounts[i]; j++) {
                cout << books[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < rows; i++) {
            delete[] books[i];
        }
        delete[] books;
        delete[] bookCounts;
        delete[] categories;
    }
};

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    Library lib(categories);
    lib.inputData();

    lib.display();

    int id;
    cout << "\nEnter Book ID to search: ";
    cin >> id;

    lib.searchBook(id);

    return 0;
}
