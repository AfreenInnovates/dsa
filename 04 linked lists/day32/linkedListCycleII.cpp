#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Approach 1: Brute Force (Hash Set)
// Time:  O(N)
// Space: O(N)
// ----------------------------
class SolutionBrute
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (visited.find(curr) != visited.end())
            {
                return curr;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};

// ----------------------------
// Approach 2: Optimized (Floyd’s Tortoise & Hare)
// Time:  O(N)
// Space: O(1)
// ----------------------------
class SolutionOptimized
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Detect cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        // No cycle
        if (!fast || !fast->next)
            return nullptr;

        // Find cycle start
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

ListNode *createLinkedListWithCycle()
{
    // Example: 3 -> 2 -> 0 -> -4
    //                   ^         |
    //                   |_________|
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    head->next->next->next->next = head->next;
    return head;
}

int main()
{
    ListNode *head = createLinkedListWithCycle();

    cout << "Choose approach to detect cycle:\n";
    cout << "1. Brute Force (HashSet)\n";
    cout << "2. Optimized (Floyd’s Cycle Detection)\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    ListNode *cycleStart = nullptr;

    if (choice == 1)
    {
        SolutionBrute s;
        cycleStart = s.detectCycle(head);
    }
    else if (choice == 2)
    {
        SolutionOptimized s;
        cycleStart = s.detectCycle(head);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
