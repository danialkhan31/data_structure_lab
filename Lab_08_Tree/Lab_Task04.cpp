// tsask 04
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

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL)
            return NULL;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Case 1 (leaf) and Case 2 (one child)
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: two children -> inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    bool exists(Node* node, int value) {
        while (node != NULL) {
            if (value == node->data)
                return true;
            node = (value < node->data) ? node->left : node->right;
        }
        return false;
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

    bool deleteValue(int value) {
        if (!exists(root, value))
            return false;
        root = deleteNode(root, value);
        return true;
    }

    void display() {
        cout << "Employee IDs (ascending): ";
        inorder(root);
        cout << endl;
        cout << "Structure (pre-order):    ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    BST company;

    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        company.insertValue(ids[i]);

    cout << "Initial tree:" << endl;
    company.display();

    int id;
    while (true) {
        cout << "\nEnter employee ID to delete (0 to exit): ";
        cin >> id;

        if (id == 0)
            break;

        if (company.deleteValue(id))
            cout << "Employee " << id << " deleted." << endl;
        else
            cout << "Employee " << id << " not found. Tree "<< endl;
            
        
        company.display();
    }

    return 0;
}
