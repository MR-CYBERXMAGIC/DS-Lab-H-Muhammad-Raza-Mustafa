#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printRotation(string type, int key) {
    if (type != "None")
        cout << "Rotation performed: " << type << " at node " << key << endl;
    else
        cout << "Rotation performed: None" << endl;
}

Node* rightRotate(Node* y) {
    cout << "Rotation: Right (LL) at node " << y->key << endl;
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    cout << "Rotation: Left (RR) at node " << x->key << endl;
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) {
        cout << "Inserted: " << key << endl;
        return new Node(key);
    }

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root; 

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);
    cout << "Balance(" << root->key << ") = " << balance << endl;

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        cout << "Rotation: Left-Right (LR) at node " << root->key << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        cout << "Rotation: Right-Left (RL) at node " << root->key << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    cout << "Rotation performed: None" << endl;
    return root;
}

Node* minValueNode(Node* n) {
    Node* cur = n;
    while (cur->left)
        cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        cout << "Deleted: " << key << endl;

        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);
    cout << "Balance(" << root->key << ") = " << balance << endl;

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "Rotation: Left-Right (LR) at node " << root->key << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "Rotation: Right-Left (RL) at node " << root->key << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    cout << "\n--- INSERT OPERATIONS ---\n";
    int inserts[] = {40, 20, 10, 25, 50, 60};
    for (int x : inserts) {
        root = insertNode(root, x);
        cout << "Tree Height = " << getHeight(root) << "\n\n";
    }

    cout << "\n--- DELETE OPERATIONS ---\n";
    int deletes[] = {20, 50, 25};
    for (int x : deletes) {
        root = deleteNode(root, x);
        cout << "Tree Height = " << getHeight(root) << "\n\n";
    }

    return 0;
}
