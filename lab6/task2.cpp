#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
class Node {
public:
    string url;
    Node* next;
};

class Stack {
private:
    Node* top;  

public:
    Stack() { top = nullptr; }

    // Push operation
    void push(string page) {
        Node* newNode = new Node();
        newNode->url = page;
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << page << endl;
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "No previous pages! Browser history is empty.\n";
            return;
        }

        cout << "Going back from: " << top->url << endl;
        Node* temp = top;
        top = top->next;
        delete temp;

        if (top != nullptr)
            cout << "Current page: " << top->url << endl;
        else
            cout << "No pages left in history.\n";
    }

    // Peek operation
    void peek() {
        if (top == nullptr)
            cout << "No pages in history.\n";
        else
            cout << "Current page: " << top->url << endl;
    }

    // Display entire stack
    void display() {
        if (top == nullptr) {
            cout << "Browser history is empty.\n";
            return;
        }

        cout << "\n--- Browser History ---\n";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->url << endl;
            temp = temp->next;
        }
        cout << "------------------------\n";
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack history;
    int choice;
    string url;

    while (true) {
        cout << "\n--- Browser History Menu ---\n";
        cout << "1. Visit new page (Push)\n";
        cout << "2. Go back (Pop)\n";
        cout << "3. Show current page (Peek)\n";
        cout << "4. Show all history (Display)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                history.push(url);
                break;
            case 2:
                history.pop();
                break;
            case 3:
                history.peek();
                break;
            case 4:
                history.display();
                break;
            case 5:
                cout << "Exiting browser simulation.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
