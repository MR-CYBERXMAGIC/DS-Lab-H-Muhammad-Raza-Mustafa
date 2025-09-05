#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node() {
        data = 0;
        next = nullptr;
        previous = nullptr;  
    }

    Node(int val) {
        data = val;
        next = nullptr;
        previous = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

Node* singlyToCircular(Node* head) {
    if (head == nullptr) return head;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head; 
    return head;
}

Node* singlyToDoubly(Node* head) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        current->previous = previous;
        previous = current;
        current = current->next;
    }
    return head;
}

void displayCircular(Node* head, int count) {
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

// Display doubly linked list
void displayDoubly(Node* head) {
    Node* temp = head;
    Node* tail = nullptr;

    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        if (temp->next == nullptr) tail = temp;
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    cout << "Backward: ";
    while (tail != nullptr) {
        cout << tail->data << " <-> ";
        tail = tail->previous;
    }
    cout << "nullptr" << endl;
}

int main() {
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);

    cout << "Original Singly Linked List: ";
    list.display();

    Node* dHead = singlyToDoubly(list.head);
    cout << "\nDoubly Linked List:\n";
    displayDoubly(dHead);

    // Convert to Circular Linked List
    Node* cHead = singlyToCircular(list.head);
    cout << "\nCircular Linked List:";
    displayCircular(cHead, 10);

    return 0;
}
