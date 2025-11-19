#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

/*
  Approach 1: Counting Method (Two Pass)
  ---------------------------------------
  Step 1️⃣: Count number of 0s, 1s, and 2s.
  Step 2️⃣: Rewrite node values in sorted order (0s → 1s → 2s).

  Time Complexity  : O(N) + O(N) = O(N)
  Space Complexity : O(1)
----------------------------------------------------------*/
class Solution_Counting
{
public:
    Node *segregate(Node *head)
    {
        if (!head)
            return nullptr;

        int c0 = 0, c1 = 0, c2 = 0;
        Node *temp = head;

        while (temp)
        {
            if (temp->data == 0)
                c0++;
            else if (temp->data == 1)
                c1++;
            else
                c2++;
            temp = temp->next;
        }

        // Rewrite node values in order
        temp = head;
        while (temp)
        {
            if (c0 > 0)
            {
                temp->data = 0;
                c0--;
            }
            else if (c1 > 0)
            {
                temp->data = 1;
                c1--;
            }
            else
            {
                temp->data = 2;
                c2--;
            }
            temp = temp->next;
        }

        return head;
    }
};

/*
  Approach 2: Pointer Rearrangement (One Pass)
  ---------------------------------------------
  Step 1️⃣: Create 3 dummy lists for 0s, 1s, and 2s.
  Step 2️⃣: Traverse the list once, attaching nodes to the right list.
  Step 3️⃣: Connect all three lists together.

  Time Complexity  : O(N)
  Space Complexity : O(1)
----------------------------------------------------------*/
class Solution_Pointer
{
public:
    Node *segregate(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *zeroL = new Node(0);
        Node *oneL = new Node(0);
        Node *twoL = new Node(0);

        Node *zero = zeroL, *one = oneL, *two = twoL;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Connect the three lists
        zero->next = (oneL->next) ? (oneL->next) : (twoL->next);
        one->next = twoL->next;
        two->next = nullptr;

        head = zeroL->next;

        delete zeroL;
        delete oneL;
        delete twoL;

        return head;
    }
};

Node *createList(vector<int> vals)
{
    if (vals.empty())
        return nullptr;
    Node *head = new Node(vals[0]);
    Node *temp = head;
    for (int i = 1; i < vals.size(); i++)
    {
        temp->next = new Node(vals[i]);
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> vals = {1, 2, 0, 1, 2, 0, 1};

    cout << "Original List: ";
    Node *head = createList(vals);
    printList(head);

    Solution_Counting sol1;
    Node *res1 = sol1.segregate(createList(vals));
    cout << "\nSorted (Counting Method - O(N), Space O(1)):\n";
    printList(res1);

    Solution_Pointer sol2;
    Node *res2 = sol2.segregate(createList(vals));
    cout << "\nSorted (Pointer Rearrangement - O(N), Space O(1)):\n";
    printList(res2);

    return 0;
}
