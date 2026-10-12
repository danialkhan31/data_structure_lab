#include <iostream> //Task04
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            cout << "Processed order: " << top->orderID << endl;
            top = top->next;
            delete temp;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No order available." << endl;
        } else {
            cout << "Current TOP order: " << top->orderID << endl;
        }
    }

    void displayOrders() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
        } else {
            Node* temp = top;

            cout << "Orders from TOP to bottom:" << endl;

            while (temp != NULL) {
                cout << temp->orderID << endl;
                temp = temp->next;
            }
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    cout << "All restaurant orders:" << endl;
    restaurant.displayOrders();

    cout << "\nProcessing two orders:" << endl;
    restaurant.pop();
    restaurant.pop();

    cout << "\n";
    restaurant.displayTop();

    cout << "\nRemaining orders:" << endl;
    restaurant.displayOrders();

    cout << "\nChecking Stack status:" << endl;

    if (restaurant.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
