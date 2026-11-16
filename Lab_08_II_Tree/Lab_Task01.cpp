
#include <iostream>
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

void display(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << "Member: " << root->name << endl;

    if (root->left != NULL)
        cout << "Left Child: " << root->left->name << endl;
    else
        cout << "Left Child: NULL" << endl;

    if (root->right != NULL)
        cout << "Right Child: " << root->right->name << endl;
    else
        cout << "Right Child: NULL" << endl;

    cout << "------------------------" << endl;

    display(root->left);
    display(root->right);
}

int main() {

    Node* root = new Node("HOD");

    root->left = new Node("Coordinator AI");
    root->right = new Node("Coordinator DS");

    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");

    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    cout << "University Department Hierarchy" << endl;
    cout << "------------------------" << endl;

    display(root);

    return 0;
}
