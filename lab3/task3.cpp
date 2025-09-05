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

Node* reverse(Node* start, Node* end) {
    Node* previous = nullptr;
    while (start != end) {
        Node* next = start->next;
        start->next = previous;
        previous = start;
        start = next;
    }
    return previous;
}

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) return head;

    Node* current = head;
    for (int i = 0; i < k; i++) {
        if (current == nullptr) break; 
        current = current->next;
    }

    Node* newHead = reverse(head, current);
    head->next = reverseKGroup(current, k);
    return newHead;
}

int main() {
    LinkedList list;

    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    
    cout << "Original List: ";
    list.display();

    int k = 3; 
    list.head = reverseKGroup(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.display();

    return 0;
}
