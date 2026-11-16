
#include <iostream>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

// In-order Traversal
void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->folder << " ";

    inorder(root->right);
}

// Pre-order Traversal
void preorder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";

    preorder(root->left);

    preorder(root->right);
}

// Post-order Traversal
void postorder(Node* root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->folder << " ";
}

int main() {

    Node* root = new Node("Computer");

    root->left = new Node("Documents");
    root->right = new Node("Downloads");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Images");
    root->right->right = new Node("Videos");

    cout << "In-order Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);

    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}
