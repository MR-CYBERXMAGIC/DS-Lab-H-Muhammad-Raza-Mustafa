#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; 
            return;
        }

        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)" << endl;
    }

    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
        head = nullptr;
    }
};

int josephusProblem(Node* head, int k) {
    Node* current = head;
    Node* prev = nullptr;

    while (current->next != current) { 
        for (int count = 1; count < k; count++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    int survivor = current->data;
    delete current;
    return survivor;
}

int main() {
    int N = 7, k = 3;

    CircularLinkedList cll;

    for (int i = 1; i <= N; i++) {
        cll.insertAtTail(i);
    }

    cout << "Initial circle: ";
    cll.display();

    int survivor = josephusProblem(cll.head, k);
    cout << "Survivor is at position: " << survivor << endl;

    return 0;
}
