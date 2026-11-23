#include <iostream>
#include <string>
using namespace std;

class OrderNode
{
public:
    int orderID;
    string customerName;
    double amount;
    OrderNode* left;
    OrderNode* right;

    OrderNode(int id, string name, double a)
    {
        orderID = id;
        customerName = name;
        amount = a;
        left = NULL;
        right = NULL;
    }
};

class OrderHeap
{
private:
    OrderNode* root;
    int size;

    OrderNode* getNode(int index)
    {
        OrderNode* current = root;

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

    void swapData(OrderNode* a, OrderNode* b)
    {
        swap(a->orderID, b->orderID);
        swap(a->customerName, b->customerName);
        swap(a->amount, b->amount);
    }

    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;

            if (getNode(index)->amount > getNode(parent)->amount)
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
                getNode(left)->amount > getNode(largest)->amount)
                largest = left;

            if (right <= size &&
                getNode(right)->amount > getNode(largest)->amount)
                largest = right;

            if (largest == index)
                break;

            swapData(getNode(index), getNode(largest));
            index = largest;
        }
    }

public:
    OrderHeap()
    {
        root = NULL;
        size = 0;
    }

    void insert(int id, string name, double amount)
    {
        OrderNode* newNode = new OrderNode(id, name, amount);

        size++;

        if (size == 1)
        {
            root = newNode;
            return;
        }

        OrderNode* parent = getNode(size / 2);

        if (size % 2 == 0)
            parent->left = newNode;
        else
            parent->right = newNode;

        heapifyUp(size);
    }

    double deleteRoot()
    {
        if (root == NULL)
            return -1;

        double deletedAmount = root->amount;

        if (size == 1)
        {
            delete root;
            root = NULL;
            size = 0;
            return deletedAmount;
        }

        OrderNode* lastNode = getNode(size);
        OrderNode* parent = getNode(size / 2);

        swapData(root, lastNode);

        if (size % 2 == 0)
            parent->left = NULL;
        else
            parent->right = NULL;

        delete lastNode;
        size--;

        heapifyDown(1);

        return deletedAmount;
    }

    void heapSort()
    {
        double sortedAmounts[100];
        int count = 0;

        cout << "\nDeleted Order Amounts (Descending):\n";

        while (size > 0)
        {
            double amount = deleteRoot();

            sortedAmounts[count] = amount;
            cout << amount << " ";
            count++;
        }

        cout << "\n\nOrder Amounts (Ascending):\n";

        for (int i = count - 1; i >= 0; i--)
        {
            cout << sortedAmounts[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    OrderHeap heap;

    heap.insert(301, "Ali", 4500);
    heap.insert(302, "Ahmed", 1200);
    heap.insert(303, "Sara", 7800);
    heap.insert(304, "Ayesha", 3200);
    heap.insert(305, "Usman", 9500);
    heap.insert(306, "Zain", 2500);

    heap.heapSort();

    return 0;
}