#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Process {
    int id;
    int priority;
};

class Queue {
private:
    Process arr[MAX];
    int front, rear;

public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add more processes.\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = p;
    }

    Process dequeue() {
        Process temp = {-1, -1};
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return temp;
        }
        temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\n[Arrival Queue]\n";
        for (int i = front; i <= rear; i++) {
            cout << "Process ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
        }
    }

    Process dequeueHighestPriority() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return {-1, -1};
        }

        int highestIndex = front;
        for (int i = front + 1; i <= rear; i++) {
            if (arr[i].priority > arr[highestIndex].priority)
                highestIndex = i;
        }

        Process highest = arr[highestIndex];

        for (int i = highestIndex; i < rear; i++)
            arr[i] = arr[i + 1];
        rear--;

        if (rear < front) front = rear = -1;

        return highest;
    }
};

class Stack {
private:
    Process arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(Process p) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = p;
    }

    Process pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return {-1, -1};
        }
        return arr[top--];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\n[Execution Stack]\n";
        for (int i = top; i >= 0; i--) {
            cout << "Process ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    Queue arrivalQueue;
    Stack executionStack;

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter Process ID: ";
        cin >> p.id;
        cout << "Enter Priority: ";
        cin >> p.priority;
        arrivalQueue.enqueue(p);
    }

    cout << "\n=== Arrival Phase ===";
    arrivalQueue.display();

    cout << "\n=== Scheduling Phase ===\n";
    while (!arrivalQueue.isEmpty()) {
        Process high = arrivalQueue.dequeueHighestPriority();
        cout << "Selected high-priority process: [ID=" << high.id << ", Priority=" << high.priority << "]\n";
        executionStack.push(high);
    }

    cout << "\n=== Execution Phase (LIFO Order) ===";
    executionStack.display();

    cout << "\nExecuting processes in LIFO order:\n";
    while (!executionStack.isEmpty()) {
        Process exec = executionStack.pop();
        cout << "Executing Process ID: " << exec.id << ", Priority: " << exec.priority << endl;
    }

    cout << "\nAll processes executed.\n";

    return 0;
}
