#include <iostream> //tASK01
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            pages[top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No page to go back!" << endl;
        } else {
            cout << "Back button pressed. Removed page: "
                 << pages[top] << endl;
            top--;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No page available." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }

    void displayHistory() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
        } else {
            cout << "Browsing history (TOP to bottom):" << endl;
            for (int i = top; i >= 0; i--) {
                cout << pages[i] << endl;
            }
        }
    }
};

int main() {
    Stack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    cout << "All visited pages:" << endl;
    browser.displayHistory();

    cout << "\nPerforming POP operation:" << endl;
    browser.pop();

    cout << "\n";
    browser.displayTop();

    cout << "\nRemaining browsing history:" << endl;
    browser.displayHistory();

    return 0;
}
