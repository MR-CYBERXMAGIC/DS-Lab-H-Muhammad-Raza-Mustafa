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

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root; 

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void rangeSearch(Node* root, int X, int Y) {
    if (!root) return;

    if (root->key > X)
        rangeSearch(root->left, X, Y);

    if (root->key >= X && root->key <= Y)
        cout << root->key << " ";

    if (root->key < Y)
        rangeSearch(root->right, X, Y);
}

int main() {
    Node* root = NULL;

    cout << "Inserting product prices...\n";

    int prices[] = {1200, 3500, 999, 2200, 1500, 5000, 3000};
    int n = sizeof(prices) / sizeof(prices[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, prices[i]);

    int X, Y;
    cout << "\nEnter price range (X Y): ";
    cin >> X >> Y;

    cout << "Products priced between " << X << " and " << Y << ": ";
    rangeSearch(root, X, Y);
    cout << endl;

    return 0;
}
