#include <iostream> // for std::cout, std::endl
#include <stack>    // for std::stack
using namespace std;

struct ListNode
{
    int val;        // stores the integer digit/value for this node
    ListNode *next; // pointer to the next node in the list (or nullptr if last)

    // default constructor: zero value and no next
    ListNode() : val(0), next(nullptr) {}

    // constructor with value only: next defaults to nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // constructor with value and explicit next pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /*
     * STACK-BASED reverse (matches your original logic, annotated)
     *
     * Time Complexity: O(n) — we visit each node twice in the worst case
     * Space Complexity: O(n) — we push every node pointer onto the stack
     *
     * This implementation uses an explicit stack to collect node pointers in LIFO
     * order, then pops them to re-link into a reversed list. It mutates the existing
     * nodes' next pointers; it does not allocate new list nodes (but uses O(n) memory
     * for the stack of pointers).
     */
    ListNode *reverseListStack(ListNode *head)
    {
        // Create an empty stack that will hold pointers to ListNode.
        // We will push node pointers from the original list so we can pop them in reverse order.
        stack<ListNode *> st;

        // Iterate through the original list, pushing every node pointer onto the stack.
        // After this loop:
        //  - 'st' contains pointers in the order head, head->next, ..., tail (top is tail)
        //  - 'head' will be moved along and becomes nullptr at the end of traversal.
        while (head != nullptr)
        {
            // push the current node pointer onto the stack
            st.push(head);

            // move the traversal pointer forward to the next node
            // IMPORTANT: this uses the original node->next as-is; we haven't changed any links yet.
            head = head->next;
        }

        // At this point head == nullptr (we walked off the end of the original list).
        // We'll reuse the 'head' variable to hold the new head of the reversed list.
        // Initialize a 'tail' pointer to track the last node of the reversed list while building it.
        ListNode *tail = nullptr;

        // Pop nodes off the stack one by one and stitch them into a new list order.
        // Because the stack is LIFO, the nodes come off in reverse (tail -> ... -> head).
        while (!st.empty())
        {
            // If head is nullptr it means we haven't yet set the new head of the reversed list.
            // The first popped node becomes the new head.
            if (head == nullptr)
            {
                // set head to the top node from the stack (this will be the last node of original list)
                head = st.top();

                // set tail to the node we just made the new head (tail tracks the end of the reversed list)
                tail = head;

                // IMPORTANT: cut the old next pointer to avoid forming cycles.
                // The original node->next might still point to some node; setting to nullptr
                // ensures the newly-constructed reversed list ends at 'tail' for now.
                tail->next = nullptr;
            }
            else
            {
                // If head is not nullptr, we already have at least one node in our reversed list.
                // Attach the next popped node to tail->next, and then advance the tail pointer.
                tail->next = st.top(); // link the next reversed-node after the current tail
                tail = tail->next;     // move tail forward to the newly appended node

                // Again we must set tail->next = nullptr to sever the original forward link
                // from the popped node. This prevents cycles and ensures the reversed list
                // remains properly terminated at tail.
                tail->next = nullptr;
            }

            // Remove the pointer we just consumed from the stack.
            st.pop();
        }

        // When the stack is empty we've reconstructed the reversed list and 'head'
        // points to its first node. Return that pointer.
        return head;
    }

    /*
     * ITERATIVE IN-PLACE reverse (optimized for O(1) extra space)
     *
     * Time Complexity: O(n) — single pass through the list
     * Space Complexity: O(1) — only a few pointers used, no auxiliary memory proportional to n
     *
     * This is the classic "three-pointer" iterative reverse:
     * prev <- cur -> next  (we move cur forward while reversing links)
     */
    ListNode *reverseListIterative(ListNode *head)
    {
        // prev will eventually become the new head; initialize to nullptr because
        // the reversed tail should point to nullptr.
        ListNode *prev = nullptr;

        // cur is our traversal pointer; we start at the current head of the list.
        ListNode *cur = head;

        // We iterate until cur becomes nullptr (we walked past the original tail).
        while (cur != nullptr)
        {
            // Save cur->next in a temporary pointer 'nxt' so we don't lose the rest of the list.
            // After we reverse cur->next to point to prev, we will use nxt to continue traversal.
            ListNode *nxt = cur->next;

            // Reverse the link of the current node: make it point backward to 'prev'
            // instead of forward to its original next node.
            cur->next = prev;

            // Move prev forward to the node we just processed (cur).
            prev = cur;

            // Move cur forward to the next node to process (original cur->next stored in 'nxt').
            cur = nxt;
        }

        // When cur == nullptr, prev points to the new head (original tail). Return it.
        return prev;
    }
}; // end of class Solution

// --------------------- Helper functions ---------------------

// Print the linked list values in order: e.g., "1 -> 2 -> 3"
void printList(ListNode *head)
{
    // Traverse from head to tail, printing each value.
    while (head != nullptr)
    {
        // Print the current node's value. No newline yet; we'll print arrows between nodes.
        cout << head->val;

        // If there is a next node, print an arrow separator for readability.
        if (head->next != nullptr)
            cout << " -> ";

        // Advance to the next node.
        head = head->next;
    }
    // After finishing traversal, print a newline to finish the line.
    cout << endl;
}

// --------------------- main (demonstration) ---------------------
int main()
{
    // Build a simple list: 1 -> 2 -> 3 -> 4
    // We allocate nodes individually and link them. These are the same nodes we will reverse.
    ListNode *node4 = new ListNode(4);        // create node with value 4, next = nullptr
    ListNode *node3 = new ListNode(3, node4); // create node 3, next -> node4
    ListNode *node2 = new ListNode(2, node3); // create node 2, next -> node3
    ListNode *head1 = new ListNode(1, node2); // create node 1, next -> node2
                                              // now head1 points to the full list 1->2->3->4

    // Print the original list before reversal
    cout << "Original list for stack-based reversal: ";
    printList(head1);

    // Use the Solution class
    Solution sol;

    // Demonstrate the stack-based reverse (matches your original approach)
    // Note: reverseListStack modifies the existing nodes' next pointers and returns the new head.
    ListNode *reversedByStack = sol.reverseListStack(head1);

    // Print the reversed list
    cout << "Reversed (stack-based): ";
    printList(reversedByStack);

    // Build another list again for demonstrating the iterative (in-place) reverse.
    // (We build a fresh list because the previous nodes were mutated by the stack method.)
    ListNode *a4 = new ListNode(4);
    ListNode *a3 = new ListNode(3, a4);
    ListNode *a2 = new ListNode(2, a3);
    ListNode *head2 = new ListNode(1, a2);

    cout << "Original list for iterative (O(1) space) reversal: ";
    printList(head2);

    // Demonstrate the optimized iterative reverse.
    ListNode *reversedIterative = sol.reverseListIterative(head2);

    // Print the reversed list produced by the iterative method
    cout << "Reversed (iterative O(1) space): ";
    printList(reversedIterative);
    return 0;
}
