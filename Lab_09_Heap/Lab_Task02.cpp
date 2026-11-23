#include <iostream>
#include <string>
#include <queue>
using namespace std;

class PatientNode
{
public:
    string name;
    int patientID;
    int priority;
    PatientNode* left;
    PatientNode* right;

    PatientNode(string n, int id, int p)
    {
        name = n;
        patientID = id;
        priority = p;
        left = NULL;
        right = NULL;
    }
};

class PatientHeap
{
private:
    PatientNode* root;
    int size;

    PatientNode* getNode(int index)
    {
        PatientNode* current = root;

        int mask = 1;
        while (mask <= index)
            mask <<= 1;

        mask >>= 1;

        while (mask > 0 && current != NULL)
        {
            if (index & mask)
                current = current->right;
            else
                current = current->left;

            mask >>= 1;
        }

        return current;
    }

    void swapData(PatientNode* a, PatientNode* b)
    {
        swap(a->name, b->name);
        swap(a->patientID, b->patientID);
        swap(a->priority, b->priority);
    }

    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;

            if (getNode(index)->priority > getNode(parent)->priority)
            {
                swapData(getNode(index), getNode(parent));
                index = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int largest = index;
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left <= size &&
                getNode(left)->priority > getNode(largest)->priority)
                largest = left;

            if (right <= size &&
                getNode(right)->priority > getNode(largest)->priority)
                largest = right;

            if (largest == index)
                break;

            swapData(getNode(index), getNode(largest));
            index = largest;
        }
    }

public:
    PatientHeap()
    {
        root = NULL;
        size = 0;
    }

    void insert(string name, int id, int priority)
    {
        PatientNode* newNode = new PatientNode(name, id, priority);

        size++;

        if (size == 1)
        {
            root = newNode;
            return;
        }

        PatientNode* parent = getNode(size / 2);

        if (size % 2 == 0)
            parent->left = newNode;
        else
            parent->right = newNode;

        heapifyUp(size);
    }

    void display()
    {
        if (root == NULL)
        {
            cout << "Heap is empty.\n";
            return;
        }

        queue<PatientNode*> q;
        q.push(root);

        cout << "\nPatients in Level Order:\n";

        while (!q.empty())
        {
            PatientNode* current = q.front();
            q.pop();

            cout << "Name: " << current->name
                 << " | Patient ID: " << current->patientID
                 << " | Priority: " << current->priority << endl;

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }
    }

    void treatHighestPriority()
    {
        if (root == NULL)
        {
            cout << "No patients available.\n";
            return;
        }

        cout << "\nPatient Being Treated:\n";
        cout << "Name: " << root->name
             << " | ID: " << root->patientID
             << " | Priority: " << root->priority << endl;

        if (size == 1)
        {
            delete root;
            root = NULL;
            size = 0;
            return;
        }

        PatientNode* lastNode = getNode(size);
        PatientNode* parent = getNode(size / 2);

        swapData(root, lastNode);

        if (size % 2 == 0)
            parent->left = NULL;
        else
            parent->right = NULL;

        delete lastNode;
        size--;

        heapifyDown(1);

        if (root != NULL)
        {
            cout << "\nNext Patient:\n";
            cout << "Name: " << root->name
                 << " | ID: " << root->patientID
                 << " | Priority: " << root->priority << endl;
        }
    }
};

int main()
{
    PatientHeap heap;

    heap.insert("Patient A", 201, 3);
    heap.insert("Patient B", 202, 8);
    heap.insert("Patient C", 203, 5);
    heap.insert("Patient D", 204, 10);
    heap.insert("Patient E", 205, 6);
    heap.insert("Patient F", 206, 7);

    cout << "Hospital Emergency Max Heap:";
    heap.display();

    heap.treatHighestPriority();

    cout << "\nUpdated Heap After Treatment:";
    heap.display();

    return 0;
}