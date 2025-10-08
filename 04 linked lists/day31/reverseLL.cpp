#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode *createList(const vector<int> &vals)
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

/**
 * Approach 1: Reverse using a stack
 * --------------------------------
 * Logic:
 *  - Traverse the linked list and push each node's value onto a stack.
 *  - Traverse the list again, popping from the stack and updating node values.
 *
 * Time Complexity: O(N)  → Each node visited twice
 * Space Complexity: O(N) → Stack stores N elements
 */
ListNode *reverseUsingStack(ListNode *head)
{
    if (!head)
        return nullptr;

    stack<int> st;
    ListNode *temp = head;

    // Push all node values to stack
    while (temp != nullptr)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    // Pop from stack to overwrite node values (reverses order)
    temp = head;
    while (temp != nullptr)
    {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

/**
 * Approach 2: Reverse iteratively by changing pointers
 * ----------------------------------------------------
 * Logic:
 *  - Use three pointers: prev, current (temp), and next (front).
 *  - Redirect each node’s `next` pointer to its previous node.
 *
 * Time Complexity: O(N)  → Single traversal
 * Space Complexity: O(1) → Constant extra space
 */
ListNode *reverseIterative(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *front = nullptr;

    while (curr != nullptr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

/**
 * Approach 3: Reverse recursively
 * -------------------------------
 * Logic:
 *  - Base case: if head is NULL or only one node, return head.
 *  - Recursively reverse the rest of the list.
 *  - Adjust the next pointer of the second node to point to head.
 *
 * Time Complexity: O(N)  → Each node visited once
 * Space Complexity: O(N) → Recursion stack
 */
ListNode *reverseRecursive(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main()
{
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode *head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Approach 1: Stack-based reversal
    ListNode *stackReversed = reverseUsingStack(createList(vals));
    cout << "\nReversed (using stack): ";
    printList(stackReversed);

    // Approach 2: Iterative pointer reversal
    ListNode *iterativeReversed = reverseIterative(createList(vals));
    cout << "Reversed (iterative): ";
    printList(iterativeReversed);

    // Approach 3: Recursive reversal
    ListNode *recursiveReversed = reverseRecursive(createList(vals));
    cout << "Reversed (recursive): ";
    printList(recursiveReversed);

    return 0;
}
