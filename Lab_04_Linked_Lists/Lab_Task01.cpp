#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
    Node(int r) : rollNo(r), next(NULL) {}
};

class StudentList {
    Node* head;
public:
    StudentList() : head(NULL) {}

    // 1 & 2. Add a student (roll number) at the end
    void addStudent(int rollNo) {
        Node* newNode = new Node(rollNo);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // 3. Display all registered students
    void display() const {
        if (head == NULL) {
            cout << "No students registered.\n";
            return;
        }
        cout << "Registered Students:\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->rollNo;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 4. Search by roll number
    bool search(int rollNo) const {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == rollNo)
                return true;
            temp = temp->next;
        }
        return false;
    }

    ~StudentList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList list;
    int choice, rollNo;

    do {
        cout << "\n--- Workshop Registration ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNo;
                list.addStudent(rollNo);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNo;
                cout << (list.search(rollNo) ? "Student Found" : "Student Not Found") << endl;
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