// task 05
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

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
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

    void showTraversals() {
        cout << "In-order   (Left, Root, Right): ";
        inorder(root);

        cout << "\nPre-order  (Root, Left, Right): ";
        preorder(root);

        cout << "\nPost-order (Left, Right, Root): ";
        postorder(root);

        cout << endl;
    }
};

int main() {
    BST hospital;

    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        hospital.insertValue(ids[i]);

    cout << "Patient IDs:" << endl;
    hospital.showTraversals();

    cout << "\nIn-order traversal displays the IDs in ascending order." << endl;

    return 0;
}