#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node *mother, *father;

    Node(string n) {
        name = n;
        mother = father = NULL;
    }
};

class FamilyTree {
public:
    Node* root;

    FamilyTree(string rootName) {
        root = new Node(rootName);
    }

    // Insert Mother or Father
    void addParents(Node* child, string mother, string father) {
        if(child == NULL) return;
        child->mother = new Node(mother);
        child->father = new Node(father);
    }

    // Display leaf nodes (ancestors)
    void showLeafNodes(Node* node) {
        if(!node) return;
        if(!node->mother && !node->father) {
            cout << node->name << " ";
            return;
        }
        showLeafNodes(node->mother);
        showLeafNodes(node->father);
    }

    // Height of tree
    int height(Node* node) {
        if(!node) return 0;
        return 1 + max(height(node->mother), height(node->father));
    }

    // Level order display
    void showLevels() {
        queue<pair<Node*, int>> q;
        q.push({root, 1});

        while(!q.empty()) {
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();

            cout << curr->name << " is at Level " << level << endl;

            if(curr->mother) q.push({curr->mother, level + 1});
            if(curr->father) q.push({curr->father, level + 1});
        }
    }
};

int main() {
    FamilyTree ft("Child (Ali)");

    ft.addParents(ft.root, "Mother (Sara)", "Father (Ahmed)");
    ft.addParents(ft.root->mother, "Grandmother (Fatima)", "Grandfather (Hassan)");
    ft.addParents(ft.root->father, "Grandmother (Ayesha)", "Grandfather (Omar)");

    cout << "Root (Youngest Person): " << ft.root->name << endl;

    cout << "Leaf (Ancestors): ";
    ft.showLeafNodes(ft.root);
    cout << endl;

    cout << "Height of Tree: " << ft.height(ft.root) << endl;

    cout << "\nLevels:\n";
    ft.showLevels();
}
