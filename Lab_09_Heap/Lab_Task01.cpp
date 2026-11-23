#include <iostream>
#include <string>
#include <queue>
using namespace std;

class StudentNode
{
public:
    string name;
    int rollNo;
    int marks;
    StudentNode* left;
    StudentNode* right;

    StudentNode(string n, int r, int m)
    {
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};

class StudentHeap
{
private:
    StudentNode* root;
    int size;

    StudentNode* getNode(int index)
    {
        StudentNode* current = root;

        int mask = 1;
        while (mask <= index)
            mask <<= 1;

        mask >>= 1; // Skip the first bit

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

    void swapData(StudentNode* a, StudentNode* b)
    {
        swap(a->name, b->name);
        swap(a->rollNo, b->rollNo);
        swap(a->marks, b->marks);
    }

    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;

            StudentNode* childNode = getNode(index);
            StudentNode* parentNode = getNode(parent);

            if (childNode->marks > parentNode->marks)
            {
                swapData(childNode, parentNode);
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
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            StudentNode* current = getNode(index);

            if (leftIndex <= size)
            {
                StudentNode* leftNode = getNode(leftIndex);

                if (leftNode->marks > current->marks)
                    largest = leftIndex;
            }

            if (rightIndex <= size)
            {
                StudentNode* rightNode = getNode(rightIndex);
                StudentNode* largestNode = getNode(largest);

                if (rightNode->marks > largestNode->marks)
                    largest = rightIndex;
            }

            if (largest == index)
                break;

            swapData(getNode(index), getNode(largest));
            index = largest;
        }
    }

public:
    StudentHeap()
    {
        root = NULL;
        size = 0;
    }

    void insert(string name, int rollNo, int marks)
    {
        StudentNode* newNode = new StudentNode(name, rollNo, marks);

        size++;

        if (size == 1)
        {
            root = newNode;
            return;
        }

        StudentNode* parent = getNode(size / 2);

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

        queue<StudentNode*> q;
        q.push(root);

        cout << "\nStudents in Level Order:\n";

        while (!q.empty())
        {
            StudentNode* current = q.front();
            q.pop();

            cout << "Name: " << current->name
                 << " | Roll No: " << current->rollNo
                 << " | Marks: " << current->marks << endl;

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }
    }

    void deleteHighest()
    {
        if (root == NULL)
        {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "\nDeleted Student:\n";
        cout << "Name: " << root->name
             << " | Roll No: " << root->rollNo
             << " | Marks: " << root->marks << endl;

        if (size == 1)
        {
            delete root;
            root = NULL;
            size = 0;
            return;
        }

        StudentNode* lastNode = getNode(size);
        StudentNode* parent = getNode(size / 2);

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
    StudentHeap heap;

    heap.insert("Dani", 101, 85);
    heap.insert("Ahmed", 102, 92);
    heap.insert("Sara", 103, 78);
    heap.insert("Ayesha", 104, 96);
    heap.insert("Usman", 105, 88);
    heap.insert("Zain", 106, 90);

    cout << "Max Heap Before Deletion:";
    heap.display();

    heap.deleteHighest();

    cout << "\nMax Heap After Deletion:";
    heap.display();

    return 0;
}