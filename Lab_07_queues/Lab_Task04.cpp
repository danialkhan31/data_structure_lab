#include <iostream>
using namespace std;

#define MAX 5

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void insertFront(int value) {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1)) {
            cout << "Deque is full!\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = MAX - 1;
        }
        else {
            front--;
        }

        arr[front] = value;

        cout << value << " inserted at the front.\n";
    }

    void insertRear(int value) {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1)) {
            cout << "Deque is full!\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;

        cout << value << " inserted at the rear.\n";
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << arr[front] << " removed from the front.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == MAX - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << arr[rear] << " removed from the rear.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = MAX - 1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Passenger requests: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, value;

    do {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger request ID: ";
                cin >> value;
                d.insertFront(value);
                break;

            case 2:
                cout << "Enter passenger request ID: ";
                cin >> value;
                d.insertRear(value);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}