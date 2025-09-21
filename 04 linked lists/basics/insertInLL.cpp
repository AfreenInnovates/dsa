#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{

    // creating nodes
    Node *head = new Node{10, nullptr};

    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    // insert after 20
    Node *second = head->next;
    Node *newNode = new Node{25, nullptr};

    newNode->next = second->next;
    second->next = newNode;

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}