#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 1; j < n - i; j++) {
            comparisons++;
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } else break;
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];  

    //Filling array randomly instead of input so that performance can be compared on large data inputs 
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }

    // Bubble Sort
    int* arrB = new int[n];
    for (int i = 0; i < n; i++) arrB[i] = arr[i];
    int compB, swapB;
    auto startB = high_resolution_clock::now();
    bubbleSort(arrB, n, compB, swapB);
    auto stopB = high_resolution_clock::now();
    auto timeB = duration_cast<milliseconds>(stopB - startB).count();

    // Insertion Sort
    int* arrI = new int[n];
    for (int i = 0; i < n; i++) arrI[i] = arr[i];
    int compI, swapI;
    auto startI = high_resolution_clock::now();
    insertionSort(arrI, n, compI, swapI);
    auto stopI = high_resolution_clock::now();
    auto timeI = duration_cast<milliseconds>(stopI - startI).count();

    // Shell Sort
    int* arrS = new int[n];
    for (int i = 0; i < n; i++) arrS[i] = arr[i];
    int compS, swapS;
    auto startS = high_resolution_clock::now();
    shellSort(arrS, n, compS, swapS);
    auto stopS = high_resolution_clock::now();
    auto timeS = duration_cast<milliseconds>(stopS - startS).count();

    cout << "\n--- Performance Comparison ---\n";
    cout << "Bubble Sort   -> Time: " << timeB << " ms, Comparisons: " << compB << ", Swaps: " << swapB << endl;
    cout << "Insertion Sort-> Time: " << timeI << " ms, Comparisons: " << compI << ", Swaps: " << swapI << endl;
    cout << "Shell Sort    -> Time: " << timeS << " ms, Comparisons: " << compS << ", Swaps: " << swapS << endl;

    delete[] arr;
    delete[] arrB;
    delete[] arrI;
    delete[] arrS;

    return 0;
}
