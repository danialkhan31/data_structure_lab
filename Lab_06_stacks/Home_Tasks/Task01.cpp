
#include <iostream>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = ch;
    }

    void pop() {
        if (top == -1) {
            return;
        }

        top--;
    }

    char TOP() {
        if (top == -1) {
            return '\0';
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatching(char open, char close) {
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}

int main() {
    Stack s;

    string expression = "{[()]}";

    bool balanced = true;

    for (int i = 0; i < expression.length(); i++) {

        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.isEmpty()) {
                balanced = false;
                break;
            }

            char open = s.TOP();

            if (isMatching(open, ch)) {
                s.pop();
            }
            else {
                balanced = false;
                break;
            }
        }
    }

    if (!s.isEmpty()) {
        balanced = false;
    }

    if (balanced) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
