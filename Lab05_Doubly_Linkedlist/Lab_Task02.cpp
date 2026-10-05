#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;
    Node(string i) : image(i), prev(NULL), next(NULL) {}
};

class Gallery {
    Node* head;
    Node* tail;
public:
    Gallery() : head(NULL), tail(NULL) {}

    void addImage(string name) {
        Node* n = new Node(name);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void displayForward() {
        cout << "Forward (first -> last):\n";
        for (Node* t = head; t; t = t->next) cout << "  " << t->image << endl;
    }

    void displayBackward() {
        cout << "Backward (last -> first):\n";
        for (Node* t = tail; t; t = t->prev) cout << "  " << t->image << endl;
    }

    void demonstrateNavigation() {
        cout << "Navigation demo using next and prev:\n";
        Node* cur = head;
        cout << "  Start at        : " << cur->image << endl;
        cur = cur->next;
        cout << "  next -> moved to: " << cur->image << endl;
        cur = cur->next;
        cout << "  next -> moved to: " << cur->image << endl;
        cur = cur->prev;
        cout << "  prev -> moved to: " << cur->image << endl;
        cur = cur->prev;
        cout << "  prev -> moved to: " << cur->image << endl;
    }

    ~Gallery() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    Gallery g;
    g.addImage("sunset.jpg");
    g.addImage("mountain.png");
    g.addImage("beach.jpg");
    g.addImage("city.png");
    g.addImage("forest.jpg");

    g.displayForward();
    cout << endl;
    g.displayBackward();
    cout << endl;
    g.demonstrateNavigation();
    return 0;
}