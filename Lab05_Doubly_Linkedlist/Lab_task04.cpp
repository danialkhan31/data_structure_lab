#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node(string s) : song(s), next(NULL) {}
};

class Playlist {
    Node* head;
    Node* tail;
    int count;
public:
    Playlist() : head(NULL), tail(NULL), count(0) {}

    void addSong(string name) {
        Node* n = new Node(name);
        if (!head) {
            head = tail = n;
            n->next = head;
        } else {
            tail->next = n;
            n->next = head;          // last node points to first, never NULL
            tail = n;
        }
        count++;
    }

    void displayOnce() {
        cout << "Playlist:\n";
        Node* cur = head;
        for (int i = 1; i <= count; i++) {
            cout << "  " << i << ". " << cur->song << endl;
            cur = cur->next;
        }
    }

    void play(int rounds) {
        Node* cur = head;
        for (int r = 1; r <= rounds; r++) {
            cout << "Round " << r << ":\n";
            for (int i = 1; i <= count; i++) {
                cout << "  Playing: " << cur->song << endl;
                cur = cur->next;     // wraps automatically after last song
            }
        }
    }

    ~Playlist() {
        if (!head) return;
        tail->next = NULL;
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    Playlist p;
    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");
    p.addSong("Song D");
    p.addSong("Song E");

    p.displayOnce();
    cout << endl;
    p.play(2);
    return 0;
}