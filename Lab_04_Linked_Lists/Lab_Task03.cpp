#include <iostream>
#include <string>
using namespace std;

struct Node {
    string productId;
    Node* next;
    Node(const string& id) : productId(id), next(NULL) {}
};

class ShoppingCart {
    Node* head;
public:
    ShoppingCart() : head(NULL) {}

    // 1 & 2. Add a product (ID) to the cart
    void addProduct(const string& id) {
        Node* newNode = new Node(id);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // 3 & 5. Display all products in the cart
    void display() const {
        if (head == NULL) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->productId;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 4. Remove a product by ID
    bool removeProduct(const string& id) {
        if (head == NULL) return false;

        // Case 1: product is at the head
        if (head->productId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Case 2: product is in the middle or at the end
        Node* curr = head;
        while (curr->next != NULL && curr->next->productId != id)
            curr = curr->next;

        if (curr->next == NULL) return false;  // not found

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return true;
    }

    ~ShoppingCart() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string id;

    do {
        cout << "\n--- Online Shopping Cart ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Cart\n";
        cout << "3. Remove Product\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cart.addProduct(id);
                break;
            case 2:
                cout << "Shopping Cart:\n";
                cart.display();
                break;
            case 3:
                cout << "Remove Product: ";
                cin >> id;
                if (cart.removeProduct(id)) {
                    cout << "Updated Cart:\n";
                    cart.display();
                } else {
                    cout << "Product not found in cart.\n";
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}