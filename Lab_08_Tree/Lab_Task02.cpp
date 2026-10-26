// task02
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            cout << "Roll number " << value << " already exists. Ignored." << endl;

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    void insertValue(int value) {
        root = insert(root, value);
    }

    void display() {
        cout << "Roll numbers (ascending): ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    int rolls[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++)
        tree.insertValue(rolls[i]);

    cout << "Initial tree:" << endl;
    tree.display();

    int r1, r2;
    cout << "\nEnter first additional roll number: ";
    cin >> r1;
    cout << "Enter second additional roll number: ";
    cin >> r2;

    tree.insertValue(r1);
    tree.insertValue(r2);

    cout << "\nAfter inserting new roll numbers:" << endl;
    tree.display();

    return 0;
}