#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// time : (2N) : O(N)
// space : (2N) : O(N)
// N new nodes + N entries in map so space
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        unordered_map<Node *, Node *> mp;

        // First pass: create copy nodes (val only) and store mapping
        Node *cur = head;
        while (cur)
        {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Second pass: assign next and random pointers using map
        cur = head;
        while (cur)
        {
            Node *copy = mp[cur];
            copy->next = (cur->next ? mp[cur->next] : nullptr);
            copy->random = (cur->random ? mp[cur->random] : nullptr);
            cur = cur->next;
        }

        // Return head of copied list
        return mp[head];
    }
};

Node *buildSampleList()
{
    // Create 5 nodes
    Node *A = new Node(7);
    Node *B = new Node(13);
    Node *C = new Node(11);
    Node *D = new Node(10);
    Node *E = new Node(1);

    // Connect next pointers
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;

    // Connect random pointers
    A->random = nullptr;
    B->random = A;
    C->random = E;
    D->random = C;
    E->random = A;

    return A;
}

void printList(Node *head, const string &label)
{
    cout << label << ":\n";
    Node *cur = head;
    while (cur)
    {
        cout << "Node(" << cur->val << ")";
        if (cur->random)
            cout << " [random -> " << cur->random->val << "]";
        else
            cout << " [random -> null]";
        cout << " | Addr: " << cur << "\n";
        cur = cur->next;
    }
    cout << "-------------------------\n";
}

// Free memory of a list
void freeList(Node *head)
{
    unordered_set<Node *> seen;
    while (head && !seen.count(head))
    {
        seen.insert(head);
        Node *nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *head = buildSampleList();

    printList(head, "Original List");

    Solution sol;
    Node *clonedHead = sol.copyRandomList(head);

    printList(clonedHead, "Cloned List");

    cout << "Verifying memory independence:\n";
    cout << "Original head address: " << head << "\n";
    cout << "Cloned head address:   " << clonedHead << "\n";
    cout << ((head != clonedHead) ? "Deep copy successful\n" : "Shallow copy (incorrect)\n");

    freeList(head);
    freeList(clonedHead);

    return 0;
}
