#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *nxt = nullptr) : val(x), next(nxt) {}
};

/*
 Time Complexity: O(n)
 Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        int len = 0;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0)
            return head;

        // make list circular
        tail->next = head;

        // find new tail: move (len - k - 1) steps from head (0-based moves),
        //    then newHead = newTail->next
        int stepsToNewTail = len - k - 1;
        ListNode *newTail = head;
        for (int i = 0; i < stepsToNewTail; ++i)
            newTail = newTail->next;

        ListNode *newHead = newTail->next;

        // break the circle
        newTail->next = nullptr;

        return newHead;
    }
};

ListNode *buildList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode *head)
{
    if (!head)
    {
        cout << "Empty\n";
        return;
    }
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val;
        if (cur->next)
            cout << " -> ";
        cur = cur->next;
    }
    cout << "\n";
}

void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter number of nodes n: ";
    int n;
    if (!(cin >> n) || n < 0)
        return 0;

    vector<int> vals;
    cout << "Enter " << n << " integers (list values):\n";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        vals.push_back(x);
    }

    cout << "Enter k (rotate right by k): ";
    int k;
    cin >> k;

    ListNode *head = buildList(vals);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode *rotated = sol.rotateRight(head, k);

    cout << "Rotated list:  ";
    printList(rotated);

    freeList(rotated);
    return 0;
}
