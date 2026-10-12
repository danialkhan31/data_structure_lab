//Task02
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            actions[top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No action to undo!" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No action available." << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }

    void displayActions() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
        } else {
            cout << "Actions from TOP to bottom:" << endl;

            for (int i = top; i >= 0; i--) {
                cout << actions[i] << endl;
            }
        }
    }
};

int main() {
    Stack editor;

    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    cout << "All actions:" << endl;
    editor.displayActions();

    cout << "\nPerforming two Undo operations:" << endl;
    editor.pop();
    editor.pop();

    cout << "\n";
    editor.displayTop();

    cout << "\nRemaining actions:" << endl;
    editor.displayActions();

    return 0;
}
