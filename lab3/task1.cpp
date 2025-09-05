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

    Node* reverse(Node* _head) {
        Node* prev = nullptr;
        Node* current = _head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;   
            current->next = prev;   
            prev = current;         
            current = next;
        }

        return prev; 
    }

    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true;  
        }

        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
       
        Node* secondHalf = reverse(slow);

        Node* firstHalf = head;
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;  
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;  
    }
    
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
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

int main() {
    LinkedList list;
    
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    cout << "Original List: ";
    list.display();  
    
    if (list.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}
