#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*----------------------------------------------------------
  Approach 1: Two-Pass Counting Method
  ------------------------------------
  Step 1️⃣: Count total number of nodes.
  Step 2️⃣: Move to (count - n - 1)-th node and remove next node.

  Time Complexity  : O(N)  → two traversals (count + delete)
  Space Complexity : O(1)  → constant extra space
----------------------------------------------------------*/
class Solution_Counting
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;

        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        if (n == count)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        for (int i = 1; i < count - n; i++)
        {
            temp = temp->next;
        }

        ListNode *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

/*----------------------------------------------------------
  Approach 2: One-Pass Two Pointer Method
  ---------------------------------------
  Step 1️⃣: Move 'fast' pointer n+1 steps ahead.
  Step 2️⃣: Move both 'fast' and 'slow' together.
  Step 3️⃣: When 'fast' hits end, 'slow' is just before node to remove.

  Time Complexity  : O(N)  → single traversal
  Space Complexity : O(1)  → constant extra space
----------------------------------------------------------*/
class Solution_TwoPointer
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        for (int i = 0; i <= n; i++)
        {
            if (!fast)
                return head;
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return dummy.next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode *createList(vector<int> vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *temp = head;
    for (int i = 1; i < vals.size(); i++)
    {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> vals = {1, 2, 3, 4, 5};
    int n = 2;

    cout << "Original List: ";
    ListNode *head = createList(vals);
    printList(head);

    Solution_Counting sol1;
    ListNode *res1 = sol1.removeNthFromEnd(createList(vals), n);
    cout << "\nAfter Removing " << n << "th from End (Counting Method): ";
    printList(res1);

    Solution_TwoPointer sol2;
    ListNode *res2 = sol2.removeNthFromEnd(createList(vals), n);
    cout << "\nAfter Removing " << n << "th from End (Two Pointer Method): ";
    printList(res2);

    return 0;
}
