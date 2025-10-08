#include <bits/stdc++.h>
using namespace std;

/**
 * ================================
 * STRUCT: ListNode
 * ================================
 * This defines what a "node" in a singly linked list looks like.
 * Each node has two parts:
 *   1. "val" → stores the actual integer data for this node.
 *   2. "next" → a pointer that stores the address of the next node in the chain.
 *
 * Example:
 *   A node with value=5 and next pointing to another node (say with value=10)
 *   looks like:  [5 | *] --> [10 | *] --> ...
 *
 * "nullptr" means the pointer does not point anywhere, i.e., end of the list.
 */
struct ListNode
{
    int val;        // the data stored in this node
    ListNode *next; // pointer to the next node in the list

    // Constructor 1: creates a node with value 0, and next = null
    ListNode() : val(0), next(nullptr) {}

    // Constructor 2: creates a node with given value, and next = null
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor 3: creates a node with given value, and also links it to another node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* =========================================================
   APPROACH 1: Brute Force (Two Pass Method)
   =========================================================
   Idea:
   - We do TWO full traversals (passes) of the linked list.
   - Pass 1: Count how many nodes are there.
   - Pass 2: Traverse again and stop at the middle node.

   Why it works:
   - If we know total nodes = N,
   - The middle node (0-based index) is at N/2.
     Example:
       N = 5 → middle index = 2 (3rd node).
       N = 6 → middle index = 3 (4th node).
========================================================= */
ListNode *middleNodeBruteForce(ListNode *head)
{
    // STEP 1: Count total number of nodes
    int count = 0;         // keeps track of how many nodes we see
    ListNode *temp = head; // "temp" will travel through the list, starting from head

    while (temp != nullptr)
    {                      // while we haven’t reached the end of the list
        count++;           // we found one more node
        temp = temp->next; // move temp to the next node in the chain
    }
    // when loop ends, count = total number of nodes

    // STEP 2: Find index of the middle node
    int midIndex = count / 2; // integer division → automatically works for odd/even cases

    // STEP 3: Traverse again until we reach midIndex
    temp = head; // reset temp to start from the beginning
    for (int i = 0; i < midIndex; i++)
    {
        temp = temp->next; // move forward one step at a time
    }

    // Now temp points exactly at the middle node
    return temp;
}

/* =========================================================
   APPROACH 2: Fast and Slow Pointers (One Pass Method)
   =========================================================
   Idea:
   - Instead of counting nodes first, we use TWO pointers.
   - "slow" pointer → moves ONE step at a time.
   - "fast" pointer → moves TWO steps at a time.
   - When fast reaches the end:
       → slow will be exactly in the middle.

   Why it works:
   - Because fast covers double the distance of slow,
     by the time fast runs out of nodes, slow has covered half.
========================================================= */
ListNode *middleNodeFastSlow(ListNode *head)
{
    // Edge cases: if list is empty or has only 1 node, then the head itself is the middle
    if (head == nullptr || head->next == nullptr)
        return head;

    // Both start at the first node
    ListNode *slow = head;
    ListNode *fast = head;

    // Keep moving until fast reaches end (or one before end if even length)
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // move slow pointer by 1 step
        fast = fast->next->next; // move fast pointer by 2 steps
    }

    // When loop ends, slow is pointing to the middle
    return slow;
}

/* =========================================================
   HELPER FUNCTION: createList
   =========================================================
   Purpose:
   - Convert a vector of integers into a linked list.
   - Returns the head pointer of that list.

   Example:
       input = {1,2,3}
       output = head pointing to 1->2->3
========================================================= */
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr; // no values → no list

    // Create the first node (head)
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head; // "current" will help us keep building the list

    // Create the remaining nodes and link them
    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]); // attach new node to the chain
        current = current->next;                 // move current to the newly created node
    }
    return head; // return starting point of the list
}

/* =========================================================
   HELPER FUNCTION: printList
   =========================================================
   Purpose:
   - Print all nodes in the linked list in a readable format.
   - Example:  1 -> 2 -> 3 -> 4 -> 5
========================================================= */
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val; // print value of current node
        if (current->next != nullptr)
            cout << " -> ";      // arrow if not last node
        current = current->next; // move forward
    }
    cout << endl;
}

/* =========================================================
   MAIN FUNCTION
   =========================================================
   Steps:
   1. Build two example linked lists (one odd length, one even length).
   2. Run BOTH approaches (Brute Force + Fast/Slow).
   3. Print results so we can compare.
========================================================= */
int main()
{
    // ------------------- TEST CASE 1: Odd length -------------------
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode *head1 = createList(values1);

    cout << "Original list (odd length): ";
    printList(head1);

    // Brute Force method
    ListNode *mid1_brute = middleNodeBruteForce(head1);
    cout << "[Brute Force] Middle node value: " << mid1_brute->val << endl;

    // Fast/Slow method
    ListNode *mid1_fastslow = middleNodeFastSlow(head1);
    cout << "[Fast/Slow] Middle node value: " << mid1_fastslow->val << endl;

    cout << "------------------------------------------------" << endl;

    // ------------------- TEST CASE 2: Even length -------------------
    vector<int> values2 = {1, 2, 3, 4, 5, 6};
    ListNode *head2 = createList(values2);

    cout << "Original list (even length): ";
    printList(head2);

    // Brute Force method
    ListNode *mid2_brute = middleNodeBruteForce(head2);
    cout << "[Brute Force] Middle node value: " << mid2_brute->val << endl;

    // Fast/Slow method
    ListNode *mid2_fastslow = middleNodeFastSlow(head2);
    cout << "[Fast/Slow] Middle node value: " << mid2_fastslow->val << endl;

    return 0;
}
