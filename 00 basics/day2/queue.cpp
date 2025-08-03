#include <bits/stdc++.h>
using namespace std;

int main()
{
    // FIFO Queue Example
    cout << "=== Standard Queue (FIFO) ===" << endl;
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.emplace(4);

    q1.back() += 5;
    cout << "Back element after +=5: " << q1.back() << endl;
    cout << "Front element: " << q1.front() << endl;

    q1.pop();
    cout << "Front after pop: " << q1.front() << endl;
    cout << "Back after pop: " << q1.back() << endl
         << endl;

    // Priority Queue (Max Heap)
    cout << "=== Priority Queue (Max Heap) ===" << endl;
    priority_queue<int> pq1;
    pq1.push(3);
    pq1.push(1);
    pq1.push(-1);
    cout << "Top element: " << pq1.top() << endl;
    cout << "Size: " << pq1.size() << endl;
    pq1.pop();
    cout << "Top after pop: " << pq1.top() << endl;
    cout << "Size after pop: " << pq1.size() << endl
         << endl;

    // Priority Queue (Min Heap)
    cout << "=== Priority Queue (Min Heap) ===" << endl;
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(3);
    pq2.push(1);
    pq2.push(-1);
    cout << "Top element: " << pq2.top() << endl;
    cout << "Size: " << pq2.size() << endl;
    pq2.pop();
    cout << "Top after pop: " << pq2.top() << endl;
    cout << "Size after pop: " << pq2.size() << endl;
}

// push - O(log(n))
// top - O(1)
// pop - O(log(n))