#include <iostream>
using namespace std;

#define MAX 5  

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << "." << endl;
            return;
        }
        if (front == -1) front = 0;  
        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        front++;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void status() {
        cout << "\n--- Queue Status ---" << endl;
        cout << "Front Index: " << front << endl;
        cout << "Rear Index : " << rear << endl;
        cout << "Is Empty   : " << (isEmpty() ? "Yes" : "No") << endl;
        cout << "Is Full    : " << (isFull() ? "Yes" : "No") << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n--- Linear Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Check Empty/Full\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.status();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
