#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    
    SafePointer() {
        ptr = new int(0); 
    }

    void setValue(int value) {
        *ptr = value;
    }

    int getValue() const {
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~SafePointer() {
        delete ptr;
    }
};

int main() {
    const int size = 5; // Constant because told in question
    SafePointer students[size];  
    
   
    for (int i = 0; i < size; i++) {
        int marks;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks;
        students[i].setValue(marks);
    }

    cout << "\nMarks of Students:\n";
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }

    for (int i = 0; i < size; i++) {
        students[i].release(); 
    }

    return 0;
}
