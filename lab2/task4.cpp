#include <iostream>
using namespace std;

class FamilyExpenses {
private:
    int* expenses;   
    int size;        

public:

    FamilyExpenses(int n) {
        size = n;
        expenses = new int[size];
        for (int i = 0; i < size; i++) {
            expenses[i] = 0; 
        }
    }

    // Input expenses
    void inputExpenses() {
        for (int i = 0; i < size; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }
    }

    // Resize array
    void resize(int newSize) {
        if(size > newSize) {
            cout << "Array contain more data" << endl;
            return;
        }

        int* newArr = new int[newSize];

        for (int i = 0; i < size; i++) {
            newArr[i] = expenses[i];
        }

        for (int i = size; i < newSize; i++) {
            newArr[i] = 0;
        }

        delete[] expenses;   
        expenses = newArr;  
        size = newSize;      
    }

    void addMoreMonths(int extra) {
        int oldSize = size;
        resize(size + extra);

        // Input expenses for new months
        for (int i = oldSize; i < size; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }
    }

    // Calculate total expenses
    int getTotal() {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += expenses[i];
        }
        return total;
    }

    // Calculate average expenses
    double getAverage() {
        return (size == 0) ? 0 : (double)getTotal() / size;
    }

    // Display all expenses
    void displayExpenses() {
        cout << "\nExpenses:\n";
        for (int i = 0; i < size; i++) {
            cout << "Month " << i + 1 << ": " << expenses[i] << endl;
        }
        cout << "Total Expenses = " << getTotal() << endl;
        cout << "Average Expenses = " << getAverage() << endl;
    }

    ~FamilyExpenses() {
        delete[] expenses;
    }

};

int main() {
    int n;
    cout << "Enter number of months to track expenses: ";
    cin >> n;

    FamilyExpenses family(n);
    family.inputExpenses();

    char choice;
    cout << "Do you want to add more months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int extra;
        cout << "Enter how many extra months: ";
        cin >> extra;
        family.addMoreMonths(extra);
    }

    family.displayExpenses();

    return 0;
}
