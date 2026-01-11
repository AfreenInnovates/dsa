#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Approach A: Hash-set (unordered_set) to record visited node addresses
 * -------------------------------------------------------------------
 * Time Complexity: O(N) -- each node visited at most once
 * Space Complexity: O(N) -- stores up to N node pointers in the hash set
 *
 * Note: We store node *addresses* (ListNode*) in the set, not node values.
 */
bool hasCycleHash(ListNode *head)
{
    unordered_set<ListNode *> seen; // stores addresses of visited nodes
    ListNode *cur = head;
    while (cur != nullptr)
    {
        // If current node address already in set -> cycle
        if (seen.find(cur) != seen.end())
            return true;
        seen.insert(cur);
        cur = cur->next;
    }
    return false;
}

/*
 * Approach B: Floyd's Tortoise & Hare (no extra space)
 * ---------------------------------------------------
 * Time Complexity: O(N) -- both pointers move and meet in linear time
 * Space Complexity: O(1)
 *
 * The while-loop condition checks `fast && fast->next` so it's always safe
 * to advance fast by two steps inside the loop.
 */
bool hasCycleFloyd(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

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

void deleteList(ListNode *head)
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
    ListNode *acyclic = createList({1, 2, 3, 4});

    // Build another list and then create a cycle: 10 -> 20 -> 30 -> 40
    // then make tail->next point to the node with value 20 (cycle entry)
    ListNode *cyclic = createList({10, 20, 30, 40});
    // find node with value 20 (2nd node) and tail
    ListNode *tail = cyclic;
    while (tail->next)
        tail = tail->next;          // tail now points to node 40
    ListNode *entry = cyclic->next; // entry points to node 20
    tail->next = entry;             // create cycle: 40 -> 20

    cout << boolalpha;

    // Test Approach A (hash-set)
    cout << "Using hash-set approach:" << endl;
    cout << "  Acyclic list has cycle? " << hasCycleHash(acyclic) << endl; // expected: false
    cout << "  Cyclic list has cycle?  " << hasCycleHash(cyclic) << endl;  // expected: true

    // Test Approach B (Floyd)
    cout << "Using Floyd's Tortoise & Hare:" << endl;
    cout << "  Acyclic list has cycle? " << hasCycleFloyd(acyclic) << endl; // expected: false
    cout << "  Cyclic list has cycle?  " << hasCycleFloyd(cyclic) << endl;  // expected: true

    deleteList(acyclic);

    return 0;
}
