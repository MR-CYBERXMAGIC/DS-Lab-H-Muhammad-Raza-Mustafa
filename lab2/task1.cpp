#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    int index, value;
    char choice;
    do {
        cout << "Enter index (0 to " << size - 1 << "): ";
        cin >> index;

        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
        } else {
            cout << "Enter value: ";
            cin >> value;
            arr[index] = value;
        }

        cout << "Do you want to update another element? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Final Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
