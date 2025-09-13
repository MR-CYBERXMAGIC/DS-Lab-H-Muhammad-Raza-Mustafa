#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1; 
        else
            high = pos - 1; 
    }
    return -1; 
}

int main() {
    int n, target;

    cout << "Enter the size of the sorted array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " sorted elements (uniformly distributed):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value to search: ";
    cin >> target;

    int result = interpolationSearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    delete[] arr;
    return 0;
}
