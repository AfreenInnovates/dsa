#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // 'next' is a pointer to the next node in the linked list.
    // It stores the memory address of the next Node object.
    // If there is no next node (i.e., this is the last node), it stores nullptr.

    Node(int data1, Node *next1 = nullptr)
    // Constructor to create a new node
    // 'data1' is the value to store in this node
    // next1 is the pointer to the next node (default is nullptr if the node is the last one)
    {
        data = data1;
        next = next1;
    }
};

// Node *first = new Node(5);   // next defaults to nullptr
// Node *second = new Node(10); // next defaults to nullptr
// first->next = second; // now first points to second
// When first was created, we didn’t know about second yet, so next = nullptr.
// Later, we update next manually to link the nodes.

//
//
// Convert to LL
Node *convertToLL(vector<int> arr)
{
    // STEP 1: Create the first node from arr[0].
    Node *head = new Node(arr[0]);
    // right now: head -> [2 | nullptr]

    // STEP 2: Create a helper pointer (mover)
    // that will "move along" the list as we build it.
    Node *mover = head;
    // right now: head, mover both point to [2 | nullptr]

    // STEP 3: Iterate for remaining elements in the array
    for (int i = 1; i < arr.size(); i++)
    {
        // ---- 1. Create a new node with arr[i] ----
        // Example for i=1: arr[1] = 5 → new Node(5)
        // new node created: [5 | nullptr]

        // ---- 2. Link the current mover->next to this new node ----
        mover->next = new Node(arr[i]);
        // now mover->next (which was nullptr earlier)
        // stores the address of the new node

        // ---- 3. Move the mover pointer forward ----
        mover = mover->next;
        // Now mover points at the node we just created.
        // head still points at the beginning!
    }

    // STEP 4: return head (the start of the list)
    return head;
}

//
//
//
// print a linked list
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//
//
// SUM APPROACHES
int sumLL_iterative(Node *head)
{
    Node *temp = head; // let's start from the head of the list
    int sum = 0;

    while (temp) // keep going until temp becomes a nullptr
    {
        sum += temp->data; // add current node's data to sum
        temp = temp->next; // move to the next node using the stored address
    }
    return sum;
}

int sumLL_recursive(Node *head)
{
    if (!head)
        return 0;
    return head->data + sumLL_recursive(head->next);
}

int sumLL_usingVector(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int sum = 0;
    for (int val : arr)
        sum += val;
    return sum;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    Node *head = convertToLL(arr);

    cout << "Linked list elements: ";
    printLL(head);

    cout << "Sum (iterative): " << sumLL_iterative(head) << endl;
    cout << "Sum (recursive): " << sumLL_recursive(head) << endl;
    cout << "Sum (using vector): " << sumLL_usingVector(head) << endl;

    return 0;
}