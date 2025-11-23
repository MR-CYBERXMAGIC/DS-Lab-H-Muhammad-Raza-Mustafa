#include <iostream>
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

void printRotation(const string& type, int key) {
    cout << "Rotation performed: " << type;
    if (type != "None") cout << " at node " << key;
    cout << endl;
}

Node* rightRotate(Node* y) {
    printRotation("Right (LL)", y->key);

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    printRotation("Left (RR)", x->key);

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
        cout << "Inserted severity score: " << key << endl;
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

    if (balance < -1 || balance > 1)
        cout << "Tree becomes unbalanced!\n";

    
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);


    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

  
    if (balance > 1 && key > root->left->key) {
        printRotation("Left-Right (LR)", root->key);
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }


    if (balance < -1 && key < root->right->key) {
        printRotation("Right-Left (RL)", root->key);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    printRotation("None", root->key);
    return root;
}

Node* getMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        cout << "Discharged patient with severity: " << key << endl;

        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = getMax(root->left);
            root->key = temp->key;
            root->left = deleteNode(root->left, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        printRotation("Left-Right (LR)", root->key);
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        printRotation("Right-Left (RL)", root->key);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    cout << "=== INSERT PATIENT SEVERITY SCORES ===\n";
    int insertValues[] = {50, 30, 70, 20, 60, 80, 75};
    int n = sizeof(insertValues) / sizeof(insertValues[0]);

    for (int x : insertValues) {
        root = insertNode(root, x);
        cout << "Tree Height = " << getHeight(root) << endl;

        cout << "Highest severity patient = "
             << getMax(root)->key << "\n\n";
    }

    cout << "=== DELETE (DISCHARGE PATIENTS) ===\n";
    int deleteValues[] = {70, 50};
    for (int x : deleteValues) {
        root = deleteNode(root, x);
        cout << "Tree Height = " << getHeight(root) << endl;

        cout << "Highest severity patient = "
             << getMax(root)->key << "\n\n";
    }

    return 0;
}
