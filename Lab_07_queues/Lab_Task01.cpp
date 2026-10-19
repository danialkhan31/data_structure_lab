#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == MAX - 1) {
            cout << "Queue is full! Cannot add customer.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = token;

        cout << "Customer " << token << " added to queue.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty! No customer to serve.\n";
            return;
        }

        cout << "Customer " << arr[front] << " is served.\n";
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void countCustomers() {
        if (front == -1) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service System ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                q.enqueue(token);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.countCustomers();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}