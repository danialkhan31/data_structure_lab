#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;
    Node(string p) : player(p), next(NULL) {}
};

class Game {
    Node* head;
    Node* tail;
    int count;
public:
    Game() : head(NULL), tail(NULL), count(0) {}

    void addPlayer(string name) {
        Node* n = new Node(name);
        if (!head) {
            head = tail = n;
            n->next = head;          // points to itself
        } else {
            tail->next = n;
            n->next = head;          // circular connection
            tail = n;
        }
        count++;
    }

    void displayTurnsOnce() {
        cout << "Each player's turn once:\n";
        Node* cur = head;
        for (int i = 1; i <= count; i++) {
            cout << "  Turn " << i << ": " << cur->player << endl;
            cur = cur->next;
        }
    }

    void showWrapAround() {
        cout << "After the last player, the turn returns to the first:\n";
        Node* cur = head;
        for (int i = 1; i <= count + 1; i++) {
            cout << "  Turn " << i << ": " << cur->player;
            if (i == count) cout << "   <-- last player";
            if (i == count + 1) cout << "   <-- back to first player";
            cout << endl;
            cur = cur->next;
        }
    }

    ~Game() {
        if (!head) return;
        tail->next = NULL;        // break the circle before deleting
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    Game g;
    g.addPlayer("Ali");
    g.addPlayer("Sara");
    g.addPlayer("Daniel");
    g.addPlayer("Hina");
    g.addPlayer("Usman");

    g.displayTurnsOnce();
    cout << endl;
    g.showWrapAround();
    return 0;
}