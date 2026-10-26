// task03
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

    // Returns true if found; comparisons is updated by reference
    bool search(int value, int &comparisons) {
        Node* current = root;
        comparisons = 0;

        while (current != NULL) {
            comparisons++;   // one comparison with the current node

            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }
};

int main() {
    BST library;

    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        library.insertValue(ids[i]);

    int bookID, comparisons;
    cout << "Enter book ID to search: ";
    cin >> bookID;

    if (library.search(bookID, comparisons))
        cout << "Book Found" << endl;
    else
        cout << "Book Not Found" << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}