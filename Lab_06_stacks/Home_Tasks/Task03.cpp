
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
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

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = top;

        int value = temp->data;

        top = top->next;

        delete temp;

        return value;
    }

    int TOP() {
        if (isEmpty()) {
            return -1;
        }

        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {

    int arr[] = {30, 35, 28, 40, 32};

    int n = 5;

    int result[5];

    Stack s;

    for (int i = 0; i < n; i++) {

        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {

        while (!s.isEmpty() && arr[i] > arr[s.TOP()]) {

            int index = s.pop();

            result[index] = arr[i];
        }

        s.push(i);
    }

    cout << "Temperature: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Next Greater Element: ";

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
