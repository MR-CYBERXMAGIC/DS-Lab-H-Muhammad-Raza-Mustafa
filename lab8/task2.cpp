#include <iostream>
using namespace std;

class Song {
public:
    int plays;
    string name;
    Song *left, *right;

    Song(int p, string n) {
        plays = p;
        name = n;
        left = right = NULL;
    }
};

class MusicBST {
public:
    Song* insert(Song* root, int p, string name) {
        if(!root) return new Song(p, name);
        if(p < root->plays) root->left = insert(root->left, p, name);
        else root->right = insert(root->right, p, name);
        return root;
    }

    void inorder(Song* root) {
        if(!root) return;
        inorder(root->left);
        cout << root->name << " (" << root->plays << " plays)\n";
        inorder(root->right);
    }

    void postorder(Song* root) {
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->name << " (" << root->plays << " plays)\n";
    }

    Song* search(Song* root, int p) {
        if(!root || root->plays == p) return root;
        return (p < root->plays) ? search(root->left, p) : search(root->right, p);
    }

    Song* minValue(Song* root) {
        while(root->left) root = root->left;
        return root;
    }

    Song* deleteNode(Song* root, int p) {
        if(!root) return root;
        if(p < root->plays) root->left = deleteNode(root->left, p);
        else if(p > root->plays) root->right = deleteNode(root->right, p);
        else {
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            Song* temp = minValue(root->right);
            root->plays = temp->plays;
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->plays);
        }
        return root;
    }
};

int main() {
    MusicBST mb;
    Song* root = NULL;

    root = mb.insert(root, 50, "Song A");
    root = mb.insert(root, 80, "Song B");
    root = mb.insert(root, 30, "Song C");
    root = mb.insert(root, 70, "Song D");
    root = mb.insert(root, 90, "Song E");

    cout << "\nInorder (Least → Most Played):\n";
    mb.inorder(root);

    cout << "\nPostorder (Remove Reverse Popularity):\n";
    mb.postorder(root);

    cout << "\nSearching for play count 70:\n";
    Song* s = mb.search(root, 70);
    if(s) cout << "Found: " << s->name << endl;
    else cout << "Not Found\n";

    cout << "\nDeleting song with 80 plays...\n";
    root = mb.deleteNode(root, 80);

    cout << "Updated Inorder:\n";
    mb.inorder(root);
}
