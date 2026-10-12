// Task03
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
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
            cout << "No patient request available!" << endl;
        } else {
            Node* temp = top;
            cout << "Handled patient request: "
                 << top->patientID << endl;
            top = top->next;
            delete temp;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No request available." << endl;
        } else {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
    }

    void displayRequests() {
        if (top == NULL) {
            cout << "No patient requests remaining." << endl;
        } else {
            Node* temp = top;

            cout << "Requests from TOP to bottom:" << endl;

            while (temp != NULL) {
                cout << temp->patientID << endl;
                temp = temp->next;
            }
        }
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
    Stack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "All patient requests:" << endl;
    hospital.displayRequests();

    cout << "\nPerforming POP operation:" << endl;
    hospital.pop();

    cout << "\n";
    hospital.displayTop();

    cout << "\nRemaining patient requests:" << endl;
    hospital.displayRequests();

    return 0;
}
