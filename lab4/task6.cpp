#include <iostream>
using namespace std;

void combSort(int arr[], int n, int &comparisons, int &swaps) {
    float shrink = 1.3;
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = (int)(gap / shrink);
        (gap < 1) ? 1 : gap;
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            comparisons++; 
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++; 
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int comparisons = 0, swaps = 0;
    
    combSort(arr, n, comparisons, swaps);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    delete[] arr;
    return 0;
}
