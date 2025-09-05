#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class MultiLevelLinkedList {
public:
    Node* head;

    MultiLevelLinkedList() {
        head = nullptr;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(Node* node) {
        while (node) {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "nullptr" << endl;
    }

    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* current = head;

        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* nextNode = current->next;
                current->next = flatten(current->child);

                while(current->next != nullptr) current = current->next;

                if(nextNode != nullptr) {
                    current->next = nextNode;
                }
            }
            current = current->next;
        }
        return head;
    }
};

int main() {
    MultiLevelLinkedList list;

    // Main list: 1 -> 2 -> 3
    list.head = new Node(1);
    list.head->next = new Node(2);
    list.head->next->next = new Node(3);

    // Child of 2: 4 -> 5
    list.head->next->child = new Node(4);
    list.head->next->child->next = new Node(5);

    cout << "Original Structure:" << endl;
    cout << "1 -> 2 -> 3" << endl;
    cout << "     |" << endl;
    cout << "     4 -> 5" << endl;

    Node* flatHead = list.flatten(list.head);

    cout << "\nFlattened List: ";
    list.display(flatHead);

    return 0;
}
