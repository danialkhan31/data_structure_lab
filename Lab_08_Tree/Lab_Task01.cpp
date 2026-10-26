//Task01
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

class FamilyTree {
private:
    Node* root;

    void display(Node* node) {
        if (node == NULL)
            return;

        cout << node->name << " -> Left: "
             << (node->left ? node->left->name : "None")
             << ", Right: "
             << (node->right ? node->right->name : "None") << endl;

        display(node->left);
        display(node->right);
    }

    void destroy(Node* node) {
        if (node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    FamilyTree() {
        root = NULL;
    }

    ~FamilyTree() {
        destroy(root);
    }

    void createTree() {
        root = new Node("Ahmed");                        // Grandfather

        root->left = new Node("Bilal");                  // Elder son
        root->right = new Node("Saeed");                 // Younger son

        root->left->left = new Node("Hassan");           // Bilal's son
        root->left->right = new Node("Ayesha");          // Bilal's daughter

        root->right->left = new Node("Fatima");          // Saeed's daughter
        root->right->right = new Node("Omar");           // Saeed's son
    }

    void display() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "Root: " << root->name << endl << endl;
        display(root);
    }
};

int main() {
    FamilyTree family;
    family.createTree();
    family.display();
    return 0;
}