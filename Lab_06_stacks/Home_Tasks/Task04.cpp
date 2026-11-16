
#include <iostream>
using namespace std;

class TwoStacks {
private:
    int arr[10];

    int top1;
    int top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = 10;
    }

    void push1(int value) {

        if (top1 + 1 == top2) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top1++;
        arr[top1] = value;
    }

    void push2(int value) {

        if (top1 + 1 == top2) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top2--;
        arr[top2] = value;
    }

    int pop1() {

        if (top1 == -1) {
            cout << "Stack 1 is Empty" << endl;
            return -1;
        }

        int value = arr[top1];

        top1--;

        return value;
    }

    int pop2() {

        if (top2 == 10) {
            cout << "Stack 2 is Empty" << endl;
            return -1;
        }

        int value = arr[top2];

        top2++;

        return value;
    }

    int TOP1() {

        if (top1 == -1) {
            cout << "Stack 1 is Empty" << endl;
            return -1;
        }

        return arr[top1];
    }

    int TOP2() {

        if (top2 == 10) {
            cout << "Stack 2 is Empty" << endl;
            return -1;
        }

        return arr[top2];
    }

    void display() {

        cout << "Available Books: ";

        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;

        cout << "Returned Books: ";

        for (int i = 9; i >= top2; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    TwoStacks s;

    // Stack 1: Available Books

    s.push1(101);
    s.push1(102);
    s.push1(103);

    // Stack 2: Returned Books

    s.push2(201);
    s.push2(202);
    s.push2(203);

    cout << "Two Stacks in One Array" << endl;

    s.display();

    cout << endl;

    cout << "Top of Available Books: "
         << s.TOP1() << endl;

    cout << "Top of Returned Books: "
         << s.TOP2() << endl;

    cout << endl;

    cout << "Popped from Stack 1: "
         << s.pop1() << endl;

    cout << "Popped from Stack 2: "
         << s.pop2() << endl;

    cout << endl;

    cout << "After Pop Operations:" << endl;

    s.display();

    return 0;
}
