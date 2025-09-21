#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

Node *convertToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

int countNodes(Node *head)
{
    int count = 0;

    Node *temp = head;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void displayLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool searchElementLL(Node *head, int target)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data == target)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

pair<int, int> findMinMax(Node *head)
{
    if (!head)
        throw runtime_error("List is empty");

    int mini = head->data;
    int maxi = head->data;

    Node *temp = head;

    while (temp)
    {
        mini = min(mini, temp->data);
        maxi = max(maxi, temp->data);

        temp = temp->next;
    }
    return {mini, maxi};
}

int countOccurrencesOfEle(Node *head, int target)
{
    int count = 0;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == target)
            count++;

        temp = temp->next;
    }
    return count;
}

int getNthNode(Node *head, int n)
{
    Node *temp = head;
    int index = 1;

    while (temp)
    {
        if (index == n)
            return temp->data;

        index++;
        temp = temp->next;
    }

    throw out_of_range("Position out of range"); // if n > length
}

int main()
{
    vector<int> arr = {2, 5, 8, 7, 5};
    Node *head = convertToLL(arr);

    cout << "Count nodes: " << countNodes(head) << endl;

    cout << "Search 8: " << (searchElementLL(head, 8) ? "Found" : "Not found") << endl;

    pair<int, int> minmax = findMinMax(head);
    cout << "Min: " << minmax.first << ", Max: " << minmax.second << endl;

    cout << "Occurrences of 5: " << countOccurrencesOfEle(head, 5) << endl;

    cout << "3rd Node: " << getNthNode(head, 3) << endl;
}
