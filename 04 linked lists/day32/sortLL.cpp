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
  Approach 1: Using Vector + Sort
  --------------------------------
  Steps:
   1️⃣ Copy all node values into a vector.
   2️⃣ Sort the vector.
   3️⃣ Copy back the sorted values into the linked list.

  Total Time=O(N)+O(NlogN)+O(N)
  Space Complexity : O(N)
----------------------------------------------------------*/
class Solution_VectorSort
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        vector<int> vals;
        ListNode *temp = head;

        // Copy node values → O(N)
        while (temp)
        {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        // Sort vector → O(N log N)
        sort(vals.begin(), vals.end());

        // Copy values back → O(N)
        temp = head;
        int i = 0;
        while (temp)
        {
            temp->val = vals[i++];
            temp = temp->next;
        }

        return head;
    }
};

/*----------------------------------------------------------
  Approach 2: Merge Sort on Linked List (Optimal)
  --------------------------------
  Steps:
   1️⃣ Split the list into halves (using slow/fast pointers).
   2️⃣ Recursively sort both halves.
   3️⃣ Merge the two sorted halves.

  Time Complexity  : O(N log N)
 Space Complexity : O(log N)   (recursive stack)
----------------------------------------------------------*/
class Solution_MergeSort
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = getMiddle(head);
        ListNode *rightHead = mid->next;
        mid->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(rightHead);

        return mergeTwoLists(left, right);
    }

private:
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1) ? l1 : l2;
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
    vector<int> vals = {4, 2, 1, 3, 5};

    cout << "Original List: ";
    ListNode *head = createList(vals);
    printList(head);

    Solution_VectorSort sol1;
    ListNode *sorted1 = sol1.sortList(createList(vals));
    cout << "\nSorted (Vector + Sort, O(N logN), Space O(N)):\n";
    printList(sorted1);

    Solution_MergeSort sol2;
    ListNode *sorted2 = sol2.sortList(createList(vals));
    cout << "\nSorted (Merge Sort, O(N logN), Space O(logN)):\n";
    printList(sorted2);

    return 0;
}
