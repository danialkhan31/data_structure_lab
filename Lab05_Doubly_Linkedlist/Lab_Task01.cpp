#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string site;
    Node* prev;
    Node* next;
    Node(string s) : site(s), prev(NULL), next(NULL) {}
};

class BrowserHistory {
    Node* head;
    Node* tail;
public:
    BrowserHistory() : head(NULL), tail(NULL) {}

    void visit(string site) {
        Node* n = new Node(site);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void displayForward() {
        cout << "History (first visited -> last visited):\n";
        for (Node* t = head; t; t = t->next)
            cout << t->site << (t->next ? " -> " : "\n");
    }

    void displayBackward() {
        cout << "History (last visited -> first visited):\n";
        for (Node* t = tail; t; t = t->prev)
            cout << t->site << (t->prev ? " -> " : "\n");
    }

    ~BrowserHistory() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    BrowserHistory h;
    h.visit("google.com");
    h.visit("youtube.com");
    h.visit("github.com");
    h.visit("stackoverflow.com");
    h.visit("wikipedia.org");

    h.displayForward();
    cout << endl;
    h.displayBackward();
    return 0;
}