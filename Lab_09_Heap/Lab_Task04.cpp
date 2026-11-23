#include <iostream>
#include <string>
#include <queue>
using namespace std;

class MedicineNode
{
public:
    string name;
    int medicineID;
    int expiryDate;
    MedicineNode* left;
    MedicineNode* right;

    MedicineNode(string n, int id, int date)
    {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = NULL;
        right = NULL;
    }
};

class MedicineHeap
{
private:
    MedicineNode* root;
    int size;

    MedicineNode* getNode(int index)
    {
        MedicineNode* current = root;

        int mask = 1;
        while (mask <= index)
            mask <<= 1;

        mask >>= 1;
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

    void swapData(MedicineNode* a, MedicineNode* b)
    {
        swap(a->name, b->name);
        swap(a->medicineID, b->medicineID);
        swap(a->expiryDate, b->expiryDate);
    }

    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;

            if (getNode(index)->expiryDate < getNode(parent)->expiryDate)
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
            int smallest = index;
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left <= size &&
                getNode(left)->expiryDate < getNode(smallest)->expiryDate)
                smallest = left;

            if (right <= size &&
                getNode(right)->expiryDate < getNode(smallest)->expiryDate)
                smallest = right;

            if (smallest == index)
                break;

            swapData(getNode(index), getNode(smallest));
            index = smallest;
        }
    }

public:
    MedicineHeap()
    {
        root = NULL;
        size = 0;
    }

    void insert(string name, int id, int date)
    {
        MedicineNode* newNode = new MedicineNode(name, id, date);

        size++;

        if (size == 1)
        {
            root = newNode;
            return;
        }

        MedicineNode* parent = getNode(size / 2);

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

        queue<MedicineNode*> q;
        q.push(root);

        cout << "\nMedicines in Level Order:\n";

        while (!q.empty())
        {
            MedicineNode* current = q.front();
            q.pop();

            cout << "Name: " << current->name
                 << " | ID: " << current->medicineID
                 << " | Expiry Date: " << current->expiryDate << endl;

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }
    }

    void deleteNearestExpiry()
    {
        if (root == NULL)
        {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "\nMedicine with Nearest Expiry:\n";
        cout << "Name: " << root->name
             << " | ID: " << root->medicineID
             << " | Expiry Date: " << root->expiryDate << endl;

        if (size == 1)
        {
            delete root;
            root = NULL;
            size = 0;
            return;
        }

        MedicineNode* lastNode = getNode(size);
        MedicineNode* parent = getNode(size / 2);

        swapData(root, lastNode);

        if (size % 2 == 0)
            parent->left = NULL;
        else
            parent->right = NULL;

        delete lastNode;
        size--;

        heapifyDown(1);
    }
};

int main()
{
    MedicineHeap heap;

    heap.insert("Panadol", 401, 20270115);
    heap.insert("Amoxicillin", 402, 20261220);
    heap.insert("Brufen", 403, 20280310);
    heap.insert("Augmentin", 404, 20261130);
    heap.insert("Calpol", 405, 20270925);
    heap.insert("Disprin", 406, 20270205);

    cout << "Medicine Min Heap:";
    heap.display();

    heap.deleteNearestExpiry();

    cout << "\nUpdated Min Heap:";
    heap.display();

    return 0;
}