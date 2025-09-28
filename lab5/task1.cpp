#include<iostream>
using namespace std;

int calculateFactorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * calculateFactorial(n - 1);
}

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout <<"The factorial is: "<< calculateFactorial(n);
}