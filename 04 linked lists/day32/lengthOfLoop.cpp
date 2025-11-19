#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    /*
      Approach 1: Using unordered_map to detect loops
      Time Complexity  : O(N)
      Space Complexity : O(N)
   */
    int lengthOfLoop_HashMap(Node *head)
    {
        if (head == nullptr)
            return 0;

        unordered_map<Node *, int> mpp;
        Node *temp = head;
        int step = 1;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                // Loop detected → difference gives loop length
                return step - mpp[temp];
            }
            mpp[temp] = step;
            step++;
            temp = temp->next;
        }
        return 0;
    }

    /*
      Approach 2: Floyd’s Cycle Detection (no extra space) : slow and fast pointers
      Time Complexity  : O(N)
      Space Complexity : O(1)
*/
    int lengthLoop(Node *slow, Node *fast)
    {
        int count = 1;
        fast = fast->next; // move one step ahead first
        while (fast != slow)
        {
            fast = fast->next;
            count++;
        }
        return count;
    }

    int lengthOfLoop_Floyd(Node *head)
    {
        if (head == nullptr)
            return 0;

        Node *slow = head;
        Node *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return lengthLoop(slow, fast);
            }
        }
        return 0;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;

    Solution sol;

    cout << "Using Hash Map Approach:\n";
    int len1 = sol.lengthOfLoop_HashMap(head);
    cout << "Loop Length = " << len1 << endl
         << endl;

    cout << "Using Floyd’s Cycle Detection:\n";
    int len2 = sol.lengthOfLoop_Floyd(head);
    cout << "Loop Length = " << len2 << endl;

    return 0;
}
