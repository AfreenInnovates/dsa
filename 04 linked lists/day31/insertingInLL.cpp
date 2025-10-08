#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int nextData, Node *nextPtr = nullptr)
    {
        data = nextData;
        next = nextPtr;
    }
};

void insertAtBeginning(Node *head, int eleToInsert)
{
    Node *newNode = new Node(eleToInsert);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *head, int eleToInsert)
{
    Node *newNode = new Node(eleToInsert);

    // CASE 1: empty list
    // If head is nullptr, the list is empty, so the new node becomes the head
    if (!head)
    {
        head = newNode;
        return;
    }

    // CASE 2: non empty list
    Node *temp = head;
    // traversing the list
    // temp starts at head
    // temp -> next means "is there a node after this one?"
    //  the loop continues as long as there is a next node
    // when temp->next == NULL, we've reached the last node
    // temp is sitting on the last node now, so we just attach the new node to it
    while (temp->next)
    { // keep going till last
        // keep going until temp points to NULL
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node *&head, int pos, int eleToInsert)
{
    if (pos == 1)
    {
        insertAtBeginning(head, eleToInsert);
    }

    Node *temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Position out of range\n";
        return;
    }

    Node *newNode = new Node(eleToInsert, temp->next);
    temp->next = newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr; // empty list

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    insertAtPosition(head, 2, 25);

    printList(head);
    return 0;
}
