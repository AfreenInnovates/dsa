#include <iostream>
#include <vector>

/*
  Detailed, self-contained implementation of "Reverse Nodes in k-Group"
*/

using namespace std;

struct ListNode
{
    int val;
    ListNode *next; // pointer to next node in the list (nullptr if none)

    // three convenient constructors:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /*
      Reverse nodes of the list in groups of size k and return new head.

      Important contract:
        - If the remaining number of nodes is < k, leave them as-is.
        - We reverse nodes in the half-open interval [head, tail), where
          tail is the node immediately after the k-group (i.e., exclusive).
    */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Safety / trivial-case guards:
        // If list is empty or k <= 1, there is nothing to change:
        //  - k == 1 means reversing group of size 1 (no-op).
        //  - k <= 0 is invalid; treat as no-op to avoid undefined behavior.
        if (!head || k <= 1)
            return head;

        // We want to check whether there are at least k nodes available starting
        // from head. We'll advance `tail` k steps (tail will end up at the
        // node after this k-block). If we can't move k steps because we hit
        // nullptr, that means fewer than k nodes remain — return head unchanged.
        ListNode *tail = head;
        for (int i = 0; i < k; ++i)
        {
            if (!tail)
            {
                // Not enough nodes to form a full group --> do not reverse
                // the final partial group; return head as-is.
                return head;
            }
            tail = tail->next; // move one step forward (tail will be exclusive)
        }

        // At this point there are at least k nodes in [head, tail).
        // Reverse those nodes (reverse returns pointer to new head of that block).
        ListNode *newHead = reverse(head, tail);

        // After reversing, the original `head` node is now the tail of the
        // reversed block (because it becomes the last node in that block).
        // Connect that tail to the result of recursively processing the remainder:
        // we pass `tail` (node after the reversed block) as the starting point.
        head->next = reverseKGroup(tail, k);

        // Return the new head of this whole piece (the new head of first reversed block).
        return newHead;
    }

private:
    /*
      Reverse nodes starting at 'curr' up to but not including 'end'.
      i.e., reverse the half-open interval [curr, end).

      Returns:
        - pointer to the new head of the reversed portion (previously the last node).

      Implementation detail:
        - Standard in-place linked list reversal using three pointers:
            prev, curr, next
        - Loop stops when curr == end (end is exclusive marker).
    */
    ListNode *reverse(ListNode *curr, ListNode *end)
    {
        ListNode *prev = nullptr;

        // Walk the list, reversing links until we reach the `end` marker.
        // Because end is exclusive, we stop when curr equals end.
        while (curr != end)
        {
            ListNode *next = curr->next; // remember next node (may be end)
            curr->next = prev;           // reverse the pointer direction
            prev = curr;                 // advance prev to current node
            curr = next;                 // advance curr to next node (could be end)
        }

        // When loop finishes, prev points to the new head of the reversed block.
        return prev;
    }
};

/* --------------------------- Helper utilities for testing --------------------------- */

/* Create a singly linked list from a vector of ints. Returns head pointer.
   Nodes are allocated with `new` and must be freed later with deleteList. */
ListNode *createList(const vector<int> &vals)
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

/* Print the linked list values in a human-readable form, e.g.
   1 -> 2 -> 3 -> nullptr
   If head == nullptr prints "Empty list". */
void printList(ListNode *head)
{
    if (!head)
    {
        cout << "Empty list\n";
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
    cout << '\n';
}

/* Delete all nodes of a list (free memory). This walks the list and `delete`s
   each node. After this call, the nodes are freed and the pointer becomes invalid. */
void deleteList(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        ListNode *nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

/* Utility to copy a vector and run a single test case: create list, print input,
   run algorithm, print output, free memory. */
void runTest(const vector<int> &vals, int k, const string &caseName)
{
    cout << "---- " << caseName << " (k = " << k << ") ----\n";
    ListNode *head = createList(vals);
    cout << "Input:  ";
    printList(head);

    Solution sol;
    ListNode *out = sol.reverseKGroup(head, k);

    cout << "Output: ";
    printList(out);
    cout << '\n';

    // free nodes to avoid memory leaks
    deleteList(out);
}

/* ----------------------------------- main ----------------------------------- */
int main()
{
    // Several test cases demonstrating common and edge cases.
    runTest({1, 2, 3, 4, 5}, 2, "Example 1: reverse every 2");
    // Expect: 2 -> 1 -> 4 -> 3 -> 5

    runTest({1, 2, 3, 4, 5}, 3, "Example 2: reverse every 3");
    // Expect: 3 -> 2 -> 1 -> 4 -> 5

    runTest({}, 3, "Edge case: empty list");
    // Expect: Empty list

    runTest({1, 2, 3, 4, 5}, 1, "Edge case: k = 1 (no changes)");
    // Expect: 1 -> 2 -> 3 -> 4 -> 5

    runTest({1, 2}, 3, "Edge case: k > length (no changes)");
    // Expect: 1 -> 2

    // A larger test (optional)
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, "Larger test: groups of 4");
    // Expect: 4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 9

    return 0;
}
