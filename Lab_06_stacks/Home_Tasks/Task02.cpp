
#include <iostream>
#include <sstream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int value = arr[top];
        top--;

        return value;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    string expression = "5 6 2 + * 12 4 / -";

    stringstream ss(expression);

    string token;

    while (ss >> token) {

        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {

            int b = s.pop();
            int a = s.pop();

            int result;

            if (token == "+") {
                result = a + b;
            }

            else if (token == "-") {
                result = a - b;
            }

            else if (token == "*") {
                result = a * b;
            }

            else {
                result = a / b;
            }

            s.push(result);
        }

        else {
            s.push(stoi(token));
        }
    }

    cout << "Final Result: " << s.pop() << endl;

    return 0;
}
