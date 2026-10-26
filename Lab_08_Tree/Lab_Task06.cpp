// task 06
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

    Node* insert(Node* node, int value, bool &inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(value);
        }

        if (value < node->data)
            node->left = insert(node->left, value, inserted);
        else if (value > node->data)
            node->right = insert(node->right, value, inserted);
        // equal: duplicate, inserted stays false

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
            // Leaf or one child
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

            // Two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
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

    void insertProduct(int id) {
        bool inserted = false;
        root = insert(root, id, inserted);

        if (inserted)
            cout << "Product " << id << " inserted successfully." << endl;
        else
            cout << "Product " << id << " already exists. Duplicate not allowed." << endl;
    }

    bool searchProduct(int id) {
        Node* current = root;
        while (current != NULL) {
            if (id == current->data)
                return true;
            current = (id < current->data) ? current->left : current->right;
        }
        return false;
    }

    void searchAndShow(int id) {
        if (searchProduct(id))
            cout << "Product " << id << " found." << endl;
        else
            cout << "Product " << id << " not found." << endl;
    }

    void deleteProduct(int id) {
        if (!searchProduct(id)) {
            cout << "Product " << id << " not found. Nothing deleted." << endl;
            return;
        }
        root = deleteNode(root, id);
        cout << "Product " << id << " deleted successfully." << endl;
    }

    void displayInorder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "In-order:   ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Pre-order:  ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST store;
    int choice, id;

    do {
        cout << "\n===== Online Store Inventory =====" << endl;
        cout << "1. Insert a product ID" << endl;
        cout << "2. Search for a product ID" << endl;
        cout << "3. Delete a product ID" << endl;
        cout << "4. Display in-order traversal" << endl;
        cout << "5. Display pre-order traversal" << endl;
        cout << "6. Display post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product ID to insert: ";
                cin >> id;
                store.insertProduct(id);
                break;
            case 2:
                cout << "Enter product ID to search: ";
                cin >> id;
                store.searchAndShow(id);
                break;
            case 3:
                cout << "Enter product ID to delete: ";
                cin >> id;
                store.deleteProduct(id);
                break;
            case 4:
                store.displayInorder();
                break;
            case 5:
                store.displayPreorder();
                break;
            case 6:
                store.displayPostorder();
                break;
            case 7:
                cout << "Exiting program. Memory released by destructor." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1-7." << endl;
        }
    } while (choice != 7);

    return 0;
}