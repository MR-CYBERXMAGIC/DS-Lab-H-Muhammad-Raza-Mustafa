#include<iostream>
using namespace std;

void functionA(int n);
void functionB(int n);

void printNumbers(int n) {
    cout << n << " ";
    if(n == 1) return;
    printNumbers(n-1);
}

void functionA(int n) {
    cout << n << " ";
    if(n == 1) return;
    functionB(n-1);
}

void functionB(int n) {
    cout << n << " ";
    if(n == 1) return;
    functionA(n-1);
}

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;
    printNumbers(n);
    cout << endl;
    functionA(n);
    return 0;
}