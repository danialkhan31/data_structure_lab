#include <iostream>
#include <string>
using namespace std;

struct Node {
    string patientId;
    Node* next;
    Node(const string& id) : patientId(id), next(nullptr) {}
};

class PatientQueue {
    Node* head;
    Node* tail;
public:
    PatientQueue() : head(nullptr), tail(nullptr) {}

    // 1 & 2. Add a patient (ID) at the end
    void addPatient(const string& id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // 3 & 5. Display all waiting patients
    void display() const {
        if (head == nullptr) {
            cout << "No patients waiting.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->patientId;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 4. Remove the first patient (doctor attends)
    void servePatient() {
        if (head == nullptr) {
            cout << "No patients to serve.\n";
            return;
        }
        Node* temp = head;
        cout << "Patient " << temp->patientId << " is being served.\n";
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    bool isEmpty() const { return head == nullptr; }

    ~PatientQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue queue;
    int choice;
    string id;

    do {
        cout << "\n--- Hospital Patient Queue ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Waiting Patients\n";
        cout << "3. Serve Next Patient\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                queue.addPatient(id);
                break;
            case 2:
                cout << "Waiting Patients:\n";
                queue.display();
                break;
            case 3:
                queue.servePatient();
                if (!queue.isEmpty()) {
                    cout << "Updated Queue:\n";
                    queue.display();
                } else {
                    cout << "Queue is now empty.\n";
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}