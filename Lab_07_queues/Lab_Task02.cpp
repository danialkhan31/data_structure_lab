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

    void enqueue(int packet) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full! Cannot add packet.\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = packet;

        cout << "Packet " << packet << " added to queue.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty! No packet to transmit.\n";
            return;
        }

        cout << "Packet " << arr[front] << " transmitted.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty! No packets waiting.\n";
            return;
        }

        cout << "Packets waiting for transmission: ";

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
    Queue q;
    int choice, packet;

    do {
        cout << "\n--- Network Packet Management System ---\n";
        cout << "1. Insert Packet (Enqueue)\n";
        cout << "2. Transmit Packet (Dequeue)\n";
        cout << "3. Display Waiting Packets\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packet;
                q.enqueue(packet);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}