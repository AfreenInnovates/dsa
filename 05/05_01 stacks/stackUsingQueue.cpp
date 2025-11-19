#include <bits/stdc++.h>
using namespace std;

/*
 Implement Stack using Two Queues

 Logic:
 - A stack works as LIFO (Last In, First Out).
 - A queue works as FIFO (First In, First Out).

 So, we will use TWO queues (q1, q2) such that:
   - q1 always stores elements in stack order (top element at front)
   - while pushing a new element x, we:
        1️- Move all elements from q1 → q2
        2️- Push new element x into q1
        3️- Move everything back from q2 → q1
   - That way, newest element (x) will always be at the front of q1,
     mimicking stack behavior (top = front of q1).
----------------------------------------------------
*/

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    // Push: O(n)
    void push(int x)
    {
        cout << "\nPushing " << x << " onto the stack...\n";

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // (Now q1 has only the new element)
        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        cout << "Element " << x << " pushed successfully.\n";
    }

    // Pop: O(1)
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        }

        int ans = q1.front();
        q1.pop();
        cout << "Popped element: " << ans << endl;
        return ans;
    }

    // Top: O(1)
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        cout << "Current top element: " << q1.front() << endl;
        return q1.front();
    }

    // Empty: O(1)
    bool empty()
    {
        return q1.empty();
    }

    // Display stack (top → bottom)
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    MyStack st;
    int choice, val;

    while (true)
    {
        cout << "\n----- Stack using Two Queues -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Is Empty?\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input detected. Exiting...\n";
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            if (!(cin >> val))
            {
                cout << "Invalid input! Exiting...\n";
                return 0;
            }
            st.push(val);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            st.top();
            break;

        case 4:
            st.display();
            break;

        case 5:
            cout << (st.empty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;

        case 6:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
