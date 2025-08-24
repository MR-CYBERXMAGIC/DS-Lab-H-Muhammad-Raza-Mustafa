#include <iostream>
using namespace std;

class Box {
private:
    int* data;

public:
    // Constructor
    Box(int value = 0) {
        data = new int(value);
        cout << "Constructed Box with value " << *data << endl;
    }

    // Destructor
    ~Box() {
        cout << "Destroying Box with value " << *data << endl;
        delete data;
    }

    // Copy Constructor (deep copy)
    Box(const Box& other) {
        data = new int(*other.data);
        cout << "Copy Constructor called. Copied value: " << *data << endl;
    }

    // Copy Assignment Operator (deep copy)
    Box& operator=(const Box& other) {
        cout << "Copy Assignment Operator called." << endl;
        if (this == &other) {
            return *this; 
        }
        delete data; 
        data = new int(*other.data);
        return *this;
    }

    // Copy Constructor (shallow copy)
    Box shallowCopy() {
        Box temp;
        delete temp.data;      
        temp.data = data;      
        cout << "Shallow copy created with value " << *temp.data << endl;
        return temp;
    }

    void setValue(int value) {
        *data = value;
    }

    int getValue() const {
        return *data;
    }
};

int main() {
    cout << "  Deep Copy Demonstration" << endl;
    Box box1(10);
    Box box2 = box1;       
    box2.setValue(20);

    cout << "box1 value: " << box1.getValue() << endl; 
    cout << "box2 value: " << box2.getValue() << endl; 

    Box box3;
    box3 = box1;            

    cout << "box1 value: " << box1.getValue() << endl; 
    cout << "box3 value: " << box3.getValue() << endl; 

    cout << "\n Shallow Copy Demonstration (unsafe)" << endl;
    Box box4(40);
    Box box5 = box4.shallowCopy();

    box5.setValue(50);

    cout << "box4 value (after modifying box5): " << box4.getValue() << endl; 
    cout << "box5 value: " << box5.getValue() << endl;                         


    return 0;
}
